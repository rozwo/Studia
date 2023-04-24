#lang plait

(define-type (2-3tree 'a)
  (leaf)
  (node2 [l : (2-3tree 'a)] [elem : 'a] [m : (2-3tree 'a)] [elem2 : 'a] [r : (2-3tree 'a)])
  (node [l : (2-3tree 'a)] [elem : 'a] [r : (2-3tree 'a)]))

; drzewo to:
; - albo (leaf)
; - albo (node l elem r), gdzie l i r to drzewa
; - albo (node2 l e m e2 r), gdzie l, m i r to drzewa

(define (tree? x)
  (type-case (2-3tree 'a) x
    [(leaf) #t]
    [(node) (and (tree? (node-l x))
                 (tree? (node-r x)))]
    [(node2) (and (tree? (node2-l x))
                  (tree? (node2-m x))
                  (tree? (node2-r x)))]
        [else #f]))

(define (heigh2 l elem r)
  (+ (max l r) 1))

(define (heigh3 l e m e2 r)
  (+ (max l m r) 1))

(define (tree-heigh t)
  (define (it acc t)
  (type-case (2-3tree 'a) t
    [(leaf) acc]
    [(node) (heigh2 (it acc (node-l t)) (node-elem t) (it acc (node-r t)))]
    [(node2) (heigh3 (it acc (node2-l t)) (node2-elem t) (it acc (node2-m t)) (node2-elem2 t) (it acc (node2-r t)))]))
  (it 0 t))

(define (good-heigh? t)
  (cond [(leaf? t) #t]
        [(and (node? t)
              (= (tree-heigh (node-l t)) (tree-heigh (node-r t))))
         (and (good-heigh? (node-r t))
              (good-heigh? (node-l t)))]
        [(and (node2? t)
              (= (tree-heigh (node2-l t)) (tree-heigh (node2-m t)) (tree-heigh (node2-r t))))
         (and (good-heigh? (node2-r t))
              (good-heigh? (node2-m t))
              (good-heigh? (node2-l t)))]
        [else #f]))
"#lang racket

(define-struct leaf () #:transparent)
(define-struct node (l elem r) #:transparent)
(define-struct node2 (l elem m elem2 r) #:transparent)

; drzewo to:
; - albo (leaf)
; - albo (node l elem r), gdzie l i r to drzewa
; - albo (node2 l e m e2 r), gdzie l, m i r to drzewa

(define (tree? x)
  (cond [(leaf? x) #t]
        [(node? x) (and (tree? (node-l x))
                        (tree? (node-r x)))]
        [(node2? x) (and (tree? (node2-l x))
                         (tree? (node2-m x))
                         (tree? (node2-r x)))]
        [else #f]))

(define (heigh2 l elem r)
  (+ (max l r) 1))

(define (heigh3 l e m e2 r)
  (+ (max l m r) 1))

(define (tree-heigh t)
  (define (it acc t)
  (cond [(leaf? t) acc]
        [(node? t) (heigh2 (it acc (node-l t)) (node-elem t) (it acc (node-r t)))]
        [(heigh3 (it acc (node2-l t)) (node2-elem t) (it acc (node2-m t)) (node2-elem2 t) (it acc (node2-r t)))]))
  (it 0 t))"

(define (good-heigh? t)
  (cond [(leaf? t) #t]
        [(and (node? t)
              (= (tree-heigh (node-l t)) (tree-heigh (node-r t))))
         (and (good-heigh? (node-r t))
              (good-heigh? (node-l t)))]
        [(and (node2? t)
              (= (tree-heigh (node2-l t)) (tree-heigh (node2-m t)) (tree-heigh (node2-r t))))
         (and (good-heigh? (node2-r t))
              (good-heigh? (node2-m t))
              (good-heigh? (node2-l t)))]
        [else #f]))

(define (good? t)
  (define (it f x t)
    (cond [(leaf? t) #t]
          [(node? t) (and (f x (node-elem t))
                          (it > (node-elem t) (node-l t))
                          (it < (node-elem t) (node-r t)))]
          [(node2? t) (and (f x (node2-elem t)) ;taaa czesc nie dziala (caly and)
                           (f x (node2-elem2 t))
                           (it > (node2-elem2 t) (node2-l t))
                           (it > (node2-elem2 t) (node2-m t))
                           (it < (node2-elem t) (node2-m t))
                           (it < (node2-elem t) (node2-r t)))]
          [else #f]))
  (cond [(leaf? t) #t]
        [(node? t) (and (it > (node-elem t) (node-l t)) (it < (node-elem t) (node-r t)))]
        [(node2? t) (and (it > (node2-elem2 t) (node2-l t))
              (it > (node2-elem2 t) (node2-m t))
              (it < (node2-elem t) (node2-m t))
              (it < (node2-elem t) (node2-r t)))]
        [else #f]))


(define (2-3tree? t)
  (and (tree? t) (good-heigh? t) (good? t)))


;testy
(define t1 (leaf))
(define t2 '())
(define t3 (node2
            (node (leaf) 2 (leaf))
            5
            (node (leaf) 4 (leaf))
            3
            (node (leaf) 6 (leaf))))
(define t4 (node2
            (node (leaf) 6 (leaf))
            3
            (node (leaf) 4 (leaf))
            1
            (node (leaf) 5 (leaf))))
(define t5 (node2
            (node (leaf) 1 (node (leaf) 2 (leaf)))
            5
            (node (leaf) 4 (leaf))
            3
            (node (leaf) 6 (leaf))))
(define t6 (node (leaf) 6 (leaf)))
(define t7 (node (node (leaf) 5 (leaf))
                 6
                 (node (leaf) 7 (leaf))))
(define t8 (node (node (leaf) 8 (leaf))
                 6
                 (node (leaf) 7 (leaf))))
(define t9 (node (node (leaf) 3 (leaf))
                 6
                 (node (leaf) 1 (leaf)))) 
;(2-3tree? t1) ;t
;(2-3tree? t2) ;f
(2-3tree? t3) ;t ;nie dziala
(2-3tree? t4) ;f ;nie dziala
;(2-3tree? t5) ;f

