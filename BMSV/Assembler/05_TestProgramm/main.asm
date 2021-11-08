;
; 05_TestProgramm.asm
;
; Created: 08.11.2021 12:30:27
; Author : philipp
; Class  : 4AHBG
; Description:
; Lies alle Bits von PortD ein
; erhoehe sie um 1
; gib sie auf PortB aus
;


; Replace with your application code
start:
	; Input
    ldi r16, 0x00
	out DDRD, r16
	; Output
	ldi r17, 0xFF
	out DDRB, r17

loop:
	; read pind
	in r18, PIND
	; r18 erhoehen
	inc r18
	; AUf PortB ausgeben
	out PORTB, r18
	; loop
	rjmp loop

