#lang plait

(module+ test
  (print-only-errors #t))

;; abstract syntax -------------------------------

(define-type Op
  (add)
  (sub)
  (mul)
  (div))

(define-type Exp
  (numE [n : Number])
  (opE [op : Op] [l : Exp] [r : Exp]))

;; parse ----------------------------------------

(define (parse [s : S-Exp]) : Exp
  (cond
    [(s-exp-match? `NUMBER s)
     (numE (s-exp->number s))]
    [(s-exp-match? `{SYMBOL ANY ANY} s)
        ; tu też była zmiana
       (parse-args (parse-op (s-exp->symbol (first (s-exp->list s)))) (rest (s-exp->list s)))
    ]
    [else (error 'parse "invalid input")]))

(define (parse-op [op : Symbol]) : Op
  (cond
    [(eq? op '+) (add)]
    [(eq? op '-) (sub)]
    [(eq? op '*) (mul)]
    [(eq? op '/) (div)]
    [else (error 'parse "unknown operator")]))

; ================================= ZADANIE 1 ======================================

(define (parse-args operator args)
    (cond 
        [(empty? args) (numE 0)]
        [(empty? (rest args)) (parse (first args))]
        [(empty? (rest (rest args))) (opE operator (parse (first args)) (parse (second args)))]
        [else (opE operator 
                (parse-args  operator (reverse (rest (reverse args)))) 
                (parse (first (reverse args))))]))

(module+ test
  (test (parse `2)
        (numE 2))
  (test (parse `{+ 2 1})
        (opE (add) (numE 2) (numE 1)))
  (test (parse `{* 3 4})
        (opE (mul) (numE 3) (numE 4)))
  (test (parse `{* 3 4 5})
        (opE (mul) (numE 3) (opE (mul) (numE 4) (numE 5))))
  (test (parse `{+ {* 3 4} 8})
        (opE (add)
             (opE (mul) (numE 3) (numE 4))
             (numE 8)))
  (test/exn (parse `{{+ 1 2}})
            "invalid input")
  (test/exn (parse `{+ 1})
            "invalid input")
  (test/exn (parse `{^ 1 2})
            "unknown operator"))
