#lang racket

(require "streams.rkt")

#;(define fibs
  (stream-cons 0 (stream-cons 1 (map2 + fibs (stream-cdr fibs)))))

(define (partial-sums s)
  (stream-cons (stream-car s) (map2 + (partial-sums s) (stream-cdr s))))





;-------testy-------
(define (stream->list s n)
  (if (or (= n 0) (stream-null? s))
      '()
      (cons (stream-car s) (stream->list (stream-cdr s) (- n 1)))))
;(define t (stream-cons 2 (stream-cons 5 (stream-cons 7 (stream-cons 8 (integers-from 1))))))
;(stream->list t 8)
;(stream->list (partial-sums t) 8)