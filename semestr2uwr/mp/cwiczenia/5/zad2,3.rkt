#lang plait

;zadanie 2

(define (apply f x)
  (f x))
;(('a -> 'b) 'a -> 'b)

(define (compose f g)
  (lambda (x)
    (f (g x))))
;(('a -> 'b) ('c -> 'a) -> ('c -> 'b))

(define (flip f)
  (lambda (x y)
    (f y x)))
;(('a 'b -> 'c) -> ('b 'a -> 'c))

(define (curry f)
  (lambda (x)
    (lambda (y)
      (f x y))))
;(('a 'b -> 'c) -> ('a -> ('b -> 'c)))


;zadanie 3

(define f1 ((curry compose) (curry compose)))
;(('a -> ('b -> 'c)) -> ('a -> (('d -> 'b) -> ('d -> 'c))))

(define f2 ((curry compose) (curry apply)))
;(('a -> ('b -> 'c)) -> ('a -> ('b -> 'c)))

(define f3 ((curry apply) (curry compose)))
;(('a -> 'b) -> (('c -> 'a) -> ('c -> 'b)))

(define f4 (compose curry flip))
;(('a 'b -> 'c) -> ('b -> ('a -> 'c)))


