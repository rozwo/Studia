#lang plait
;Róża Wójcicka - pracownia 3

(module+ test
  (print-only-errors #t))

;; abstract syntax -------------------------------

(define-type P
  (funP [l : (Listof d)] [e : Exp]))

(define-type d
  (funD [s : Symbol] [l : (Listof Symbol)] [e : Exp]))

(define-type Exp
  (numE [n : Number])
  (varE [x : Symbol])
  (appE [e1 : Exp] [e2 : Exp])
  (ifzE [e0 : Exp] [e1 : Exp] [e2 : Exp])
  (letE [x : Symbol] [e1 : Exp] [e2 : Exp])
  (funE [f : Symbol] [l : (Listof Exp)]))

;e := {f (e1...el)} gdzie l>=0
;d := [fun f (x1...xl) = e] gdzie l>=0
;p := {define {d1...dk} for e} gdzie k>=0

;; parse ----------------------------------------
(define (parse-p [s : S-Exp]) : P
  (if (s-exp-match? `{define {ANY ...} for ANY} s)
      (funP (map parse-d (s-exp->list (second (s-exp->list s))))
            (parse (fourth (s-exp->list s))))
      (error 'parse-p "invalid input")))

(define (parse-d [s : S-Exp]) : d
  (if (s-exp-match? `{fun SYMBOL {SYMBOL ...} = ANY} s)
      (funD (s-exp->symbol (second (s-exp->list s)))
            (map s-exp->symbol (s-exp->list (third (s-exp->list s))))
            (parse (list-ref (s-exp->list s) 4)))
      (error 'parse-d "invalid input")))

(define (parse [s : S-Exp]) : Exp
  (cond
    [(s-exp-match? `NUMBER s)
     (numE (s-exp->number s))]
    [(s-exp-match? `SYMBOL s)
     (varE (s-exp->symbol s))]
    [(s-exp-match? `{ANY SYMBOL ANY} s)
     (appE (appE (varE (parse-op (s-exp->symbol (second (s-exp->list s)))))
                 (parse (first (s-exp->list s))))
           (parse (third (s-exp->list s))))]
    [(s-exp-match? `{ANY ANY} s)
     (appE (parse (first (s-exp->list s)))
           (parse (second (s-exp->list s))))]
    [(s-exp-match? `{ifz ANY then ANY else ANY} s)
     (ifzE (parse (second (s-exp->list s)))
           (parse (fourth (s-exp->list s)))
           (parse (list-ref (s-exp->list s) 5)))]
    [(s-exp-match? `{let SYMBOL be ANY in ANY} s)
     (letE (s-exp->symbol (second (s-exp->list s)))
           (parse (fourth (s-exp->list s)))
           (parse (list-ref (s-exp->list s) 5)))]
    [(s-exp-match? `{SYMBOL {ANY ...}} s)
     (funE (s-exp->symbol (first (s-exp->list s)))
           (map parse (s-exp->list (second (s-exp->list s)))))]
    [else (error 'parse "invalid input")]))

(define prim-ops '(+ - * / = <=))

(define (parse-op [op : Symbol]) : Symbol
  (if (member op prim-ops)
      op 
      (error 'parse "unknown operator")))

(module+ test
  (test (parse `2)
        (numE 2))
  (test (parse `x)
        (varE 'x))
  (test (parse `{2 + 1})
        (appE (appE (varE '+) (numE 2)) (numE 1)))
  (test (parse `{3 * 4})
        (appE (appE (varE '*) (numE 3)) (numE 4)))
  (test/exn (parse `{{1 + 2}})
            "invalid input")
  (test (parse `{+ 1})
        (appE (varE '+) (numE 1)))
  (test/exn (parse `{1 ^ 2})
            "unknown operator")
  (test (parse `{double 9})
        (appE (varE 'double) (numE 9))))


;; eval --------------------------------------

;; values

(define-type ValueE
  (numV [n : Number])
  (boolV [b : Boolean])
  (funV [x : (Listof Symbol)] [e : Exp])
  (primopV [f : (ValueE -> ValueE)]))

(define-type Binding
  (bind [name : Symbol]
        [val : ValueE]))

;; environments

(define-type-alias Env (Listof Binding))

(define-type-alias Value Number)

(define mt-env empty)

(define (extend-env [env : Env] [x : Symbol] [v : ValueE]) : Env
  (cons (bind x v) env))

(define (lookup-env [n : Symbol] [env : Env]) : ValueE
  (type-case (Listof Binding) env
    [empty (error 'lookup "unbound variable")]
    [(cons b rst-env) (cond
                        [(eq? n (bind-name b))
                         (bind-val b)]
                        [else (lookup-env n rst-env)])]))

;; primitive operations and the initial environment

(define (op-num->valueE [f : (Number Number -> Number)]) : ValueE
  (primopV
   (λ (v1)
     (type-case ValueE v1
       [(numV n1)
        (primopV
         (λ (v2)
           (type-case ValueE v2
             [(numV n2)
              (numV (f n1 n2))]
             [else
              (error 'eval "type error")])))]
       [else
        (error 'eval "type error")]))))

(define (leqE n1 n2)
  (if (<= n1 n2) 0 -1))

(define init-env-op 
  (foldr (λ (b env) (extend-env env (fst b) (snd b)))
         mt-env 
         (list (pair '+ (op-num->valueE +))
               (pair '- (op-num->valueE -))
               (pair '* (op-num->valueE *))
               (pair '<= (op-num->valueE leqE)))))

(define (init-env [l : (Listof d)] [env : Env]) : Env
  (if (empty? l)
      env
      (init-env (rest l) (extend-env env
                                     (funD-s (first l))
                                     (funV (funD-l (first l)) (funD-e (first l)))))))

;; evaluation function (eval/apply)

(define (apply [v1 : ValueE] [v2 : ValueE] [env : Env]) : ValueE
  (type-case ValueE v1
    [(funV x b)
     (eval b (extend-env env (first x) v2))]
    [(primopV f)
     (f v2)]
    [else (error 'apply "not a function")]))

(define (eval [e : Exp] [env : Env]) : ValueE
  (type-case Exp e
    [(numE n) (numV n)]
    [(varE x)
     (lookup-env x env)]
    [(appE e1 e2)
     (apply (eval e1 env) (eval e2 env) env)] ;apply
    [(ifzE e0 e1 e2)
     (type-case ValueE (eval e0 env)
       [(numV n)
        (if (= n 0) (eval e1 env) (eval e2 env))]
       [(boolV b)
        (if b (eval e1 env) (eval e2 env))]
       [else
        (error 'eval "type error")])]
    [(letE x e1 e2)
     (let ([v1 (eval e1 env)])
       (eval e2 (extend-env env x v1)))]
    [(funE f l)
     (let ([tmp (lookup-env f env)])
       (eval (funV-e tmp) (env-var-extend (funV-x tmp) l env)))]))

(define (env-var-extend [ls :(Listof Symbol)] [le : (Listof Exp)] [env : Env]) : Env
  (if (eq? (length ls) (length le)) ;jesli nie mamy tyle samo symboli co exp ktore chcemy do nich przypisac to zle
      (if (and (empty? ls) (empty? le)) ;tu wlasciwie moge sprawdzic obojetnie ktory z nich a nie koniecznie oba
          env
          (env-var-extend (rest ls)
                          (rest le)
                          (extend-env env       ;rozszerzone srodowisko o pierwsza pare
                                      (first ls)
                                      (eval (first le) env))))
      (error 'eval "inalid argument count for a function")))

(define (eval-p [p : P] [env : Env]) : ValueE
  (eval (funP-e p) (init-env (funP-l p) env)))

(define (valueE->value [v : ValueE]) : Value
  (type-case ValueE v
    [(numV n) n]
    [else (error 'valueE->value "not a value")]))

(define (run [s : S-Exp]) : Value
  (valueE->value (eval-p (parse-p s) init-env-op)))

#;(module+ test
  (test (run `{define
                {[fun fact (n) = {ifz n then 1 else {n * {fact ({n - 1})}}}]}
                for
                {fact (5)}})
        120)
  (test (run `{define
                {[fun even (n) = {ifz n then 0 else {odd ({n - 1})}}]
                 [fun odd (n) = {ifz n then 42 else {even ({n - 1})}}]}
                for
                {even (1024)}})
        0)
  (test (run `{define
                {[fun gcd (m n) = {ifz n then m
                                       else {ifz {m <= n}
                                                 then {gcd (m {n - m})}
                                                 else {gcd ({m - n} n)}}}]}
                for
                {gcd (81 63)}})
        9))