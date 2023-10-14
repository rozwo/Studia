#lang racket

(define (add1 x) (+ x 1))

(define (add1-to-all xs)
  (if (null? xs)
      null
      (cons (add1 (car xs))
            (add1-to-all (cdr xs)))))

(define (number-list->string-list xs)
  (if (null? xs)
      null
      (cons (number->string (car xs))
            (number-list->string-list (cdr xs)))))

(define (my-map f xs)
  (if (null? xs)
      null
      (cons (f (car xs))
            (my-map f (cdr xs)))))

(define (only-positive xs)
  (if (null? xs)
      null
      (if (positive? (car xs))
          (cons (car xs) (only-positive (cdr xs)))
          (only-positive (cdr xs)))))

(define (only-numbers xs)
  (if (null? xs)
      null
      (if (number? (car xs))
          (cons (car xs) (only-numbers (cdr xs)))
          (only-numbers (cdr xs)))))

(define (my-filter p? xs)
  (if (null? xs)
      null
      (if (p? (car xs))
          (cons (car xs) (my-filter p? (cdr xs)))
          (my-filter p? (cdr xs)))))
