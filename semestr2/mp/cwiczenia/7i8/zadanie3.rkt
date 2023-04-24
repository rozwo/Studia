#lang racket

(define/contract (suffixes xs)
  (parametric->/c [a] (-> (listof a) (listof (listof a))))
  (if (null? xs)
      (list null)
      (cons xs (suffixes (cdr xs)))))

(define (suffixes2 xs)
  (if (null? xs)
      (list null)
      (cons xs (suffixes2 (cdr xs)))))

(define x (time (suffixes (range 3000))))
(define y (time (suffixes2 (range 3000))))

(define z (time (suffixes2 (range 300000))))
