;----------------------------------------------
;Manic Miner
; Atom version by Kees van Oss  2014
;----------------------------------------------
	.DEFINE asm_code $0500
	.DEFINE header   1		; Header Wouter Ras emulator
	.DEFINE filenaam "MM"

.org asm_code-22*header

.IF header
;********************************************************************
; ATM Header for Atom emulator Wouter Ras

name_start:
	.byte filenaam			; Filename
name_end:
	.repeat 16-name_end+name_start	; Fill with 0 till 16 chars
	  .byte $0
	.endrep

	.word asm_code			; 2 bytes startaddress
	.word exec			; 2 bytes linkaddress
	.word eind_asm-start_asm	; 2 bytes filelength

;********************************************************************
.ENDIF


exec  = L3190

start_asm:
	.include "mm.inc"
	.include "controls.inc"
	.include "joystick.inc"
	.include "sound.inc"
	.include "font.inc"
	.include "mm6200.inc"
buffer:
eind_asm: