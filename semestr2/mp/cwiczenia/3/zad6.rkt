#lang racket

;empty-set – reprezentacja zbioru pustego,
;(singleton a) – zwraca zbiór zawierający wyłącznie element a (można wykorzystać predykat equal? ),
;(in a s) – zwraca #t gdy a należy do zbioru s, w przeciwnym wypadku wynikiem jest #f,
;(union s t) – zwraca sumę zbiorów s i t,
;(intersect s t) – zwraca przecięcie zbiorów s i t.

(define (empty-set)
  (lambda (x) #f))

(define (singleton a)
  (lambda (x) (equal? a x)))

(define (in a s)
  (s a))

(define (union s t)
  (lambda (x) (or (s x) (t x))))

(define (intersect s t)
  (lambda (x) (and (s x) (t x))))
