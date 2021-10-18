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
    ; Stack -> Saves adress to jump back to after intrrupt
    ldi r16, high(RAMEND)
    out SPH, r16
    ldi r16, low(RAMEND)
    out SPL, r16
    ; Define and enable external interrupt 0
    ; x register -> 16 bit wide
    ; xh -> high byte
    ; xl -> low byte
    ldi xh, 0
    ldi xl, EICRA
    ; load -> write to register above 0x40 / r31
    ld r16, x
    ; set bits -> falling edge
    ori r16, 0x02
    ; 
    st x, r16
    ; load mask to r16
    ldi r16, 1<<INT0
    ; output mask to EIMSK
    out EIMSK, r16
    ; activate all interrupts
    sei

loop:
    inc r26
    rjmp loop

Int0Function:
    inc r20
    reti