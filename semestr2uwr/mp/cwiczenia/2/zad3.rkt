#lang racket

(define-struct matrix (a b c d))
;(define-struct matrix (a b c d) #:transparent)

(define (print n) (list (matrix-a n) (matrix-b n) (matrix-c n) (matrix-d n)))
(print (make-matrix 5 6 7 8))

(define matrix-id (make-matrix 1 0 0 1))
(print matrix-id)

(define m (make-matrix 1 2 3 2))
(define n (make-matrix 1 0 3 0))

(define (matrix-mult m n)
  (make-matrix
   (+ (* (matrix-a m) (matrix-a n)) (* (matrix-b m) (matrix-c n)))
   (+ (* (matrix-a m) (matrix-b n)) (* (matrix-b m) (matrix-d n)))
   (+ (* (matrix-c m) (matrix-a n)) (* (matrix-d m) (matrix-c n)))
   (+ (* (matrix-c m) (matrix-b n)) (* (matrix-d m) (matrix-d n)))))
(print (matrix-mult m n))

(define (matrix-expt m k)
  (cond [(= k 1) m]
        [(= k 0) matrix-id]
        [else (matrix-mult m (matrix-expt m (- k 1)))]))

(print (matrix-expt m 5))

(define (fib-matrix k)
  (define m (matrix-expt (make-matrix 1 1 1 0) k))
  (matrix-b m))

(fib-matrix 9)
