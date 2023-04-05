#lang plait

;zadanie 4

(define-type (NNF 'v)
  (nnf-lit [polarity : Boolean] [var : 'v])
  (nnf-conj [l : (NNF 'v)] [r : (NNF 'v)])
  (nnf-disj [l : (NNF 'v)] [r : (NNF 'v)]))

;((NNF 'a) -> (NNF 'a))
(define (neg-nnf a)
  (cond [(nnf-disj? a) (nnf-conj (neg-nnf(nnf-disj-l a)) (neg-nnf(nnf-disj-r a)))]
        [(nnf-conj? a) (nnf-disj (neg-nnf(nnf-conj-l a)) (neg-nnf(nnf-conj-r a)))]
        [else (nnf-lit (not (nnf-lit-polarity a)) (nnf-lit-var a))]))



;zadanie 6

(define-type (Formula 'v)
  (var [var : 'v])
  (neg [f : (Formula 'v)])
  (conj [l : (Formula 'v)] [r : (Formula 'v)])
  (disj [l : (Formula 'v)] [r : (Formula 'v)]))

(define (to-nnf a)
  (cond [(neg? a) (neg-nnf (to-nnf(neg-f a)))]
        [(conj? a) (nnf-conj (to-nnf(conj-l a)) (to-nnf(conj-r a)))]
        [(disj? a) (nnf-disj (to-nnf(disj-l a)) (to-nnf(disj-r a)))]
        [else (nnf-lit #t (var-var a))]))

;test
;(to-nnf (neg (conj (disj (var "x") (var "y")) (neg (var "z")))))


