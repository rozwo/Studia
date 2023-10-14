#lang racket

(define-struct matrix (a b c d))

(define (print-matrix m)
  (display "|")
  (display (matrix-a m))
  (display " ")
  (display (matrix-b m))
  (displayln "|")
  (display "|")
  (display (matrix-c m))
  (display " ")
  (display (matrix-d m))
  (displayln "|"))

(define my-matrix (make-matrix 1 2 3 4))

(print-matrix my-matrix)

(define (print-matrix-mult m n)
  (let ((a1 (matrix-a m)) (b1 (matrix-b m))
        (c1 (matrix-c m)) (d1 (matrix-d m))
        (a2 (matrix-a n)) (b2 (matrix-b n))
        (c2 (matrix-c n)) (d2 (matrix-d n)))
  (display "|") (display a1) (display " ") (display b1) (display "|")
  (display " * ")
  (display "|") (display a2) (display " ") (display b2) (display "|")
  (display " _ ")
  (display "|") (display (+ (* a1 a2) (* b1 c2))) (display " ") (display (+ (* a1 b2) (* b1 d2))) (displayln "|")
  (display "|") (display c1) (display " ") (display d1) (display "|")
  (display "   ")
  (display "|") (display c2) (display " ") (display d2) (display "|")
  (display " ¯ ")
  (display "|") (display (+ (* c1 a2) (* d1 c2))) (display " ") (display (+ (* c1 b2) (* d1 d2))) (displayln "|")))

(define x (make-matrix 1 2 3 4))
(define y (make-matrix 5 6 7 8))
(print-matrix-mult x y)





;cout << n;
;printf("%i", n);

;cin >> a;
;scanf("%i", a);