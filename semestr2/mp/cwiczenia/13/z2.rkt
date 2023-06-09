#lang racket

(require "streams.rkt")

#;(define (pierwsza n s)
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
;(pierwsza 9 s)n
;(pierwsza 10 s)
;(pierwsza 11 s)


;dobra to inaczej!
(define (pierwsza n l)
  (cond [(null? l) #t]
        [(= (modulo n (car l)) 0) #f]
        [else (pierwsza n (cdr l))]))

(define (licz-pierwsze)
    (define (pierw-pom n l)
      (if (pierwsza n l)
          (stream-cons n (pierw-pom (+ n 1) (append l (list n))))
          (pierw-pom (+ n 1) l)))
    (pierw-pom 2 '()))

(define pierwsze (licz-pierwsze))


;-------testy-------
(define (print n)
  (define (it i n l)
    (if (= n 0)
        l
        (it (+ i 1) (- n 1) (append l (list (stream-ref pierwsze i))))))
  (it 0 n '()))
(print 11)

