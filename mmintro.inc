OSCLI		= $fff7
LFFF4		= $fff4
L3190		= $3298

straddr		= $80
scrolladdr	= $82
stop_flag	= $85
irq_flag	= $86

; Clear screen

	lda #12		; Clear screen
	jsr LFFF4

	lda #0		; Erase cursor
	sta $e1
	sta stop_flag

	ldx #<str1	; Print (C) SOFTWARE PROJECTS
	ldy #>str1
	jsr prtstr

	ldx #<str2	; Print PRESS SPACE
	ldy #>str2
	jsr prtstr

	ldx #<str3	; Print empty scrollbar
	ldy #>str3
	jsr prtstr

	jsr scrollinit
	jsr irqinit

; Main loop 

main:
	jsr copy_screen1
	jsr wait
	lda stop_flag
	bne end_routine
	jsr scroll
	jsr copy_screen2
	jsr wait
	lda stop_flag
	bne end_routine
	jsr scroll
	jmp main

end_routine:
	sei
	lda #0
	sta $b000	; Reset keyscan
	sta $b002	; Reset colour pallet

; Load MM.ATM

	ldx #0
namecopy:
	lda filename,x
	sta $0100,x
	inx
	cmp #13
	bne namecopy

;	lda #<filename
;	sta straddr
;	lda #>filename
;	sta straddr+1

;	lda #<$0500
;	sta straddr+2
;	lda #>$0500
;	sta straddr+3

;	lda #<$0500
;	sta straddr+4
;	lda #>$0500
;	sta straddr+5

;	lda #21		; No text
;	jsr LFFF4

;	ldx #straddr
	jmp OSCLI
;	jmp L3190	; Exec address MM.ATM

;	lda #12		; Clear screen
;	jmp LFFF4

filename:	.byte "R.",$22,"MMCODE",$22,13

;----------------------------------------------------------------
; Wait routine between 2 screens
;----------------------------------------------------------------

wait:
	ldy #50
wl2:
	ldx #$0
wl1:
	lda #9		; Test space pressed
	sta $b000
	lda $b001
	and #1
	beq keypressed
	inx
	bne wl1

	dey
	bne wl2

	rts

keypressed:
	inc stop_flag
	rts

;----------------------------------------------------------------
; Text scroller
;----------------------------------------------------------------

scroll:
	jsr $fe66
	ldx #6
copyleft:
	lda $81a0,x
	sta $819f,x
	inx
	cpx #28
	bne copyleft

	ldy #0
	lda (scrolladdr),y
	beq scrollinit
	cmp #65
	bcc sign
	ora #$20
	jmp store
sign:
	eor #$a0
store:
	sta str4+2

	ldx #<str4
	ldy #>str4
	jsr prtstr

	inc scrolladdr
	bne endscroll
	inc scrolladdr+1
endscroll:
	rts

scrollinit:
	lda #<scrolltxt
	sta scrolladdr
	lda #>scrolltxt
	sta scrolladdr+1
	rts
	
;----------------------------------------------------------------
; Print string in X,Y
;----------------------------------------------------------------

prtstr:
	stx straddr
	sty straddr+1

	lda #30
	jsr LFFF4

	ldy #1
	lda (straddr),y
	tay
	lda #10
vtab:
	jsr LFFF4
	dey
	bne vtab


	ldy #0
	lda (straddr),y
	tay
	lda #9
htab:
	jsr LFFF4
	dey
	bne htab

	ldy #2
scrloop:
	lda (straddr),y
	beq endstr
	jsr LFFF4
	iny
	jmp scrloop
endstr:
	rts

str1:	.byte 5,11,"(C) SOFTWARE PROJECTS",0
str2:	.byte 10,15,"PRESS SPACE",0
str3:	.byte 3,13,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80
	.byte $80,$80,$80,$80,$80,$80,$80,$80,$80,$80,$80
	.byte $80,$80,$80,$80,$80,0
str4:   .byte 26,13,$ff,0

;----------------------------------------------------------------
; Copy screen routines
;----------------------------------------------------------------

copy_screen1:
	ldx #0
loop1:
	lda scr1_l0,x
	sta $8000,x
	lda scr1_l1,x
	sta $8020,x
	lda scr1_l2,x
	sta $8040,x
	lda scr1_l3,x
	sta $8060,x
	lda scr1_l4,x
	sta $8080,x
	lda scr1_l5,x
	sta $80a0,x
	lda scr1_l6,x
	sta $80c0,x
	lda scr1_l7,x
	sta $80e0,x
	lda scr1_l8,x
	sta $8100,x
	lda scr1_l9,x
	sta $8120,x
	inx
	cpx #32
	bne loop1
	rts

copy_screen2:
	ldx #0		; 2+32*96=
loop2:
	lda scr2_l0,x	; 4
	sta $8000,x	; 5
	lda scr2_l1,x	; 4
	sta $8020,x	; 5
	lda scr2_l2,x	; 4
	sta $8040,x	; 5
	lda scr2_l3,x	; 4
	sta $8060,x	; 5
	lda scr2_l4,x	; 4
	sta $8080,x	; 5
	lda scr2_l5,x	; 4
	sta $80a0,x	; 5
	lda scr2_l6,x	; 4
	sta $80c0,x	; 5
	lda scr2_l7,x	; 4
	sta $80e0,x	; 5
	lda scr2_l8,x	; 4
	sta $8100,x	; 5
	lda scr2_l9,x	; 4
	sta $8120,x	; 5
	inx		; 2
	cpx #32		; 2
	bne loop2	; 2

	rts

;----------------------------------------------------------------
; IRQ routine
; - Repeat
; -   Trigger at flyback
; -   Switch to colour pallete 1
; -   Set new IRQ timer for switchback to colour pallete 0
; -   Switch to colour pallete 0
; -   Set new IRQ at flyback for switchback to colour pallete 1
; - Until 0
;----------------------------------------------------------------

irqtime		= 16600
coltime		= 12*64

irqinit:
	sei

	ldx #0
	stx irq_flag

	jsr $fe66		; Trigger at flyback
	lda #>irqvec		; Set new IRQ vec
	sta $205
	lda #<irqvec
	sta $204

	lda timer_l,x		; Set IRQ timer for flyback
	sta $b804
	lda timer_h,x
	sta $b805

	lda #$40
	sta $b80b

	lda #$c0		; Enable T1-IRQ
	sta $b80e

	cli
	rts

; IRQ handler to switch to colour pallette 1
; Set timer for switching back to pallette 0

irqvec:
	lda $b804		; Clear IRQ flag

	sei

	txa
	pha
	tya
	pha

	lda irq_flag
	and #1
	tax
	bne irq2

wait_vsync:
	bit $b002		; Wait for flyback
	bmi wait_vsync

	lda #8			; Switch to pallette 1
	jmp set_palette
irq2:
	lda #0
set_palette:
	sta $b002

	lda timer_l,x		; Set IRQ timer for pallette 1
	sta $b804
	lda timer_h,x
	sta $b805

	inc irq_flag

	pla
	tay
	pla
	tax
	pla
	rti

timer_l:	.byte <(10*12*64+240),<8000
timer_h:	.byte >(10*12*64+240),>8000

;----------------------------------------------------------------
; Screen 1, MANIC MINER
;----------------------------------------------------------------

scr1_l0:
	.byte 32,32,32
	.byte 255,195,32,195,255,32,32,67,67,67,32,32,255,195
	.byte 32,32,255,32,32,32,32,32,32,195,195,195,32
	.byte 32,32
scr1_l1:
	.byte 32,32,32
	.byte 255,240,207,240,255,32,79,112,112,112,79,32,255,240
	.byte 207,32,255,32,79,79,79,32,207,240,240,240,207
	.byte 32,32
scr1_l2:
	.byte 32,32,32
	.byte 255,32,32,32,255,32,127,67,67,67,127,32,255,32
	.byte 32,252,255,32,32,127,32,32,255,32,32,32,195
	.byte 32,32
scr1_l3:
	.byte 32,32,32
	.byte 240,32,32,32,240,32,127,112,112,112,127,32,240,32
	.byte 32,32,240,32,32,127,32,32,240,207,207,207,240
	.byte 32,32
scr1_l4:
	.byte 32,32,32
	.byte 32,32,32,32,32,32,32,32,32,32,32,32,32,32
	.byte 32,32,32,32,124,124,124,32,32,32,32,32,32
	.byte 32,32
scr1_l5:
	.byte 32,32,32
	.byte 32,32,32,32,32,32,207,207,207,32,32,32,32,32
	.byte 32,32,207,207,207,207,32,32,32,32,32,32,32
	.byte 32,32
scr1_l6:
	.byte 32,32,32
	.byte 67,32,32,32,67,32,32,255,32,32,127,67,32,32
	.byte 127,32,255,195,195,195,32,67,67,67,67,32,32
	.byte 32,32
scr1_l7:
	.byte 32,32,32
	.byte 127,79,32,79,127,32,32,255,32,32,127,112,79,32
	.byte 127,32,255,240,240,240,32,127,112,112,112,79,32
	.byte 32,32
scr1_l8:
	.byte 32,32,32
	.byte 127,32,124,32,127,32,252,252,252,32,127,32,32,124
	.byte 127,32,252,252,252,252,32,127,124,127,124,32,32
	.byte 32,32
scr1_l9:
	.byte 32,32,32
	.byte 127,32,32,32,127,32,32,32,32,32,112,32,32,32
	.byte 112,32,32,32,32,32,32,127,32,112,79,79,32
	.byte 32,32


;----------------------------------------------------------------
; Screen 2, MANIC MINER
;----------------------------------------------------------------

scr2_l0:
	.byte 32,32,32
	.byte 32,32,32,32,32,32,67,124,124,124,67,32,32,32
	.byte 32,32,32,32,67,67,67,32,32,32,32,32,32
	.byte 32,32
scr2_l1:
	.byte 32,32,32
	.byte 207,32,32,32,207,32,127,32,32,32,127,32,207,32
	.byte 32,32,207,32,112,127,112,32,32,207,207,207,32
	.byte 32,32
scr2_l2:
	.byte 32,32,32
	.byte 255,252,195,252,255,32,127,124,124,124,127,32,255,255
	.byte 195,32,255,32,32,127,32,32,255,32,32,32,252
	.byte 32,32
scr2_l3:
	.byte 32,32,32
	.byte 255,32,240,32,255,32,112,32,32,32,112,32,255,32
	.byte 240,207,255,32,79,127,79,32,255,32,32,32,207
	.byte 32,32
scr2_l4:
	.byte 32,32,32
	.byte 252,32,32,32,252,32,32,32,32,32,32,32,252,32
	.byte 32,32,252,32,32,32,32,32,32,252,252,252,32
	.byte 32,32
scr2_l5:
	.byte 32,32,32
	.byte 79,32,32,32,79,32,32,32,32,32,79,32,32,32
	.byte 79,32,32,32,32,32,32,32,32,32,32,32,32
	.byte 32,32
scr2_l6:
	.byte 32,32,32
	.byte 127,124,67,124,127,32,195,195,195,32,127,124,67,32
	.byte 127,32,195,195,195,195,32,127,124,124,124,67,32
	.byte 32,32
scr2_l7:
	.byte 32,32,32
	.byte 127,32,112,32,127,32,240,255,240,32,127,32,112,79
	.byte 127,32,255,240,240,240,32,127,79,79,79,112,32
	.byte 32,32
scr2_l8:
	.byte 32,32,32
	.byte 124,32,32,32,124,32,32,255,32,32,124,32,32,32
	.byte 124,32,255,252,252,252,32,127,32,124,67,67,32
	.byte 32,32
scr2_l9:
	.byte 32,32,32
	.byte 32,32,32,32,32,32,207,255,207,32,32,32,32,32
	.byte 32,32,255,207,207,207,32,112,32,32,112,112,32
	.byte 32,32

;----------------------------------------------------------------
; Scrollerdata
;----------------------------------------------------------------

scrolltxt:
	.byte "BBC VERSION WRITTEN BY D.J.COATHUPE.  "
	.byte "ATOM VERSION WRITTEN BY K.V.OSS.  "
	.byte "ORIGINAL PROGRAM BY MATTHEW SMITH.  "
	.byte "GUIDE MINER WILLY AROUND 20 LETHAL CAVERNS "
	.byte "COLLECTING KEYS AS YOU GO . . . . . . "
	.byte "Z-LEFT  X-RIGHT  RETURN-JUMP  Q-SOUND OFF  "
	.byte "S-SOUND ON  DELETE-FREEZE  COPY-CONTINUE    "
	.byte $0