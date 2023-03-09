#lang racket

(require rackunit)

(define lista (cons 1 (cons 2 null)))

(define lista-2 (cons null (cons 2 null)))

(define lista-3 (list 1 2))

(define nie-lista (cons null (cons 2 3)))

; lista to:
; albo null
; albo (cons x xs), gdzie xs to lista

(define (czy-lista? l)
  (or (null? l)
      (and (pair? l) (czy-lista? (cdr l)))))

(check-true (list? lista))
(check-false (list? nie-lista))

; list-ref

(define (my-list-ref xs n)
  (if (= n 0)
      (car xs)
      (my-list-ref (cdr xs) (- n 1))))

(define (my-list-ref2 xs n)
  (if (= n 0)
      (first xs)
      (my-list-ref2 (rest xs) (- n 1))))

; (my-list-ref (cons 1 (cons 2 null)) 1)
; -> (my-list-ref (cdr (...)) (- 1 1))
; -> (my-list-ref (cons 2 null) 0)
; -> (car (cons 2 null))
; -> 2

; append

(define (my-append xs ys)
  (if (null? xs)
      ys
      (cons (car xs)
            (my-append (cdr xs) ys))))

; (my-append (cons 1 null) (cons 2 (cons 3 null)))
; -> (cons 1 (my-append null (cons 2 (cons 3 null))))
; -> (cons 1 (cons 2 (cons 3 null)))

; reverse

(define (my-reverse xs)
  (define (it xs ys)
    (if (null? xs)
        ys
        (it (cdr xs) (cons (car xs) ys))))
  (it xs null))

; (my-reverse (cons 1 (cons 2 null)))
; -> (it (cons 1 (cons 2 null)) null)
; -> (it (cons 2 null) (cons 1 null))
; -> (it null (cons 2 (cons 1 null)))
; -> (cons 2 (cons 1 null))

; rekursja strukturalna:
; dwa przypadki:
; - dla listy pustej (null)
; - i niepustej (cons)
; wywołanie rekurencyjne w przypadku dla listy niepustej
; wykonywane na ogonie (reszcie) listy

(define (insert n xs)
  (if (null? xs)
      (list n)
      (if (< n (car xs))
          (cons n xs)
          (cons (car xs) (insert n (cdr xs))))))

(define (insertion-sort xs)
  (define (it xs ys)
    (if (null? xs)
        ys
        (it (cdr xs) (insert (car xs) ys))))
  (it xs null))

