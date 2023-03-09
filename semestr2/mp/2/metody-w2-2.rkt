#lang racket

(define (loop) (loop))

; (loop) -> (loop) -> (loop) -> ...

(define (loop-n n) (loop-n (+ n 1)))

; (loop-n 1) -> (loop-n (+ 1 1))
; -> (loop-n 2) -> ...

(define (silnia n)
  (if (= n 0) 1
      (* n (silnia (- n 1)))))

; (silnia 5) -> (if ...)
; -> (* 5 (silnia 4))
; -> (* 5 (* 4 (silnia 3)))
; -> (* 5 (* 4 (* 3 (silnia 2))))
; -> (* 5 (* 4 (* 3 (* 2 (silnia 1)))))
; -> (* 5 (* 4 (* 3 (* 2 (* 1 (silnia 0))))))
; -> (* 5 (* 4 (* 3 (* 2 (* 1 1)))))
; -> (* 5 (* 4 (* 3 (* 2 1))))
; -> (* 5 (* 4 (* 3 2)))
; -> (* 5 (* 4 6))
; -> (* 5 24)
; -> 120

(define (silnia-iter n)
  (define (it n acc)
    (if (= n 0)
        acc
        (it (- n 1) (* n acc))))
  (it n 1))

; (silnia-iter 5)
; -> (it 5 1)
; -> (if (= 5 0) 1 (it (- 5 1) (* 1 5)))
; -> (it 4 5)
; -> (it 3 20)
; -> (it 2 60)
; -> (it 1 120)
; -> (it 0 120)
; -> 120

