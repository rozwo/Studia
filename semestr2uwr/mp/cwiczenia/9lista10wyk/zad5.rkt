#lang racket

;zadanie 5

(define decode
  (list
   ;litery
   (cons "._" "a")
   (cons "_..." "b")
   (cons "_._." "c")
   (cons "_.." "d")
   (cons "." "e")
   (cons ".._." "f")
   (cons "__." "g")
   (cons "...." "h")
   (cons ".." "i")
   (cons ".___" "j")
   (cons "_._" "k")
   (cons "._.." "l")
   (cons "__" "m")
   (cons "_." "n")
   (cons "___" "o")
   (cons ".__." "p")
   (cons "__._" "q")
   (cons "._." "r")
   (cons "..." "s")
   (cons "_" "t")
   (cons ".._" "u")
   (cons ".__" "w")
   (cons "..._" "v")
   (cons "_.._" "x")
   (cons "_.__" "y")
   (cons "__.." "z")
        
   ;cyfry
   (cons "_____" "0")
   (cons ".____" "1")
   (cons "..___" "2")
   (cons "...__" "3")
   (cons "...._" "4")
   (cons "....." "5")
   (cons "_...." "6")
   (cons "__..." "7")
   (cons "___.." "8")
   (cons "____." "9")

   ;wybrane znaki interpunkcyjne
   (cons "._._._" ".")
   (cons "__..__" ",")
   (cons "_._._." ";")
   (cons "" " ")))

(define (decoding letters)
  (if (null? letters)
      ""
      (string-append (dict-ref decode (first letters)) (decoding (rest letters)))))

(define (morse-decode morse)
  (define letters (string-split morse " "))   ;bo string-split zmienia " " na ""
  (decoding letters))


;mozna uzyc string-normalize-spaces zeby z wielu spacji zrobic jedna

;test
(morse-decode "__ .__.  ..___ _____ ..___ ..___ ") ;dziala
