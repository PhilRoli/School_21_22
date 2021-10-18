;
; 03_HU_Geburtstag.asm
;
; Created: 06.10.2021 12:38:47
; Author : philipp
; Class  : 4AHBG
; Description:
; Read PINB to r18
; Add Birthday (27)
; Output to PORTD
;


; Replace with your application code
start:
	; Input
	ldi r16, 0x00
	out DDRB, r16
	; Output
	ldi r17, 0xFF
	out DDRD, r17
	; load birtday (27) to r27
	ldi r27, 0x1B

	rjmp loop

loop:
	; Read PINB to r18
	in r18, PINB
	; Do nothing for 1 cycle
	NOP
	; Add Birthday
	; add <ziel>, <quelle>
	; quelle wird yu ziel addiert
	add r18, r27
	; Do nothing for 1 cycle
	NOP
	; Output r18 to PORTD
	out PORTD, r18

	rjmp loop
