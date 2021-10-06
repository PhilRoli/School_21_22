;
; 02_PortCopy.asm
;
; Created: 04.10.2021 12:49:26
; Author : philipp
; Class  : 4AHBG
; Description:
;  Copy state of PORTA to PORTB
; PORTA must be input
; PORTB is output
;

; NOTES
; 

; Replace with your application code
start:
; Input
    ldi r16, 0x00
    out DDRA, r16

; Output
    ldi r17, 0xFF
    out DDRB, r17

    rjmp loop

loop:
    
    in r16, PINA
    out PORTB, r16
    out PORTB, r17

    rjmp loop
