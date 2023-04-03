#lang plait

(define-type (NNF 'v)
(nnf-lit [polarity : Boolean] [var : 'v])
(nnf-conj [l : (NNF 'v)] [r : (NNF 'v)])
(nnf-disj [l : (NNF 'v)] [r : (NNF 'v)]))

;((NNF 'a) -> (NNF 'a))
(define (neg-nnf a)
  (cond [(nnf-disj? a) (nnf-conj (neg-nnf(nnf-disj-l a)) (neg-nnf(nnf-disj-r a)))]
        [(nnf-conj? a) (nnf-disj (neg-nnf(nnf-conj-l a)) (neg-nnf(nnf-conj-r a)))]
        [else (nnf-lit (not (nnf-lit-polarity a)) (nnf-lit-var a))]))