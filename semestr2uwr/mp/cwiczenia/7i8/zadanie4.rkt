#lang racket

;pozytywne(wyjsciowe) i negatywne(wejsciowe) w kolejnych funkcjach odwrotnie (potem znowu odwrotnie itd)

;(parametric->/c [a b] (-> a[neg] b[neg] a[poz]))
(define/contract (f1 x y)
  (parametric->/c [a b] (-> a b a))
  x)

#;(define (f2h x)
  (- x 3))
#;(define (f2g x y)
  (+ x y))
;(parametric->/c [a b c] (-> (-> a[poz] b[poz] c[neg]) (-> a[poz] b[neg]) a[neg] c[poz]))
(define/contract (f2 g h x)
  (parametric->/c [a b c] (-> (-> a b c) (-> a b) a c))
  (g x (h x)))

;(parametric->/c [a b c] (-> (-> b[poz] c[neg]) (-> a[poz] b[neg]) (-> a[neg] c[poz])))
(define/contract (f3 g h)
  (parametric->/c [a b c] (-> (-> b c) (-> a b) (-> a c)))
  (lambda (x) (g (h x))))

#;(define (f4g f) (f 3))
;(parametric->/c [a] (-> (-> (-> a[neg] a[poz]) a[neg]) a[poz]))
(define (id x) x)
(define/contract (f4 g)
  (parametric->/c [a] (-> (-> (-> a a) a) a))
  (g id))

 