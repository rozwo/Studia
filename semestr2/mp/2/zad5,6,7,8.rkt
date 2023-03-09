#lang racket

;zadanie 5
(define (elem? x xs)
  (cond [(null? xs) #f]
        [(equal? (car xs) x) #t]
        [else (elem? x (cdr xs))]))

;(elem? 4 (list 1 2 4 5 6 7))
;(elem? 4 (list 1 2 3 5 6 7))

;zadanie 6
(define (maximum xs)
  (define (it xs m)
    (if (null? xs)
        m
        (if (> (car xs) m)
            (it (cdr xs) (car xs))
            (it (cdr xs) m))))
  (it xs -inf.0))

;(maximum (list 3 2 4 5 8 -1 0 -9 6))

;zadanie 7
;iteracyjnie
#;(define (suffixes xs)
  (define (it xs)
    (if (null? xs)
        (list xs)
        (cons xs
              (it (cdr xs)))))
  (it xs))
;rekurencyjnie
(define (suffixes xs)
    (if (null? xs)
        (list xs)
        (cons xs
              (suffixes (cdr xs)))))
;(suffixes (list 1 2 3 4))

;zadanie 8
(define (sorted? xs)
  (define (it xs x)
    (cond [(null? xs) #t]
          [(< (car xs) x) #f]
          [else (it (cdr xs) (car xs))]))
  (it xs -inf.0))

;(sorted? (list 1 2 3 4))
;(sorted? (list 5 4 3 2))
;(sorted? (list 3 7 2 9))
