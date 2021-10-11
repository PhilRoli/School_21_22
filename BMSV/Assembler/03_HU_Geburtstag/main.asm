;
; 03_HU_Geburtstag.asm
;
; Created: 06.10.2021 12:38:47
; Author : philipp
; Class  : 4AHBG
; Description:
; Read PINB to PORTB
; Add Birthday (27)
; Output to PORTA
;


; Replace with your application code
start:
; Input
	ldi r16, 0x00
	out DDRB, r16
; Output
	ldi r17, 0xFF
	out DDRA, r17
; load birtday (27) to r27
	ldi r27, 0x1B

	rjmp loop

loop:
	; Read PINB to r18
	in r18, PINB
	; Wait
	NOP
	; Add Birthday
	; add <ziel>, <quelle>
	; quelle wird yu ziel addiert
	add r18, r27
	; Wait
	NOP
	; Output r18 to PORTA
	out PORTA, r18

	rjmp loop
