#lang plait

;zadanie 5
;rozszerz kalkulator z wykładu o operacje potęgowania, silni i liczby przeciwnej
;W tym celu najpierw uzupełnij składnię abstrakcyjną i interpreter,
;a następnie rozbuduj parser, tak aby obsługiwał nowe konstrukcje

; ==============================================
;skladnia:

(define-type Op1arg
  (op-neg)
  (op-stg))

(define-type Op2arg
  (op-add)
  (op-mul)
  (op-sub)
  (op-div)
  (op-pow))

(define-type Exp
  (exp-number [n : Number])
  (exp-op1arg [op1arg : Op1arg] [e : Exp])
  (exp-op2arg [op2arg : Op2arg] [e1 : Exp] [e2 : Exp]))

(define (parse-Op1arg s)
  (let ([sym (s-exp->symbol s)])
  (cond
    [(equal? sym '-) (op-neg)]
    [(equal? sym '!) (op-stg)])))

(define (parse-Op2arg s)
  (let ([sym (s-exp->symbol s)])
  (cond
    [(equal? sym '+) (op-add)]
    [(equal? sym '-) (op-sub)]
    [(equal? sym '*) (op-mul)]
    [(equal? sym '/) (op-div)]
    [(equal? sym '^) (op-pow)])))

(define (parse-Exp s)
  (cond
    [(s-exp-number? s) (exp-number (s-exp->number s))]
    [(s-exp-list? s)
     (let ([xs (s-exp->list s)])
       (if (empty? (rest (rest xs)))
           (exp-op1arg (parse-Op1arg (first xs))
               (parse-Exp (second xs)))
           (exp-op2arg (parse-Op2arg (first xs))
               (parse-Exp (second xs))
               (parse-Exp (third xs)))))]))

; ==============================================
;semantyka:

(define (power a n)
  (cond [(= n 0) 1]
        [(< n 0) (error 'power "nie można brać ujemnej potęgi z liczby")]
        [else (* a (power a (- n 1)))]))

#;(define (power a n) ;nie dziala czemu? nwm ale to nie wazne
  (define (pow a n)
    (if (= n 0)
        1
        (* a (pow a (- n 1)))))
 (cond [(and (< n 0) (= a 0)) (error 'power "nie mozna dzielic przez zero")]
        [(< n 0) (pow (/ 1 a) (- 0 n))]
        [else (pow a n)]))

(define (silnia n)
  (cond [(= n 0) 1]
        [(< n 0) (error 'silnia "nie można brać silni z liczby ujemnych")]
        [else (* n (silnia (- n 1)))]))

(define (eval-op1arg op)
  (type-case Op1arg op
    [(op-neg) (lambda (x) (- 0 x))]
    [(op-stg) silnia]))

(define (eval-op2arg op)
  (type-case Op2arg op
    [(op-add) +]
    [(op-sub) -]
    [(op-mul) *]
    [(op-div) /]
    [(op-pow) power]))

(define (eval e)
  (type-case Exp e
    [(exp-number n) n]
    [(exp-op1arg op e)
     ((eval-op1arg op) (eval e))]
    [(exp-op2arg op e1 e2)
     ((eval-op2arg op) (eval e1) (eval e2))]))

