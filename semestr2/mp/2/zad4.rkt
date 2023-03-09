#lang racket

(define-struct matrix (a b c d))

(define (print n) (list (matrix-a n) (matrix-b n) (matrix-c n) (matrix-d n)))

(define matrix-id (make-matrix 1 0 0 1))

(define (matrix-mult m n)
  (make-matrix
   (+ (* (matrix-a m) (matrix-a n)) (* (matrix-b m) (matrix-c n)))
   (+ (* (matrix-a m) (matrix-b n)) (* (matrix-b m) (matrix-d n)))
   (+ (* (matrix-c m) (matrix-a n)) (* (matrix-d m) (matrix-c n)))
   (+ (* (matrix-c m) (matrix-b n)) (* (matrix-d m) (matrix-d n)))))

(define (matrix-expt m k)
  (cond [(= k 1) m]
        [(= k 0) matrix-id]
        [else (matrix-mult m (matrix-expt m (- k 1)))]))
;(print (matrix-expt (make-matrix 1 2 3 2) 77))

(define (matrix-expt-fast m k)
  (define (it n acc)
    (cond [(= n 1) acc]
          [(= (* (floor (/ n 2)) 2) n) (it (/ n 2) (matrix-mult acc acc))]
          [else (matrix-mult acc (it (- n 1) acc))]))
  (if (= k 0)
      matrix-id
      (it k m)))

;(print (matrix-expt-fast (make-matrix 1 2 3 2) 77))


;zwykly fib O(k^2)

(define (fib-iter n)
  (define (it n x y)
    (cond [(and (= n 0) (= y 0)) 0]
          [(and (= n 1) (= y 0)) 1]
          [(and (> n 1) (= y 0)) (it (- n 1) 0 1)]
          [(and (= n 0) (> y 0)) y]
          [else (it (- n 1) y (+ x y))]))
  (it n 0 0))
;O(k)
;(fib-iter 500000) ;ok.43s
; (fib-iter 8)
; -> (it 8 0 0)
; -> (it 7 0 1)
; -> (it 6 1 1)
; -> (it 5 1 2)
; -> (it 4 2 3)
; -> (it 3 3 5)
; -> (it 2 5 8)
; -> (it 1 8 13)
; -> (it 0 13 21)
; -> 21

(define (fib-matrix k)
  (define m (matrix-expt (make-matrix 1 1 1 0) k))
  (matrix-b m))
;O(k)
;(fib-matrix 500000) ;ok.59s
; (fib-matrix 8)
; -> (matrix-expt (1 1 1 0) 8)
; -> (matrix-mult (1 1 1 0) (matrix-expt (1 1 1 0) 7))
; -> (matrix-mult (1 1 1 0) (matrix-mult (1 1 1 0) (matrix-expt (1 1 1 0) 6)))
; -> (matrix-mult (1 1 1 0) (matrix-mult (1 1 1 0) (matrix-mult (1 1 1 0) (matrix-expt (1 1 1 0) 5))))
; -> (matrix-mult (1 1 1 0) (matrix-mult (1 1 1 0) (matrix-mult (1 1 1 0) (matrix-mult (1 1 1 0) (matrix-expt (1 1 1 0) 4)))))
; -> (matrix-mult (1 1 1 0) (matrix-mult (1 1 1 0) (matrix-mult (1 1 1 0) (matrix-mult (1 1 1 0) (matrix-mult (1 1 1 0) (matrix-expt (1 1 1 0) 3))))))
; -> (matrix-mult (1 1 1 0) (matrix-mult (1 1 1 0) (matrix-mult (1 1 1 0) (matrix-mult (1 1 1 0) (matrix-mult (1 1 1 0) (matrix-mult (1 1 1 0) (matrix-expt (1 1 1 0) 2)))))))
; -> (matrix-mult (1 1 1 0) (matrix-mult (1 1 1 0) (matrix-mult (1 1 1 0) (matrix-mult (1 1 1 0) (matrix-mult (1 1 1 0) (matrix-mult (1 1 1 0) (matrix-mult (1 1 1 0) (matrix-expt (1 1 1 0) 1))))))))
; -> (matrix-mult (1 1 1 0) (matrix-mult (1 1 1 0) (matrix-mult (1 1 1 0) (matrix-mult (1 1 1 0) (matrix-mult (1 1 1 0) (matrix-mult (1 1 1 0) (matrix-mult (1 1 1 0) (1 1 1 0))))))))
; -> (matrix-mult (1 1 1 0) (matrix-mult (1 1 1 0) (matrix-mult (1 1 1 0) (matrix-mult (1 1 1 0) (matrix-mult (1 1 1 0) (matrix-mult (1 1 1 0) (2 1 1 1)))))))
; -> (matrix-mult (1 1 1 0) (matrix-mult (1 1 1 0) (matrix-mult (1 1 1 0) (matrix-mult (1 1 1 0) (matrix-mult (1 1 1 0) (3 2 2 1))))))
; -> (matrix-mult (1 1 1 0) (matrix-mult (1 1 1 0) (matrix-mult (1 1 1 0) (matrix-mult (1 1 1 0) (5 3 3 2)))))
; -> (matrix-mult (1 1 1 0) (matrix-mult (1 1 1 0) (matrix-mult (1 1 1 0) (8 5 5 3))))
; -> (matrix-mult (1 1 1 0) (matrix-mult (1 1 1 0) (13 8 8 5)))
; -> (matrix-mult (1 1 1 0) (21 13 13 8))
; -> (34 21 21 13)
; -> 21


(define (fib-fast k)
  (define m (matrix-expt-fast (make-matrix 1 1 1 0) k))
  (matrix-b m))
;O(log k)
;(fib-fast 500000) ;ok.24s
; (fib-fast 8)
; -> (matrix-expt-fast (1 1 1 0) 8)
; -> (it 8 (1 1 1 0))
; -> (it 4 (2 1 1 1))
; -> (it 2 (5 3 3 2))
; -> (it 1 (5 3 3 2))
; -> (34 21 21 13)
; -> 21

; (fib-fast 12)
; -> (matrix-expt-fast (1 1 1 0) 8)
; -> (it 12 (1 1 1 0))
; -> (it 6 (2 1 1 1))
; -> (it 3 (5 3 3 2))
; -> (matrix-mult (5 3 3 2) (it 2 (5 3 3 2)))
; -> (matrix-mult (5 3 3 2) (it 1 (34 21 21 13)))
; -> (matrix-mult (5 3 3 2) (34 21 21 13))
; -> (233 144 144 89)
; -> 144

