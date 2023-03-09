#lang racket

(require rackunit)

(define (+two x)
  (+ x 2))

(check-equal? (+two 2) 4)
(check-true (number? (+two 0)))
