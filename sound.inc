sound:
	sta note
	lda #0
snd_loop1:
	ldx note
snd_loop2:
	dex
	nop
	nop
	bne snd_loop2
	eor #4
	sta $b002
	dey
	bne snd_loop1
	rts

note:	.byte 0

; Jump sound
;	pha
;	lda L0065
;	ldy #20
;	jsr sound
;	pla

; Foot down
;	lda L0A25
;	eor #$ff
;	lsr a
;	ldy #7
;	jsr L0B27              ; Sound

; Death sound
;	lda #10
;	sta L1764
;L1728:
;	lda L1764
;	ldy #60
;	jsr L0B27		; Make death high note sound
;	lda L1764
;	ora #32
;	ldy #40
;	jsr L0B27		; Make death low note sound
;	inc L1764
;	lda L1764
;	cmp #20
;	bne L1728

