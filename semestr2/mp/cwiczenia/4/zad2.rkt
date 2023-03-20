#lang racket

(define-struct leaf () #:transparent)
(define-struct node (l elem r) #:transparent)


(define (fold-tree f acc t)
  (if (leaf? t)
      acc
      (f (fold-tree f acc (node-l t)) (node-elem t) (fold-tree f acc (node-r t)))))


;suma wszystkich wartości występujących w drzewie
(define (tree-sum t)
  (fold-tree + 0 t))


;odwrócenie kolejności: zamiana lewego i prawego poddrzewa wszystkich węzłów w drzewie
(define (flip l elem r)
  (node r elem l))

(define (tree-flip t)
  (fold-tree flip (leaf) t))


;wysokosć drzewa (liczba węzłów na najdłuższej ścieżce od korzenia do liścia)
(define (heigh l elem r)
  (if (> l r)
      (+ l 1)
      (+ r 1)))

(define (tree-height t)
  (fold-tree heigh 0 t))


;para złożona z wartości skrajnie prawego i skrajnie lewego węzła w drzewie
;(czyli najmniejszej i największej wartości w drzewie BST)
(define (span l elem r)
  (cond [(and (null? l) (null? r)) (cons elem elem)]
        [(null? l) (cons elem (cdr r))]
        [(null? r) (cons (car l) elem)]
        [else (cons (car l) (cdr r))]))

(define (tree-span t)
  (fold-tree span null t))


;lista wszystkich elementów występujących w drzewie, w kolejności infiksowej
;(define (flatten t))



;testy
(define t
  (node
   (node (leaf) 2 (leaf))
   5
   (node
    (node (leaf)
          6
          (node (leaf) 7 (leaf)))
    8
    (node (leaf) 9 (leaf)))))

(tree-sum t)
(tree-flip t)
(tree-height t)
(tree-span t)
;(flatten t)
