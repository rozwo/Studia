#lang plait

(define (fact x)
  (if (= x 0)
      1
      (* x (fact (- x 1)))))

(define (returns-8 x) 8)

(define (foo x)
  (if x x x))

(define (id x) x)

(define (pair-ns)
  (pair (id 1) (id "x")))

;(define (pair-ns-2 f)
;  (pair (f 1) (f "x")))

(define (pair-ns-3 f g)
  (pair (f 1) (g "x")))

(define (not-id x)
  (error 'x "aaa"))

(define (not-id2 x)
  (let [(a (error 'x "aaa"))]
    x))

(define (not-id3 x)
  (if #t (not-id3 x) x))

(define (my-length xs)
  (if (empty? xs)
      0
      (+ 1 (my-length (rest xs)))))

(define (sum xs)
  (local
    [(define (it xs acc)
       (if (empty? xs)
           acc
           (it (rest xs) (+ acc (first xs)))))]
    (it xs 0)))

(define (sum2 xs)
  (letrec [(it (lambda (xs acc)
                 (if (empty? xs)
                     acc
                     (it (rest xs) (+ acc (first xs))))))]
    (it xs 0)))

(define (my-foldr f x xs)
  (if (empty? xs)
      x
      (f (first xs) (my-foldr f x (rest xs)))))

(define (my-foldr-err f x xs)
  (if (empty? xs)
      x
      (f (first xs) (rest xs))))

(define-type-alias NumberList (Listof Number))

(define x : NumberList empty)

(define-type MyPair
  (my-pair [fst : Number] [snd : String]))
; definiuje konstruktor:
; my-pair : (Number String -> MyPair)
; selektory:
; my-pair-fst : (MyPair -> Number)
; my-pair-snd : (MyPair -> String)
; predykat:
; my-pair? : (MyPair -> Boolean)

; poniższe nie definiują list - dwa oddzielne typy

;(define-type MyNumberList
;  (my-empty))

;(define-type MyNumberList2
;  (my-cons [first : Number] [rest : MyNumberList]))

; listy liczb

(define-type MyNumberList
  (my-empty)
  (my-cons [first : Number] [rest : MyNumberList]))

; listy wartości jednego, konkretnego typu
; jaki to typ określa późniejsze użytkowanie

(define-type MyListMono
  (mlm-empty)
  (mlm-cons [first : 'a] [rest : MyListMono]))

; listy wartości dowolnego typu (wybranego dla jednej listy)

(define-type (MyList 'a)
  (ml-empty)
  (ml-cons [first : 'a] [rest : (MyList 'a)]))

; ml-empty jest zeroargumentowym konstruktorem
; aby uzyskać odpowiednik empty z Plaita można napisać:

(define ml-empty-val (ml-empty))

; drzewa

(define-type (Tree 'a)
  (leaf)
  (node [l : (Tree 'a)] [elem : 'a] [r : (Tree 'a)]))

(define example-tree
  (node (node (leaf) 1 (leaf))
        2
        (node (leaf)
              3
              (node (leaf) 4 (leaf)))))

; drzewa jako słowniki

(define example-dict-tree
  (node (node (leaf) (pair 1 "foo") (leaf))
        (pair 2 "bar")
        (node (leaf)
              (pair 3 "baz")
              (node (leaf)
                    (pair 4 "qux")
                    (leaf)))))

; wyszukanie wartości w drzewie-słowniku
; brak wartości oznacza błąd

(define (bst-lookup x t)
  (cond [(leaf? t) (error 'bst-lookup "Not found")]
        [(= x (fst (node-elem t)))
         (snd (node-elem t))]
        [(< x (fst (node-elem t)))
         (bst-lookup x (node-l t))]
        [else
         (bst-lookup x (node-r t))]))

; rozwiązanie w stylu Racketa - nie sprawdza się!
; wymusza, aby elementy listy były wartościami logicznymi

(define (bst-lookup-opt-bool x t)
  (cond [(leaf? t) #f]
        [(= x (fst (node-elem t)))
         (snd (node-elem t))]
        [(< x (fst (node-elem t)))
         (bst-lookup-opt-bool x (node-l t))]
        [else
         (bst-lookup-opt-bool x (node-r t))]))

; zgłaszanie braku wartości przy pomocy Optionof
; można myśleć, że typ Optionof jest zdefiniowany tak:
; (define-type (Optionof 'a)
;    (none)
;    (some [v : 'a]))

(define (bst-lookup-opt x t)
  (cond [(leaf? t) (none)]
        [(= x (fst (node-elem t)))
         (some (snd (node-elem t)))]
        [(< x (fst (node-elem t)))
         (bst-lookup-opt x (node-l t))]
        [else
         (bst-lookup-opt x (node-r t))]))

; typ wartości różnych (wybranych przez nas) typów

(define-type Any
  (any-number [v : Number])
  (any-string [v : String])
  (any-boolean [v : Boolean]))

; przy jego pomocy można stworzyć listę wartości różnych typów

(define polylist
  (cons (any-number 5) (cons (any-boolean #f) empty)))
