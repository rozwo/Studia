#lang plait

; dane     mają strukturę
; programy mają strukturę
; dowody   mają strukturę

; Świat formuł, własności: ∧, ∨, ∀, ∃ ...
;             Relacje
; Świat obiektów (termy): liczby, zbiory, programy, ...

; Relacje: e₁ ≡ e₂

; Czego wymagamy od ≡
; • Relacja równoważności
; • Kongruencja:
;   - Jeśli e₁ ≡ e₁' i e₂ ≡ e₂' to (e₁ e₂) ≡ (e₁' e₂')
;   - Jeśli e₁ ≡ e₁', e₂ ≡ e₂', e₃ ≡ e₃' to
;       (if e₁ e₂ e₃) ≡ (if e₁' e₂' e₃')
;   - ...
; • Zgodna z modelem obliczeń:
;   Jeśli e₁ → e₂ (w podstawieniowym modelu obliczeń) to e₁ ≡ e₂
; • Rozróżnia rzeczy w oczywisty sposób różne, np. #t ≠ #f

; (bst? t) ≡ #t

; ======================================================

(define (append xs ys)
  (if (empty? xs)
      ys
      (cons (first xs) (append (rest xs) ys))))

; Lemat 1.
; Dla dowolnej listy xs (wartości), (append empty xs) ≡ xs
; (append empty xs) ≡
; (if (empty? empty) xs (cons (first empty) (append (rest empty) xs))) ≡
; (if #t xs (cons (first empty) (append (rest empty) xs))) ≡
; xs

; =======================================================
; Lemat 2.
; Dla dowolnej listy xs, (append xs empty) ≡ xs

; Zasada indukcji dla list:
; Niech P będzie własnością list, taką, że:
; i)  P(empty)
; ii) Dla każdej wartości x i każdej listy xs,
;     jeśli P(xs) to P((cons x xs))
; Wówczas dla dowolnej listy xs zachodzi P(xs)

; Niech P(xs) := (append xs empty) ≡ xs

; Trzeba pokazać:
; i) P(empty)
;    (append empty empty) ≡ empty
; ii) Dla dowolnych x i xs, t. że (append xs empty) ≡ xs zachodzi
;    (append (cons x xs) empty) ≡ (cons x xs)
;
;    Weźmy dowolne x i xs i załóżmy, że (append xs empty) ≡ xs,
;    pokażmy, że (append (cons x xs) empty) ≡ (cons x xs)
;
; (append (cons x xs) empty) ≡
; (cons x (append xs empty)) ≡
; (cons x xs)
;
; Na mocy zasady indukcji mamy (append xs empty) ≡ xs dla dowolnej listy xs

; Lemat 3.
; Dla dowolnych list xs, ys i zs zachodzi
; (append (append xs ys) zs) ≡ (append xs (append ys zs))
;
; Dowód: przez indukcję strukturalną względem listy xs
; P(xs) := (append (append xs ys) zs) ≡ (append xs (append ys zs))
;
; i) L ≡
;    (append (append empty ys) zs) ≡
;    (append ys zs)
;
;    ∃ v - wartość, (append ys zs) ≡ v
;
;    P ≡
;    (append empty (append ys zs)) ≡ "(append empty v) ≡ v ≡"
;    (append ys zs) ≡ L
;
; ii) Załóżmy, że (append (append xs ys) zs) ≡ (append xs (append ys zs))
;     i pokażmy, że (append (append (cons x xs) ys) zs) ≡ (append (cons x xs) (append ys zs)))
;     L ≡ (append (append (cons x xs) ys) zs) ≡
;     (append (cons x (append xs ys)) zs) ≡
;     (cons x (append (append xs ys) zs)) ≡ (z zał. indukcyjnego)
;     (cons x (append xs (append ys zs)))
;     P ≡ (append (cons x xs) (append ys zs)) ≡
;     (cons x (append xs (append ys zs))) ≡ L

; ======================================================

(define (rev1 xs)
  (if (empty? xs)
      empty
      (append (rev1 (rest xs)) (cons (first xs) empty))))

(define (revapp xs ys)
  (if (empty? xs)
      ys
      (revapp (rest xs) (cons (first xs) ys))))

(define (rev2 xs)
  (revapp xs empty))

; Twierdzenie: (rev1 xs) ≡ (rev2 xs), dla dowolnej listy xs
; Dowód:
; P(xs) := (rev1 xs) ≡ (rev2 xs)

; i) ...
; ii) Zał. że (rev1 xs) ≡ (rev2 xs) i pokażmy, że (rev1 (cons x xs)) ≡ (rev2 (cons x xs))
; L ≡ (rev1 (cons x xs)) ≡
; (append (rev1 xs) (cons x empty)) ≡
; (append (rev2 xs) (cons x empty)) ≡
; (append (revapp xs empty) (cons x empty))

; P ≡ (rev2 (cons x xs)) ≡
; (revapp (cons x xs) empty) ≡
; (revapp xs (cons x empty))
;
; To się nie uda!

; Lemat: ∀ xs ys, (append (rev1 xs) ys) ≡ (revapp xs ys)
; Dowód: Przez indukcję względem xs
; P(xs) := ∀ ys, (append (rev1 xs) ys) ≡ (revapp xs ys)
;
; i) L ≡ (append (rev1 empty) ys) ≡ (append empty ys) ≡ ys
;    P ≡ (revapp empty ys) ≡ ys
; ii) Załóżmy, że ∀ ys, (append (rev1 xs) ys) ≡ (revapp xs ys)
;    i pokażmy, że dla dowolnego ys,
;        (append (rev1 (cons x xs)) ys) ≡ (revapp (cons x xs) ys)
;    L ≡ (append (rev1 (cons x xs)) ys) ≡
;        (append (append (rev1 xs) (cons x empty)) ys) ≡ (z lączności append)
;        (append (rev1 xs) (append (cons x empty) ys)) ≡ (z def. append)
;        (append (rev1 xs) (cons x ys))

;    P ≡ (revapp (cons x xs) ys) ≡
;        (revapp xs (cons x ys)) ≡
;        (append (rev1 xs) (cons x ys))

; Dowód twierdzenia:
; (rev2 xs) ≡ (z def.)
; (revapp xs empty) ≡ (z Lematu)
; (append (rev1 xs) empty) ≡ (z Lematu 2, i tego, że rev1 się zatrzymuje)
; (rev1 xs)

; ======================================================

(define-type (Tree 'a)
  (leaf)
  (node [l : (Tree 'a)] [elem : 'a] [r : (Tree 'a)]))

; Zasada indukcji dla typu Tree:
; Niech P będzie własności drzew t. że:
; i) P((leaf))
; ii) Dla dowolnych wartości l x r, jeśli P(l) i P(r) to P((node l x r))
; Wówczas zachodzi P(t) dla dowolnego drzewa t.

(define-type (RoseTree 'a)
  (rleaf [elem : 'a])
  (rnode [children : (Listof (RoseTree 'a))]))

; Zasada (wzajemnej) indukcji dla RoseTree:
; Niech P będzie własnością drzew różanych, a Q własnością list drzew t. że:
; i)  dla dowolnego x mamy P((rleaf x))
; ii) Dla dowolnych wartości xs, jeśli zachodzi Q(xs)
;     to P(rnode xs)
; iii) zachodzi Q(empty)
; iv) Dla dowolnych t ts jeśli P(t) i Q(ts) to Q((cons t ts))
; Wówczas zachodzi P(t) dla dowolnego drzewa t i Q(ts) dla dowolnej listy drzew różanych

(define (insert x xs)
  (if (empty? xs)
      (cons x empty)
      (if (< x (first xs))
          (cons x xs)
          (cons (first xs) (insert x (rest xs))))))

(define (bound? x xs)
  (if (empty? xs)
      #t
      (<= x (first xs))))

(define (sorted? xs)
  (if (empty? xs)
      #t
      (and (sorted? (rest xs)) (bound? x (rest xs)))))

; Twierdzenie 2:
; Jeśli (sorted? xs) ≡ #t to (sorted? (insert x xs)) ≡ #t

; Dowód: przez indukcję strukturalną względem xs