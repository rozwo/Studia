#lang racket

(define/contract (foldl-map f a xs)
  ;(parametric->/c [a b] (-> (-> b a (pair a a)) a (listof b) (pair (listof a) a)))
  (parametric->/c [a b] (-> (-> b a (cons/c a a)) a (listof b) (cons/c (listof a) a)))
  (define (it a xs ys)
    (if (null? xs)
        (cons (reverse ys) a)
        (let [(p (f (car xs) a))]
          (it (cdr p)
              (cdr xs)
              (cons (car p) ys)))))
  (it a xs null))

;(foldl-map (lambda (x a) (cons a (+ a x))) 5 '(2 1 2))
