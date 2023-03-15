#lang racket

#;(define (product xs)
  (define (it xs acc)
    (if (null? xs)
        acc
        (it (cdr xs) (* (car xs) acc))))
  (it xs 1))

(define (product xs)
  (foldl * 1 xs))

;przykłady:
(product (list 3 4 5 6 7))
(product (list 1 2 3 4 5))
(product (list 1 1 1 1))
(product (list))
(product (list 4 5))
