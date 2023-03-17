#lang racket

(define x 5)

(define (square x)
  (* x x))

(define (square-local-x)
  (define x 6)
  (* x x))

(define (square-x)
  (* x x))

;globalne x
(let [(x 3) (y x)] (+ x y))

;lokalne x
(let [(x 3)]
  (let [(y x)]
    (+ x y)))

;lokalne x
(let* [(x 3) (y x)] (+ x y))

(let* [(y x) (x 3)] (+ x y))
