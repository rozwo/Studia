#lang racket

(require "streams.rkt")

(define (merge sx sy)
  (cond [(= (stream-car sx) (stream-car sy))
         (stream-cons (stream-car sx) (merge (stream-cdr sx) (stream-cdr sy)))]
        [(< (stream-car sx) (stream-car sy))
         (stream-cons (stream-car sx) (merge (stream-cdr sx) sy))]
        [else (stream-cons (stream-car sy) (merge sx (stream-cdr sy)))]))

(define (scale s n)
  (stream-cons (* (stream-car s) n) (scale (stream-cdr s) n)))

(define hamming
  (letrec ([two (scale (integers-from 1) 2)]
           [three (scale (integers-from 1) 3)]
           [five (scale (integers-from 1) 5)])
  (merge two (merge three five))))




;-------testy-------
(define (stream->list s n)
  (if (or (= n 0) (stream-null? s))
      '()
      (cons (stream-car s) (stream->list (stream-cdr s) (- n 1)))))

;------testy---merge-----
#;(define (x n)
  (stream-cons n (x (+ n 2))))
#;(define (y n)
  (stream-cons n (y (+ n 3))))
;(stream->list (x 1) 8)
;(stream->list (y 0) 7)
;(stream->list (merge (x 1) (y 0)) 10)
;------testy---scale-----
;(stream->list (x 1) 8)
;(stream->list (scale (x 1) 2) 8)

(define (print n)
  (define (it i n l)
    (if (= n 0)
        l
        (it (+ i 1) (- n 1) (append l (list (stream-ref hamming i))))))
  (it 0 n '()))
(print 11)


