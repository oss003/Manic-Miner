;---------------------------------------------
; Read key in matrix
;
; Controlflag
;	$00 = Keyboard
;	$40 = Joykey
;	$80 = JoyMMC
;
; Select row and read column:
;
; X = key to be checked
;
; columnbit = 0 - key pressed,
;             1 - key not pressed
;---------------------------------------------

controlflag = $0381

readkey:
	bit controlflag		; Check controls
	bvs joykey		; Control = Joykey
	bmi joymmc		; Control = JoyMMC

; Control = Keyboard -------------------------

keyboard:
	lda key_row,x
	ora #$f0
	sta $b000		; Select row

	lda $b001		; Read column
	and key_column,x
	bne not_pressed
	lda key_return,x
	rts

not_pressed:
	lda #0
	rts
;                      Z   X  RET DEL CPY ESC  S   N   JL  JR  JA
key_row:	.byte $01,$03,$06,$04,$05,$00,$08,$03,$00,$00,$00
key_column:	.byte $20,$20,$02,$02,$02,$20,$20,$10,$02,$08,$01
key_return:	.byte $01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01

; Control = Joykey ---------------------------

joykey:
	cpx #3
	bcs keyboard
	inx
	inx
	inx
	inx
	inx
	inx
	inx
	inx
	jmp keyboard

; Control = JoyMMC ---------------------------

joymmc:
	cpx #3
	bcs keyboard
	jsr joyget
	sta joy_scan

	cpx #0
	bne scan_r
scan_l:
	and #$02
	beq scan_no
	lda #$fe
	rts
scan_r:
	cpx #1
	bne scan_u
	lda joy_scan
	and #$01
	beq scan_no
	lda #$02
	rts
scan_u:
	cpx #2
	bne scan_no
	lda joy_scan
	and #$10
	beq scan_no
	lda #$ff
	rts
scan_no:
	lda #0
	rts

joy_scan:	.byte 0
