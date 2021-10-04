;
; 01_IO_Assembler.asm
;
; Created: 29.09.2021 08:52:40
; Author : Philipp Rolinek
; Class  : 4AHBG
;


; Replace with your application code

; name: <- label - address of next instruction
; wird nicht in asm �bernommen, compiler directive
start:
    ; ldi -> load immediate
    ; start at r16
    ldi r17, 0xFF

    ; out -> toogle output
    ; only able to write registers
    out DDRA, r17


loop:
    ; increment = erh�hen
    inc r16

    ; output r16 to port A
    out PORTA, r16

    ; relative jump -> jump to label / line below label
    rjmp loop
