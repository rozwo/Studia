#lang racket

;x-zmienna zwiazana, y,+-zmienne wolne
#;(let ([x 3])
    (+ x y))

;x(tylko [x 1]),y-zmienne zwiazane, x(tylko [y (+ x 2)]),+-zmienne wolne
#;(let ([x 1]
        [y (+ x 2)])
    (+ x y))

;x,y-zmienne zwiazane, *,+-zmienne wolne
#;(let ([x 1])
    (let ([y (+ x 2)])
      (* x y)))

;x,y-zmienne zwiazane, z,*-zmienne wolne
#;(define (f x y)
    (* x y z ))

;x,y,z-zmienne zwiazane, *-zmienna wolna
#;(define (f x)
  (define (g y z)
    (* x y z))
  (f x x x))
