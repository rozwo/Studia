#lang plait

;zadanie 4
;zmodyfikuj parser wyrażeń arytmetycznych z wykładu tak, by nie konstruował abstrakcyjnego drzewa rozbioru
;(drzewa typu Exp), ale od razu obliczał podane wyrażenie do liczby

(define (parse-Op s)
  (let ([sym (s-exp->symbol s)])
  (cond
    [(equal? sym '+) +] ;[(equal? sym '+) (op-add)]
    [(equal? sym '-) -] ;[(equal? sym '-) (op-sub)]
    [(equal? sym '*) *] ;[(equal? sym '*) (op-mul)]
    [(equal? sym '/) /]))) ;[(equal? sym '/) (op-div)])))

(define (parse-Exp s)
  (cond
    [(s-exp-number? s) (s-exp->number s)] ;(exp-number (s-exp->number s))
    [(s-exp-list? s)
     (let ([xs (s-exp->list s)])
       ((parse-Op  (first  xs)) ;(exp-op (parse-Op  (first  xs))
        (parse-Exp (second xs))
        (parse-Exp (third  xs))))]))


(parse-Exp `(* 2 (+ 2 2))) ;(eval (parse-Exp `(* 2 (+ 2 2))))
(parse-Exp `(+ 2 (* 2 2)))