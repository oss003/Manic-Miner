;
; User equates
;
OSWORD      = $FFF1
;
; Code equates
;

L199F       = L199E+1

; Screen coordinates

;L32A0       = $32A0
;L32A8       = $32A8
L332E       = $81c6
L33C0       = $8110

L3942       = $8258
L394A       = $8258

;L4000       = $4000
;L4A00       = $4A00

L4F42       = $8b50
L4F4A       = $8b50

;L5000       = $5000

;L6364       = L6362+2
;L6367       = L6365+2
L661D       = L661C+1
L661E       = L661C+2
L6936       = L6935+1
L693C       = L693B+1
L6A2A       = L6A29+1

;LFFFF       = $FFFF
;
; Start of code
;
;            *= $6200
;

;--------------------------------------------
; Start game with player
;--------------------------------------------

L6200:      lda #$01               ; Set level
            jsr L62C3              ; Buildscreen

            jsr L62F4              ; Reset music pointer and play sound

; Game play loop

L6208:      lda L651D              ; Lb miner screen address
            sta L0075              ; 85 75
            lda L651E              ; Hb miner screen address
            sta L0076              ; 85 76

            jsr L109C              ; Move miner

            lda L0075              ; A5 75
            sta L651D              ; Lb miner screen address
            lda L0076              ; A5 76
            sta L651E              ; Hb miner screen address

            jsr L1E0D              ; Show guards
            jsr L68BE              ; 20 BE 68

            jsr L3146              ; 20 46 31

; Wait loop

            ldx #$c0               ; A2 00
            ldy #$FF               ; A0 FF
L622C:      inx                    ; E8
            bne L622C              ; D0 FD
            iny                    ; C8
            bne L622C              ; D0 FA

; Scan keys

;	jsr $fe71		; Read key
;	cpy #$0f
	ldx #3
	jsr readkey
	bne L6291              ; Delete key pressed

;	jsr $fe71		; Read key
;	cpy #$3b
	ldx #5
	jsr readkey
	bne L62AA              ; Escape key pressed

;	jsr $fe71		; Read key
;	cpy #$33
	ldx #6
	jsr readkey
	bne L62B8              ; S key pressed

;	jsr $fe71		; Read key
;	cpy #$31
	ldx #7
	jsr readkey
	bne L62AD              ; N key pressed

L6266:      lda L6B7F              ; Check cheatmode
            cmp #$00               ; C9 00
            beq L628E              ; F0 21

; Scan function keys f0-f9

            lda #$00               ; A9 00
            sta L635C              ; 8D 5C 63
L6272:      ldy #$FF               ; A0 FF

	lda #$f0
	sta $b000
	jsr $fe71		; Scan key
	tya
            ldx L635C              ; AE 5C 63
	cmp L6352,X		; Check if function key
	bne L6273
	jmp L6303		; If so, jump
L6273:
            inc L635C              ; Point to next funtion key
            lda L635C              ; AD 5C 63
            cmp #$0A               ; C9 0A
            bne L6272              ; D0 E4

L628E:      jmp L6208              ; Game loop

guardflag:	.byte 0
shadow_print:	.byte 0


;--------------------------------------------
; Delete key pressed
; Freeze game until Copy key is pressed
;--------------------------------------------

L6291:      jsr L62E9              ; Stop music
L6294:      jsr L30FC              ; Check for cheatcode

;	jsr $fe71		; Read key
;            cpy #$0E               ; C0 FF
	ldx #4
	jsr readkey
            beq L6294              ; Copy key not pressed

            jsr L62F4              ; Reset music pointer and play sound
            jmp L6208              ; 4C 08 62

;--------------------------------------------
; Escape key pressed
; Return to intro screen
;--------------------------------------------

L62AA:      jmp L24F8              ; Jump L0090

;--------------------------------------------
; Q key pressed
; Turn off tune
;--------------------------------------------

L62AD:      lda #$00               ; A9 00
            sta L62F3              ; Reset soundflag

            jsr L62E9              ; Stop music
            jmp L6266              ; 4C 66 62

;--------------------------------------------
; S key pressed
; Turn on tune
;--------------------------------------------

L62B8:      lda #$01               ; A9 01
            sta L62F3              ; Set soundflag

            jsr L62E3              ; Start music
            jmp L6266              ; 4C 66 62

;--------------------------------------------
; Build screen
;--------------------------------------------

L62C3:
	jsr L6333              ; Check levelnr

	lda #$05               ; Reset 
	sta L2FFF              ; Nr of keys

	lda L0080              ; Get levelnr
	jsr L28B8              ; Build screen

            jsr L1FB5              ; 20 B5 1F
            jsr L229B              ; Skip printing bottomline + set vars

; Copy screen to buffer

	lda #>buffer
	sta buf_loop+5
	lda #$80
	sta buf_loop+2

	ldx #$11
	ldy #0
buf_loop:
	lda $8000,y
	sta buffer,y
	iny
	bne buf_loop

	inc buf_loop+2
	inc buf_loop+5
	dex
	bne buf_loop	

; Wipe keys

	lda L2FFF		; Reset key pointer
	sta key_max
	ldx #0
	stx key_cnt
key1:
	ldx key_cnt
	lda L2E7F,X		; Get X-pos key
	sec
	sbc #4
	sta SCR

	inx
	lda L2E7F,X		; Get Y-pos key
	clc
	adc #>buffer
	sta SCR+1

	ldx #7
	lda #0
key2:
	ldy scrtab,x
	sta (SCR),y
	dex
	bpl key2

	inc key_cnt
	inc key_cnt
	dec key_max
	bne key1

; Continue game

            jmp L6391              ; 4C 91 63

key_cnt:	.byte 0
key_max:	.byte 0

;--------------------------------------------
; Start or stop music routine
; Music pointer is L3098
; Start music is poke INC at start musicroutine
; Stop music is poke RTS at start musicroutine
;--------------------------------------------

; Start music

L62E3:
	lda #$EE		; INC instruction
	sta L303B		; Musicroutine
	rts

; Stop music

L62E9:	lda #$60               ; RTS instruction
	sta L303B              ; Musicroutine
	
	lda #$9F               ; Set tone
	jmp L3075              ; Sound output

; Soundflag

L62F3:      .byte $EA		; Soundflag

; Reset music pointer and play sound

L62F4:      lda #$00               ; Reset music pointer
            sta L3098              ; 8D 98 30

            lda L62F3              ; Check soundflag
            cmp #$00               ; C9 00
            beq L62E9              ; Stop music

            jmp L62E3              ; Start music

;--------------------------------------------
; Entry Function key pressed cheatmode
;
; F0 = goto level  1 ; SHIFT-F0 = goto level 11
; F1 = goto level  2 ; SHIFT-F1 = goto level 12
; F2 = goto level  3 ; SHIFT-F2 = goto level 13
; F3 = goto level  4 ; SHIFT-F3 = goto level 14
; F4 = goto level  5 ; SHIFT-F4 = goto level 15
; F5 = goto level  6 ; SHIFT-F5 = goto level 16
; F6 = goto level  7 ; SHIFT-F6 = goto level 17
; F7 = goto level  8 ; SHIFT-F7 = goto level 18
; F8 = goto level  9 ; SHIFT-F8 = goto level 1
; F9 = goto level 10 ; SHIFT-F9 = goto level 1
;--------------------------------------------

L6303:
	bit $b001		; Read key
            bpl L6327              ; SHIFT key pressed
	bvc L6310		; CTRL key pressed
	jmp L6208		; wrong key

L6310:      lda L635C              ; AD 5C 63
            cmp L635D              ; CD 5D 63
            beq L6324              ; F0 0C
            sta L635D              ; 8D 5D 63
            clc                    ; 18
            adc #$01               ; 69 01
            jsr L62C3              ; Buildscreen
            jmp L6208              ; 4C 08 62

L6324:      jmp L6208              ; 4C 08 62

; Entry SHIFT-Fx key pressed, add 10 to level

L6327:      lda L635C              ; AD 5C 63
            clc                    ; 18
            adc #$0A               ; 69 0A
            sta L635C              ; 8D 5C 63
            jmp L6310              ; 4C 10 63

;--------------------------------------------
; Check levelnr
;--------------------------------------------

L6333:      sta L0080              ; Set current level

            sta L635D              ; Set temp level
            dec L635D              ; Decrement temp level

            lda L6B7F              ; Check cheatmode
            cmp #$00               ; C9 00
            beq L6351              ; F0 0F

.if debug=0
            lda L0080              ; Get level
            cmp #$13               ; Check max level
            bcc L6351              ; If not reached, skip
            lda #$01               ; Reset current level
            sta L0080              ; 85 80
            lda #$00               ; A9 00
.endif
            nop                    ; EA
            nop                    ; EA
            nop                    ; EA
L6351:      rts                    ; 60

;--------------------------------------------
; Keys to be scanned
;--------------------------------------------

L6352:
;            .byte $DF	; F0 key
;            .byte $8E	; F1 key
;            .byte $8D	; F2 key
;            .byte $8C	; F3 key
;            .byte $EB	; F4 key
;            .byte $8B	; F5 key
;            .byte $8A	; F6 key
;            .byte $E9	; F7 key
;            .byte $89	; F8 key
;            .byte $88	; F9 key

; Keys 1,2,3,4,5,6,7,8,9,0

	.byte $11,$12,$13,$14,$15,$16,$17,$18,$19,$10

; Read key pointer

L635C:      .byte $EA

;--------------------------------------------

L635D:      .byte $EA

;            ldx #$00               ; A2 00
;            ldy #$0A               ; A0 0A
;L6362:      lda L4000,X            ; BD 00 40
;L6365:      sta L0F00,X            ; 9D 00 0F
;            inx                    ; E8
;            bne L6362              ; D0 F7
;            inc L6364              ; EE 64 63
;            inc L6367              ; EE 67 63
;            dey                    ; 88
;            bne L6362              ; D0 EE
;
;            ldx #$00               ; A2 00
;L6376:      lda L4A00,X            ; BD 00 4A
;            sta L1900,X            ; 9D 00 19
;            inx                    ; E8
;            cpx #$80               ; E0 80
;            bne L6376              ; D0 F5
;
;            ldx #$00               ; A2 00
;L6383:      lda L5000,X            ; BD 00 50
;            sta L0D40,X            ; 9D 40 0D
;            inx                    ; E8
;            cpx #$40               ; E0 40
;            bne L6383              ; D0 F5
;
;            jmp L24F8              ; Jump L0090

L6391:      ldx #$00               ; A2 00
L6393:      lda ext_font,X            ; BD 00 0C
            sta ext_font+$D0,X            ; 9D D0 0C
            lda ext_font+$78,X            ; BD 78 0C
            sta ext_font+$B8,X            ; 9D B8 0C
            lda ext_font+$08,X            ; BD 08 0C
            sta ext_font+$E8,X            ; 9D E8 0C
            inx                    ; E8
            cpx #$08               ; E0 08
            bne L6393              ; D0 E9

            lda #$00               ; A9 00
            sta ext_font+$D6              ; 8D D6 0C
            sta ext_font+$BE              ; 8D BE 0C
            sta ext_font+$EE              ; 8D EE 0C
            lda #$FF               ; A9 FF
            sta ext_font+$D7              ; 8D D7 0C
            sta ext_font+$BF              ; 8D BF 0C
            sta ext_font+$EF              ; 8D EF 0C

            lda L0070              ; A5 70
	sec
	sbc #4
            sta L25FE              ; XPOS Exit
            lda L0071              ; A5 71
            sta L25FF              ; YPOS Exit

            lda #$4C               ; JMP instruction
            sta L19EB              ; 8D EB 19

            lda #$FF               ; A9 F0
            sta L199F              ; 8D 9F 19
            lda #$10               ; A9 10
            sta L66DC              ; 8D DC 66

            lda #$A9               ; LDA instruction
            sta L19EE              ; 8D EE 19

            lda #$00               ; A9 00
            sta L197F              ; Monster falling flag
            sta L184B              ; Miner jump flag
 
            lda #$27               ; A9 27
            sta L1842              ; 8D 42 18

            lda #$06               ; Direction left
            sta L1840              ; 8D 40 18

; Set X and Y coordinate Miner
; High nibble is X
; Low nibble is Y

            ldx L0080              ; Get level nr
            lda L6B87,X            ; Get coordinates
            tax                    ; Save coordinates

            and #$F0               ; Filter X-pos
            lsr A                  ; Divide by 2
            clc                    ; 18
            adc #$17               ; Add 23
            sta L183A              ; X-coordinaat Miner in pixels old
            sta L183C              ; X-coordinaat Miner in pixels new

            txa                    ; Get coordinates
            and #$0F               ; Filter Y-pos
            asl A                  ; 0A
            asl A                  ; 0A
            asl A                  ; Multiply by 8
	sec
	sbc #2
            sta L183B              ; Y-coordinaat Miner in pixels old
            sta L183D              ; Y-coordinaat Miner in pixels new
            sta L6B7B              ; Set Y-pos

            ldx L183A              ; X-coordinaat Miner in pixels old
            cpx #$40               ; E0 40
            bcc L6444              ; 90 2C

            lda #$03               ; A9 03
L641A:      sta L183F              ; Miner sprite nr
            ldy L183B              ; Y-coordinaat Miner in pixels old
            lda #$01               ; A9 01
            jsr L1869              ; 20 69 18
            lda L1840              ; AD 40 18
            sta L1843              ; 8D 43 18
            lda L25A4              ; AD A4 25
            and #$80               ; 29 80
            cmp #$80               ; C9 80
            beq L643C              ; F0 08
            lda #$FF               ; A9 FF
            sta L1854              ; 8D 54 18
            jmp L2FC2              ; 4C C2 2F

L643C:      lda #$01               ; A9 01
            sta L1854              ; 8D 54 18
            jmp L2FC2              ; 4C C2 2F

L6444:      lda #$E7               ; A9 E7
            sta L1842              ; 8D 42 18
            lda #$05               ; A9 05
            sta L1840              ; 8D 40 18
            lda #$00               ; A9 00
            jmp L641A              ; 4C 1A 64

;--------------------------------------------
; Jump to next level
;--------------------------------------------

L6453:      lda L6B7F              ; Check cheatmode
            cmp #$01               ; C9 01
            beq L6462              ; F0 08

            lda L0080              ; Get levelnr
            cmp #$14               ; 
            beq L646A              ; If last level jump
            inc L0080              ; If not, next level

L6462:      lda L0080              ; A5 80
            jsr L62C3              ; Buildscreen
            jmp L6208              ; Continue game

L646A:      jmp L6200              ; Start at level 1

;--------------------------------------------

L646D:
	jsr L6639              ; 20 39 66

            lda L2FFF              ; Nr of keys
            cmp #$00               ; C9 00
            beq L6478              ; F0 01
            rts                    ; 60

L6478:
	lda #$22-4               ; A9 22
	sta XPOS
	lda #$17               ; A9 17
	sta YPOS
            jsr L14A7              ; 20 A7 14

            lda L0080              ; A5 80
            cmp #$05               ; C9 05
            bne L64A0              ; D0 10
            lda L1C48              ; AD 48 1C
            ora #$80               ; 09 80
            sta L1C48              ; 8D 48 1C
            lda #$60               ; A9 60
            sta L19EB              ; 8D EB 19
            jsr L6A31              ; 20 31 6A
L64A0:      lda L183C              ; X-coordinaat Miner in pixels new
            lsr A                  ; 4A
            lsr A                  ; 4A
	sec
	sbc #4
            cmp L25FE              ; XPOS Exit
            bne L64BE              ; D0 14
            lda L183D              ; Y-coordinaat Miner in pixels new
            sec                    ; 38
            sbc #$00               ; E9 00
            lsr A                  ; 4A
            lsr A                  ; 4A
            lsr A                  ; 4A
            clc                    ; 18
            adc #$02               ; 69 02
            cmp L25FF              ; YPOS Exit
            bne L64BE              ; D0 03
            jmp L651F              ; 4C 1F 65

L64BE:      lda L0080              ; A5 80
            cmp #$06               ; C9 06
            bne L64D5              ; D0 11

            lda L183A              ; X-coordinaat Miner in pixels old
            cmp #$82               ; C9 82
            bne L64D5              ; D0 0A

            lda L183B              ; Y-coordinaat Miner in pixels old
            cmp #$0D               ; C9 0D
            bne L64D5              ; D0 03

            jmp L651F              ; 4C 1F 65

L64D5:      inc L6517              ; EE 17 65
            lda L6517              ; AD 17 65
            and #$03               ; 29 03
            cmp #$00               ; C9 00
            beq L64E2              ; F0 01
            rts                    ; 60

L64E2:
	lda L109B
;VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV

	sta tmp_cnt
            lda L6516               ; Set textcolour=?
	eor #$FF
	sta L6516

	sta L109B
;            jsr OSWRCH             ; 20 EE FF
            lda L6517              ; AD 17 65
            and #$04               ; 29 04
            cmp #$04               ; C9 04
            beq L6518              ; F0 28

;            lda #$02               ; A9 02
L64F2:
;        jsr OSWRCH             ; 20 EE FF

	lda L25FE              ; XPOS Exit
	sta XPOS
	lda L25FF              ; YPOS Exit
	sec                    ; 38
	sbc #$02               ; E9 02
	sta YPOS

            ldx #$00               ; A2 00
L650B:      lda L6564,X            ; BD 64 65
            jsr OSWRCH             ; 20 EE FF
            inx                    ; E8
            cpx #$07               ; E0 07
            bne L650B              ; D0 F5

	lda tmp_cnt
	sta L109B
            rts                    ; 60

tmp_cnt:	.byte 0

;^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

L6516:	.byte $ff
L6517:      .byte $EA

L6518:      lda #$03               ; A9 03
            jmp L64F2              ; 4C F2 64

L651D:      .byte $00		; Lb miner screen address
L651E:      .byte $05		; Hb miner screen address

L651F:
            lda #$4C               ; A9 4C
            sta L145D              ; 8D 5D 14
            jsr L1423              ; 20 23 14
            lda #$20               ; A9 20
            sta L145D              ; 8D 5D 14
            jsr L62E9              ; Stop music
            lda #$00               ; A9 00
            sta L635C              ; 8D 5C 63
L6534:      lda L6B7E              ; Air level
            lsr A                  ; 4A
            clc                    ; 18
            adc #$01               ; 69 01
            eor #$3F               ; 49 3F
            sta L3099              ; 8D 99 30
            jsr L6639              ; 20 39 66
            inc L635C              ; EE 5C 63
            lda L635C              ; AD 5C 63
            and #$03               ; 29 03
            cmp #$00               ; C9 00
            beq L655C              ; F0 0D

L654F:      lda L6B7E              ; Air level
            cmp #$00               ; C9 00
            bne L6534              ; D0 DE
            jsr L62F4              ; Reset music pointer and play sound
            jmp L6453              ; Increment level

L655C:      lda #$05               ; A9 05
            jsr L673C              ; 20 3C 67
            jmp L654F              ; 4C 4F 65

;------------------------------------------------
; Exit shape

L6564:      .byte $91,$92,$0A,$08,$08,$93,$94

;------------------------------------------------

L656B:      .byte "AIR"

;------------------------------------------------
; Draw air gauge
;------------------------------------------------

L6577:
	lda #$67		; Set gauge Air level to max
	sta L6B7E

	lda #0			; Reset gauge pointer
	sta airgauge_pos

	jsr L6A42		; Print score, lives + levelnr 
	jsr L2CA2		; 20 A2 2C

; Print 'AIR'

	lda #22
	sta XPOS
	lda #21
	sta YPOS

	ldx #$00
L658E:
	lda L656B,X
	jsr OSWRCH
	inx
	cpx #$03
	bne L658E

; Draw white bar

	lda #>$94e7
	sta L6590+2
	sta L6591+2
	lda #<$94e7
	sta L6590+1
	sta L6591+1

	ldy #9
L658F:
	lda #$ff
	ldx #17
L6590:
	lda $9507,x
	eor #$ff
L6591:
	sta $9507,x
	dex
	bpl L6590

	clc
	lda L6590+1
	adc #$20
	sta L6590+1
	lda L6590+2
	adc #0
	sta L6590+2

	sta L6591+2
	lda L6590+1
	sta L6591+1

	dey
	bne L658F

            lda #$00               ; A9 00
            sta L6693              ; 8D 93 66

; Fillup air gauge

	ldx #12
	lda #0
L661B:
	sta $9508,x
	sta $9528,x
	sta $9548,x
	sta $9568,x
	sta $9588,x
	sta $95a8,x
	sta $95c8,x
	dex
	bpl L661B

;            lda #$F0               ; A9 F0
;            sta L32A0              ; 8D A0 32
;            sta L32A8              ; 8D A8 32

            lda #>$9507               ; A9 32
            sta L661E              ; hb

            lda #<$9507               ; A9 A0
            sta L661D              ; lb

            rts                    ; 60

L661C:      sta LFFFF,X            ; 9D FF FF
            rts                    ; 60

; Point 8 lines below
;
;L6620:
;	lda L661D
;	clc
;	adc #$20
;	sta L661D
;	lda L661E
;	adc #0
;	sta L661E
;	rts

L6632:
	.byte $EA

;--------------------------------------------
;Entry 6639 for demo mode
;--------------------------------------------

L6633:
	jsr L6695
	jmp L6640

; Entry for demo mode

L6639:
	lda L197F		; Monster falling flag
	cmp #$01

	beq L6633

L6640:
	inc L6694
	lda L6694
	and #$0F
	cmp #$00
	beq L664D

	rts

;--------------------------------------------
; Decrement and draw airgauge in game
;--------------------------------------------

L664D:
	dec L6B7E		; Air level

	inc L6693		; Adjust gauge pointer
	lda L6693
	and #$07
	cmp #$00
	beq L6683

; Draw left end air gauge

L665C:
	tay
	ldx airgauge_pos
	lda airgauge_chr,y
	sta $9508,x
	sta $9528,x
	sta $9548,x
	sta $9568,x
	sta $9588,x
	sta $95a8,x
	sta $95c8,x

	rts
L6683:
	inc airgauge_pos
	lda #0
	jmp L665C		; Return

L6693:		.byte $EA
L6694:		.byte $EA

airgauge_pos:	.byte 0
airgauge_chr:	.byte $80,$c0,$e0,$f0,$f8,$fc,$fe,$ff

;--------------------------------------------
;
;--------------------------------------------

L6695:      lda L66DC              ; AD DC 66
            cmp #$70               ; C9 70
            bcs L66D4              ; B0 38

            cmp #$10               ; C9 10
            beq L66DD              ; F0 3D
            and #$04               ; 29 04

            cmp #$04               ; C9 04
            beq L66BD              ; F0 17
            jsr L672F              ; 20 2F 67
            jsr L66E9              ; 20 E9 66

            lda L66DC              ; AD DC 66
            clc                    ; 18
            adc #$04               ; 69 04
            sta L66DC              ; 8D DC 66

            ldx #$00               ; A2 00
            jsr L66F8              ; 20 F8 66

            jmp L6725              ; 4C 25 67

L66BD:      jsr L672F              ; 20 2F 67
            jsr L66F8              ; 20 F8 66

            lda L66DC              ; AD DC 66
            clc                    ; 18
            adc #$04               ; 69 04
            sta L66DC              ; 8D DC 66

            ldx #$00               ; A2 00
            jsr L66E9              ; 20 E9 66
            jmp L6725              ; 4C 25 67

L66D4:      lda #$00               ; A9 00
            sta L197F              ; Monster falling flag

            jmp L6725              ; 4C 25 67

L66DC:      .byte $EA

L66DD:      lda L66DC              ; AD DC 66
            clc                    ; 18
            adc #$04               ; 69 04
            sta L66DC              ; 8D DC 66
            jmp L66F8              ; 4C F8 66

L66E9:      cpx #$01               ; E0 01
            beq L6716              ; F0 29
            lda #<L0480               ; A9 80
            sta L0077              ; 85 77
            lda #>L0480               ; A9 04
            sta L0078              ; 85 78
            jmp L6707              ; 4C 07 67

L66F8:      cpx #$01               ; E0 01
            beq L6716              ; F0 1A
            lda #<L04C0               ; A9 C0
            sta L0077              ; 85 77
            lda #>L04C0               ; A9 04
            sta L0078              ; 85 78
            jmp L6707              ; 4C 07 67

L6707:      lda #$39               ; A9 39
            jsr L673C              ; 20 3C 67
            ldx #$4E               ; A2 4E
            ldy L66DC              ; AC DC 66
            lda #$0A               ; A9 0A
            jmp L0F00              ; Plot sprite

L6716:      lda #$69               ; A9 69
            jsr L673C              ; 20 3C 67
            ldx #$4E               ; A2 4E
            ldy L66DC              ; AC DC 66
            lda #$02               ; A9 02
            jmp L0F00              ; Plot sprite

L6725:
;            lda #$11               ; Set textcolour to colour2
;            jsr OSWRCH             ; 20 EE FF
;            lda #$02               ; A9 02
            jmp L64F2              ; 4C F2 64

L672F:      lda L66DC              ; AD DC 66
            cmp #$60               ; C9 60
            bcs L6739              ; B0 03
            ldx #$00               ; A2 00
            rts                    ; 60

L6739:      ldx #$01               ; A2 01
            rts                    ; 60

;--------------------------------------------

L673C:      cmp #$63               ; C9 63
            beq L67BF              ; Key hit, add 100 to score

;--------------------------------------------
; Increment score with A + print score
;--------------------------------------------

L6740:      clc                    ; 18
            adc #$01               ; 69 01
            sed                    ; F8
            clc                    ; 18
            adc L67BA              ; 6D BA 67
            sta L67BA              ; 8D BA 67
            lda L67BB              ; AD BB 67
            adc #$00               ; 69 00
            sta L67BB              ; 8D BB 67
            lda L67BC              ; AD BC 67
            bcs L678F              ; B0 37

L6758:      cld                    ; D8

	lda #6               ; A9 0A
	sta XPOS
	lda #$13               ; A9 13
	sta YPOS

            ldx #$02               ; Print score in 6 digits
L6774:      lda L67BA,X            ; BD BA 67
            jsr L67A4              ; Print 2 digits
            dex                    ; CA
            cpx #$FF               ; E0 FF
            bne L6774              ; D0 F5

            lda #$09               ; Skip 9 characters
            ldx #$08               ; A2 08
L6783:      jsr OSWRCH             ; 20 EE FF
            dex                    ; CA
            bne L6783              ; D0 FA

            lda L67BE              ; Get lives
            jmp L67A4              ; Print 2 digits

L678F:      adc #$00               ; 69 00
            sta L67BC              ; 8D BC 67
            cld                    ; D8
; Make sound

	lda #5
	sta tmp_note
bonus_loop:
	lda #$40
	ldy #$20
	jsr sound
	lda #$20
	ldy #$40
	jsr sound
	dec tmp_note
	bne bonus_loop

;            lda #$04               ; A9 03
;            ldx #$64               ; A2 64
;            ldy #$04               ; A0 04
;            jsr L68AC              ; Make sound

            inc L67BE              ; Add 1 to lives
            jmp L6758              ; 4C 58 67

;-------------------------------------------
; Print byte as 2 digits
;--------------------------------------------

L67A4:      tay                    ; Print left digit
            and #$F0               ; 29 F0
            lsr A                  ; 4A
            lsr A                  ; 4A
            lsr A                  ; 4A
            lsr A                  ; 4A
            clc                    ; 18
            adc #$30               ; 69 30
            jsr OSWRCH             ; 20 EE FF

            tya                    ; Print right digit
            and #$0F               ; 29 0F
            clc                    ; 18
            adc #$30               ; 69 30
            jmp OSWRCH             ; 4C EE FF

;--------------------------------------------
; Score
;--------------------------------------------

L67BA:      .byte $00		; Right 2 digits
L67BB:      .byte $00		; Middle 2 digits
L67BC:      .byte $00		; Left 2 digits


L67BD:      .byte $00

L67BE:      .byte $02		; Live digits

;--------------------------------------------
; Key hit, add 100 to score
;--------------------------------------------

L67BF:
	lda #10			; Make sound
	sta tmp_note
ping_loop:
	lda #$15
	ldy #$15
	jsr sound
	dec tmp_note
	bne ping_loop

;            lda #$05               ; A9 02
;            ldx #$C8               ; A2 C8
;            ldy #$01               ; A0 01
;            jsr L68AC              ; Make sound

            lda #$01               ; A9 01
            sta L009F              ; 85 9F

            lda #$49               ; Add 50
            jsr L6740              ; Print score + lives
            lda #$49               ; Add 50
            jmp L6740              ; Print score + lives

;--------------------------------------------
; End game, check lives
;--------------------------------------------

L67D6:      jsr L62E9              ; Stop music


; Make sound 

	lda #$20
	sta tmp_note
snd_loop6:
	lda tmp_note
	ldy #8
	jsr sound
	lda #$40
	ldy #8
	jsr sound
	inc tmp_note
	lda tmp_note
	cmp #$40
	bne snd_loop6

;            lda #$06               ; A9 01
;            ldx #$C8               ; A2 C8
;            ldy #$01               ; A0 01
;            jsr L68AC              ; Make sound

            ldx #$FD               ; A2 FD
            txs                    ; 9A

            lda L67BE              ; Check if lives=0
            cmp #$00               ; C9 00
            beq L67FA              ; Lives is 0, jump
.if debug=0
            dec L67BE              ; Decrement lives
.endif
            lda L0080              ; Get level
            jsr L62C3              ; Buildscreen
            jsr L62F4              ; Reset music pointer and play sound
            jmp L6208              ; Start game

;--------------------------------------------
; Lives is 0, end game
;--------------------------------------------

L67FA:      lda #>$8000               ; Set screenaddress top left
            sta L0071              ; 85 71
            lda #<$8000               ; A9 80
            sta L0070              ; 85 70

            ldx #$11               ; Clear screen except level+score
            ldy #$00               ; A0 00
            tya                    ; 98
L6807:      sta (L0070),Y          ; 91 70
            iny                    ; C8
            bne L6807              ; D0 FB
            inc L0071              ; E6 71
            dex                    ; CA
            bne L6807              ; D0 F6

; Wipe air gauge

	ldy #0
L6808:
	sta $9400,y
	sta $9500,y
	dey
	bne L6808

            jsr L2EF0              ; Print level name

            ldx #$00               ; Copy shoe graphics into font
L6816:      lda L7B20,X            ; BD 20 7B
            sta ext_font,X            ; 9D 00 0C
            inx                    ; E8
            cpx #$40               ; E0 40
            bne L6816              ; D0 F5

	lda #15
	sta XPOS
	lda #15
	sta YPOS

            ldx #$00               ; Print pillar
L6823:      lda L689F,X            ; BD 9F 68
            jsr OSWRCH             ; Print character
            inx                    ; E8
            cpx #$07               ; E0 0C
            bne L6823              ; D0 F5

            lda #<L0580               ; Spriteaddress L0580
            sta L0077              ; 85 77
            lda #>L0580               ; A9 05
            sta L0078              ; 85 78

            ldx #$4E               ; X=78
            ldy #$68               ; Y=104
            lda #$03               ; Plotmode 3
            jsr L0F00              ; Plot sprite

            lda #$08               ; A9 08
            sta L68AB              ; 8D AB 68

L6844:      lda #<L0D40               ; Spriteaddress L0D40
            sta L0077              ; 85 77
            lda #>L0D40               ; A9 0D
            sta L0078              ; 85 78

            ldx #$4E               ; X=78
            ldy L68AB              ; Y=L68AB
            lda #$03               ; Plotmode 3
            jsr L0F00              ; Plot sprite

            ldx #$FF               ; Wait loop
            ldy #$40               ; A0 40
L685A:      dex                    ; CA
            bne L685A              ; D0 FD

            lda L68AB              ; Decrement shoe counter
            lsr A                  ; 4A
            eor #$3F               ; 49 3F
            sta L3099              ; 8D 99 30

;	and #7
;	bne skip_sound

skip_sound:
            dey                    ; 88
            bne L685A              ; D0 F1

	pha
	tya
	pha
	lda L3099
	ldy #$10
	jsr sound
	pla
	tay
	pla

            inc L68AB              ; EE AB 68
            inc L68AB              ; EE AB 68
            lda L68AB              ; AD AB 68
            cmp #$6A               ; C9 6A
            bne L6844              ; Repeat

;            lda #$9F               ; A9 9F
;            jsr L3075              ; Sound output

            lda #$10               ; A9 10
            jsr L6883              ; 20 83 68

            jmp L24F8              ; Jump L0090

; SUb

L6883:      sta L0070              ; 85 70

L6885:      ldx #$FF               ; A2 FF
            ldy #$FF               ; A0 FF
L6889:      dex                    ; CA
            bne L6889              ; D0 FD
            dey                    ; 88
            bne L6889              ; D0 FA

            dec L0070              ; C6 70
            bne L6885              ; D0 F2

            ldx #$00               ; Wipe font
            txa                    ; 8A
L6896:      sta ext_font,X            ; 9D 00 0C
            inx                    ; E8
            cpx #$40               ; E0 40
            bne L6896              ; D0 F8

            rts                    ; 60

;--------------------------------------------
; Print pillar data
;--------------------------------------------

L689F:
;            .byte $11,$03	; Define textcolour 3
;            .byte $1F,$13,$0F	; Cursor at 19,15
            .byte $80,$81	; Print top pillar
            .byte $0A,$08,$08	; Down,left,left
            .byte $82,$83	; Print bottom pillar

;--------------------------------------------

L68AB:      .byte $EA

;--------------------------------------------
; Make sound
;--------------------------------------------

L68AC:
;            sta L6B82              ; 8D 82 6B
;            stx L6B84              ; 8E 84 6B
;            sty L6B86              ; 8C 86 6B
;
;            lda #$07               ; Sound param at L6B80
;            ldx #$80               ; A2 80
;            ldy #$6B               ; A0 6B
;            jmp OSWORD             ; 4C F1 FF

	tya
	asl a
	asl a
	asl a
	asl a
	tay
	txa
	eor #$ff
	jmp sound

;--------------------------------------------

L68BE:
;???
;            lda L0077              ; A5 77
;            sec                    ; 38
;            sbc #$27               ; E9 27
;            sta L0077              ; 85 77
;
;            lda L0078              ; A5 78
;            sbc #$00               ; E9 00
;            sta L0078              ; 85 78
;???

            ldx L183C              ; X-coordinaat Miner in pixels new
            ldy L183D              ; Y-coordinaat Miner in pixels new
            lda #$06               ; A9 06
            jsr L0F00              ; Plot sprite

            jsr L6AC9              ; 20 C9 6A
            jsr L6A4B              ; 20 4B 6A
            jsr L6967              ; 20 67 69

L68DF:      lda #$03               ; A9 03
            sta L6936              ; 8D 36 69

            lda #$04               ; A9 04
            sta L693C              ; 8D 3C 69

            lda L183F              ; Miner sprite nr
            cmp #$03               ; C9 03
            bne L68FA              ; D0 0A

            lda #$04               ; A9 04
            sta L6936              ; 8D 36 69

            lda #$03               ; A9 03
            sta L693C              ; 8D 3C 69

L68FA:      lda L183A              ; X-coordinaat Miner in pixels old
            and #$03               ; 29 03
            eor L183F              ; Miner sprite nr

            cmp #$03               ; C9 03
            bne L691A              ; D0 14

            lda L183F              ; Miner sprite nr
            cmp #$03               ; C9 03
            bne L6915              ; D0 08

            lda #$05               ; A9 05
            sta L6936              ; 8D 36 69

            jmp L691A              ; 4C 1A 69

L6915:      lda #$05               ; A9 05
            sta L693C              ; 8D 3C 69

L691A:      ldx #$00               ; A2 00
L691C:      lda L0D80,X            ; BD 80 0D
            cmp #$FF               ; C9 FF
            beq L693F              ; F0 1C
            jsr L692E              ; 20 2E 69
            txa                    ; 8A
            clc                    ; 18
            adc #$04               ; 69 04
            tax                    ; AA
            jmp L691C              ; 4C 1C 69

L692E:      clc                    ; 18
            adc #$13               ; 69 13
            sec                    ; 38
            sbc L183A              ; X-coordinaat Miner in pixels old
L6935:      cmp #$03               ; C9 03
            bcc L6940              ; 90 07
            eor #$FE               ; 49 FE
L693B:      cmp #$03               ; C9 03
            bcc L6940              ; 90 01

L693F:      rts                    ; 60

L6940:      inx                    ; E8
            lda L0D80,X            ; BD 80 0D
            sec                    ; 38
            sbc #$01               ; E9 01
            asl A                  ; 0A
            asl A                  ; 0A
            asl A                  ; 0A
            cmp L183B              ; Y-coordinaat Miner in pixels old
            bcc L6951              ; 90 02
            dex                    ; CA
            rts                    ; 60

L6951:      lda L0D80,X            ; BD 80 0D
            dex                    ; CA
            clc                    ; 18
            adc #$03               ; 69 03
            asl A                  ; 0A
            asl A                  ; 0A
            asl A                  ; 0A
            sec                    ; 38
            sbc #$01               ; E9 01
            cmp L183B              ; Y-coordinaat Miner in pixels old
            bcs L6964              ; B0 01
            rts                    ; 60

L6964:      jmp L67D6              ; Death

L6967:      lda #$00               ; A9 00
            sta L005A              ; 85 5A
            lda L183A              ; X-coordinaat Miner in pixels old
            and #$03               ; 29 03
            eor L183F              ; Miner sprite nr
            cmp #$00               ; C9 00
            beq L697B              ; F0 04
            lda #$01               ; A9 01
            sta L005A              ; 85 5A
L697B:      lda L0080              ; A5 80
            cmp #$05               ; C9 05
            bne L6996              ; D0 15
            lda L1C48              ; AD 48 1C
            and #$7F               ; 29 7F
            sec                    ; 38
            sbc #$08               ; E9 08
            sta L1DAE              ; 8D AE 1D
            lda #$FF               ; A9 FF
            sta L1DB1              ; 8D B1 1D
            lda #$0F               ; A9 0F
            sta L1DAD              ; 8D AD 1D
L6996:      lda L0080              ; A5 80
            cmp #$08               ; C9 08
            beq L69A3              ; F0 07
            cmp #$0C               ; C9 0C
            beq L69A3              ; F0 03
            jmp L69BE              ; 4C BE 69


; Check if Kong is standing

L69A3:      lda #$FF               ; A9 FF
            sta L1DAD              ; 8D AD 1D
            lda L33C0              
            cmp #$00               ; C9 00
            beq L69BE              ; F0 0F
            lda #$0F               ; A9 0F
            sta L1DAD              ; 8D AD 1D
            lda #$FF               ; A9 FF
            sta L1DB1              ; 8D B1 1D
            lda #$00               ; A9 00
            sta L1DAE              ; 8D AE 1D

L69BE:      lda #$F1               ; A9 F1
            sta L6A2A              ; 8D 2A 6A
            lda L0080              ; A5 80
            cmp #$0E               ; C9 0E
            bne L69CE              ; D0 05
            lda #$F1               ; A9 F1
            sta L6A2A              ; 8D 2A 6A
L69CE:      ldx #$00               ; A2 00
L69D0:      lda L1DAD,X            ; BD AD 1D
            cmp #$FF               ; C9 FF
            beq L6A1A              ; F0 43
            jsr L69E6              ; 20 E6 69
            txa                    ; 8A
            clc                    ; 18
            adc #$04               ; 69 04
            tax                    ; AA
            cpx #$10               ; E0 10
            bcs L6A1A              ; B0 37
            jmp L69D0              ; 4C D0 69

L69E6:      lda L1DAD,X            ; BD AD 1D
            and #$3F               ; 29 3F
            clc                    ; 18
            adc #$05               ; 69 05
            asl A                  ; 0A
            asl A                  ; 0A
            sta L6632              ; 8D 32 66

            lda L183A              ; X-coordinaat Miner in pixels old
            clc                    ; 18
            adc #$04               ; 69 04
            sec                    ; 38

            sbc L6632              ; ED 32 66
            cmp #$00               ; C9 00
            beq L6A1B              ; F0 1A

            cmp #$07               ; C9 07
            bcc L6A1B              ; 90 16
            sec                    ; 38
            sbc L005A              ; E5 5A

            cmp #$07               ; C9 07
            bcc L6A1B              ; 90 0F
            clc                    ; 18
            adc L005A              ; 65 5A

            cmp #$FD               ; C9 FD
            bcs L6A1B              ; B0 08
            clc                    ; 18
            adc L005A              ; 65 5A

            cmp #$FD               ; C9 FD
            bcs L6A1B              ; B0 01

L6A1A:      rts                    ; 60

L6A1B:      lda L1DAE,X            ; BD AE 1D
            clc                    ; 18
            adc #$08               ; 69 08
            sec                    ; 38
            sbc L183B              ; Y-coordinaat Miner in pixels old

            cmp #$13               ; C9 13
            bcc L6A2E              ; 90 05
L6A29:      cmp #$F0               ; C9 F0
            bcs L6A2E              ; B0 01
            rts                    ; 60

L6A2E:      jmp L67D6              ; Death

L6A31:      lda L199F              ; AD 9F 19
            eor #$FF               ; 49 0F
            sta L199F              ; 8D 9F 19
            jsr L1980              ; 20 80 19
            lda #$FF               ; A9 FF
            sta L109B              ; Colour mask
            rts                    ; 60

;--------------------------------------------
; Print levelnr
;--------------------------------------------

L6A42:      jsr L25C8              ; Print level nr
            lda #$FF               ; A9 FF
            sta L1DAD              ; 8D AD 1D
            rts                    ; 60

;--------------------------------------------
; Check if left switch if turned on
;--------------------------------------------

L6A4B:      lda L332E 
	and #$0f
            cmp #$00               ; C9 00
            bne L6A53              ; Yes, it's switched on
            rts                    ; No, it's not switched on

L6A53:      lda L0080              ; A5 80
            cmp #$08               ; Check if level 8
            beq L6A63              ; Yes, jump

            cmp #$0C               ; Check if level 12
            bne L6A62              ; No, jump

            lda #$47               ; Set new left boundery guard 
            sta L0D83              ; 8D 83 0D

L6A62:      rts                    ; 60

L6A63:      lda #$47               ; Set new left boundery guard
            sta L0D87              ; 8D 87 0D
L6A68:      rts                    ; 60

;--------------------------------------------
;
;--------------------------------------------

L6A69:      lda L6B7E              ; Air level
            cmp #$00               ; If no air
            beq L6AC6              ; Death

            lda L183B              ; Y-coordinaat Miner in pixels old
            cmp L6B7B              ; CD 7B 6B
            bcs L6A7B              ; B0 03
            sta L6B7B              ; 8D 7B 6B

L6A7B:      lda L183B              ; Y-coordinaat Miner in pixels old
            and #$07               ; 29 07
            cmp #$00               ; C9 00
            beq L6A89              ; F0 05

            lda #$00               ; A9 00
            sta L6B7C              ; 8D 7C 6B

L6A89:      lda L183B              ; Y-coordinaat Miner in pixels old
            and #$07               ; 29 07
            cmp L6B7D              ; CD 7D 6B
            bne L6ABA              ; D0 27

            cmp #$00               ; C9 00
            bne L6ABA              ; D0 23

            lda L6B7C              ; AD 7C 6B
            cmp #$00               ; C9 00
            bne L6ABA              ; D0 1C

            lda #$FF               ; A9 FF
            sta L6B7C              ; 8D 7C 6B

            jsr L254D              ; Scroll conveyor

            lda L183B              ; Y-coordinaat Miner in pixels old
            sec                    ; 38
            sbc L6B7B              ; ED 7B 6B
            cmp #$28               ; C9 28
            bcc L6AB4              ; 90 03
            jmp L67D6              ; Death

L6AB4:      lda L183B              ; Y-coordinaat Miner in pixels old
            sta L6B7B              ; 8D 7B 6B
L6ABA:      lda L183B              ; Y-coordinaat Miner in pixels old
            and #$07               ; 29 07
            sta L6B7D              ; 8D 7D 6B
            rts                    ; 60

L6AC3:      jsr L6B5E              ; 20 5E 6B

L6AC6:      jmp L67D6              ; Death

;--------------------------------------------
;
;--------------------------------------------

L6AC9:      jsr L6A69              ; 20 69 6A

            lda L0080              ; A5 80
            cmp #$14               ; C9 14
            bne L6A68              ; D0 96

            inc L6B7A              ; EE 7A 6B
            jsr L6B5E              ; 20 5E 6B
            lda L6B7A              ; AD 7A 6B
            and #$10               ; 29 10
            cmp #$00               ; C9 00
            beq L6B4E              ; F0 6D

            lda L4F42              ; AD 42 4F
            and #$80               ; 29 80
            cmp #$00               ; C9 00
            bne L6AC3              ; D0 D9

            lda L3942              ; AD 42 39
            and #$80               ; 29 80
            cmp #$00               ; C9 00
            bne L6AC3              ; D0 D0

            lda L394A              ; AD 4A 39
            and #$01               ; 29 01
            cmp #$00               ; C9 00
            bne L6AC3              ; D0 C7

            lda L4F4A              ; AD 4A 4F
            and #$01               ; 29 01
            cmp #$00               ; C9 00
            bne L6AC3              ; D0 BE

            lda L6B7A              ; AD 7A 6B
            and #$01               ; 29 01
            cmp #$00               ; C9 00
            beq L6B47              ; F0 39

            lda #$00               ; A9 00
            sta L003F              ; 85 3F

L6B12:
	lda L6B72+3
	sec
	sbc #4
	sta XPOS
	lda L6B72+4
	sta YPOS
	jmp L6B29

;            ldx #$00               ; A2 00
;L6B14:      lda L6B72,X            ; BD 72 6B
;            jsr OSWRCH             ; 20 EE FF
;            inx                    ; E8
;            cpx #$05               ; E0 05
;            beq L6B29              ; F0 0A

L6B1F:
	lda L6B72+6
	sec
	sbc #4
	sta XPOS
	lda L6B72+7
	sta YPOS

;            cpx #$08               ; E0 08
;            bne L6B14              ; D0 F1

            jsr L6B2F              ; 20 2F 6B
            jmp L6B5E              ; 4C 5E 6B

L6B29:      jsr L6B2F              ; 20 2F 6B
            jmp L6B1F              ; 4C 1F 6B

L6B2F:      lda #$E0               ; A9 E0
            clc                    ; 18
            adc L003F              ; 65 3F
            jsr OSWRCH             ; Print character
            tay                    ; A8
            iny                    ; C8

            lda #$0A               ; A9 0A
            jsr OSWRCH             ; Move cursor down 1 pos

            lda #$08               ; A9 08
            jsr OSWRCH             ; Move cursor back 1 pos

            tya                    ; 98
            jmp OSWRCH             ; Print character

L6B47:      lda #$02               ; A9 02
            sta L003F              ; 85 3F
            jmp L6B12              ; 4C 12 6B

L6B4E:      lda #$04               ; A9 04
            sta L003F              ; 85 3F
            lda L6B7A              ; AD 7A 6B
            and #$0F               ; 29 0F
            cmp #$00               ; C9 00
            bne L6B5E              ; D0 03
            jmp L6B12              ; 4C 12 6B

;--------------------------------------------
; Switch ext_font with L1DC1 for $40 bytes
;--------------------------------------------

L6B5E:      ldx #$40               ; A2 40
L6B60:      lda ext_font,X            ; BD 00 0C
            tay                    ; A8
            lda L1DC1,X            ; BD C1 1D
            sta ext_font,X            ; 9D 00 0C
            tya                    ; 98
            sta L1DC1,X            ; 9D C1 1D
            dex                    ; CA
            bne L6B60              ; D0 EF

            rts                    ; 60

;--------------------------------------------

L6B72:      .byte $11,$02,$1F,$14,$0B,$1F,$1C,$02

L6B7A:      .byte $EA
L6B7B:      .byte $EA
L6B7C:      .byte $EA
L6B7D:      .byte $EA
L6B7E:      .byte $EA		; Air level

L6B7F:
.if debug=0
            .byte $00		; Cheatmode <>0
.else
	.byte $01
.endif

L6B80:      .byte $01,$00	; Sound parameter block
L6B82:      .byte $00
L6B83:      .byte $00
L6B84:      .byte $00,$00
L6B86:      .byte $00

L6B87:      .byte $00

;--------------------------------------------
; Level 1-20 data X,Y-position MM from L6B88
;  High nibble = X
;  Low nibble  = Y
;--------------------------------------------

L6B88:      .byte $0E,$0E,$0E,$DE,$04,$74,$0E
            .byte $0E,$0E,$05,$12,$0E,$EE,$8E,$0E
            .byte $4E,$04,$DE,$0E,$0E

;--------------------------------------------

L6B9C:      .byte $DE,$0E,$0E,$00

;--------------------------------------------
; Temp sprite buffer for moving miner
;--------------------------------------------

;L6BA0:      .byte $00,$00,$00,$00,$00,$00,$00,$00
;            .byte $00,$00,$00,$00,$00,$00,$00,$00
;            .byte $00,$00,$00,$00,$00,$00,$00,$00
;            .byte $00,$00,$00,$00,$00,$00,$00,$00
;
;            .byte $00,$00,$00,$00,$00,$00,$00,$00
;            .byte $00,$00,$00,$00,$00,$00,$00,$00
;            .byte $00,$00,$00,$00,$00,$00,$00,$00
;            .byte $00,$00,$00,$00,$00,$00,$00
;L6BDF:      .byte $00
;
;L6BE0:      .byte $0F,$0F,$0D,$02,$0C,$02,$00
;L6BE7:      .byte $FF
;L6BE8:      .byte $0F,$0F,$0B,$0E,$05,$00,$00
;L6BEF:      .byte $FF
;L6BF0:      .byte $0F,$0F,$0D,$02,$0C,$02,$00
;L6BF7:      .byte $FF
;L6BF8:      .byte $0F,$0F,$0B,$0E,$05,$00,$00,$FF

;------------------------------------------------
; Screen layout data
; Parameter block has 6 bytes
;------------------------------------------------

ptr:
	.repeat (>ptr+1)*256-ptr
		.byte 0
	.endrep

; Screen 1

L6C00:	.byte $FF,$FF		; Level ID
L6C02:	.byte $10,$02		; Nibble = colour 0-2

	.byte $00		; Char solid floor $E0/$E1
	.byte $01
	.byte $00
	.byte $00
	.byte $01
	.byte $21,$10		; X,Y exit

	; Horizontal stripes solid floor X,Y,L

	.byte $04,$0D,$0F
	.byte $1B,$0C,$03
	.byte $1C,$0A,$02
	.byte $00,$09,$04
	.byte $00,$07,$03
	.byte $00,$05,$0E
	.byte $11,$05,$01
	.byte $16,$05,$08

	; Horizontal stripes sinking floor X,Y,L

	.byte $FF
	.byte $16,$0C,$05
	.byte $0D,$05,$04
	.byte $12,$05,$04

	; Horizontal stripes wall X,Y,L

	.byte $FF
	.byte $13,$0C,$03
	.byte $10,$08,$03

	; Horizontal stripes conveyor X,Y,L

	.byte $FF
	.byte $07,$09,$14

; Screen 2
	.byte $FF,$FF
L6C3A:	.byte $54,$07

	.byte $00
	.byte $01,$01,$80,$02,$21,$10

	.byte $0D,$0C,$04	; Solid floor
	.byte $08,$09,$07
	.byte $00,$07,$01
	.byte $00,$05,$13
	.byte $14,$06,$04
	.byte $17,$03,$01

	.byte $FF		; Hor Sinking floor X,Y,L
	.byte $07,$0D,$04
	.byte $12,$0A,$04
	.byte $14,$03,$03
	.byte $01,$07,$05
	.byte $19,$06,$02

	.byte $FE		; Ver Sinking floor X,Y,W,H
	.byte $19,$08,$02,$0D

	.byte $FF		; Hor wall X,Y,L
	.byte $12,$00,$0C

	.byte $FE		; Ver wall X,Y,W,H
	.byte $18,$06,$01,$0D

	.byte $FE		; Ver wall X,Y,W,H
	.byte $1B,$05,$01,$0D

	.byte $FF		; Hor conveyor X,Y,L
	.byte $02,$0B,$04

; Screen 3
            .byte $FF,$FF
L6C7E:      .byte $64,$07,$11,$02,$10,$42
            .byte $00,$21,$0E,$04,$0C,$06
            .byte $14,$0D,$0A,$0D,$0B,$05
            .byte $18,$0A,$06,$1A,$07,$04
            .byte $00,$07,$06,$00,$05,$04
            .byte $FF,$04,$05,$1A,$FF,$1E
            .byte $00,$01,$FF,$05,$09,$06
; Screen 4
            .byte $FF,$FF
L6CAA:      .byte $20,$05,$00,$01,$00,$01
            .byte $00,$21,$04,$05,$0C,$02
            .byte $06,$08,$02,$00,$05,$01
            .byte $06,$05,$01,$0B,$0B,$03
            .byte $0B,$06,$02,$10,$05,$01
            .byte $11,$0D,$02,$11,$09,$03
            .byte $12,$03,$06,$14,$06,$03
            .byte $15,$0B,$03,$19,$08,$03
            .byte $1B,$0C,$03,$1D,$0A,$01
            .byte $1A,$04,$04,$FF,$00,$07
            .byte $03,$FF,$0E,$00,$10,$FF
            .byte $00,$0A,$03
; Screen 5
            .byte $FF,$FF
L6CF1:      .byte $24,$07,$00,$01,$02,$80
            .byte $00,$13,$10,$00,$0D,$02
            .byte $02,$0B,$0B,$03,$09,$0A
            .byte $00,$05,$0D,$11,$0B,$07
            .byte $1D,$0B,$01,$15,$05,$06
            .byte $1C,$06,$02,$FF,$00,$0B
            .byte $02,$11,$05,$04,$FF,$07
            .byte $0F,$10,$0D,$0E,$0A,$0D
            .byte $0D,$04,$FE,$07,$0C,$01
            .byte $10,$FF,$11,$08,$0A
; Screen 6
            .byte $FF,$FF
L6D2E:      .byte $20,$06,$20,$01,$00,$81
            .byte $00,$21,$03,$00,$09,$02
            .byte $02,$06,$02,$07,$05,$03
            .byte $0E,$05,$02,$06,$0A,$13
            .byte $14,$05,$05,$1B,$0C,$03
            .byte $15,$0D,$02,$1B,$06,$03
            .byte $16,$08,$05,$FF,$1D,$00
            .byte $01,$FF,$FE,$0F,$06,$01
            .byte $08,$FE,$0F,$0A,$01,$0D
            .byte $FF,$02,$0D,$04
; Screen 7
            .byte $FF,$FF
L6D6A:      .byte $10,$02,$03,$02,$00
            .byte $02,$00,$13,$10,$08,$0D,$03,$00
            .byte $0A,$0B,$0D,$09,$03,$00,$08,$01
            .byte $00,$06,$03,$0D,$05,$03,$0E,$03
            .byte $02,$FF,$FE,$11,$03,$0D,$0D,$FF
            .byte $FE,$10,$03,$01,$0D,$0D,$0C,$04
            .byte $FE,$0D,$0D,$01,$10,$0D,$0F,$11
            .byte $0D,$00,$11,$FF,$06,$05,$05
; Screen 8
            .byte $FF,$FF
L6DA8:      .byte $10,$02,$00,$02,$03,$82,$00
            .byte $13,$10,$03,$0C,$02,$03,$0C,$02
            .byte $00,$0A,$01,$01,$07,$03,$00,$05
            .byte $03,$08,$05,$06,$0E,$02,$02,$08
            .byte $0B,$02,$0B,$0A,$03,$07,$08,$03
            .byte $11,$05,$02,$14,$06,$04,$11,$09
            .byte $05,$11,$0D,$02,$15,$0C,$05,$1A
            .byte $0A,$04,$1A,$07,$01,$1D,$06,$01
            .byte $1C,$02,$02,$FF,$10,$0E,$01,$FF
            .byte $FE,$10,$00,$01,$0F,$FE,$13,$00
            .byte $01,$02,$FE,$0D,$0D,$01,$0F,$FF
            .byte $0A,$0D,$03
; Screen 9
            .byte $FF,$FF
L6E04:      .byte $10,$02,$00
            .byte $02,$00,$83,$00,$05,$03,$02,$0C
            .byte $1A,$02,$08,$08,$00,$05,$1C,$00
            .byte $0A,$02,$1C,$0D,$02,$1C,$07,$02
            .byte $15,$09,$07,$FF,$02,$00,$01,$FF
            .byte $FE,$02,$00,$01,$01,$FF,$0C,$08
            .byte $07,$FD,$04,$FE,$04,$04,$02,$0E
            .byte $FE,$0A,$04,$02,$0E,$FE,$13,$04
            .byte $02,$0E,$FE,$18,$04,$02,$0E,$FD
            .byte $03
; Screen 10
            .byte $FF,$FF
L6E4A:      .byte $20,$01,$32,$01,$34
            .byte $43,$00,$11,$10,$00,$0D,$03,$00
            .byte $0A,$04,$00,$08,$05,$00,$06,$04
            .byte $00,$02,$06,$0C,$00,$03,$07,$05
            .byte $01,$08,$09,$07,$10,$0A,$07,$10
            .byte $07,$07,$10,$04,$04,$14,$00,$0A
            .byte $1A,$02,$04,$16,$05,$08,$1C,$09
            .byte $02,$1B,$0D,$03,$FF,$04,$0A,$02
            .byte $08,$05,$07,$17,$07,$03,$17,$0B
            .byte $03,$FF,$FE,$0F,$00,$01,$0C,$FF
            .byte $00,$0F,$1E,$07,$0C,$0A
; Screen 11
            .byte $FF,$FF
L6E9F:      .byte $64,$07,$00,$00,$76,$80,$00,$05
            .byte $04,$00,$03,$04,$04,$05,$06,$00
            .byte $08,$02,$00,$0D,$02,$1B,$0C,$03
            .byte $16,$0D,$03,$1B,$0A,$01,$1C,$08
            .byte $02,$1C,$06,$02,$0A,$09,$09,$0E
            .byte $05,$0A,$08,$0B,$01,$FF,$05,$0B
            .byte $03,$FF,$00,$00,$05,$FF,$04,$08
            .byte $02
; Screen 12
            .byte $FF,$FF
L6EDA:      .byte $50,$06,$00,$02,$03
            .byte $84,$00,$13,$10,$0A,$0D,$03,$00
            .byte $0C,$06,$05,$0A,$01,$05,$07,$02
            .byte $02,$08,$01,$00,$05,$03,$09,$09
            .byte $04,$11,$0A,$03,$18,$0B,$02,$18
            .byte $08,$06,$1D,$06,$01,$17,$05,$02
            .byte $FF,$11,$05,$06,$08,$05,$05,$0E
            .byte $02,$02,$FF,$10,$00,$01,$14,$00
            .byte $01,$FE,$10,$05,$01,$0F,$FE,$0D
            .byte $05,$01,$0A,$FE,$0D,$0D,$01,$0F
            .byte $0D,$0F,$04,$FF,$11,$0D,$0B
; Screen 13
            .byte $FF,$FF
L6F30:      .byte $20,$07,$50,$02,$05,$40,$00
            .byte $05,$10,$00,$0F,$1E,$06,$03,$18
            .byte $06,$06,$18,$06,$0C,$18,$06,$09
            .byte $18,$FF,$FE,$02,$01,$01,$0F,$FF
            .byte $00,$00,$1E,$FF,$02,$0F,$1A,$FD
            .byte $04,$08,$06,$02,$09,$0C,$02,$15
            .byte $06,$02,$14,$0C,$02,$0E,$06,$02
            .byte $0E,$0C,$02,$10,$09,$02,$1B,$06
            .byte $02,$1A,$0C,$02,$0B,$09,$02,$18
            .byte $09,$02,$18,$03,$02,$FD,$04
; Screen 14
            .byte $FF,$FF
L6F80:      .byte $24,$05,$60,$02,$27,$85,$00
            .byte $13,$03,$00,$0B,$00,$02,$06,$00
            .byte $04,$09,$00,$06,$0D,$00,$06,$07
            .byte $00,$08,$0B,$00,$0C,$09,$00,$0A
            .byte $06,$00,$0E,$05,$00,$12,$06,$00
            .byte $16,$07,$00,$14,$09,$00,$1A,$06
            .byte $00,$1C,$09,$00,$18,$0B,$00,$FD
            .byte $02,$00,$0F,$1E,$FF,$0E,$0B,$06
; Screen 15
            .byte $FF,$FF
L6FC1:      .byte $20,$06,$00,$00,$78,$41
            .byte $00,$05,$06,$00,$0A,$02,$02,$08
            .byte $02,$00,$05,$05,$04,$0C,$03,$0B
            .byte $0D,$02,$0B,$0A,$02,$0B,$07,$02
            .byte $11,$0B,$02,$11,$08,$02,$17,$06
            .byte $02,$18,$09,$02,$16,$0C,$02,$17
            .byte $03,$05,$FF,$06,$07,$01,$FF,$05
            .byte $00,$19,$FF,$07,$03,$10,$FE,$1C
            .byte $01,$02,$0F,$07,$03,$10
; Screen 16
            .byte $FF,$FF
L7007:      .byte $10,$06,$00,$02,$09,$86,$00,$10
            .byte $08,$00,$0C,$09,$0B,$0B,$02,$00
            .byte $05,$01,$05,$05,$01,$03,$07,$01
            .byte $14,$0D,$01,$1A,$0D,$01,$1A,$0B
            .byte $01,$19,$07,$05,$16,$05,$03,$FF
            .byte $00,$09,$02,$FF,$09,$0B,$02,$FE
            .byte $0A,$05,$01,$09,$0D,$05,$01,$0D
            .byte $06,$02,$0D,$07,$03,$0D,$08,$04
            .byte $FF,$02,$09,$19
; Screen 17
            .byte $FF,$FF
L704D:      .byte $20,$06
            .byte $03,$01,$50,$87,$00,$21,$04,$1A
            .byte $0E,$04,$1C,$05,$02,$00,$05,$02
            .byte $00,$0F,$1E,$FF,$02,$05,$1A,$FE
            .byte $00,$06,$1E,$0D,$FF,$1C,$00,$02
            .byte $FF,$0D,$08,$05,$FD,$04,$FE,$02
            .byte $08,$02,$0D,$FE,$09,$05,$02,$0D
            .byte $FE,$12,$05,$02,$0A,$FE,$1A,$05
            .byte $02,$0D,$FD,$04
; Screen 18
            .byte $FF,$FF
L708D:      .byte $10,$06
            .byte $00,$00,$40,$88,$00,$21,$03,$00
            .byte $0F,$1E,$00,$0D,$02,$02,$0C,$1A
            .byte $02,$09,$07,$00,$07,$02,$02,$05
            .byte $1C,$0A,$08,$12,$1C,$0A,$02,$FD
            .byte $02,$1B,$00,$01,$FD,$04,$FE,$04
            .byte $05,$02,$0D,$FE,$09,$05,$02,$0D
            .byte $FE,$13,$05,$02,$0D,$FE,$18,$05
            .byte $02,$0D,$FD,$04
; Screen 19
            .byte $FF,$FF
L70CD:      .byte $24,$07
            .byte $00,$01,$00,$89,$00,$13,$07,$00
            .byte $05,$02,$02,$08,$03,$08,$0D,$0E
            .byte $05,$06,$03,$07,$0A,$04,$17,$0B
            .byte $02,$16,$07,$02,$1A,$05,$04,$1B
            .byte $09,$03,$FF,$FD,$02,$FE,$0A,$03
            .byte $0A,$0B,$FF,$02,$0C,$03,$FF,$FE
            .byte $0A,$04,$0A,$06,$FE,$0A,$08,$0A
            .byte $0A,$FD,$03
; Screen 20
            .byte $FF,$FF
L710C:      .byte $20,$06,$00
            .byte $01,$00,$8A,$01,$21,$04,$07,$05
            .byte $07,$0D,$03,$07,$00,$08,$02,$08
            .byte $07,$07,$1B,$07,$03,$10,$07,$04
            .byte $13,$0D,$01,$10,$0C,$01,$16,$0D
            .byte $01,$18,$09,$01,$FF,$00,$09,$01
            .byte $14,$03,$03,$14,$0A,$01,$17,$0D
            .byte $02,$FF,$0C,$00,$12,$17,$03,$05
            .byte $03,$07,$05,$00,$0B,$02,$00,$0C
            .byte $0B,$0D,$0E,$03,$0E,$0D,$02,$0F
            .byte $0C,$01,$FE,$0F,$07,$01,$0A,$0A
            .byte $0B,$01,$FF,$02,$0B,$08,$FE,$1C
            .byte $03,$02,$07,$02,$0B,$08

            .byte $FF,$FF

;------------------------------------------------
; Bush/key/rock datatable
; Byte 0: bit 0-5 =
;         bit 6-7 = nr of items
; Byte 1: bit 0-4 = y
;         bit 5-7 = dx
;------------------------------------------------

L716F:      .byte $FF
            .byte $FF
; Level 1
            .byte $C1,$80,$F1		; keys left
            .byte $FE,$74,$C0,$D6	; keys right
            .byte $BC			; bush left
            .byte $FE,$48,$64,$A4	; bush right
            .byte $FD,$A0,$F0		; rocks left
            .byte $FF

; Level 2
            .byte $C1,$29,$61		; keys left
            .byte $FE,$71,$97,$2C	; keys right
            .byte $FD			; rocks left
            .byte $FE,$D1		; rocks right
            .byte $FF

; Level 3
            .byte $C2,$50,$E0		; keys left
            .byte $FE,$60,$D6,$46	; keys right
            .byte $FD,$08,$03,$90,$00	; spiders left	
            .byte $FE,$10,$01,$A0,$00	; spiders right
            .byte $FF

; Level 4
            .byte $C2,$00,$B1,$F6	; keys left
            .byte $FE,$81,$D6		; keys right
            .byte $FD,$60,$00		; spider left
            .byte $FE,$6C,$00		; spider right
            .byte $FF

; Level 5
            .byte $C0,$6C,$8C,$96	; keys left
            .byte $FE,$D1,$C7		; keys right
            .byte $4E			; bush left
            .byte $FE,$7E,$8E,$47,$74	; bush right
            .byte $FD			; rocks left
            .byte $FE,$30		; rocks right
            .byte $FF

; Level 6
            .byte $C4,$0A,$CB,$E6	; keys left
            .byte $FE,$06,$D7		; keys right
            .byte $2C			; bush left
            .byte $FD			; cross left
            .byte $FE,$0B,$44		; cross right
            .byte $FF

; Level 7
            .byte $C5			; keys left
            .byte $FE,$2A,$36,$A7,$D3,$DB ; keys right
            .byte $FD			; star left
            .byte $FE,$6C,$68,$BA,$B5	; star right
            .byte $FF

; Level 8
            .byte $80,$18,$D6,$B2	; keys left
            .byte $FE,$CD		; keys right
            .byte $FE,$6E		; bush right
            .byte $FF

; Level 9
            .byte $00,$F1		; keys left
            .byte $F1
            .byte $FE
            .byte $FF

; Level 10
            .byte $C6,$D1,$B6		; keys left
            .byte $FE,$18,$42,$D1	; keys right
            .byte $FD,$23,$09,$90	; leaf left
            .byte $FE,$10,$30,$41,$6B,$DA ; leaf right
            .byte $FF

; Level 11
            .byte $C2,$04		; coins left
            .byte $FE,$26,$70,$D1,$DD	; coins right
            .byte $FD,$BA,$02		; spider left
            .byte $FE,$20,$01,$2A,$01,$76,$03 ; spider right
            .byte $FF

; Level 12
            .byte $C0,$16,$E3,$F7	; keys left
            .byte $FE,$95,$CD		; keys right
            .byte $FE,$6C,$BC		; bush right
            .byte $FF

; Level 13
            .byte $C0,$AC,$96		; clock left
            .byte $FE,$93,$99,$29	; clock right
            .byte $FE
            .byte $FF

; Level 14
            .byte $80,$28,$F7		; comb left
            .byte $FE,$62,$A7		; comb right
            .byte $FE
            .byte $FF

; Level 15
            .byte $42,$B6		; money left
            .byte $FE,$82,$9E		; money right
            .byte $FD,$74,$01		; spider left
            .byte $FE,$B4,$06		; spider right
            .byte $FF

; Level 16
            .byte $87,$00,$C7		; blocks left
            .byte $FE,$0A,$D2		; blocks right
            .byte $FD			; pins left
            .byte $FE,$6E,$7E,$8E	; pins right
            .byte $FF

; Level 17
            .byte $C8,$09,$E7		; keys left
            .byte $FE,$2A,$75,$9B	; keys right
            .byte $54,$84,$C4,$F4	; bush left
            .byte $FE,$54,$74		; bush right
            .byte $FD,$26,$8B		; cross left
            .byte $FE,$5A,$97		; cross right
            .byte $FF

; Level 18
            .byte $00,$E1		; key left
            .byte $E1		
            .byte $FE
            .byte $FF

; Level 19
            .byte $C1,$02,$C8		; keys left
            .byte $FE,$D1,$DC,$18	; keys right
            .byte $FE
            .byte $FF

; Level 20
            .byte $C2,$88		; keys left
            .byte $FE,$0D,$28,$41,$DB	; keys right
            .byte $66			; bush left
            .byte $FE,$06,$2E,$4E	; bush right
            .byte $FD,$40,$02		; spider left
            .byte $FE,$B8,$03		; spider right
            .byte $FF

;------------------------------------------------

            .byte $F0,$07,$C9
            .byte $FF
            .byte $F0,$09,$00,$00,$00,$00,$00
            .byte $00

;------------------------------------------------
; HORIZONTAL GUARDS
;------------------------------------------------
;------------------------------------------------
; Level 1, 4x Top hor.guard walking robot
;------------------------------------------------

L7280:      .byte $1F,$39,$19,$0F,$9F,$5F,$FF,$5E
            .byte $20,$E0,$E0,$20,$00,$80,$C0,$00

            .byte $07,$0E,$06,$23,$17,$17,$3F,$17
            .byte $C4,$7C,$7C,$C4,$C0,$E0,$F0,$F0

            .byte $01,$03,$01,$00,$01,$09,$05,$0F
            .byte $F2,$9E,$9E,$F2,$F0,$F8,$FC,$E0

            .byte $00,$00,$00,$00,$00,$00,$03,$00
            .byte $7D,$E7,$67,$3D,$7C,$7F,$FC,$70

;------------------------------------------------
; Level 1, 4x Feet hor.guard walking robot
;------------------------------------------------

            .byte $9F,$1F,$0E,$1F,$BB,$71,$20,$10
            .byte $C0,$80,$00,$00,$80,$E0,$C0,$80

            .byte $17,$27,$03,$03,$06,$06,$1C,$06
            .byte $F0,$E0,$80,$80,$C0,$C0,$38,$60

            .byte $05,$09,$00,$00,$00,$00,$00,$01
            .byte $FC,$F8,$E0,$E0,$E0,$E0,$E0,$F0

            .byte $00,$00,$00,$00,$00,$00,$01,$00
            .byte $7C,$7F,$78,$38,$6C,$6C,$C7,$6C

;------------------------------------------------
; Level 2, 4x Top hor.guard penguin
;------------------------------------------------

            .byte $0C,$1E,$1B,$1E,$39,$32,$3A,$3D
            .byte $00,$00,$00,$C0,$00,$00,$00,$00

            .byte $03,$07,$06,$07,$0E,$0C,$0F,$0D
            .byte $00,$80,$C0,$B0,$40,$80,$80,$C0

            .byte $00,$01,$01,$01,$03,$03,$03,$03
            .byte $C0,$E0,$B0,$EC,$90,$20,$A0,$D0

            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $30,$78,$6C,$7B,$E4,$C8,$E8,$F4

;------------------------------------------------
; Level 2, 4x Feet hor.guard penguin
;------------------------------------------------

            .byte $6D,$69,$69,$61,$71,$BE,$08,$1E
            .byte $00,$00,$00,$00,$00,$00,$00,$00

            .byte $1B,$1B,$16,$18,$1C,$2F,$05,$0F
            .byte $40,$40,$40,$40,$40,$80,$40,$80

            .byte $06,$06,$06,$06,$07,$0B,$02,$07
            .byte $D0,$90,$90,$10,$10,$E8,$50,$E0

            .byte $01,$01,$01,$01,$01,$00,$00,$00
            .byte $B4,$94,$94,$84,$84,$F8,$52,$FC

;------------------------------------------------
; Level 3, 4x Top hor.guard bird
;------------------------------------------------

L7380:      .byte $03,$06,$07,$03,$01,$00,$BE,$E3
            .byte $00,$80,$C0,$00,$80,$C0,$C0,$80

            .byte $00,$01,$01,$00,$00,$00,$2F,$38
            .byte $C0,$A0,$F0,$C0,$60,$30,$B0,$E0

            .byte $00,$00,$00,$00,$00,$00,$0B,$0E
            .byte $30,$68,$7E,$30,$18,$0C,$EC,$38

            .byte $00,$00,$00,$00,$01,$00,$03,$03
            .byte $0C,$1A,$1F,$AC,$56,$A3,$43,$86

;------------------------------------------------
; Level 3, 4x Feet hor.guard bird
;------------------------------------------------

            .byte $40,$AA,$7F,$3F,$04,$04,$04,$0A
            .byte $80,$80,$80,$00,$00,$00,$00,$00

            .byte $18,$30,$15,$0A,$15,$02,$05,$00
            .byte $C0,$C0,$C0,$80,$00,$00,$00,$00

            .byte $04,$0A,$07,$03,$00,$01,$00,$00
            .byte $10,$B0,$F0,$E0,$80,$40,$00,$00

            .byte $01,$03,$01,$00,$00,$00,$00,$00
            .byte $0C,$FC,$FC,$F8,$20,$20,$50,$00

;------------------------------------------------
; Level 4, 4x Top hor.guard seal
;------------------------------------------------

            .byte $07,$0B,$13,$13,$13,$0B,$07,$01
            .byte $00,$80,$C0,$C0,$C0,$80,$00,$00

            .byte $01,$02,$05,$05,$05,$02,$01,$00
            .byte $C0,$E0,$D0,$D0,$D0,$E0,$C0,$40

            .byte $00,$00,$01,$01,$01,$00,$00,$00
            .byte $70,$E8,$E4,$E4,$E4,$E8,$70,$10

            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $1C,$36,$63,$63,$63,$36,$1C,$04

;------------------------------------------------
; Level 4, 4x Bottom hor.guard seal
;------------------------------------------------

            .byte $07,$05,$07,$07,$4F,$5F,$FE,$3C
            .byte $00,$00,$00,$80,$80,$C0,$C0,$40

            .byte $01,$01,$01,$01,$23,$2F,$7F,$1F
            .byte $C0,$40,$C0,$E0,$E0,$F0,$B0,$10

            .byte $00,$00,$00,$00,$21,$27,$7F,$0F
            .byte $70,$50,$70,$F8,$F8,$FC,$EC,$C4

            .byte $00,$00,$00,$00,$08,$08,$1F,$03
            .byte $1C,$14,$1C,$1E,$3E,$FF,$FB,$F1

;------------------------------------------------
; Level 5, 4x Top hor.guard toilet
;------------------------------------------------

L7480:      .byte $C0,$C0,$C0,$C0,$C0,$C0,$C0,$C0
            .byte $00,$00,$00,$00,$00,$00,$00,$00

            .byte $30,$30,$30,$30,$30,$30,$33,$34
            .byte $00,$00,$00,$00,$20,$C0,$00,$00

            .byte $18,$18,$18,$18,$18,$18,$18,$19
            .byte $00,$00,$20,$40,$40,$80,$80,$00

            .byte $03,$03,$03,$03,$03,$03,$03,$03
            .byte $00,$00,$00,$00,$02,$0C,$30,$40

;------------------------------------------------
; Level 5, 4x Bottom hor.guard toilet
;------------------------------------------------

            .byte $DF,$FF,$1F,$0F,$77,$FF,$DF,$DF
            .byte $C0,$C0,$C0,$80,$80,$00,$00,$00

            .byte $37,$3F,$07,$03,$1D,$3F,$37,$37
            .byte $F0,$F0,$F0,$E0,$E0,$C0,$C0,$C0

            .byte $1B,$1F,$03,$01,$0E,$1F,$1B,$1B
            .byte $FC,$FC,$FC,$F8,$F8,$F0,$F0,$F0

            .byte $03,$03,$00,$00,$01,$03,$03,$03
            .byte $7F,$FF,$7F,$3E,$DE,$FC,$7C,$7C

;------------------------------------------------
; Level 6, 4x Top hor.guard pacman
;------------------------------------------------

            .byte $1F,$7F,$73,$F3,$FE,$F8,$FE,$FF
            .byte $00,$C0,$E0,$80,$00,$00,$00,$80

            .byte $07,$1F,$1E,$3E,$3F,$3E,$3F,$3F
            .byte $C0,$F0,$70,$78,$F8,$00,$F8,$F8

            .byte $01,$07,$07,$0F,$0F,$0F,$0F,$0F
            .byte $F0,$FC,$3E,$38,$E0,$80,$E0,$F8

            .byte $00,$01,$01,$03,$03,$03,$03,$03
            .byte $7C,$CF,$CE,$FC,$F0,$E0,$F0,$FC

;------------------------------------------------
; Level 6, 4x Feet hor.guard pacman
;------------------------------------------------

            .byte $7F,$7F,$1F,$0A,$0A,$0A,$0A,$1F
            .byte $E0,$C0,$00,$00,$00,$00,$00,$00

            .byte $1F,$1F,$07,$02,$02,$07,$00,$00
            .byte $F0,$F0,$C0,$80,$80,$C0,$00,$00

            .byte $07,$07,$01,$01,$00,$00,$00,$00
            .byte $FE,$FC,$F0,$F0,$00,$00,$00,$00

            .byte $01,$01,$00,$00,$00,$00,$00,$00
            .byte $FE,$FF,$7C,$28,$28,$7C,$00,$00

;------------------------------------------------
; Level 7, 4x Top hor.guard kangerou
;------------------------------------------------

L7580:      .byte $18,$1C,$0A,$0F,$0C,$1C,$1E,$1D
            .byte $00,$00,$80,$80,$00,$00,$00,$00

            .byte $00,$00,$06,$07,$02,$03,$03,$07
            .byte $00,$00,$00,$00,$A0,$E0,$80,$00

            .byte $00,$00,$00,$00,$01,$01,$00,$00
            .byte $00,$00,$00,$00,$80,$C0,$A8,$F8

            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$60,$70,$2A,$3E,$38,$70

;------------------------------------------------
; Level 7, 4x Feet hor.guard kangerou
;------------------------------------------------

            .byte $3C,$3C,$3E,$3E,$6E,$44,$42,$81
            .byte $00,$00,$00,$00,$00,$00,$00,$00

            .byte $07,$07,$0F,$0F,$0F,$1B,$33,$41
            .byte $80,$40,$00,$80,$80,$80,$00,$C0

            .byte $00,$01,$01,$01,$03,$03,$07,$3E
            .byte $E0,$C0,$E0,$D0,$C0,$E0,$E0,$F8

            .byte $00,$00,$00,$00,$01,$01,$03,$04
            .byte $78,$74,$F0,$F8,$F8,$B0,$0C,$00

;------------------------------------------------
; Level 8, 4x Top hor.guard hot ball
;------------------------------------------------

            .byte $08,$05,$08,$25,$48,$21,$4C,$33
            .byte $00,$00,$80,$00,$80,$00,$00,$00

            .byte $02,$21,$12,$21,$12,$20,$03,$0C
            .byte $00,$20,$40,$20,$40,$20,$00,$C0

            .byte $00,$02,$04,$02,$04,$02,$00,$03
            .byte $40,$20,$48,$24,$48,$04,$C8,$30

            .byte $00,$01,$02,$01,$02,$01,$02,$00
            .byte $44,$22,$44,$22,$44,$02,$30,$CC

;------------------------------------------------
; Level 8, 4x Bottom hor.guard hot ball
;------------------------------------------------

            .byte $44,$44,$88,$84,$48,$48,$33,$0C
            .byte $80,$80,$40,$40,$80,$80,$00,$00

            .byte $10,$10,$22,$25,$18,$10,$0C,$03
            .byte $20,$60,$90,$10,$20,$20,$C0,$00

            .byte $04,$04,$0B,$08,$04,$04,$03,$00
            .byte $08,$08,$44,$B4,$08,$08,$30,$C0

            .byte $01,$01,$02,$02,$01,$01,$00,$00
            .byte $42,$22,$11,$21,$12,$0A,$CC,$30

;------------------------------------------------
; Level 9, 4x Top hor.guard pin car
;------------------------------------------------

L7680:      .byte $0C,$0C,$0C,$0C,$0C,$0C,$0C,$0C
            .byte $00,$00,$00,$00,$00,$00,$00,$00

            .byte $03,$03,$03,$03,$03,$03,$03,$03
            .byte $00,$00,$00,$00,$00,$00,$00,$00

            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $C0,$C0,$C0,$C0,$C0,$C0,$C0,$C0

            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $30,$30,$30,$30,$30,$30,$30,$30

;------------------------------------------------
; Level 9, 4x Bottom hor.guard pin car
;------------------------------------------------

            .byte $0C,$0C,$FF,$0C,$61,$D2,$B3,$61
            .byte $00,$00,$C0,$00,$80,$C0,$40,$80

            .byte $03,$03,$3F,$03,$18,$24,$3C,$18
            .byte $00,$00,$F0,$00,$60,$D0,$D0,$60

            .byte $00,$00,$0F,$00,$06,$0B,$0D,$06
            .byte $C0,$C0,$FC,$C0,$18,$34,$2C,$18

            .byte $00,$00,$03,$00,$01,$02,$03,$01
            .byte $30,$30,$FF,$30,$86,$4D,$CD,$86

;------------------------------------------------
; Level 10, 4x Top hor.guard rabbit
;------------------------------------------------

            .byte $70,$50,$7C,$34,$3E,$3E,$18,$3C
            .byte $00,$00,$00,$00,$00,$00,$00,$00

            .byte $1C,$14,$1F,$0D,$0F,$0F,$06,$0F
            .byte $00,$00,$00,$00,$80,$80,$00,$00

            .byte $07,$05,$07,$03,$03,$03,$01,$03
            .byte $00,$00,$C0,$40,$E0,$E0,$80,$C0

            .byte $01,$01,$01,$00,$00,$00,$00,$00
            .byte $C0,$40,$F0,$D0,$F8,$F8,$60,$F0

;------------------------------------------------
; Level 10, 4x Top hor.guard rabbit
;------------------------------------------------

            .byte $7E,$7E,$F7,$FB,$3C,$76,$6E,$77
            .byte $00,$00,$00,$00,$00,$00,$00,$00

            .byte $1B,$1B,$1B,$1D,$0F,$06,$06,$07
            .byte $80,$80,$80,$80,$00,$00,$00,$00

            .byte $07,$07,$0F,$0F,$03,$07,$06,$07
            .byte $E0,$E0,$70,$B0,$C0,$60,$E0,$70

            .byte $01,$03,$07,$06,$00,$01,$03,$03
            .byte $F8,$FC,$FE,$F6,$F8,$DA,$0E,$84

;------------------------------------------------
; Level 11, 4x Top hor.guard bow car
;------------------------------------------------

L7780:      .byte $0C,$16,$2D,$4C,$8C,$8C,$4C,$2D
            .byte $00,$00,$00,$80,$40,$40,$80,$00

            .byte $03,$03,$05,$07,$0B,$0B,$07,$05
            .byte $00,$00,$80,$80,$40,$40,$80,$80

            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $C0,$C0,$C0,$C0,$80,$80,$C0,$C0

            .byte $00,$00,$00,$00,$01,$01,$00,$00
            .byte $30,$68,$B4,$B4,$32,$32,$B4,$B4
;------------------------------------------------
; Level 11, 4x Bottom hor.guard bow car
;------------------------------------------------

            .byte $16,$0C,$37,$4C,$7F,$7F,$20,$17
            .byte $00,$00,$00,$00,$E0,$E0,$40,$00

            .byte $03,$03,$0E,$03,$3F,$3F,$10,$07
            .byte $00,$00,$C0,$20,$E0,$F0,$20,$40

            .byte $00,$00,$01,$04,$0F,$0F,$00,$03
            .byte $C0,$C0,$D0,$C8,$FC,$F8,$08,$B0

            .byte $00,$00,$00,$01,$03,$01,$01,$00
            .byte $68,$30,$B8,$32,$FF,$FF,$00,$DC

;------------------------------------------------
; Level 12, 4x Top hor.guard stomper
;------------------------------------------------

            .byte $61,$B2,$B3,$61,$0C,$FF,$52,$12
            .byte $80,$40,$C0,$80,$00,$C0,$80,$00

            .byte $18,$24,$3C,$18,$03,$3F,$14,$04
            .byte $60,$D0,$D0,$60,$00,$F0,$A0,$80

            .byte $06,$0D,$0D,$06,$00,$0F,$05,$01
            .byte $18,$3C,$24,$18,$C0,$FC,$28,$20

            .byte $01,$03,$02,$01,$00,$03,$01,$00
            .byte $86,$CB,$4B,$86,$30,$FF,$4A,$48

;------------------------------------------------
; Level 12, 4x Top hor.guard stomper
;------------------------------------------------

            .byte $12,$1E,$0C,$0C,$0C,$0C,$1E,$3F
            .byte $00,$00,$00,$00,$00,$00,$00,$00

            .byte $04,$07,$03,$03,$07,$0F,$00,$00
            .byte $80,$80,$00,$00,$80,$C0,$00,$00

            .byte $01,$01,$01,$03,$00,$00,$00,$00
            .byte $20,$E0,$E0,$F0,$00,$00,$00,$00

            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $48,$78,$30,$30,$78,$FC,$00,$00

;------------------------------------------------
; Level 15, 4x Top hor.guard postcard
;------------------------------------------------

L7880:      .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00

            .byte $00,$00,$00,$00,$00,$00,$3F,$20
            .byte $00,$00,$00,$00,$00,$00,$F0,$70

            .byte $00,$00,$00,$00,$0F,$08,$0F,$08
            .byte $00,$00,$00,$00,$FC,$1C,$FC,$24

            .byte $00,$00,$00,$00,$00,$00,$03,$02
            .byte $00,$00,$00,$00,$00,$00,$FF,$07

;------------------------------------------------
; Level 15, 4x Bottom hor.guard postcard
;------------------------------------------------

            .byte $00,$00,$FF,$81,$FF,$82,$FE,$FF
            .byte $00,$00,$C0,$C0,$C0,$40,$40,$C0

            .byte $3F,$20,$3F,$3F,$00,$00,$00,$00
            .byte $F0,$90,$90,$F0,$00,$00,$00,$00

            .byte $0F,$0F,$00,$00,$00,$00,$00,$00
            .byte $E4,$FC,$00,$00,$00,$00,$00,$00

            .byte $03,$02,$03,$03,$00,$00,$00,$00
            .byte $FF,$09,$F9,$FF,$00,$00,$00,$00

;------------------------------------------------
; Level 16, 4x Top hor.guard flagger
;------------------------------------------------

            .byte $00,$08,$14,$2A,$55,$4A,$84,$80
            .byte $00,$00,$00,$00,$00,$00,$00,$C0

            .byte $2A,$15,$2A,$15,$20,$20,$20,$20
            .byte $00,$00,$00,$00,$00,$00,$00,$18

            .byte $00,$10,$28,$54,$AA,$51,$21,$01
            .byte $00,$00,$00,$00,$00,$00,$00,$0C

            .byte $15,$2A,$15,$2A,$00,$00,$00,$00
            .byte $40,$80,$40,$80,$40,$40,$40,$43

;------------------------------------------------
; Level 16, 4x Bottom hor.guard flagger
;------------------------------------------------

            .byte $80,$41,$7F,$3F,$1F,$0F,$0A,$12
            .byte $C0,$00,$80,$C0,$80,$00,$80,$40

            .byte $20,$10,$1F,$0F,$07,$03,$02,$04
            .byte $18,$20,$F0,$F8,$F0,$E0,$90,$88

            .byte $02,$02,$03,$03,$01,$00,$00,$01
            .byte $0C,$10,$F8,$FC,$F8,$F0,$A8,$24

            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $83,$84,$FE,$FF,$7E,$3C,$2A,$49

;------------------------------------------------
; Level 17, 4x Top hor.guard longleg
;------------------------------------------------

L7980:      .byte $7E,$99,$FF,$DB,$E7,$7E,$24,$24
            .byte $00,$00,$00,$00,$00,$00,$00,$00

            .byte $00,$0F,$13,$1F,$1B,$1C,$0F,$08
            .byte $00,$C0,$20,$E0,$60,$E0,$C0,$40

            .byte $00,$00,$00,$07,$09,$0F,$0D,$0E
            .byte $00,$00,$00,$E0,$90,$F0,$B0,$70

            .byte $00,$01,$02,$03,$03,$03,$01,$01
            .byte $00,$F8,$64,$FC,$6C,$9C,$F8,$08

;------------------------------------------------
; Level 17, 4x Bottom hor.guard longleg
;------------------------------------------------

            .byte $24,$42,$42,$42,$81,$81,$C3,$C3
            .byte $00,$00,$00,$00,$00,$00,$00,$00

            .byte $10,$10,$20,$20,$40,$40,$60,$60
            .byte $20,$20,$10,$10,$08,$18,$18,$00

            .byte $07,$08,$10,$20,$40,$80,$C0,$C0
            .byte $E0,$10,$08,$04,$02,$01,$03,$03

            .byte $02,$02,$04,$04,$08,$0C,$0C,$00
            .byte $04,$04,$02,$02,$01,$01,$03,$03

;------------------------------------------------
; Level 19, 4x Top hor.guard bulldozer
;------------------------------------------------

            .byte $06,$0C,$18,$38,$74,$CA,$85,$03
            .byte $00,$00,$00,$00,$00,$40,$E0,$E0

            .byte $01,$03,$06,$0E,$1D,$32,$21,$00
            .byte $80,$00,$00,$00,$00,$A0,$70,$F0

            .byte $00,$00,$00,$01,$03,$06,$04,$00
            .byte $30,$60,$C0,$C0,$A0,$54,$2E,$1E

            .byte $00,$00,$00,$00,$00,$01,$01,$00
            .byte $0C,$18,$30,$60,$F0,$AA,$17,$0F

;------------------------------------------------
; Level 19, 4x Bottom hor.guard bulldozer
;------------------------------------------------

            .byte $07,$CF,$DC,$FF,$E2,$C8,$D5,$08
            .byte $20,$60,$20,$E0,$00,$80,$40,$80

            .byte $61,$63,$66,$7F,$78,$62,$65,$02
            .byte $90,$B0,$10,$F0,$80,$20,$50,$20

            .byte $30,$30,$30,$3F,$3E,$30,$30,$00
            .byte $32,$76,$C2,$FE,$10,$44,$AA,$44

            .byte $00,$06,$06,$07,$07,$06,$06,$00
            .byte $19,$3B,$41,$FF,$88,$22,$55,$22

;------------------------------------------------
; Level 14, Hor.guard explosion1
;------------------------------------------------

L7A80:      .byte $00,$00,$00,$00,$00,$22,$00,$00
            .byte $00,$00,$88,$11,$00,$00,$22,$00

            .byte $00,$00,$00,$00,$88,$00,$00,$22
            .byte $00,$00,$00,$00,$00,$00,$44,$22

            .byte $00,$11,$99,$66,$CC,$66,$00,$CC
            .byte $77,$DD,$77,$44,$EE,$44,$99,$44

            .byte $11,$22,$88,$00,$00,$00,$88,$44
            .byte $44,$00,$00,$44,$00,$22,$44,$88

;------------------------------------------------
; Level 14, Hor.guard explosion1
;------------------------------------------------

L7AC0:      .byte $00,$00,$00,$00,$00,$00,$11,$00
            .byte $00,$00,$00,$00,$00,$22,$00,$00

            .byte $00,$00,$00,$00,$00,$00,$00,$88
            .byte $00,$00,$00,$00,$00,$00,$00,$00

            .byte $22,$00,$00,$00,$00,$11,$99,$66
            .byte $00,$00,$22,$00,$77,$DD,$77,$44

            .byte $00,$00,$00,$22,$11,$22,$88,$EE
            .byte $00,$00,$44,$22,$44,$00,$00,$00

;------------------------------------------------
; VERTICAL GUARDS
;------------------------------------------------

;------------------------------------------------
; Level 5, Vert.guard puppet with glasses
;------------------------------------------------

L7B00:      .byte $00,$03,$0F,$1F,$31,$0E,$6F,$AE
            .byte $00,$C0,$F0,$F8,$8C,$70,$F6,$75
            .byte $B1,$9F,$9B,$8C,$47,$02,$0E,$00
            .byte $8D,$F9,$D9,$31,$E2,$40,$70,$00

;------------------------------------------------
; End, pillar
;------------------------------------------------

L7B20:      .byte $FF,$72,$8A,$AA,$4A,$12,$22,$2A
            .byte $FF,$4E,$51,$55,$52,$48,$44,$54
            .byte $2A,$2A,$2A,$2A,$2A,$2A,$2A,$FF
            .byte $54,$54,$54,$54,$54,$54,$54,$FF

;------------------------------------------------
; Level 14, Vert.guard explosion2
;------------------------------------------------

            .byte $00,$00,$08,$01,$00,$20,$02,$00
            .byte $00,$00,$00,$00,$80,$00,$04,$22
            .byte $07,$1D,$97,$64,$CE,$64,$09,$C4
            .byte $14,$20,$80,$04,$00,$02,$84,$48

;------------------------------------------------
; Level 14, Vert.guard explosion3
;------------------------------------------------

            .byte $00,$00,$00,$00,$00,$02,$10,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$80
            .byte $20,$00,$02,$00,$07,$1D,$97,$64
            .byte $00,$00,$04,$22,$14,$20,$80,$E0

;------------------------------------------------
; Level 8+12, Monster
;------------------------------------------------

L7B80:      .byte $13,$1D,$0F,$06,$05,$02,$07,$0F
            .byte $C8,$B8,$F0,$60,$A0,$40,$E0,$F0
            .byte $1F,$33,$63,$46,$2C,$06,$02,$0E
            .byte $F8,$CC,$C6,$62,$34,$60,$40,$70

            .byte $0B,$0D,$0F,$06,$05,$02,$03,$1F
            .byte $D0,$B0,$F0,$60,$A0,$40,$C0,$F8
            .byte $7F,$E7,$83,$C7,$06,$0C,$08,$38
            .byte $FE,$E7,$C1,$E3,$60,$30,$10,$1C

            .byte $1C,$06,$0C,$06,$63,$27,$67,$37
            .byte $38,$60,$30,$60,$C6,$E4,$E6,$EC
            .byte $1F,$0F,$02,$05,$06,$0F,$0D,$0B
            .byte $F8,$F0,$40,$A0,$60,$F0,$B0,$D0

            .byte $70,$18,$0C,$06,$63,$27,$67,$37
            .byte $0E,$18,$30,$60,$C6,$E4,$E6,$EC
            .byte $1F,$0F,$02,$05,$16,$0F,$0D,$07
            .byte $F8,$F0,$40,$A0,$68,$F0,$B0,$E0

;------------------------------------------------
; Level 11, Ringing telephone
;------------------------------------------------

L7C00:
            .byte $00,$00,$3F,$63,$EB,$E8,$0F,$07
            .byte $00,$00,$FC,$C6,$D7,$17,$F0,$E0
            .byte $0C,$0B,$1B,$1C,$3F,$3F,$3F,$00
            .byte $30,$D0,$D8,$38,$FC,$FC,$FC,$00

            .byte $3C,$7F,$7F,$63,$08,$08,$0F,$07
            .byte $00,$C0,$F8,$C6,$57,$17,$F7,$E0
            .byte $0C,$0B,$1B,$1C,$3F,$3F,$3F,$00
            .byte $30,$D0,$D8,$38,$FC,$FC,$FC,$00

            .byte $00,$00,$3F,$63,$E8,$E8,$0F,$07
            .byte $00,$00,$FC,$C6,$17,$17,$F0,$E0
            .byte $0C,$0B,$1B,$1C,$3F,$3F,$3F,$00
            .byte $30,$D0,$D8,$38,$FC,$FC,$FC,$00

            .byte $00,$03,$1F,$63,$E8,$E8,$EF,$07
            .byte $3C,$FE,$FE,$C6,$10,$10,$F0,$E0
            .byte $0C,$0B,$1B,$1C,$3F,$3F,$3F,$00
            .byte $30,$D0,$D8,$38,$FC,$FC,$FC,$00

;------------------------------------------------
; Level 13, Vert.guard - Blinking eye
;------------------------------------------------

            .byte $00,$00,$00,$03,$0C,$10,$20,$40
            .byte $00,$00,$00,$C0,$30,$08,$04,$02
            .byte $80,$40,$20,$D0,$2C,$4B,$12,$02
            .byte $01,$02,$04,$0B,$34,$D2,$48,$40

            .byte $00,$00,$00,$03,$0C,$10,$20,$40
            .byte $00,$00,$00,$C0,$30,$08,$04,$02
            .byte $F8,$57,$2B,$12,$0C,$03,$00,$00
            .byte $1F,$EA,$D4,$48,$30,$C0,$00,$00

            .byte $04,$04,$12,$4B,$2C,$93,$A7,$46
            .byte $20,$20,$48,$D2,$34,$C9,$E5,$62
            .byte $86,$47,$23,$10,$0C,$03,$00,$00
            .byte $61,$E2,$C4,$08,$30,$C0,$00,$00

            .byte $00,$00,$00,$03,$0C,$12,$2A,$5F
            .byte $00,$00,$00,$C0,$30,$48,$54,$FA
            .byte $F6,$47,$23,$10,$0C,$03,$00,$00
            .byte $7F,$E2,$C4,$08,$30,$C0,$00,$00

;------------------------------------------------
; Level 14, Falling platform
;------------------------------------------------

L7D00:
            .byte $03,$FF,$AB,$FF,$13,$29,$15,$0B
            .byte $C0,$FF,$D5,$FF,$C8,$94,$A8,$D0
            .byte $05,$03,$03,$05,$0A,$14,$28,$10
            .byte $A0,$C0,$C0,$A0,$50,$28,$14,$08

            .byte $00,$00,$03,$FF,$AB,$FF,$13,$29
            .byte $00,$00,$C0,$FF,$D5,$FF,$C8,$94
            .byte $15,$0B,$05,$03,$23,$45,$0A,$14
            .byte $A8,$D0,$A0,$C0,$C0,$A8,$54,$28

            .byte $00,$00,$00,$00,$03,$FF,$AB,$FF
            .byte $00,$00,$00,$07,$FD,$D7,$F8,$C0
            .byte $03,$01,$15,$4B,$05,$23,$0B,$25
            .byte $C0,$80,$A4,$D2,$A4,$C2,$D0,$A8

            .byte $00,$00,$00,$00,$00,$00,$03,$1F
            .byte $00,$00,$00,$00,$00,$00,$C7,$FD
            .byte $CB,$A7,$E3,$01,$25,$4B,$05,$53
            .byte $D7,$F8,$C0,$82,$A5,$D0,$A2,$C4

;------------------------------------------------
; Level 15, Package with rotating top
;------------------------------------------------

            .byte $61,$9F,$9F,$61,$07,$FF,$80,$AA
            .byte $86,$F9,$F9,$86,$E0,$FF,$01,$A9
            .byte $9F,$B5,$90,$B5,$9F,$AA,$80,$FF
            .byte $FD,$59,$0D,$59,$FD,$A9,$01,$FF

            .byte $1D,$22,$22,$1D,$03,$FF,$D5,$BF
            .byte $B8,$E4,$E4,$B8,$C0,$FF,$55,$FF
            .byte $EA,$B0,$E5,$B0,$EA,$BF,$D5,$FF
            .byte $AD,$07,$4D,$07,$AD,$FF,$55,$FF

            .byte $07,$08,$08,$07,$03,$FF,$FF,$D5
            .byte $E0,$10,$10,$E0,$C0,$FF,$FF,$57
            .byte $E0,$CA,$E7,$CA,$E0,$D5,$FF,$FF
            .byte $03,$A7,$F3,$27,$03,$57,$FF,$FF

            .byte $1D,$2F,$2F,$1D,$03,$FF,$AA,$C0
            .byte $B8,$44,$44,$B8,$C0,$FF,$AB,$01
            .byte $95,$CF,$98,$CF,$95,$C0,$AA,$FF
            .byte $53,$F9,$13,$F9,$53,$01,$AB,$FF

;------------------------------------------------
; Level 17, Rotating triangle
;------------------------------------------------
L7E00:
            .byte $00,$00,$00,$03,$0C,$31,$C6,$99
            .byte $0E,$33,$C5,$19,$65,$9D,$7D,$9D
            .byte $C6,$F1,$7C,$1F,$07,$01,$00,$00
            .byte $1D,$9D,$7D,$1D,$DD,$FD,$7F,$1E

            .byte $03,$07,$06,$0E,$0C,$1D,$19,$3A
            .byte $C0,$40,$20,$A0,$90,$50,$48,$28
            .byte $32,$74,$64,$FF,$FF,$FF,$40,$7F
            .byte $24,$14,$12,$EA,$E9,$F5,$03,$FE

            .byte $38,$FE,$BF,$BB,$B8,$BE,$B9,$B8
            .byte $00,$00,$80,$E0,$F8,$3E,$8F,$63
            .byte $B9,$BE,$B9,$A6,$98,$A3,$CC,$70
            .byte $99,$63,$8C,$30,$C0,$00,$00,$00

            .byte $7F,$80,$AF,$97,$57,$4A,$2A,$25
            .byte $FE,$02,$FF,$FF,$FF,$26,$2E,$4C
            .byte $15,$12,$0A,$09,$05,$04,$02,$03
            .byte $5C,$98,$B8,$30,$70,$60,$E0,$C0

;------------------------------------------------
; Plot beams in level 19
;------------------------------------------------

L7E80:      lda L0080              ; A5 80
            cmp #$13               ; C9 13
            beq L7E87              ; F0 01
            rts                    ; 60

L7E87:      inc L7EED              ; EE ED 7E
            jsr L6B5E              ; 20 5E 6B
            lda L7EED              ; AD ED 7E
            and #$10               ; 29 10
            cmp #$00               ; C9 00
            beq L7EDD              ; F0 47
            lda #$00               ; A9 00
            sta L003F              ; 85 3F
            lda L7EED              ; AD ED 7E
            and #$01               ; 29 01
            cmp #$00               ; C9 00
            beq L7EA7              ; F0 04
            lda #$02               ; A9 02
            sta L003F              ; 85 3F

L7EA7:
;            lda #$11               ; Set texcolour=2
;            jsr OSWRCH             ; 20 EE FF
;            lda #$02               ; A9 02
;            jsr OSWRCH             ; 20 EE FF

            ldx #$00               ; A2 00
L7EB3:      lda L7EEE,X            ; Read XPOS beam
	sec
	sbc #4
	sta XPOS

	inx
	lda L7EEE,x		; Read YPOS beam
	sta YPOS

L7EC5:      lda #$E0               ; A9 E0
            clc                    ; 18
            adc L003F              ; 65 3F
            tay                    ; A8
            iny                    ; C8
            jsr OSWRCH             ; Print character

            lda #$0A               ; Move cursor down 1 pos
            jsr OSWRCH             ; 20 EE FF

            lda #$08               ; Move cursor back 1 pos
            jsr OSWRCH             ; 20 EE FF

            tya                    ; 98
            jsr OSWRCH             ; Print character
	inx
	cpx #8
	bne L7EB3
            jmp L6B5E              ; 4C BA 7E

L7EDD:      lda #$04               ; A9 04
            sta L003F              ; 85 3F
            lda L7EED              ; AD ED 7E
            and #$0F               ; 29 0F
            cmp #$00               ; C9 00
            beq L7EA7              ; F0 BD
            jmp L6B5E              ; 4C 5E 6B

L7EED:      .byte $EA

L7EEE:      .byte $0F,$05
            .byte $0F,$09
            .byte $18,$05
            .byte $18,$09

            .byte $10,$C0

	.repeat ((*/128+1)*128)-*
	   .byte $ff
	.endrep

;------------------------------------------------
; Must be aligned at $80 from L7E80!!!!!
;------------------------------------------------

L7F00:
            .byte $0A,$16,$01,$39,$65,$03
            .byte $FF,$87,$20,$68,$50,$62,$CE,$D0
            .byte $EE,$F1,$77,$C7,$8B,$32,$64,$49
            .byte $12,$36,$F4,$FF,$F1,$AC,$A6,$A2
            .byte $90,$98,$00,$05,$03,$31,$1D,$03
            .byte $3F,$03,$00,$20,$40,$74,$CC,$D0
            .byte $EC,$F4,$3F,$67,$0B,$32,$24,$0B
            .byte $1A,$00,$E0,$FC,$F2,$AC,$A4,$90
            .byte $D8,$C0,$00,$00,$02,$09,$05,$03
            .byte $1F,$07,$00,$00,$20,$60,$C8,$D0
            .byte $E0,$F8,$1F,$17,$0F,$12,$05,$0A
            .byte $00,$00,$E0,$F8,$F0,$A8,$A0,$B0
            .byte $C0,$00,$00,$05,$03,$31,$1D,$03
            .byte $3F,$03,$00,$20,$40,$74,$CC,$D0
            .byte $EC,$F4,$3F,$67,$0B,$32,$24,$0B
            .byte $1A,$00,$E0,$FC,$F2,$AC,$A4,$90
            .byte $D8,$C0,$00,$0C,$02,$01,$07,$6F
            .byte $19,$0A,$00,$30,$40,$80,$E0,$F6
            .byte $98,$50,$F9,$1E,$1C,$7C,$9B,$0C
            .byte $07,$01,$9F,$78,$38,$2E,$D9,$B0
            .byte $E0,$80,$00,$00,$0E,$41,$27,$1F
            .byte $89,$7A,$00,$00,$70,$82,$E4,$F8
            .byte $91,$5E,$19,$1E,$FC,$14,$1F,$0C
            .byte $07,$01,$98,$78,$3F,$28,$D8,$70
            .byte $E0,$80,$00,$0C,$02,$01,$07,$4F
            .byte $3F,$0E,$00,$30,$40,$80,$E0,$F2
            .byte $FC,$70,$D9,$3E,$1C,$74,$9B,$0E
            .byte $07,$01,$9B,$7C,$38,$2E,$FB,$30
            .byte $E0,$80,$04,$04,$02,$01,$07,$0F
            .byte $7F,$0A,$20,$20,$40,$80,$E0,$F0
            .byte $FE,$51,$09,$7E,$9C,$14,$3B,$4D
            .byte $47,$01,$98,$7E,$39,$28,$DC,$32
            .byte $E2,$80
