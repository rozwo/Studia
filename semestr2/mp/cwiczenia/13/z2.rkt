#lang racket

(require "streams.rkt")

(define (pierwsza n s)
  (cond [(stream-null? s) #t]
        [(= (modulo n (stream-car s)) 0) #f]
        [else (pierwsza n (stream-cdr s))]))

#;(define (pierwsze n)
  (if (pierwsza n s) ;no wlasnie jak tu jako s dac to co bylo juz wczesniej?
      (stream-cons n (pierwsze (+ n 1)))
      (pierwsze (+ n 1))))



;-------testy-------
;(define s (stream-cons 2 (stream-cons 3 (stream-cons 5 (stream-cons 7 null)))))
;(pierwsza 8 s)
;(pierwsza 9 s)
;(pierwsza 10 s)
;(pierwsza 11 s)