#lang racket

;zadanie 4

(define code
  (list
   ;litery
   (cons "a" "._")
   (cons "b" "_...")
   (cons "c" "_._.")
   (cons "d" "_..")
   (cons "e" ".")
   (cons "f" ".._.")
   (cons "g" "__.")
   (cons "h" "....")
   (cons "i" "..")
   (cons "j" ".___")
   (cons "k" "_._")
   (cons "l" "._..")
   (cons "m" "__")
   (cons "n" "_.")
   (cons "o" "___")
   (cons "p" ".__.")
   (cons "q" "__._")
   (cons "r" "._.")
   (cons "s" "...")
   (cons "t"  "_" )
   (cons "u" ".._")
   (cons "w" ".__")
   (cons "v" "..._")
   (cons "x" "_.._")
   (cons "y" "_.__")
   (cons "z" "__..")
        
   ;cyfry
   (cons "0" "_____")
   (cons "1" ".____")
   (cons "2" "..___")
   (cons "3" "...__")
   (cons "4"  "...._")
   (cons "5" ".....")
   (cons "6" "_....")
   (cons "7" "__...")
   (cons "8" "___..")
   (cons "9" "____.")

   ;wybrane znaki interpunkcyjne
   (cons "." "._._._")
   (cons "," "__..__")
   (cons ";" "_._._.")
   ;(cons " " " ")
   ))


(define (remove-whitespaces xs)
  (if (null? xs)
      null
      (if (char-whitespace? (first xs)) ;char-whitespace sprawdza czy cos jest spacja
          (remove-whitespaces (rest xs))
          xs)))

(define (morse-code-list litery)
  (cond [(null? litery) ""]
        [(char-whitespace? (first litery))
         (if (null? (rest litery))
             (list " ")
             (string-append "  " (morse-code-list (remove-whitespaces (rest litery)))))]
        [else (string-append (string-append (dict-ref code (string (char-downcase (first litery)))) " "
                    (morse-code-list (rest litery))))]))  ;char-downcase dziala jak lower

(define (morse-code nazwa)
  (morse-code-list (string->list nazwa)))



;test
(morse-code "Metody Programowania") ;dziala
