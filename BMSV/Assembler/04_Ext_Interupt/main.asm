;
; 04_Ext_Interupt.asm
;
; Created: 11.10.2021 13:51:59
; Author : philipp
; Class  : 4AHBG
; Description:
; 
;


; Replace with your application code

; Set the programm counter to 0
    .org 0
start:
    jmp MainStart

; Set programm counter to 2, EXT0 interrupt
    .org 2
    jmp Int0Function

; Set the programm counter to 0x100 / 256
    .org 0x100
MainStart:
; Initialize the external interrupt
; Set stackpointer to the top of RAM
    ldi r16, high(RAMEND)
    out SPH, r16
    ldi r16, low(RAMEND)
    out SPL, r16
; Define and enable external interrupt 0

loop:
    inc r26
    rjmp loop

Int0Function:
    reti