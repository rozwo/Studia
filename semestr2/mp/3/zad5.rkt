#lang racket

;(build-list n f) = ( list (f 0) ... (f (- n 1) ))

; zwracającą listę liczb ujemnych od −1 do −n
(define (negatives n)
  (build-list n (lambda (x) (- (+ x 1)))))

; zwracającą listę odwrotności liczb od 1 do n (czyli 1, . . . , 1 n ),
(define (reciprocals n)
  (build-list n (lambda (x) (/ 1 (+ x 1)))))

; zwracajacą listę pierwszych n liczb parzystych,
(define (evens n)
  (build-list n (lambda (x) (* x 2))))

; zwracającą macierz identycznościową o wymiarach n × n w postaci listy list:
;(identityM 3) '((1 0 0) (0 1 0) (0 0 1))
(define (identityM n)
  (define (gdzie_1 x n)
    (define (it k)
      (cond [(= k n) null]
            [(= k x) (cons 1 (it (+ k 1)))]
            [else (cons 0 (it (+ k 1)))]))
    (it 0))
  (build-list n (lambda (x) (gdzie_1 x n))))
