#lang plait

;zmienia miejsce x
(define (remove x lst)
  (filter (lambda (y) (not (eq? x y))) lst))

;funkcja bierze w jakiejs kolejnosci elem listy i je skleja
(define (flatmap f lst)
  (foldl (lambda (x acc) (append (f x) acc)) '() lst))

(define (perms lst)
  (if (empty? lst)
      (list '())
      (flatmap (lambda (x)
                 (map (lambda (p) (cons x p))
                      (perms (remove x lst))))
               lst)))

;test
(perms '(1 2 3))

