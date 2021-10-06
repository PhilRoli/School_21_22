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
    
	; Zustand von PINA in r16 laden
    in r16, PINA
	; r16 (PINA) auf PORTB ausgeben
    out PORTB, r16
	; Einen Takt warten / Nichts tun
 	NOP
	; Toggeln von PORTB durch laden von r17 (0xFF) nach PINB
    out PINB, r17

    rjmp loop
