#lang plait

;Zadanie 1.
;Zaimplementuj procedury o podanych poniżej typach.
;Procedury nie powinny pętlić się ani zgłaszać błędów.

;('a 'b -> 'a)
(define (f1 a b) a)

;(('a 'b -> 'c) ('a -> 'b) 'a -> 'c)
(define (f2 f g x)
  (f x (g x)))

;((('a -> 'a) -> 'a) -> 'a)
;(define (((f3 a) a) a) a) ; to nie dziala XD szkodaaa
(define (id x) x)
(define (zloz g h) (h (g h)))
(define (f3 f) (zloz f id))

(define (f3v2 [f : (('a -> 'a) -> 'a)]) (f (lambda (x) x)))

;(('a -> 'b) ('a -> 'c) -> ('a -> ('b * 'c)))
(define (f4 f g)
  (lambda (x) (values (f x) (g x))))

;(('a -> (Optionof ('a * 'b))) 'a -> (Listof 'b))
#;(define (f5 f a)
  (list (snd (some-v (f (fst (some-v (f a)))))))) ;nie dziala dla none

#;(define (f5v2 f a)
  (type-case (Optionof 'a) (f a)
    ((none) '())
    ((some n)
     (if (some? (f (fst n)))
         (list (snd n))
         '()))))


