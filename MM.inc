; User equates
;
OSWRCH      = PRINTCHAR
OSBYTE      = GET_CHR
;
; Code equates
;

debug=0		; Force no live lost and cheatmode on

L0003       = $0003

L003F       = $003F
L0040       = $0040
;L0050       = $0050
;L0053       = $0053

L005A       = $005A

L005B	= $005B
L005C	= $005C

;L0060       = $0060

L0070       = $0070
L0071       = $0071
L0072       = $0072
L0073       = $0073
L0074       = $0074
L0075       = $0075
L0076       = $0076
L0077       = $0077
L0078       = $0078
L0079       = $0079
L007A       = $007A

L0080       = $0080	; Current level
L0081       = $0081
L0082       = $0082
L0083       = $0083
L0084       = $0084
L0085       = $0085
L0086       = $0086
L008A       = $008A
L008B       = $008B
L008C       = $008C
L008D       = $008D
L008E       = $008E
L008F       = $008F
L0090       = $0090

L009F       = $009F

L00EC       = $00EC
L00ED       = $00ED

L0318       = $0318	; Current text cursor X
L0319       = $0319	; Current text cursor Y

L0400       = $0400
L0440       = L0400+$20
L0480       = L0400+$40
L04C0       = L0400+$60

L0FCC       = L0FCB+1
L0FCD       = L0FCB+2

L1933       = L1932+1
L1934       = L1932+2
L1938       = L1937+1
L194F       = L194E+1
L196B       = L196A+1
L196C       = L196A+2
L1AE9       = L1AE8+1
L1B2A       = L1B29+1
L1C6B       = L1C6A+1
L1C6C       = L1C6A+2
L1CC5       = L1CC4+1
L1CC6       = L1CC4+2
L1D97       = L1D96+1
L1D98       = L1D96+2
L1E04       = L1E03+1
L1E05       = L1E03+2
L2278       = L2277+1
L2279       = L2277+2
L2601       = L2600+1
L2602       = L2600+2
L2693       = L2690+3
L2694       = L2690+4
L2695       = L2690+5
L2696       = L2690+6
L283B       = L283A+1
L283C       = L283A+2
L28B3       = L28B2+1
L28B4       = L28B2+2
L2924       = L2923+1
L2925       = L2923+2
L2995       = L2994+1
L2A62       = L2A61+1
L2A63       = L2A61+2
L2C00       = L2BFF+1
L2EED       = L2EEC+1
L2EEE       = L2EEC+2
L2FF8       = L2FF7+1
L2FF9       = L2FF7+2

;L6200       = $6200
;L62C3       = $62C3
;L62E3       = $62E3
;L62E9       = $62E9
;L646D       = $646D
;L673C       = $673C
;L67BA       = $67BA
;L67BE       = $67BE
;L67D6       = $67D6
;L68AC       = $68AC
;L68DF       = $68DF
;L6B7C       = $6B7C
;L6B7F       = $6B7F
;L6B83       = $6B83
;L6BA0       = $6BA0
;L6BDF       = $6BDF
;L6BE0       = $6BE0
;L6BE7       = $6BE7
;L6BE8       = $6BE8
;L6BEF       = $6BEF
;L6BF0       = $6BF0
;L6BF7       = $6BF7
;L6BF8       = $6BF8

;L7B00       = $7B00
;L7E80       = $7E80
;L7EED       = $7EED

LFFFF       = $FFFF

;------------------------------------------------
; Sprites for Manic Miner
;------------------------------------------------

; Miner facing right standing on left pos

L0500:
	.byte $06,$3e,$7c,$34,$3e,$3c,$18,$3c
	.byte $00,$00,$00,$00,$00,$00,$00,$00
	.byte $7e,$7e,$f7,$fb,$3c,$76,$6e,$77
	.byte $00,$00,$00,$00,$00,$00,$00,$00

	.byte $00,$00,$00,$00,$00,$00,$00,$00
	.byte $00,$00,$00,$00,$00,$00,$00,$00
	.byte $00,$00,$00,$00,$00,$00,$00,$00
	.byte $00,$00,$00,$00,$00,$00,$00,$00

; Miner facing right resting

L0540:
	.byte $01,$0f,$1f,$0d,$0f,$0f,$06,$0f
	.byte $80,$80,$00,$00,$80,$00,$00,$00
	.byte $1b,$1b,$1b,$1d,$0f,$06,$06,$07
	.byte $80,$80,$80,$80,$00,$00,$00,$00

	.byte $00,$00,$00,$00,$00,$00,$00,$00
	.byte $00,$00,$00,$00,$00,$00,$00,$00
	.byte $00,$00,$00,$00,$00,$00,$00,$00
	.byte $00,$00,$00,$00,$00,$00,$00,$00

; Miner facing right standing

L0580:
	.byte $00,$03,$07,$03,$03,$03,$01,$03
	.byte $60,$e0,$c0,$40,$e0,$c0,$80,$c0
	.byte $07,$07,$0f,$0f,$03,$07,$06,$07
	.byte $e0,$e0,$70,$b0,$c0,$60,$e0,$70

	.byte $00,$00,$00,$00,$00,$00,$00,$00
	.byte $00,$00,$00,$00,$00,$00,$00,$00
	.byte $00,$00,$00,$00,$00,$00,$00,$00
	.byte $00,$00,$00,$00,$00,$00,$00,$00

; Miner facing right walking

L05C0:
	.byte $00,$00,$01,$00,$00,$00,$00,$00
	.byte $18,$f8,$f0,$d0,$f8,$f0,$60,$f0
	.byte $01,$03,$07,$06,$00,$01,$03,$03
	.byte $f8,$fc,$fe,$f6,$f8,$da,$0e,$84

	.byte $00,$00,$00,$00,$00,$00,$00,$00
	.byte $00,$00,$00,$00,$00,$00,$00,$00
	.byte $00,$00,$00,$00,$00,$00,$00,$00
	.byte $00,$00,$00,$00,$00,$00,$00,$00

; Miner facing left standing on right pos

L0600:
	.byte $00,$00,$00,$00,$00,$00,$00,$00
	.byte $60,$7C,$3E,$2C,$7C,$3C,$18,$3C
	.byte $00,$00,$00,$00,$00,$00,$00,$00
	.byte $7E,$7E,$EF,$DF,$3C,$6E,$76,$EE

	.byte $00,$00,$00,$00,$00,$00,$00,$00
	.byte $00,$00,$00,$00,$00,$00,$00,$00
	.byte $00,$00,$00,$00,$00,$00,$00,$00
	.byte $00,$00,$00,$00,$00,$00,$00,$00

; Miner facing left resting

L0640:
	.byte $01,$01,$00,$00,$01,$00,$00,$00
	.byte $80,$f0,$f8,$b0,$f0,$f0,$60,$f0
	.byte $01,$01,$01,$01,$00,$00,$00,$00
	.byte $d8,$d8,$d8,$b8,$f0,$60,$60,$e0

	.byte $00,$00,$00,$00,$00,$00,$00,$00
	.byte $00,$00,$00,$00,$00,$00,$00,$00
	.byte $00,$00,$00,$00,$00,$00,$00,$00
	.byte $00,$00,$00,$00,$00,$00,$00,$00

; Miner facing left standing

L0680:
	.byte $06,$07,$03,$02,$07,$03,$01,$03
	.byte $00,$c0,$e0,$c0,$c0,$c0,$80,$c0
	.byte $07,$07,$0e,$0d,$03,$06,$07,$0e
	.byte $e0,$e0,$f0,$f0,$c0,$e0,$60,$e0

	.byte $00,$00,$00,$00,$00,$00,$00,$00
	.byte $00,$00,$00,$00,$00,$00,$00,$00
	.byte $00,$00,$00,$00,$00,$00,$00,$00
	.byte $00,$00,$00,$00,$00,$00,$00,$00

; Miner facing left walking

L06C0:
	.byte $18,$1f,$0f,$0b,$1f,$0f,$06,$0f
	.byte $00,$00,$80,$00,$00,$00,$00,$00
	.byte $1f,$3f,$7f,$6f,$1f,$5b,$70,$21
	.byte $80,$c0,$e0,$60,$00,$80,$c0,$c0

	.byte $00,$00,$00,$00,$00,$00,$00,$00
	.byte $00,$00,$00,$00,$00,$00,$00,$00
	.byte $00,$00,$00,$00,$00,$00,$00,$00
	.byte $00,$00,$00,$00,$00,$00,$00,$00

;------------------------------------------------
; Manic Miner (c) text intro screen
;------------------------------------------------

L0700:      .byte $00,$00,$00,$03,$04,$04,$04,$03
            .byte $07,$03,$06,$0C,$98,$30,$60,$C0
            .byte $8E,$9C,$BC,$EC,$CC,$0C,$0C,$1E
            .byte $00,$0E,$1B,$31,$31,$7F,$60,$F1
            .byte $00,$0E,$07,$87,$86,$C6,$C6,$EF
            .byte $00,$3D,$18,$98,$D8,$78,$38,$19
            .byte $00,$E1,$C3,$C6,$C6,$C6,$C3,$E1
            .byte $00,$F0,$18,$00,$00,$00,$18,$F0
            .byte $00,$01,$01,$00,$00,$00,$00,$00
            .byte $FE,$0F,$2D,$CC,$0C,$0C,$0C,$1E
            .byte $1E,$3C,$EC,$CC,$0C,$0C,$0C,$1E
            .byte $00,$F7,$63,$63,$63,$63,$63,$F7
            .byte $00,$1E,$8C,$CC,$6C,$3C,$1C,$8C
            .byte $00,$FF,$63,$68,$78,$68,$63,$FF
            .byte $00,$7F,$30,$30,$3F,$31,$30,$78
            .byte $00,$80,$C0,$C0,$80,$80,$C8,$70
            .byte $3C,$42,$99,$A1,$A1,$99,$42,$3C
            .byte $00,$00,$00,$00,$00,$00,$00,$00

;------------------------------------------------
; Plot logo data intro screen
;------------------------------------------------

L0790:      .byte $FE,$01,$04,$19,$A0,$05,$7D,$75
            .byte $55,$19,$AD,$55,$70,$87,$04,$7D
            .byte $75,$05,$70,$87,$55,$7D,$C6,$55
            .byte $70,$C0,$FE,$02,$04,$7D,$75,$05
            .byte $89,$81,$55,$7D,$C6,$55,$89,$D9
            .byte $04,$89,$D9,$05,$7D,$C6,$55,$38
            .byte $AD,$55,$44,$A7,$FE,$03,$04,$70
            .byte $BF,$05,$70,$94,$05,$44,$A7,$05
            .byte $7D,$C6,$05,$7D,$75,$05,$19,$A0
            .byte $05,$19,$AD,$05,$7D,$E5,$05,$89
            .byte $D9,$05,$89,$81,$05,$7D,$75,$04
            .byte $89,$D9,$05,$38,$AD,$05,$70,$94
            .byte $05,$70,$87,$05,$19,$AD,$FF,$A9
            .byte $FF,$8D,$7C,$6B,$4C,$E8,$1C,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00

;------------------------------------------------
L0800:
            .byte $C0,$C0,$C0,$C0,$04,$04,$04,$04
            .byte $00,$64,$00,$00,$00,$00,$00,$00
            .byte $00,$1F,$00,$00,$00,$00,$00,$00
            .byte $00,$05,$00,$00,$00,$30,$00,$00
            .byte $00,$01,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$8A,$00,$00
            .byte $FF,$FD,$C1,$00,$00,$F0,$00,$0E
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $01,$01,$00,$64,$01,$08,$64,$01
            .byte $10,$64,$01,$18,$64,$01,$00,$F8
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $01,$78,$00,$00,$1E,$00,$00,$7E
            .byte $FF,$00,$FF,$7E,$5A,$00,$00,$00
            .byte $01,$00,$00,$00,$01,$01,$01,$7F
            .byte $FF,$FF,$FE,$7E,$01,$00,$00,$00
            .byte $05,$10,$00,$00,$07,$00,$00,$20
            .byte $F6,$FE,$FE,$7E,$64,$00,$00,$00
            .byte $01,$02,$00,$00,$64,$00,$00,$7E
            .byte $00,$00,$FE,$7E,$7E,$00,$00,$00

;------------------------------------------------
; Characters block 1
;------------------------------------------------

L0900:      .byte $07,$0F,$09,$09,$0F,$05,$06,$03
            .byte $E0,$F0,$90,$90,$F0,$A0,$60,$C0
            .byte $71,$F8,$FE,$0D,$73,$FF,$FE,$7C
            .byte $BE,$7F,$FF,$CE,$B0,$7F,$1F,$0E
            .byte $FF,$80,$BF,$BF,$B7,$95,$A3,$80
            .byte $FF,$01,$FD,$FD,$FD,$FD,$FD,$C5
            .byte $A3,$95,$B7,$BF,$BF,$BF,$80,$FF
            .byte $B9,$FD,$FD,$FD,$FD,$FD,$01,$FF
            .byte $FF,$44,$99,$22,$22,$99,$44,$44
            .byte $FF,$44,$99,$22,$22,$99,$44,$44
            .byte $99,$22,$22,$99,$44,$44,$99,$FF
            .byte $99,$22,$22,$99,$44,$44,$99,$FF
            .byte $FF,$88,$AA,$AA,$88,$DD,$D1,$D5
            .byte $FF,$9F,$B1,$B5,$85,$39,$7D,$55
            .byte $D5,$D1,$DD,$8D,$A8,$AA,$88,$FF
            .byte $45,$7D,$BB,$83,$AB,$AB,$89,$FF
L0980:      .byte $FF,$99,$BB,$FF,$FF,$99,$BB,$FF
            .byte $88,$44,$22,$11,$88,$44,$22,$11
            .byte $FF,$81,$81,$81,$81,$81,$81,$FF
L0998:      .byte $FF,$92,$92,$92,$92,$92,$92,$92
            .byte $92,$92,$92,$92,$92,$92,$92,$FF
            .byte $FF,$81,$81,$81,$8F,$8F,$8C,$FC
            .byte $FC,$8C,$8F,$8F,$81,$81,$81,$FF
            .byte $FF,$80,$80,$C0,$A0,$D0,$A8,$94
            .byte $8A,$C5,$A2,$91,$89,$92,$A4,$FF
            .byte $FF,$81,$82,$84,$88,$90,$A1,$C3
            .byte $C3,$A1,$90,$88,$84,$82,$81,$FF
            .byte $FF,$80,$80,$8F,$8F,$8F,$8C,$8C
            .byte $8C,$8C,$8F,$8F,$8F,$80,$80,$FF
            .byte $FF,$80,$80,$80,$87,$88,$90,$91
            .byte $91,$90,$88,$87,$80,$80,$80,$FF
            .byte $FF,$80,$80,$FF,$FF,$80,$80,$FF

;------------------------------------------------
; Characters block 2
;------------------------------------------------

	.repeat 256
	  .byte 00
	.endrep

L0A00:      .byte $FF,$80,$80,$FF,$FF,$80,$80,$FF
            .byte $FF,$80,$BF,$A0,$AF,$A8,$AB,$AA
            .byte $AA,$AA,$AA,$AA,$AA,$AA,$AA,$FF
            .byte $FF,$80,$80,$9F,$90,$96,$96,$96
            .byte $96,$96,$96,$90,$9F,$80,$80,$FF
            .byte $FF,$80,$BF,$A0,$AF,$A8,$AB,$AA
            .byte $AA,$AB,$A8,$AF,$A0,$BF,$80,$FF
            .byte $0F,$1F,$3F,$3C,$38,$38,$38,$38
            .byte $38,$1C,$0E,$0E,$CE,$FE,$FC,$00
            .byte $38,$1C,$0E,$0E,$CE,$FE,$FC,$00
            .byte $1C,$38,$70,$70,$73,$7F,$3F,$00
L0A58:      .byte $44,$28,$54,$31,$95,$76,$18,$10
L0A60:      .byte $7E,$3C,$1C,$18,$18,$08,$08,$00
            .byte $FF,$FE,$7E,$4C,$4C,$08,$08,$00
            .byte $08,$6B,$1C,$6B,$1C,$22,$63,$14
            .byte $63,$14,$1C,$6B,$1C,$22,$63,$14
            .byte $3C,$18,$BD,$E7,$E7,$BD,$18,$3C
            .byte $AA,$44,$38,$D6,$38,$7C,$AA,$28
            .byte $48,$AA,$5D,$0A,$78,$AE,$A9,$47
            .byte $44,$44,$44,$44,$66,$EE,$EE,$FF
            .byte $C3,$66,$3C,$24,$24,$3C,$66,$C3
            .byte $08,$08,$08,$08,$08,$08,$08,$08
L0AB0:      .byte $30,$48,$88,$90,$68,$04,$0A,$04
            .byte $50,$A8,$54,$A8,$58,$24,$02,$01
            .byte $1F,$23,$47,$FF,$8F,$8E,$8C,$F8
            .byte $C0,$EC,$72,$28,$54,$4A,$07,$00
            .byte $08,$08,$7E,$BF,$9F,$8F,$C3,$7E
            .byte $18,$66,$42,$D9,$C9,$62,$7E,$18
            .byte $3C,$5A,$95,$D5,$D5,$D5,$5A,$3C
            .byte $AA,$AA,$FE,$FE,$FE,$FE,$AA,$AA
            .byte $7E,$3C,$66,$DF,$8F,$DF,$83,$7E
            .byte $0F,$09,$3F,$24,$FC,$90,$F0,$00

;------------------------------------------------
; Characters block 3
;------------------------------------------------

L0B00:      .byte $FF,$FF,$DB,$2E,$C5,$20,$00,$00
            .byte $FF,$FF,$66,$99,$66,$99,$FF,$00
L0B10:      .byte $FF,$FF,$99,$99,$FF,$99,$66,$00
            .byte $3C,$FF,$EF,$DF,$1C,$08,$08,$08
            .byte $FF,$FF,$EA,$95,$4A,$A5,$50,$87
            .byte $FF,$FF,$11,$22,$44,$88,$FF,$FF
            .byte $FF,$FF,$62,$64,$68,$70,$60,$60
            .byte $FF,$FF,$46,$26,$16,$0E,$06,$06
L0B40:      .byte $22,$FF,$88,$FF,$22,$FF,$88,$FF
            .byte $81,$C3,$A5,$99,$99,$A5,$C3,$81
            .byte $FE,$7D,$3B,$17,$1F,$27,$43,$81
            .byte $DB,$DB,$DB,$DB,$B4,$BB,$DB,$DB
            .byte $FF,$81,$81,$FF,$FF,$81,$81,$FF
            .byte $FF,$99,$BB,$FF,$FF,$99,$BB,$FF
            .byte $FF,$A5,$A5,$A5,$A5,$A5,$A5,$FF
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
L0B80:      .byte $FF,$DB,$24,$54,$22,$00,$00,$00
L0B88:      .byte $FF,$FF,$33,$CC,$21,$0C,$E5,$00
            .byte $3C,$FF,$F7,$0C,$18,$10,$10,$10
            .byte $FF,$88,$22,$88,$22,$88,$22,$88
L0BA0:      .byte $FE,$66,$FE,$00,$00,$00,$00,$00
            .byte $FB,$66,$BF,$00,$00,$00,$00,$00
            .byte $EF,$66,$EF,$00,$00,$00,$00,$00
            .byte $BF,$66,$FB,$00,$00,$00,$00,$00
L0BC0:      .byte $C3,$66,$18,$66,$00,$99,$FF,$00
            .byte $0F,$66,$0F,$66,$00,$99,$FF,$00
            .byte $3C,$66,$81,$66,$00,$99,$FF,$00
            .byte $F0,$66,$F0,$66,$00,$99,$FF,$00
            .byte $C3,$66,$18,$66,$00,$00,$00,$00
            .byte $0F,$66,$0F,$66,$00,$00,$00,$00
            .byte $3C,$66,$81,$66,$00,$00,$00,$00
            .byte $F0,$66,$F0,$66,$00,$00,$00,$00

;------------------------------------------------
; Characters block 4
;------------------------------------------------

L0C00:      .byte $55,$55,$55,$55,$55,$55,$55,$55
L0C08:      .byte $55,$2B,$2B,$2B,$2B,$2B,$2B,$55
L0C10:      .byte $AA,$D4,$D4,$D4,$D4,$D4,$D4,$AA
L0C18:      .byte $00,$FF,$88,$22,$88,$22,$88,$22
            .byte $00,$00,$FF,$88,$22,$88,$22,$88
            .byte $00,$00,$00,$FF,$88,$22,$88,$22
            .byte $00,$00,$00,$00,$FF,$88,$22,$88
            .byte $00,$00,$00,$00,$00,$FF,$88,$22
            .byte $00,$00,$00,$00,$00,$00,$FF,$88
            .byte $00,$00,$00,$00,$00,$00,$00,$FF
            .byte $00,$00,$00,$00,$00,$00,$00,$00
L0C58:      .byte $C3,$66,$18,$66,$00,$00,$00,$00
            .byte $0F,$66,$0F,$66,$00,$00,$00,$00
            .byte $3C,$66,$81,$66,$00,$00,$00,$00
            .byte $F0,$66,$F0,$66,$00,$00,$00,$00
L0C78:      .byte $22,$FF,$88,$FF,$22,$FF,$88,$FF
L0C80:      .byte $30,$48,$88,$90,$68,$04,$0A,$04
L0C88:      .byte $FF,$81,$81,$81,$81,$81,$81,$FF
L0C90:      .byte $FF,$81,$81,$81,$81,$81,$81,$FF
L0C98:      .byte $FF,$81,$81,$81,$81,$81,$81,$FF
L0CA0:      .byte $FF,$81,$81,$81,$81,$81,$81,$FF
            .byte $FF,$81,$81,$81,$81,$81,$81,$81
            .byte $FF,$FF,$18,$18,$18,$18,$18,$18
L0CB8:      .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $FE,$82,$82,$44,$38,$20,$C0,$C0
            .byte $FE,$82,$82,$44,$38,$08,$06,$06
L0CD0:      .byte $00,$00,$00,$00,$00,$00,$00,$00
L0CD8:      .byte $00,$00,$00,$00,$00,$00,$00,$00
L0CE0:      .byte $00,$00,$00,$00,$00,$00,$00,$00
L0CE8:      .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $08,$08,$08,$08,$08,$08,$08,$08
            .byte $00,$00,$00,$00,$00,$00,$00,$00

;------------------------------------------------

L0D00:      .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00

;------------------------------------------------
; Shoe sprite
;------------------------------------------------

L0D40:
	.byte $35,$2a,$35,$2a,$3f,$09,$09,$1f
	.byte $40,$c0,$40,$c0,$c0,$00,$00,$80
	.byte $10,$11,$22,$20,$59,$44,$44,$ff
	.byte $80,$80,$40,$b8,$24,$42,$02,$ff

	.byte $00,$00,$00,$00,$00,$00,$00,$00
	.byte $00,$00,$00,$00,$00,$00,$00,$00
	.byte $00,$00,$00,$00,$00,$00,$00,$00
	.byte $00,$00,$00,$00,$00,$00,$00,$00

;------------------------------------------------

L0D80:      .byte $00
L0D81:      .byte $00,$00
L0D83:      .byte $00
L0D84:      .byte $00,$00,$00
L0D87:      .byte $00,$00,$00,$00,$00
            .byte $00,$00,$00,$00
L0D90:      .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00

;------------------------------------------------
;------------------------------------------------

L0E00:      .byte "MANICMINLOAD   $!BOO"
            .byte "T  $Miner1 $Miner2 $"
            .byte "Miner3 $"
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00

;------------------------------------------------
; Plot sprite routine
;
; A = Plotmode (2,3,4,5 or 10)
; X = X-coordinate miner
; Y = Y-coordinate miner
;
; $70 = Plotmode
; $71 = X DIV 2
; $72 = Y DIV 8
; $73 = X MOD 2
; $74 = Y MOD 8
; $75/$76 = Screenaddress
; $77/$78 = Sprite address
;------------------------------------------------

L0F00:      sta L0070              ; 85 70
            stx L0071              ; 86 71
            sty L0072              ; 84 72

; Select character x-position in pixels, X MOD 8

            txa                    ; 8A
            and #$07               ; 29 03
            sta L0073              ; 85 73

; Select character y-position in pixels, Y MOD 8

            tya                    ; 98
            and #$07               ; 29 07
            sta L0074              ; 85 74

; Select character x-position in bytes, (X DIV 4) - 4

            txa                    ; 8A
            and #$FC               ; 29 FC
            clc                    ; 18
            ror A                  ; 6A
	ror a
	sec
	sbc #4
            sta L0071              ; 85 71

; Select character x-position in bytes, Y DIV 8

            tya                    ; 98
            and #$F8               ; 29 F8
            clc                    ; 18
            ror A                  ; 6A
            ror A                  ; 6A
            ror A                  ; 6A
            sta L0072              ; 85 72

; Select sprite routine according to spritenr

            lda L0070              ; A5 70
            cmp #$0A               ; C9 0A
            beq L0F43              ; Plotmode = 10

            cmp #$02               ; C9 02
            beq L0F77              ; Plotmode = 2

            cmp #$03               ; C9 03
            beq L0F50              ; Plotmode = 3

            cmp #$04               ; C9 04
            beq L0F5D              ; Plotmode = 4

            cmp #$05               ; C9 05
            beq L0F6A              ; Plotmode = 5

; Entry for other sprites

            lda #<L101B               ; A9 1B
            sta L0FCC              ; 8D CC 0F
            lda #>L101B               ; A9 10
            sta L0FCD              ; 8D CD 0F
            jmp L0F81              ; 4C 81 0F

; Entry for Plotmode = 10

L0F43:      lda #<L1026               ; A9 26
            sta L0FCC              ; 8D CC 0F
            lda #>L1026               ; A9 10
            sta L0FCD              ; 8D CD 0F
            jmp L0F81              ; 4C 81 0F

; Entry for Plotmode = 3

L0F50:      lda #<L102D               ; A9 2D
            sta L0FCC              ; 8D CC 0F
            lda #>L102D               ; A9 10
            sta L0FCD              ; 8D CD 0F
            jmp L0F81              ; 4C 81 0F

; Entry for Plotmode = 4

L0F5D:      lda #<L1033               ; A9 33
            sta L0FCC              ; 8D CC 0F
            lda #>L1033               ; A9 10
            sta L0FCD              ; 8D CD 0F
            jmp L0F81              ; 4C 81 0F

; Entry for Plotmode = 5

L0F6A:      lda #<L103A               ; A9 3A
            sta L0FCC              ; 8D CC 0F
            lda #>L103A               ; A9 10
            sta L0FCD              ; 8D CD 0F
            jmp L0F81              ; 4C 81 0F

; Entry for Plotmode = 2

L0F77:      lda #<L1023               ; A9 23
            sta L0FCC              ; 8D CC 0F
            lda #>L1023               ; A9 10
            sta L0FCD              ; 8D CD 0F

; Continue sprite routine

L0F81:      lda #<$8000               ; Top screen address
            sta L0075              ; 85 75
            lda #>$8000               ; A9 30
            sta L0076              ; 85 76

; Calculate screenaddress

            lda #$00               ; A9 00
            sta L184F              ; 8D 4F 18

	ldx L0074		; Determine lb screen address
	lda scrtab,x
	clc
	adc L0071
	sta L0075

	lda L0072
	adc #$80
	sta L0076

; Plot sprite

L0FC9:
	ldx #$00
L0FCA:
	ldy scrtab,x
L0FCB:
	jsr LFFFF		; Adjustable code
	sta (L0075),Y		; Put data on screen

	inx
	cpx #32
	beq L0FE9
	cpx #16
	bne L0FCA

	inc L0076		; Screen 8 lines down

	jmp L0FCA

L0FE9:
            lda L0079              ; ????
            clc                    ; 18
            adc #01               ; 69 01
            sta L0079              ; 85 79
            lda L007A              ; A5 7A
            adc #$00               ; 69 00
            sta L007A              ; 85 7A

	jmp L105E

scrtab:
		.byte $00,$20,$40,$60,$80,$a0,$c0,$e0
		.byte $01,$21,$41,$61,$81,$a1,$c1,$e1
		.byte $00,$20,$40,$60,$80,$a0,$c0,$e0
		.byte $01,$21,$41,$61,$81,$a1,$c1,$e1

tmp_y:		.byte 0

; Calculate data to put on screen for other sprites

L101B:
	sty tmp_y
	txa
	tay
            lda (L0077),y          ; B1 77
            and L109B              ; Colour mask
	ldy tmp_y
;	eor (L0075),Y          ; 11 75
            ora (L0075),Y          ; 11 75
            rts                    ; 60

; Calculate data to put on screen for spritenr = 2

L1023:      lda #$00               ; A9 00
            rts                    ; 60

; Calculate data to put on screen for spritenr = 10

L1026:
	sty tmp_y
	txa
	tay
            lda (L0077),y          ; B1 77
;            and #$F0               ; 29 F0
	ldy tmp_y
            eor (L0075),Y          ; 51 75
            rts                    ; 60

; Calculate data to put on screen for spritenr = 3

L102D:
	sty tmp_y
	txa
	tay
            lda (L0077),y          ; B1 77
            and L109B              ; Colour mask
	ldy tmp_y
            rts                    ; 60

; Calculate data to put on screen for spritenr = 4

L1033:      lda (L0075),Y          ; B1 75
            cmp #$FF               ; C9 FF
            bne L102D              ; D0 F4
            rts                    ; 60

; Calculate data to put on screen for spritenr = 5

L103A:      lda (L0075),Y          ; B1 75
            cmp #$FF               ; C9 FF
            bne L1023              ; D0 E3
            rts                    ; 60

L105E:      rts                    ; 60

L105F:      .byte $EA

;--------------------------------------------
; Sinking floor
;
; Copy second last byte to last byte, 6 times
; Wipe top byte
;--------------------------------------------

L1074:
	lda YPOS
	clc
	adc #$80
	sta L0076
	sec
	sbc #($8000-buffer)/256
	sta L005C

	lda L0075
	sta L005B

	lda #0
	sta floorchk

	ldx #$06		; Set pointer
L1076:
	ldy scrtab,x
	lda (L0075),Y		; Load second last byte
	inx
	ldy scrtab,x
	sta (L0075),Y		; Store last byte
	sta (L005B),y

	ora floorchk
	sta floorchk

	dex
	dex
	bpl L1076		; Repeat 6x

	lda #$00		; Load blank
	ldy #$00
	sta (L0075),Y		; Clear top byte
	sta (L005B),y

	lda floorchk
	bne L109A

	jsr calc_mapaddress	; Wipe tile in charmap

	ldy #0
	lda #$20
	sta (SCR),y

L109A:	
	rts

L109B:	.byte $FF		; Colour mask

floorchk:
	.byte $00

;--------------------------------------------
; Check floors under miner for sinking floor
; or conveyor
;--------------------------------------------

L109C:
	lda #$FF               ; A9 FF
	sta L109B              ; Colour mask

	lda #$00               ; A9 00
	sta L183E              ; Delta X old
	sta L1848              ; Start walking on conveyor

	lda L184B              ; Miner jump flag
	cmp #$00               ; C9 00
	beq L10B3              ; Jump if miner not jumping

	jmp L1634              ; Miner is jumping

;--------------------------------------------
; Miner not jumping
; Check if tiles under miner are sinking floor
;--------------------------------------------

; Restore data-/screen addresses

L10B3:      ldx #$00               ; A2 00
L10B5:      lda L1842,X            ; BD 42 18
            sta L0077,X            ; 95 77
            inx                    ; E8
            cpx #$05               ; E0 05
            bne L10B5              ; D0 F6

; CHECK IF FLOOR UNDER MINER IS SINKING FLOOR
; Check floor tiles for sinking floor under miner

	lda L183A              ; X-coordinaat Miner in pixels old
	lsr A                  ; 4A
	lsr A                  ; 4A
	sec
	sbc #4
	sta XPOS

	lda L183B              ; Y-coordinaat Miner in pixels old
	lsr A                  ; 4A
	lsr A                  ; 4A
	lsr A                  ; 4A
	clc                    ; 18
	adc #$02               ; 69 02
	sta YPOS

	jsr L14A7		; Get left+right bottom tile under miner

; Check if miner jumping/falling

            lda L183B              ; Y-coordinaat Miner in pixels old
            and #$07               ; 29 07
            cmp #$00               ; C9 00
            bne L115D              ; Jump if jumping/falling

	inc L0076		; Adjust screen pointer

; Check if lower left tile under miner is sinking floor

            lda L1849              ; Char at current left position
            jsr L15C8              ; Check hit sinking floor
            cmp #$01               ; C9 01
            beq L1131              ; Sink tile
L10FB:
	inc L0075		; Point to right lower tile

            lda L184A              ; AD 4A 18
            jsr L15C8              ; Check hit sinking floor
            cmp #$01               ; C9 01
            bne L1150              ; Check lower right tile

; Tile is sinking floor

            jsr L1074              ; Sink lower left tile
            jmp L1150              ; Check lower right tile

L1131:
            jsr L1074              ; Sink tile
            jmp L10FB              ; Check lower right tile

; Check if lower right tile under miner is sinking floor

; CHECK IF FLOOR IS CONVEYOR

L1150:
	dec L0075		; Adjust screenpointer
;	inc L0076

; Check if lower left tile under miner is conveyor

L115D:      lda L1849              ; Char at current position
            jsr L15DA              ; Check hit conveyor
            cmp #$00               ; C9 00
            bne L1176              ; Yes, set conveyor flag

; Check if lower right tile under miner is conveyor

            lda L184A              ; AD 4A 18
            jsr L15DA              ; Check hit conveyor
            cmp #$00               ; C9 00
            bne L1176              ; Yes, set conveyor flag

; No conveyor, clear conveyor flag

            lda #$00               ; A9 00
            sta L1852              ; Move on conveyor flag

; Yes conveyor, set conveyor flag

L1176:      lda L1852              ; Move on conveyor flag
            cmp #$01               ; C9 01
            bne L1187              ; If conveyor flag already set, jump

            lda L1853              ; Direction movement on conveyor
            cmp #$00               ; C9 00
            bne L1187              ; D0 03
            jmp L1238              ; 4C 38 12

; Check if miner is landed

L1187:
            lda L183B              ; Y-coordinaat Miner in pixels old
            and #$07               ; 29 07
            cmp #$00               ; C9 00
            beq L119C              ; Miner is landed

; Miner is falling

L1190:
            lda L183D              ; Y-coordinaat Miner in pixels new
            clc                    ; 18
            adc #$02               ; 69 02
            sta L183D              ; Y-coordinaat Miner in pixels new
            jmp L1375              ; Miner if falling, jump

; Miner is not falling

L119C:      lda L1849              ; Char at current position
            jsr L15AC              ; Check hit solid floor
            cmp #$01               ; C9 01
            beq L11B8              ; F0 12

            lda L184A              ; AD 4A 18
            jsr L15AC              ; Check hit solid floor
            cmp #$01               ; C9 01
            beq L11B8              ; F0 08

            lda #$01               ; A9 01
            sta L1847              ; 8D 47 18
            jmp L1190              ; 4C 90 11

L11B8:      lda #$00               ; A9 00
            sta L1841              ; Direction change

; READ KEYS
; Check for Z-key

;	jsr $fe71		; Read key
;	cpy #$3a
	ldx #0
	jsr readkey
	beq L11FC		; Skip if Z key not pressed

; Z key pressed

	lda L183F		; Miner sprite nr        
	cmp #$03
	bne L11E2		; Jump if miner was facing right

	lda #$FF		; Set direction left
	sta L183E		; Delta X old

	lda L183C		; X-coordinaat Miner in pixels new
	sec
	sbc #$01		; Decrement X-pos miner
	sta L183C		; X-coordinaat Miner in pixels new
	jmp L1238		; Jump check conveyor tiles

L11E2:      lda #$03               ; A9 03
            sta L183F              ; Miner sprite nr
            lda #$06               ; A9 06
            sta L1840              ; Direction
            lda #$01               ; A9 01
            sta L1841              ; Direction change

            jsr L1375              ; 20 75 13

            lda #$00               ; A9 00
            sta L183E              ; Delta X old

            jmp L1238              ; Jump check conveyor tiles

; Check for X-key

L11FC:
;	jsr $fe71		; Read key
;	cpy #$38		; Check X
	ldx #1
	jsr readkey
            beq L1238

; X key pressed

            lda L183F              ; Miner sprite nr
            cmp #$00
            bne L1221              ; Skip if X key not pressed

            lda #$01               ; A9 01
            sta L183E              ; Delta X old

            lda L183C              ; X-coordinaat Miner in pixels new
            clc                    ; 18
            adc #$01               ; 69 01
            sta L183C              ; X-coordinaat Miner in pixels new

            jmp L1238              ; Jump check conveyor tiles

; No key pressed, stop walking miner

L1221:      lda #$00               ; A9 00
            sta L183F              ; Miner sprite nr

            lda #$05               ; A9 05
            sta L1840              ; Direction

            lda #$01               ; A9 01
            sta L1841              ; Direction change

            jsr L1375              ; 20 75 13

            lda #$00               ; A9 00
            sta L183E              ; Delta X old

; Check floor tiles for conveyor

L1238:
	lda L183A		; X-coordinaat Miner in pixels old
	lsr A
	lsr A
	sec
	sbc #4
	sta XPOS

	lda L183B		; Y-coordinaat Miner in pixels old
	lsr A	
	lsr A	
	lsr A
	clc
	adc #$02
	sta YPOS

            jsr L14A7              ; Read char + 1 char right

            lda L1852              ; Move on conveyor flag
            cmp #$00               ; C9 00
            bne L127A              ; On conveyor

            lda L1849              ; Lower left tile under miner
            jsr L15DA              ; Check hit conveyor
            cmp #$01               ; C9 01
            beq L126F              ; Check lower right tile

            lda L184A              ; Lower right tile under conveyor
            jsr L15DA              ; Check hit conveyor
            cmp #$01               ; C9 01
            bne L127A              ; No conveyor

; tile under miner is conveyor

L126F:      lda L183E              ; Delta X old
            sta L1853              ; Direction movement on conveyor

            lda #$01               ; A9 01
            sta L1852              ; Move on conveyor flag

; End check

L127A:      lda L1852              ; Move on conveyor flag
            cmp #$01               ; C9 01
            bne L12C4              ; D0 43

            lda L1847              ; AD 47 18
            cmp #$01               ; C9 01
            bne L1297              ; D0 0F

            lda L183E              ; Delta X old
            eor #$FE               ; 49 FE
            cmp L1854              ; CD 54 18
            bne L1297              ; D0 05

            lda #$FE               ; A9 FE
            sta L1853              ; Direction movement on conveyor

L1297:      lda L1847              ; AD 47 18
            cmp #$01               ; C9 01
            bne L12B0              ; D0 12

            lda #$FE               ; A9 FE
            sta L1853              ; Direction movement on conveyor

L12A3:      lda L183C              ; X-coordinaat Miner in pixels new
            sec                    ; 38
            sbc L183E              ; Delta X old
            sta L183C              ; X-coordinaat Miner in pixels new

            jmp L12F6              ; 4C F6 12

L12B0:      lda L1853              ; Direction movement on conveyor
            cmp #$FE               ; C9 FE
            bne L12C4              ; D0 0D
            lda L183E              ; Delta X old
            eor #$FE               ; 49 FE
            cmp L1854              ; CD 54 18
            bne L12C4              ; D0 03
            jmp L12A3              ; 4C A3 12

L12C4:      lda L183E              ; Delta X old
            cmp #$00               ; C9 00
            beq L12D3              ; F0 08
            lda L183E              ; Delta X old
            cmp L1854              ; CD 54 18
            bne L12D8              ; D0 05
L12D3:      lda #$00               ; A9 00
            sta L1853              ; Direction movement on conveyor
L12D8:      lda L1853              ; Direction movement on conveyor
            cmp #$00               ; C9 00
            bne L12E9              ; D0 0A
            lda L1852              ; Move on conveyor flag
            cmp #$01               ; C9 01
            bne L12E9              ; D0 03
            jsr L17DB              ; 20 DB 17
L12E9:      lda L183E              ; Delta X old
            sta L184E              ; Delta X new
            cmp #$00               ; C9 00
            beq L12F6              ; F0 03
            jsr L1375              ; 20 75 13

; Check for RETURN key

L12F6:
;	lda #$f6
;	sta $b000
;	lda $b001
;	ldy #$f0
;	sty $b000
;	and #$02
	ldx #2
	jsr readkey
	beq L1314		; Skip if not pressed

; Return key pressed
	lda L1848              ; Start walking on conveyor
            cmp #$00               ; C9 00
            bne L1314              ; D0 0A
            lda L1847              ; AD 47 18
            cmp #$00               ; C9 00
            bne L1314              ; D0 03
            jmp L1335              ; 4C 35 13

L1314:      lda #$00               ; A9 00
            sta L183E              ; Delta X old
            sta L1851              ; 8D 51 18
            sta L1847              ; 8D 47 18
            sta L184E              ; Delta X new
            lda L1846              ; AD 46 18
            cmp #$00               ; C9 00
            beq L132F              ; F0 06
            lda #$00               ; A9 00
            sta L1846              ; 8D 46 18
            rts                    ; 60

L132F:      jsr L254D              ; Scroll conveyor
            jmp L1423              ; 4C 23 14

;--------------------------------------------
; Miner jumps
;--------------------------------------------

; Check hit sealing for wall while jumping

L1335:
	lda L183C		; X-coordinaat Miner in pixels new
	lsr A			; 4A
	lsr A                  ; 4A
	sec
	sbc #4
	sta XPOS

	lda L183D              ; Y-coordinaat Miner in pixels new
	lsr A                  ; 4A
	lsr A                  ; 4A
	lsr A                  ; 4A
	sec                    ; 38
	sbc #$01               ; E9 01
	sta YPOS		; Get left+right top tiles above miner

            jsr L14A7              ; Read char + 1 char right

; Check top left tile above miner

            lda L1849              ; Char at current position
            cmp #$8F               ; Check hit wall
            beq L1372              ; Jump if hit wall

; Check top right tile above miner

            lda L184A              ; AD 4A 18
            cmp #$8F               ; Check hit wall
            beq L1372              ; Jump if hit wall

            lda #$01               ; A9 01
            sta L184B              ; Miner jump flag

            lda L183B              ; Y-coordinaat Miner in pixels old
            sta L184C              ; 8D 4C 18

            lda #$00               ; A9 00
            sta L184D              ; Miner jump position
            jmp L1634              ; Miner is jumping

L1372:      jmp L1314              ; Return

;--------------------------------------------
;
;--------------------------------------------

L1375:      lda #$00               ; A9 00
            sta L105F              ; 8D 5F 10
            sta L1851              ; 8D 51 18

; Check if miner landed

            lda L183D              ; Y-coordinaat Miner in pixels new
            and #$07               ; 29 07
            cmp #$00               ; C9 00
            beq L1392              ; F0 0C
            sta L1850              ; 8D 50 18

; Miner is jumping

            lda #$FF               ; A9 FF
            clc                    ; 18
            sbc L1850              ; ED 50 18
            sta L1851              ; 8D 51 18

; Miner is landed

L1392:      lda L183C              ; X-coordinaat Miner in pixels new
            and #$03               ; 29 03
            sta L1850              ; 8D 50 18

            lda L1850              ; AD 50 18
            cmp #$03               ; C9 03
            bne L13AB              ; D0 0A

            lda L183E              ; Delta X old
            cmp #$FF               ; C9 FF
            bne L13AB              ; D0 03

            jsr L1709              ; Check movement to the left

L13AB:      lda L183E              ; Delta X old
            cmp #$FD               ; C9 FD
            bne L13C3              ; D0 11

            lda L183C              ; X-coordinaat Miner in pixels new
            clc                    ; 18
            adc #$01               ; 69 01
            sta L183C              ; X-coordinaat Miner in pixels new

            lda #$00               ; A9 00
            sta L183E              ; Delta X old

            jmp L13EF              ; 4C EF 13

L13C3:      lda L1850              ; AD 50 18
            cmp #$00               ; C9 00
            bne L13D4              ; D0 0A

            lda L183E              ; Delta X old
            cmp #$01               ; C9 01
            bne L13D4              ; D0 03
            jsr L1772              ; Check movement to the right

L13D4:      lda L183E              ; Delta X old
            cmp #$FE               ; C9 FE
            bne L13EC              ; D0 11

            lda L183C              ; X-coordinaat Miner in pixels new
            sec                    ; 38
            sbc #$01               ; E9 01
            sta L183C              ; X-coordinaat Miner in pixels new
            lda #$00               ; A9 00
            sta L183E              ; Delta X old
            jmp L13EF              ; 4C EF 13

L13EC:      jmp L1405              ; 4C 05 14

L13EF:      lda L183B              ; Y-coordinaat Miner in pixels old
            cmp L184C              ; CD 4C 18
            bne L1405              ; D0 0E
            lda L184D              ; Miner jump position
            cmp #$00               ; C9 00
            bne L1405              ; D0 07
            lda L183D              ; Y-coordinaat Miner in pixels new
            sta L183B              ; Y-coordinaat Miner in pixels old
            rts                    ; 60

L1405:      ldx L183A              ; X-coordinaat Miner in pixels old
            ldy L183B              ; Y-coordinaat Miner in pixels old
            lda #$00               ; A9 00
            jsr L1869              ; 20 69 18
            jsr L254D              ; Scroll conveyor

            lda #$01               ; A9 01
            sta L1846              ; 8D 46 18
            ldx L183C              ; X-coordinaat Miner in pixels new
            ldy L183D              ; Y-coordinaat Miner in pixels new
            lda #$01               ; A9 01
            jsr L1869              ; 20 69 18

L1423:      lda #$00               ; A9 00
            sta L0077              ; 85 77
            lda L1840              ; AD 40 18
            sta L0078              ; 85 78

            lda #$00               ; A9 00
            sta L0079              ; 85 79
            lda #$0D               ; A9 0D
            sta L007A              ; 85 7A

            lda L183C              ; X-coordinaat Miner in pixels new
            and #$03               ; 29 03
            eor L183F              ; Miner sprite nr
            sta L0075              ; 85 75

            ldx #$00               ; A2 00
L1440:      cpx L0075              ; E4 75
            beq L1455              ; F0 11

            lda L0077              ; A5 77
            clc                    ; 18
            adc #$40               ; 69 40
            sta L0077              ; 85 77
            lda L0078              ; A5 78
            adc #$00               ; 69 00
            sta L0078              ; 85 78

            inx                    ; E8

            jmp L1440              ; 4C 40 14

;--------------------------------------------
; Plot Miner
;--------------------------------------------

L1455:      ldx L183C              ; X-coordinaat Miner in pixels new
            ldy L183D              ; Y-coordinaat Miner in pixels new
            lda #$00               ; Set plotmode
L145D:      jsr L0F00              ; Plot sprite
            jsr L14FD              ; 20 FD 14

	lda L183C		; X-coordinaat Miner in pixels old
	lsr A
	lsr A
	sec
	sbc #4
	sta XPOS

	lda L183D		; Y-coordinaat Miner in pixels old
	lsr A
	lsr A
	lsr A
	sta YPOS
;	inc YPOS

;            lda #$22-4               ; A9 22
;	sta XPOS
;           lda #22               ; A9 17
;	sta YPOS

	jsr L14D3		; Check lb + rb hit

	lda #$08               ; Move cursor forward 1 position
	jsr OSWRCH             ; 20 EE FF
	lda #$0a               ; Move cursor forward 1 position
	jsr OSWRCH             ; 20 EE FF
	jsr L14D3		; Check lb + rb hit

	lda L183D              ; Y-coordinaat Miner in pixels new
	and #$07               ; 29 07
	cmp #$00               ; C9 00
	beq L148E              ; F0 08

	lda #$08               ; Move cursor forward 1 position ????
	jsr OSWRCH             ; 20 EE FF
	jsr L14D3		; Check lb + rb hit

L148E:      ldx #$00               ; A2 00
L1490:      lda L0077,X            ; B5 77
            sta L1842,X            ; 9D 42 18
            inx                    ; E8
            cpx #$04               ; E0 04
            bne L1490              ; D0 F6
            lda L183C              ; X-coordinaat Miner in pixels new
            sta L183A              ; X-coordinaat Miner in pixels old
            lda L183D              ; Y-coordinaat Miner in pixels new
            sta L183B              ; Y-coordinaat Miner in pixels old
            rts                    ; 60

;-------------------------------------------
; Read char + 1 char right
;-------------------------------------------

L14A7:

;	jsr marker

            lda #$87               ; Read char at current position in X
            jsr OSBYTE             ; 20 F4 FF
            stx L1849              ; Char at current position
;	cpx #$90
;	bne go_on
;	jsr $fe94

go_on:
            lda #$09               ; Move cursor forward 1 position
            jsr OSWRCH             ; 20 EE FF

;	jsr marker

            lda #$87               ; Read char at current position in X
            jsr OSBYTE             ; 20 F4 FF
            stx L184A              ; 8E 4A 18
;	cpx #$90
;	bne go_on2
;	jsr $fe94
go_on2:
            rts                    ; 60

;-------------------------------------------
; Read char + 1 char down
;-------------------------------------------

L14BD:
            lda #$87               ; Read char at current position in X
            jsr OSBYTE             ; 20 F4 FF
            stx L1849              ; Char at current position

            lda #$0A               ; Move cursor down 1 position
            jsr OSWRCH             ; 20 EE FF

            lda #$87               ; Read character at cursor position in X
            jsr OSBYTE             ; 20 F4 FF
            stx L184A              ; 8E 4A 18

            rts                    ; 60

;-------------------------------------------
; Read char + 1 char right
;-------------------------------------------

L14D3:
            jsr L14A7              ; Read char + 1 char right

            lda #$08               ; Move cursor back 1 position
            jsr OSWRCH             ; 20 EE FF


            lda L1849              ; Char at current position
            jsr L14EC              ; Check hit character

;???
            lda #$09               ; Move cursor forward 1 position
            jsr OSWRCH             ; 20 EE FF
;???

            lda L184A              ; AD 4A 18
            jsr L14EC              ; Check hit character

	rts

;--------------------------------------------
; Check hit character
;--------------------------------------------

L14EC:
            cmp #$9B               ; Check hit bush
            bne L14ED
	jmp L1550              ; Death if hit
L14ED:
            cmp #$9c               ; Check hit rock1
            bne L14EE
	jmp L1550              ; Death if hit
L14EE:
            cmp #$90               ; Check hit key
            beq L152F              ; Add points if hit

            cmp #$98               ; Check hit switch
            bne L14EF
	jmp L1555              ; F0 59
L14EF:
            rts                    ; 60

;--------------------------------------------
; Check hit bush, rock
;--------------------------------------------

L14FD:
            lda #$22-4               ; A9 22
	sta XPOS
            lda #22               ; A9 17
	sta YPOS

L150C:
            lda #$87               ; Read char at current position in X
            jsr OSBYTE             ; 20 F4 FF

            cpx #$00               ; E0 00
            beq L152A              ; F0 15

            cpx #$9B               ; Check hit bush
            beq L1550              ; Death if hit

            cpx #$9C               ; Check hit rock1
            beq L1550              ; Death if hit

            lda #$09               ; Move cursor forward 1 position
L151F:      jsr OSWRCH             ; 20 EE FF

            lda L0318              ; AD 18 03
            cmp #$00               ; C9 00
            bne L150C              ; D0 E3
            rts                    ; 60

L152A:      lda #$20               ; A9 20
            jmp L151F              ; 4C 1F 15

;--------------------------------------------
; Hit key
;--------------------------------------------

L152F:
            lda #$20              ; Print space
            jsr OSWRCH             ; 20 EE FF


            dec L2FFF              ; Nr of keys

            lda #$08               ; Move cursor back 1 position
            jsr OSWRCH             ; 20 EE FF

            lda L0318              ; AD 18 03
            sta L1867              ; 8D 67 18
            lda L0319              ; AD 19 03
            sta L1868              ; 8D 68 18

            lda #$63               ; A9 63
            jsr L673C              ; 20 3C 67

            jmp L159B              ; 4C 9B 15

;--------------------------------------------
; Hit rock,bush
;--------------------------------------------

L1550:
            jmp L67D6              ; Death
            nop                    ; EA
            nop                    ; EA

;--------------------------------------------
; Hit switch
;--------------------------------------------

L1555:
	lda #1			; jsr L0040
	sta L009F

; Save XPOS and YPOS

	lda L0318
	sta L1867              ; 8D 67 18
	lda L0319              ; AD 19 03
	sta L1868              ; 8D 68 18

	lda #$80
	sta shadow_print
	jsr L0060		; Print turned switch and hole in wall
	asl shadow_print

; Check hit left or right switch

	lda L183A              ; X-coordinaat Miner in pixels old
	cmp #$50               ; C9 50
	bcc L159B              ; Hit left switch

; Hit right switch

	lda #$01               ; A9 01
	sta L197F              ; Monster falling flag

	lda #$80
	sta shadow_print
	jsr L0050

; Erase Kong + floor Kong (3 lines)

	ldy #$02               ; A0 02
L1587:
	jsr L0053
	dey                    ; 88
	bne L1587              ; D0 F1

	asl shadow_print

	lda #$60               ; Set RTS instruction in Kong plot routine
	sta L19EE              ; 8D EE 19

; Restore XPOS and YPOS

L159B:
	lda L1867              ; AD 67 18
	sta XPOS
	lda L1868              ; AD 68 18
	sta YPOS
	rts

;--------------------------------------------
; Check if hit solid floor
;
;  .. .. 5f .. .. 80 .. .. 90 .. .. 95 .. ..
;  00 00 01 00 00 01 01 01 00 00 00 01 01 01
;--------------------------------------------

L15AC:
	    cmp #$95              ; If char>$95
	beq L15BC

	cmp #$9c
	bcs L15BC              ; Makes miner fall through bush!!

            cmp #$5F               ; If char=$5f
            beq L15BC              ; Jump

            cmp #$80               ; If char<$80
            bcc L15C5              ; Jump

            cmp #$90               ; If char>$90
            bcs L15C5              ; Jump

L15BC:      lda L183B              ; Y-coordinaat Miner in pixels old
            sta L184C              ; 8D 4C 18
            lda #$01               ; A9 01
            rts                    ; 60

L15C5:      lda #$00               ; A9 00
            rts                    ; 60

;--------------------------------------------
; Check if hit sinking floor
;
;  .. .. 5f .. .. 82 .. .. 8a .. ..
;  00 00 01 00 00 01 01 01 01 00 00 
;--------------------------------------------

L15C8:      cmp #$5F               ; C9 5F
            beq L15D4              ; F0 08

            cmp #$82               ; C9 82
            bcc L15D7              ; 90 07

            cmp #$8A               ; C9 8A
            bcs L15D7              ; B0 03

L15D4:      lda #$01               ; A9 01
            rts                    ; 60

L15D7:      lda #$00               ; A9 00
            rts                    ; 60

;--------------------------------------------
; Check if hit conveyor
;
;  .. .. 8b .. .. 8f .. ..
;  00 00 01 01 01 01 00 00 
;--------------------------------------------

L15DA:      cmp #$8B               ; C9 8B
            bcc L15E5              ; 90 07

            cmp #$8F               ; C9 8F
            bcs L15E5              ; B0 03

            lda #$01               ; A9 01
            rts                    ; 60

L15E5:      lda #$00               ; A9 00
            rts                    ; 60

;--------------------------------------------
;
;--------------------------------------------

L15E8:      lda L184E              ; Delta X new
            cmp #$00               ; C9 00
            bne L15F5              ; D0 06

            lda #$01               ; A9 01
            sta L1847              ; 8D 47 18

            rts                    ; 60

; Check hit conveyor while landing

L15F5:
	lda L183A              ; X-coordinaat Miner in pixels old
	lsr A                  ; 4A
	lsr A                  ; 4A
	sec
	sbc #4
	sta XPOS

	lda L183B              ; Y-coordinaat Miner in pixels old
	lsr A                  ; 4A
	lsr A                  ; 4A
	lsr A                  ; 4A
	clc                    ; 18
	adc #$02               ; 69 02
	sta YPOS

            jsr L14A7              ; Read char + 1 char right
            lda L1849              ; Char at current position
            jsr L15DA              ; Check hit conveyor
            cmp #$01               ; C9 01
            beq L1626              ; F0 0B

            lda L184A              ; AD 4A 18
            jsr L15DA              ; Check hit conveyor
            cmp #$01               ; C9 01
            beq L1626              ; F0 01

            rts                    ; 60

L1626:      lda #$01               ; A9 01
            sta L1848              ; Start walking on conveyor
            lda L184E              ; Delta X new
            sta L183E              ; Delta X old
            jmp L1238              ; 4C 38 12

;--------------------------------------------
; Miner is jumping
;--------------------------------------------

jump_snd:	.byte $80,$70,$60,$50,$40,$30,$20,$10


L1634:
	lda L184B
	beq no_jump_sound

	lda L184D
	cmp #8
	bcs no_jump_sound
	and #7
	tax
	lda jump_snd,x
	ldy #$10
	jsr sound
	
;	lda #$02
;	ldx #$64
;	ldy #$02
;	jmp L68AC		; Make sound

no_jump_sound:
            lda L184D              ; Miner jump position
            cmp #$11               ; Check highest position
            bcc L163E              ; If not reached, skip
            jmp L16F8              ; Top of jump reached, jump

L163E:
            lda L183B              ; Y-coordinaat Miner in pixels old
            and #$07               ; 29 07
            cmp #$00               ; C9 00
            beq L164A              ; F0 03
            jmp L16CF              ; 4C CF 16

; Check sealing for wall while jumping

L164A:
	lda L183A			; X-coordinaat Miner in pixels old
	lsr A                  ; 4A
	lsr A                  ; 4A
	sec
	sbc #4
	sta XPOS

	lda L183B              ; Y-coordinaat Miner in pixels old
	sec                    ; 38
	sbc #$02               ; E9 02
	lsr A                  ; 4A
	lsr A                  ; 4A
	lsr A                  ; 4A
	sta YPOS

            jsr L14A7              ; Read char + 1 char right

            lda L1849              ; Char at current position
            cmp #$8F               ; Check hit wall
            beq L1677              ; F0 0A

            lda L184A              ; AD 4A 18
            cmp #$8F               ; Check hit wall
            beq L1677              ; F0 03

            jmp L168C              ; 4C 8C 16

L1677:      lda L184D              ; Miner jump position
            cmp #$09               ; C9 09
            bcs L168C              ; B0 0E

            lda #$11               ; A9 11
            sec                    ; 38
            sbc L184D              ; Miner jump position
            sta L184D              ; Miner jump position

            lda #$00               ; A9 00
            sta L184E              ; Delta X new

L168C:
            lda L183B              ; Y-coordinaat Miner in pixels old
            and #$07               ; 29 07
            cmp #$00               ; C9 00
            bne L16CF              ; D0 3A

            lda L184D              ; Miner jump position
            cmp #$08               ; C9 08
            bcc L16CF              ; 90 33

; Check floor while jumping for solid

	lda L183A              ; X-coordinaat Miner in pixels old
	lsr A                  ; 4A
	lsr A                  ; 4A
	sec
	sbc #4
	sta XPOS

	lda L183B              ; Y-coordinaat Miner in pixels old
	clc                    ; 18
	adc #$03               ; 69 03
	lsr A                  ; 4A
	lsr A                  ; 4A
	lsr A                  ; 4A
	clc                    ; 18
	adc #$02               ; 69 02
	sta YPOS

            jsr L14A7              ; Read char + 1 char right
            lda L1849              ; Char at current position
            jsr L15AC              ; Check hit solid floor
            cmp #$01               ; C9 01
            beq L16F8              ; F0 33

            lda L184A              ; AD 4A 18
            jsr L15AC              ; Check hit solid floor
            cmp #$01               ; C9 01
            beq L16F8              ; F0 29

; Miner still falling, calculate new coordinates

L16CF:      lda L184D              ; Incr.miner jump position
            clc
            adc #$01
            sta L184D

            ldy L184D              ; Set pointer

            lda L183D              ; Get Y-coordinaat Miner in pixels new
            sec
            sbc L1855,Y            ; Substract delta Y-jump
            sta L183D              ; Set Y-coordinaat Miner in pixels new

            lda L183C              ; Get X-coordinaat Miner in pixels new
            clc                    ; 18
            adc L184E              ; Delta X new
            sta L183C              ; Set X-coordinaat Miner in pixels new

            lda L184E              ; Get delta X new
            sta L183E              ; Set delta X old

            jmp L1375              ; 4C 75 13

;--------------------------------------------
; Top of jump reached, fall
;--------------------------------------------

L16F8:      lda #$00
            sta L184B              ; Miner jump flag
            sta L184D              ; Miner jump position
            jsr L254D              ; Scroll conveyor
            jsr L15E8              ; 20 E8 15
            jmp L109C              ; 4C 9C 10

;--------------------------------------------
; Check movement to the left
;--------------------------------------------

L1709:
	lda L183A              ; X-coordinaat Miner in pixels old
	lsr A                  ; 4A
	lsr A                  ; 4A
	sec
	sbc #$5               ; E9 01
	sta XPOS

	lda L183D              ; Y-coordinaat Miner in pixels new
	clc                    ; 18
	adc L1851              ; 6D 51 18
	lsr A                  ; 4A
	lsr A                  ; 4A
	lsr A                  ; 4A
	sta YPOS

            jsr L14BD              ; Read char + 1 char down

            lda L183D              ; Y-coordinaat Miner in pixels new
            and #$07               ; 29 07
            cmp #$00               ; C9 00
            beq L1740              ; F0 0E

            lda L184A              ; AD 4A 18
            sta L105F              ; 8D 5F 10

            lda #$0A               ; Move cursor down 1 pos
            jsr OSWRCH             ; 20 EE FF

            jsr L14BD              ; Read char + 1 char down

L1740:      lda L105F              ; AD 5F 10
            cmp #$20               ; C9 20
            bne L1756              ; D0 0F

            lda L184A              ; AD 4A 18
            cmp #$20               ; C9 20
            bne L1756              ; D0 08

            lda L184D              ; Miner jump position
            cmp #$05               ; C9 05
            bne L1756              ; D0 01

            rts                    ; 60

L1756:      lda L1849              ; Char at current position
            cmp #$8F               ; Check if wall
            beq L176C              ; If so decrement X-pos with 2

            lda L184A              ; Char at 1 position down
            cmp #$8F               ; Check if wall
            beq L176C              ; If so decrement X-pos with 2

            lda L105F              ; Char at 
            cmp #$8F               ; Check if wall
            beq L176C              ; If so decrement X-pos with 2
            rts

L176C:      lda #$FD               ; Set -3
            sta L183E              ; Delta X old
            rts

;--------------------------------------------
; Check movement to the right
;--------------------------------------------

L1772:
	lda L183A              ; X-coordinaat Miner in pixels old
	lsr A                  ; 4A
	lsr A                  ; 4A
	sec
	sbc #$02
	sta XPOS

	lda L183D              ; Y-coordinaat Miner in pixels new
	clc                    ; 18
	adc L1851              ; 6D 51 18
	lsr A                  ; 4A
	lsr A                  ; 4A
	lsr A                  ; 4A
	sta YPOS

            jsr L14BD              ; Read char + 1 char down

            lda L183D              ; Y-coordinaat Miner in pixels new
            and #$07               ; 29 07
            cmp #$00               ; C9 00
            beq L17A9              ; F0 0E

            lda L184A              ; AD 4A 18
            sta L105F              ; 8D 5F 10

            lda #$0A               ; Move cursor down 1 pos
            jsr OSWRCH             ; 20 EE FF

            jsr L14BD              ; Read char + 1 char down

L17A9:      lda L105F              ; AD 5F 10
            cmp #$20               ; C9 20
            bne L17BF              ; D0 0F

            lda L184A              ; AD 4A 18
            cmp #$20               ; C9 20
            bne L17BF              ; D0 08

            lda L184D              ; Miner jump position
            cmp #$05               ; C9 05
            bne L17BF              ; D0 01

            rts                    ; 60

L17BF:      lda L1849              ; Char at current position
            cmp #$8F               ; Check if wall
            beq L17D5              ; F0 0F

            lda L184A              ; AD 4A 18
            cmp #$8F               ; Check if wall
            beq L17D5              ; F0 08

            lda L105F              ; AD 5F 10
            cmp #$8F               ; Check if wall
            beq L17D5              ; F0 01

            rts                    ; 60

L17D5:      lda #$FE               ; Set -2
            sta L183E              ; Delta X old
            rts                    ; 60

;--------------------------------------------

L17DB:      lda L1854              ; AD 54 18
            cmp #$01               ; C9 01
            bne L17F6              ; D0 14
            lda L183F              ; Miner sprite nr
            cmp #$03               ; C9 03
            bne L17F6              ; D0 0D
            lda #$05               ; A9 05
            sta L1840              ; 8D 40 18
            lda #$00               ; A9 00
            sta L183F              ; Miner sprite nr
            jmp L1375              ; 4C 75 13

L17F6:      lda L1854              ; AD 54 18
            cmp #$01               ; C9 01
            bne L180E              ; D0 11
            lda L1854              ; AD 54 18
            sta L183E              ; Delta X old
            lda L183C              ; X-coordinaat Miner in pixels new
            clc                    ; 18
            adc L1854              ; 6D 54 18
            sta L183C              ; X-coordinaat Miner in pixels new
            rts                    ; 60

L180E:      lda L1854              ; AD 54 18
            cmp #$FF               ; C9 FF
            bne L1829              ; D0 14
            lda L183F              ; Miner sprite nr
            cmp #$00               ; C9 00
            bne L1829              ; D0 0D
            lda #$06               ; A9 06
            sta L1840              ; 8D 40 18
            lda #$03               ; A9 03
            sta L183F              ; Miner sprite nr
            jmp L1375              ; 4C 75 13

L1829:      lda L1854              ; AD 54 18
            sta L183E              ; Delta X old
            lda L183C              ; X-coordinaat Miner in pixels new
            clc                    ; 18
            adc L1854              ; 6D 54 18
            sta L183C              ; X-coordinaat Miner in pixels new
            rts                    ; 60

L183A:      .byte $18		; X-coordinaat Miner in pixels old
L183B:      .byte $20		; Y-coordinaat Miner in pixels old

L183C:      .byte $18		; X-coordinaat Miner in pixels new
L183D:      .byte $20		; Y-coordinaat Miner in pixels new

L183E:      .byte $EA		; Delta X old
L183F:      .byte $03		; Miner sprite nr
L1840:      .byte $06		; Direction, 5=right, 6=left
L1841:      .byte $EA           ; Direction change 0=no change, 1=changed

L1842:      .byte $00           ; Temp storage data/screen addresses
L1843:      .byte $00,$00,$00

L1846:      .byte $EA
L1847:      .byte $EA
L1848:      .byte $EA		; Start walking on conveyor
L1849:      .byte $EA		; Char at current position
L184A:      .byte $EA
L184B:      .byte $EA		; Miner jump flag
L184C:      .byte $EA
L184D:      .byte $EA		; Miner jump position
L184E:      .byte $EA		; Delta X new
L184F:      .byte $EA		
L1850:      .byte $EA
L1851:      .byte $EA
L1852:      .byte $EA		; Move on conveyor flag
L1853:      .byte $EA		; Direction movement on conveyor
L1854:      .byte $FF

L1855:      .byte $EA,$04,$04,$03,$03,$02,$02,$01 ; Delta Y miner jump
            .byte $00,$00,$00,$FF,$FE,$FE,$FD,$FD
            .byte $FC,$FC

L1867:      .byte $00           ; Temp X-pos
L1868:      .byte $EA           ; Temp Y-pos

;--------------------------------------------
; Move miner
; - Plotmode=0 -> Copy buffer to screen
; - Plotmode=1 -> Copy screen to buffer
;--------------------------------------------

L1869:
	stx L0071		; Current X-pos miner
	sty L0072		; Current Y-pos miner
	sta L0070		; Plotmode

; Calculate screenaddress and set address in subroutine at L196A

	txa
	and #$FC
	clc
	ror a
	ror a
	sec
	sbc #4
	sta L0071		; Set column

	tya
	and #$f8
	clc
	ror a
	ror a
	ror a
	sta L0072		; Set major row

	tya
	and #$07
	tay
	lda scrtab,y
	clc
	adc L0071
	sta L196E+1
	sta L196B		; Set lb screenaddress

	lda L0072
	adc #>buffer		; Bufferaddress
	sta L196E+2
	adc #($8000-buffer)/256
	sta L196C		; Set hb screenaddress

; If plotmode=1 -> Set JSR L1978

L18B7:
	lda #<L1978		; Copy screen to buffer
	sta L1933
	lda #>L1978
	sta L1934

	lda #$B9		; Set LDA,Y instruction
	sta L196A		; Load screen
	lda #$9D		; Set STA,X instruction
	sta L196E		; Store buffer

; Check plotmode

	lda L0070              ; A5 70
	cmp #$01               ; C9 01
	beq L194E		; L18E5              ; F0 14

; If plotmode=0 -> Set JSR L1972

	lda #<L1972		; Copy buffer to screen
	sta L1933
	lda #>L1972
	sta L1934

	lda #$99		; Set STA,Y instruction
	sta L196A		; Store screen
	lda #$B9		; Set LDA,Y instruction
	sta L196E		; Load buffer

; Settings done

L18E5:
            lda L1852              ; Move on conveyor flag
            cmp #$01               ; C9 01
            beq L192B              ; F0 3A

            lda L009F              ; A5 9F
            cmp #$01               ; C9 01
            beq L192B              ; F0 34

            lda L1841              ; Direction change
            cmp #$00               ; C9 00
            bne L192B              ; D0 2D

            lda L0070              ; A5 70
L1900:      cmp #$00               ; C9 00
            bne L192B              ; Jump if plotmode=1

            lda L183A              ; AD 3A 18
            and #$03               ; 29 03
            eor L183F              ; 4D 3F 18
            cmp #$00               ; C9 00
            bne L192B              ; D0 1B

            lda L183F              ; AD 3F 18
            cmp #$03               ; C9 03
            beq L191F              ; F0 08
L191F:

L192B:
            ldx #$00               ; Copy toprow miner to buffer
L1930:      ldy scrtab,x
            stx L194F              ; 8E 4F 19
L1932:      jsr LFFFF              ; Adjustable code
            inx                    ; E8
            iny                    ; C8
L1937:      cpx #$20               ; Adjustable code
            beq L194E
	cpx #$10
	bne L1930              ; D0 F7
	inc L196C
	inc L196E+2
	jmp L1930
L194E:
            lda #$00               ; A9 00
            sta L009F              ; 85 9F

            rts                    ; 60

;--------------------------------------------

L196A:      lda L3000,X            ; BD 00 30
            rts                    ; 60

L196E:      lda buffer,Y            ; B9 A0 6B
            rts                    ; 60

L1972:      jsr L196E              ; 20 6E 19
L1975:      jmp L196A              ; 4C 6A 19

L1978:      jsr L196A              ; 20 6A 19
L187B:      jmp L196E              ; 4C 6E 19

L197E:      .byte $00
L197F:      .byte $00		; Monster falling flag

;--------------------------------------------
; Plot monsters in levels
;--------------------------------------------

L1980:      lda L0080              ; Get level nr

            cmp #$05               ; C9 05
            beq L199E              ; Jump at level 5

            cmp #$08               ; C9 08
            beq L19EE              ; Jump at level 8

            cmp #$0C               ; 
            beq L19EE              ; Jump at level 12

            cmp #$09               ; C9 09
            beq L199B              ; Jump at level 9

            cmp #$10               ; C9 10
            beq L199A              ; Jump at level 16

            cmp #$0B               ; C9 0B
            bcs L199B              ; Jump at level >10

L199A:      rts                    ; 60

;--------------------------------------------
; Entry level 9 + >10
;--------------------------------------------

L199B:      jmp L1A29              ; 4C 29 1A

;--------------------------------------------
; Entry level 5+8+12
;--------------------------------------------

L199E:
	lda #$FF
	sta L109B		; Colour mask

	lda L1C48		; Vertical pos monster
	and #$7F		; Filter Y-pos
	
	cmp #$60		; Check lower position monster
	beq L19E3		; Invert direction if reached

	cmp #$08		; Check upper position monster
	beq L19E3		; Invert direction if reached
L19B0:
	lda L1C48		; Vertical pos monster
	and #$80		; Filter direction bit
	cmp #$80
	bne L19BF		; Jump if rising

	inc L1C48		; Monster is falling
	jmp L19C2		; Plot vertical guard
L19BF:
	dec L1C48		; Monster is rising

; plot vertical guard

L19C2:
	ldx #$4C		; X-pos 

	lda L1C48		; Vertical pos monster
	and #$7F		; Filter Y-pos
	tay			; Set Y-pos
	jsr L19D2		; Set sprite vars
	lda #$03		; Set plot mode
	jmp L0F00		; Plot sprite

; Set sprite vars

L19D2:
	lda #<L0400		; Set sprite data address
	sta L0077
	lda #>L0400
	sta L0078

	lda #$00		; Set ???
	sta L0079
	lda #$2F
	sta L007A
	rts

; Invert vertical direction monster

L19E3:
	lda L1C48		; Vertical pos monster
	eor #$80		; Filter direction bit
	sta L1C48		; Set direction bit
L19EB:
	jmp L19B0		; Return

;--------------------------------------------
; Entry level 8+12
;--------------------------------------------

L19EE:
	lda #$FF
	sta L109B		; Colour mask

	inc L1C49		; Monster move delay counter
	lda L1C49		; Monster move delay counter
	and #$08		; Move every 8 frames
	cmp #$08
	beq L1A0A		; Display monster 1

	lda #<L0400		; Sprite address monster 1
	sta L0077
	lda #>L0400
	sta L0078

	jmp L1A12		; Plot sprite
L1A0A:
	lda #<(L0440)	; Sprite address monster 2
	sta L0077
	lda #>(L0440)
	sta L0078
L1A12:
	ldx #$4E		; Set X-pos
	ldy #$08		; Set Y-pos
	lda #$03		; Set plotmode
	jmp L0F00		; Plot sprite
L1A1B:
	rts

;--------------------------------------------
; Called by level 9 + >10 
;--------------------------------------------

L1A1C:
	lda #$04		; Set plotmode
	sta L1B2A

	lda #$05		; Set plotmode
	sta L1AE9

	jmp L1A39		; Jump

;--------------------------------------------
; Entry level 9 + >10 at L1A29
;--------------------------------------------

L1A29:
	lda L0080		; Get level nr
	cmp #$13
	beq L1A1C		; Jump if level=19

	lda #$02		; Set plotmode
	sta L1AE9

	lda #$03		; Set plotmode
	sta L1B2A
L1A39:
	inc L1C4A		; Increment counter
	lda L1C4A
	and #$03		; Mask 0-3
	sta L1C48		; Set Sprite delay

	ldx #$00		; Reset animation pointer

	lda #<L0400		; Set first sprite animation
	sta L1C54
	lda #>L0400
	sta L1C55

; Set animation sprite address

L1A50:
	cpx L1C48		; Load sprite animation
	beq L1A62		; Stop at current sprite address

	inx
	lda L1C54
	clc
	adc #$20		; Skip to next sprite
	sta L1C54
	jmp L1A50

; Check for level 14

L1A62:
	lda L0080		; Get level nr
	cmp #$0E		; Check if level 14
	bne L1A6D		; If not level14, jump

	lda #$00		; Reset animation pointer at level 14
	sta L1C54
L1A6D:
	lda #$00		; Don't reset at other levels
	sta L1D95		; 8D 95 1D

	ldx #$00		; A2 00
	stx L1C4F		; 8E 4F 1C
L1A77:
	lda L1DAD,X		; Read sprite data
	cmp #$FF
	beq L1A1B		; Skip if all sprite s handled

	sta L1C4B		; Set X-pos
	inx

	jsr L1D9A		; Read sprite data
	sta L1C4C		; Set Y-pos
	inx

	jsr L1D9A		; Read sprite data
	sta L1C4D		; Set plotmode
	inx

	jsr L1D9A		; Read sprite data
	sta L1C4E		; Set ??

	stx L1C4F              ; 8E 4F 1C

	lda L1C4B              ; AD 4B 1C
	and #$40               ; 29 40
	cmp #$40               ; C9 40
	beq L1AA7              ; F0 05

	lda #$02               ; A9 02
	jmp L1AA9              ; 4C A9 1A

L1AA7:      lda #$04               ; A9 04
L1AA9:      sta L1C57              ; 8D 57 1C

; Set colour mask
	lda L1D95		; Get data
	and #$03		; Mask 0-3
	tax
	lda L1DBD,X		; Get colour mask
	sta L109B		; Colour mask

            lda L1C4D              ; AD 4D 1C
            and #$80               ; 29 80
            cmp #$80               ; C9 80
            bne L1AC4              ; D0 03
            jmp L1B97              ; 4C 97 1B

L1AC4:      lda L0080              ; Get level nr
            cmp #$13               ; C9 13
            bne L1AD6              ; D0 0C
            lda L109B              ; Colour mask
            cmp #$FF               ; C9 FF
            bne L1AD6              ; D0 05
            lda #$FF               ; A9 F0
            sta L109B              ; Colour mask

L1AD6:      lda L1C4B              ; AD 4B 1C
            and #$3F               ; 29 3F
            asl A                  ; 0A
            asl A                  ; 0A
            clc                    ; 18
            adc #$10               ; 69 10
            tax                    ; AA

            lda L1C4C              ; AD 4C 1C
            clc                    ; 18
            adc #$08               ; 69 08
            tay                    ; A8

L1AE8:      lda #$05               ; A9 05
            jsr L0F00              ; Plot sprite

            lda L1C4B              ; AD 4B 1C
            and #$80               ; 29 80
            cmp #$80               ; C9 80
            beq L1B03              ; F0 0D
            lda L1C4C              ; AD 4C 1C
            sec                    ; 38
            sbc L1C57              ; ED 57 1C
            sta L1C4C              ; 8D 4C 1C
            jmp L1B0D              ; 4C 0D 1B

L1B03:      lda L1C4C              ; AD 4C 1C
            clc                    ; 18
            adc L1C57              ; 6D 57 1C
            sta L1C4C              ; 8D 4C 1C
L1B0D:      lda L1C4B              ; AD 4B 1C
            and #$3F               ; 29 3F
            asl A                  ; 0A
            asl A                  ; 0A
            clc                    ; 18
            adc #$10               ; 69 10
            tax                    ; AA
            lda L1C4C              ; AD 4C 1C
            clc                    ; 18
            adc #$08               ; 69 08
            tay                    ; A8

            lda L1C54              ; AD 54 1C
            sta L0077              ; 85 77
            lda L1C55              ; AD 55 1C
            sta L0078              ; 85 78

L1B29:      lda #$04               ; A9 04
            jsr L0F00              ; Plot sprite

            lda L1C4C              ; AD 4C 1C
            cmp L1C4D              ; CD 4D 1C
            beq L1B73              ; F0 3D
            cmp L1C4E              ; CD 4E 1C
            beq L1B73              ; F0 38

L1B3B:      ldx L1C4F              ; AE 4F 1C
            dex                    ; CA
            dex                    ; CA
            dex                    ; CA
            lda L1C4B              ; AD 4B 1C
            jsr L1D9E              ; 20 9E 1D
            inx                    ; E8
            lda L1C4C              ; AD 4C 1C
            jsr L1D9E              ; 20 9E 1D
            inx                    ; E8
            lda L1C4D              ; AD 4D 1C
            jsr L1D9E              ; 20 9E 1D
            inx                    ; E8
            lda L1C4E              ; AD 4E 1C
            jsr L1D9E              ; 20 9E 1D
            inx                    ; E8
            stx L1C4F              ; 8E 4F 1C
            lda L1D95              ; AD 95 1D
            clc                    ; 18
            adc #$01               ; 69 01
            and #$03               ; 29 03
            sta L1D95              ; 8D 95 1D
            cpx #$10               ; E0 10
            beq L1B72              ; F0 03
            jmp L1A77              ; 4C 77 1A

L1B72:      rts                    ; 60

;--------------------------------------------

L1B73:      lda L0080              ; Get level nr
            cmp #$0E               ; C9 0E
            beq L1B84              ; F0 0B

            lda L1C4B              ; AD 4B 1C
            eor #$80               ; 49 80
            sta L1C4B              ; 8D 4B 1C
            jmp L1B3B              ; 4C 3B 1B

L1B84:      lda L1C4D              ; AD 4D 1C
            eor #$80               ; 49 80
            sta L1C4D              ; 8D 4D 1C
            jsr L1BF6              ; 20 F6 1B
            lda #$00               ; A9 00
            sta L1C51,Y            ; 99 51 1C
            jmp L1B3B              ; 4C 3B 1B

L1B97:      jsr L1BF6              ; 20 F6 1B

            lda L1C51,Y            ; B9 51 1C
            clc                    ; 18
            adc #$01               ; 69 01
            sta L1C51,Y            ; 99 51 1C
            asl A                  ; 0A
            asl A                  ; 0A
            asl A                  ; 0A
            asl A                  ; 0A
            asl A                  ; 0A
            asl A                  ; 0A
            sta L0077              ; 85 77

            sty L1C50              ; 8C 50 1C

            jsr L1C16              ; 20 16 1C

            lda L1C4B              ; AD 4B 1C
            and #$3F               ; 29 3F
            asl A                  ; 0A
            asl A                  ; 0A
            clc                    ; 18
            adc #$10               ; 69 10
            tax                    ; X-pos

            lda L1C4C              ; AD 4C 1C
            clc                    ; 18
            adc #$08               ; 69 08
            tay                    ; Y-pos

            lda #$03               ; A9 03
            jsr L0F00              ; Plot sprite

            ldy L1C50              ; AC 50 1C
            lda L1C51,Y            ; B9 51 1C
            cmp #$06               ; C9 06
            beq L1BD5              ; F0 03
            jmp L1B3B              ; 4C 3B 1B

L1BD5:      lda #$00               ; A9 00
            sta L1C4C              ; 8D 4C 1C
            lda L1C4D              ; AD 4D 1C
            eor #$80               ; 49 80
            sta L1C4D              ; 8D 4D 1C
            lda L1C4B              ; AD 4B 1C
            ora #$80               ; 09 80
            clc                    ; 18
            adc #$08               ; 69 08
            sta L1C4B              ; 8D 4B 1C
            and #$3F               ; 29 3F
            cmp #$20               ; C9 20
            bcs L1C0A              ; B0 17
            jmp L1B3B              ; 4C 3B 1B

L1BF6:      lda L1C4C              ; AD 4C 1C
            cmp #$48               ; C9 48
            beq L1C04              ; F0 07
            cmp #$38               ; C9 38
            beq L1C07              ; F0 06
            ldy #$02               ; A0 02
            rts                    ; 60

L1C04:      ldy #$00               ; A0 00
            rts                    ; 60

L1C07:      ldy #$01               ; A0 01
            rts                    ; 60

L1C0A:      lda L1C4B              ; AD 4B 1C
            sec                    ; 38
            sbc #$20               ; E9 20
            sta L1C4B              ; 8D 4B 1C
            jmp L1B3B              ; 4C 3B 1B

L1C16:      jsr L1BF6              ; 20 F6 1B

            lda L1C51,Y            ; B9 51 1C
            cmp #$04               ; C9 04
            beq L1C2D              ; F0 0D
            cmp #$05               ; C9 05
            beq L1C36              ; F0 12
            cmp #$06               ; C9 06
            beq L1C3F              ; F0 17

            lda #>L0400               ; A9 04
            sta L0078              ; 85 78
            rts                    ; 60

L1C2D:      lda #<L7A80               ; A9 80
            sta L0077              ; 85 77
            lda #>L7A80               ; A9 7A
            sta L0078              ; 85 78
            rts                    ; 60

L1C36:      lda #<L7AC0               ; A9 C0
            sta L0077              ; 85 77
            lda #>L7AC0               ; A9 7A
            sta L0078              ; 85 78
            rts                    ; 60

L1C3F:      lda #<$801F               ; A9 D0
            sta L0077              ; 85 77
            lda #>$801F               ; A9 34
            sta L0078              ; 85 78
            rts                    ; 60

L1C48:      nop                    ; EA
L1C49:      nop                    ; Monster move delay counter
L1C4A:      nop                    ; Sprite pointer
L1C4B:      nop                    ; EA
L1C4C:      nop                    ; EA
L1C4D:      nop                    ; EA
L1C4E:      nop                    ; EA
L1C4F:      nop                    ; EA
L1C50:      nop                    ; EA
L1C51:      nop                    ; EA
            nop                    ; EA
            nop                    ; EA
L1C54:      nop                    ; EA
L1C55:      nop                    ; EA
            nop                    ; EA
L1C57:      nop                    ; EA

;--------------------------------------------
; Copy sprite data guard to L0400
;--------------------------------------------

L1C58:      ldy #$00               ; A0 00

            lda #<L0400               ; A9 00
            sta L1CC5              ; 8D C5 1C
            sta L1CCA              ; 8D CA 1C

            lda #>L0400               ; A9 04
            sta L1CC6              ; 8D C6 1C

L1C67:      ldx L1CCA              ; AE CA 1C
L1C6A:      lda L7B00,X            ; BD 00 7B
            stx L1CCA              ; 8E CA 1C
            jsr L1CC4              ; 20 C4 1C

            ldx L1CCA              ; AE CA 1C
            inx                    ; E8
            stx L1CCA              ; 8E CA 1C
	inc L1CC5

            ldx L1CCA              ; AE CA 1C
            cpx #$80               ; E0 80
            bne L1C67              ; D0 A4

            rts                    ; 60

L1CC4:      sta LFFFF,Y            ; 99 FF FF
            rts                    ; 60

L1CC8:      nop                    ; EA
L1CC9:      nop                    ; EA
L1CCA:      nop                    ; EA

;-------------------------------------------
; Entry level 8 + 12
;-------------------------------------------

L1CCB:      lda #$02               ; A9 02
            sta L1CC9              ; 8D C9 1C
            jmp L1D15              ; 4C 15 1D

;-------------------------------------------
; Entry level 9
;-------------------------------------------

L1CD3:      lda #$09               ; A9 09
            sta L1CC9              ; 8D C9 1C
            jmp L1D15              ; 4C 15 1D

;-------------------------------------------
; Entry level 5
;-------------------------------------------

L1CDB:      lda #$01               ; A9 01
            sta L1CC9              ; 8D C9 1C

            lda #$08               ; A9 08
            sta L1C48              ; 8D 48 1C

            jmp L1D15              ; 4C 15 1D

;--------------------------------------------
;--------------------------------------------

L1CE8:      lda #$00               ; A9 00
            sta L1C4A              ; Sprite pointer

            lda #>L7B00               ; Data address
            sta L1C6C              ; 8D 6C 1C
            lda #<L7B00               ; A9 00
            sta L1C6B              ; 8D 6B 1C

            lda L0080              ; Get level nr
            cmp #$0C               ; 
            beq L1CCB              ; If level=12, jump

            cmp #$08               ; C9 08
            beq L1CCB              ; If level=8, jump

            cmp #$09               ; C9 09
            beq L1CD3              ; If level=9, jump

            cmp #$05               ; C9 05
            beq L1CDB              ; If level=5, jump

            lda L0080              ; Get level nr
            sec                    ; 38
            sbc #$0A               ; E9 0A
            tax                    ; AA
            lda L1DA2,X            ; BD A2 1D
            sta L1CC9              ; 8D C9 1C

L1D15:      ldx #$01               ; A2 01
L1D17:      cpx L1CC9              ; EC C9 1C
            beq L1D32              ; F0 16

            lda L1C6B              ; AD 6B 1C
            clc                    ; 18
            adc #$80               ; 69 80
            sta L1C6B              ; 8D 6B 1C

            lda L1C6C              ; AD 6C 1C
            adc #$00               ; 69 00
            sta L1C6C              ; 8D 6C 1C

            inx                    ; E8

            jmp L1D17              ; 4C 17 1D

L1D31:      rts                    ; 60

L1D32:      jsr L1C58              ; Plot horizontal guard

            lda L0080              ; Get level nr
            cmp #$09               ; If level=9, jump
            beq L1D3F              ; F0 04

            cmp #$0B               ; C9 0B
            bcc L1D31              ; If level <=10, jump

L1D3F:      ldx #$08               ; Level is >10
            lda #$00               ; A9 00
L1D43:      clc                    ; 18
            adc #$08               ; 69 08
            inx                    ; E8
            cpx L0080              ; Get level nr
            bne L1D43              ; D0 F8

            clc                    ; 18
            adc #<(L2480-$8)      ; 69 78
            sta L1D97              ; 8D 97 1D
	lda #>(L2480-$8)
	adc #0
	sta L1D98

            ldx #$00               ; A2 00
            ldy #$00               ; A0 00
L1D55:      jsr L1D96              ; Get level data
            cmp #$FF               ; C9 FF
            beq L1D91              ; F0 35

            sta L1DAD,Y            ; 99 AD 1D
            iny                    ; C8
            inx                    ; E8
            jsr L1D96              ; 20 96 1D
            sta L1DAD,Y            ; 99 AD 1D

            iny                    ; C8
            sta L1DAD,Y            ; 99 AD 1D

            iny                    ; C8
            sta L1DAD,Y            ; 99 AD 1D

            lda L1DAD,Y            ; B9 AD 1D
            and #$0F               ; 29 0F
            asl A                  ; 0A
            asl A                  ; 0A
            asl A                  ; 0A
            sta L1DAD,Y            ; 99 AD 1D

            dey                    ; 88
            lda L1DAD,Y            ; B9 AD 1D
            and #$F0               ; 29 F0
            lsr A                  ; 4A
            sta L1DAD,Y            ; 99 AD 1D

            dey                    ; 88
            sta L1DAD,Y            ; 99 AD 1D
            iny                    ; C8
            iny                    ; C8
            iny                    ; C8
            inx                    ; E8
            cpx #$08               ; E0 08
            bne L1D55              ; D0 C5

            rts                    ; 60

L1D91:      sta L1DAD,Y            ; 99 AD 1D
            rts                    ; 60

L1D95:      .byte $EA

L1D96:      lda L2480,X            ; BD 80 24
            rts                    ; 60

L1D9A:      lda L1DAD,X            ; BD AD 1D
            rts                    ; 60

L1D9E:      sta L1DAD,X            ; 9D AD 1D
            rts                    ; 60

;--------------------------------------------
; Level data pointer
;--------------------------------------------

L1DA2:      .byte $EA,$03,$00,$04,$05,$06,$00,$07
            .byte $0A,$08,$04

;--------------------------------------------

L1DAD:      .byte $EA
L1DAE:      .byte $EA,$EA,$EA
L1DB1:      .byte $EA,$EA,$EA,$EA
            .byte $EA,$EA,$EA,$EA,$EA,$EA,$EA,$EA

;--------------------------------------------
; Colour mask
;--------------------------------------------

L1DBD:
            .byte $FF,$FF,$FF,$FF

;--------------------------------------------
;
;--------------------------------------------

L1DC1:      .byte $FF,$66,$00,$24
            .byte $42,$24,$42,$24,$42,$24,$42,$24
            .byte $42,$00,$66,$FF,$FF,$66,$00,$42
            .byte $24,$42,$24,$42,$24,$42,$24,$42
            .byte $24,$00,$66,$FF,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$49

L1E00:      jmp L2074              ; 4C 74 20

L1E03:      lda L2280,X            ; BD 80 22
            rts                    ; 60

L1E07:      jsr L1E26              ; 20 26 1E
            jmp L20FA              ; 4C FA 20

;--------------------------------------------
; Show guards
;--------------------------------------------

L1E0D:      nop                    ; EA
            nop                    ; EA
            nop                    ; EA

            jsr L2E8C              ; 20 8C 2E

            lda L0080              ; Get level nr
            cmp #$13               ; C9 13
            beq L1E07              ; F0 E4

            jmp L1E26              ; Level 19

L1E26:      jsr L2074              ; 20 74 20

            lda #$00               ; A9 00
            sta L1FA6              ; 8D A6 1F
            tay                    ; A8
            tax                    ; AA
L1E30:      lda L0D80,Y            ; B9 80 0D
            sta L008A,X            ; 95 8A
            iny                    ; C8
            inx                    ; E8
            cpx #$04               ; E0 04
            bne L1E30              ; D0 F5

            lda L008A              ; A5 8A
            cmp #$FF               ; C9 FF
            beq L1E00              ; F0 BF

            jsr L1E78              ; 20 78 1E

            lda L1FA6              ; AD A6 1F
            clc                    ; 18
            rol A                  ; 2A
            rol A                  ; 2A
            tay                    ; A8
            ldx #$00               ; A2 00

L1E4D:      lda L008A,X            ; B5 8A
            sta L0D80,Y            ; 99 80 0D
            inx                    ; E8
            iny                    ; C8
            cpx #$04               ; E0 04
            bne L1E4D              ; D0 F5

            inc L1FA6              ; EE A6 1F

            lda L1FA6              ; AD A6 1F
            clc                    ; 18
            rol A                  ; 2A
            rol A                  ; 2A
            tay                    ; A8
            ldx #$00               ; A2 00

            jmp L1E30              ; 4C 30 1E

;--------------------------------------------

L1E78:      lda L008B              ; A5 8B
            eor #$40               ; 49 40
            sta L008B              ; 85 8B
            tay                    ; A8
            and #$20               ; 29 20
            cmp #$20               ; C9 20
            bne L1E8D              ; D0 08
            tya                    ; 98
            and #$40               ; 29 40
            cmp #$40               ; C9 40
            beq L1E8D              ; F0 01
            rts                    ; 60

L1E8D:      lda L008B              ; A5 8B
            and #$80               ; 29 80
            cmp #$80               ; C9 80
            bne L1EEF              ; D0 5A
            lda L008A              ; A5 8A
            clc                    ; 18
            adc #$01               ; 69 01
            and #$7F               ; 29 7F
            sta L1FA5              ; 8D A5 1F
            lda L008A              ; A5 8A
            and #$03               ; 29 03
            asl A                  ; 0A
            sta L008E              ; 85 8E
            jsr L1F4B              ; Set XPOS/YPOS

            lda L008E              ; A5 8E
            cmp #$00               ; C9 00
            bne L1EB5              ; D0 06
            jsr L1F67              ; 20 67 1F
            jsr L1F4B              ; Set XPOS/YPOS

L1EB5:      lda #$E0               ; A9 E0
            clc                    ; 18
            adc L008E              ; 65 8E
            jsr L20AD              ; 20 AD 20
            lda #$E1               ; A9 E1
            clc                    ; 18
            adc L008E              ; 65 8E
            jsr L20AD              ; 20 AD 20

            lda #$0A               ; Move cursor down 1 pos
            jsr OSWRCH             ; 20 EE FF

            lda #$08               ; Move cursor back 2 pos
            jsr OSWRCH             ; 20 EE FF
            jsr OSWRCH             ; 20 EE FF

            lda #$E8               ; A9 E8
            clc                    ; 18
            adc L008E              ; 65 8E
            jsr L20AD              ; 20 AD 20
            lda #$E9               ; A9 E9
            clc                    ; 18
            adc L008E              ; 65 8E
            jsr L20AD              ; 20 AD 20
            jmp L1FA7              ; 4C A7 1F

L1EE5:      lda L008A              ; A5 8A
            and #$03               ; 29 03
            asl A                  ; 0A
            sta L008E              ; 85 8E
            jmp L1EB5              ; 4C B5 1E

L1EEF:      lda L008A              ; A5 8A
            sec                    ; 38
            sbc #$01               ; E9 01
            and #$7F               ; 29 7F
            sta L1FA5              ; 8D A5 1F
            lda L008A              ; A5 8A
            and #$03               ; 29 03
            eor #$03               ; 49 03
            asl A                  ; 0A
            sta L008E              ; 85 8E
            jsr L1F4B              ; Set XPOS/YPOS
            lda L008E              ; A5 8E
            cmp #$00               ; C9 00
            bne L1F11              ; D0 06
            jsr L1F81              ; 20 81 1F
            jsr L1F4B              ; Set XPOS/YPOS

L1F11:      lda L0080              ; Get level nr
            cmp #$13               ; C9 13
            beq L1EE5              ; F0 CE
            cmp #$0F               ; C9 0F
            beq L1EE5              ; F0 CA
            lda #$F1               ; A9 F1
            clc                    ; 18
            adc L008E              ; 65 8E
            jsr L20AD              ; 20 AD 20
            lda #$F0               ; A9 F0
            clc                    ; 18
            adc L008E              ; 65 8E
            jsr L20AD              ; 20 AD 20

            lda #$08               ; Move cursor back 2 pos
            jsr OSWRCH             ; 20 EE FF
            jsr OSWRCH             ; 20 EE FF

            lda #$0A               ; Move cursor down 1 pos
            jsr OSWRCH             ; 20 EE FF

            lda #$F9               ; A9 F9
            clc                    ; 18
            adc L008E              ; 65 8E
            jsr L20AD              ; 20 AD 20
            lda #$F8               ; A9 F8
            clc                    ; 18
            adc L008E              ; 65 8E
            jsr L20AD              ; 20 AD 20
            jmp L1FA7              ; 4C A7 1F

;--------------------------------------------
; Set XPOS/YPOS
;--------------------------------------------

L1F4B:
            lda L008A              ; A5 8A
            and #$FC               ; 29 FC
            clc                    ; 18
            ror A                  ; 6A
            ror A                  ; 6A
            clc                    ; 18
            adc #$05-4               ; 69 05
	sta XPOS
            lda L008B              ; A5 8B
            and #$0F               ; 29 0F
            clc                    ; 18
            adc #$01               ; 69 01
	sta YPOS
	rts

;--------------------------------------------
; Wipe 2 characters vertical
;--------------------------------------------

L1F67:      lda #$08               ; Move cursor back 1 pos
            jsr OSWRCH             ; 20 EE FF

            lda #$20               ; A9 20
            jsr L20AD              ; 20 AD 20

            lda #$0A               ; Move cursor down 1 pos
            jsr OSWRCH             ; 20 EE FF

            lda #$08               ; Move cursor back 1 pos
            jsr OSWRCH             ; 20 EE FF

            lda #$20               ; A9 20
            jsr L20AD              ; 20 AD 20
            rts                    ; 60

L1F81:      lda #$09               ; Move cursor forward 2 pos
            jsr OSWRCH             ; 20 EE FF
            jsr OSWRCH             ; 20 EE FF

            lda #$20               ; A9 20
            jsr L20AD              ; 20 AD 20

            lda #$0A               ; Move cursor down 1 pos
            jsr OSWRCH             ; 20 EE FF

            lda #$08               ; Move cursor back 1 pos
            jsr OSWRCH             ; 20 EE FF

            lda #$20               ; A9 20
            jsr L20AD              ; 20 AD 20
            rts                    ; 60
L1F9E:      lda L008B              ; A5 8B
            eor #$80               ; 49 80
            sta L008B              ; 85 8B
            rts                    ; 60
L1FA5:      nop                    ; EA
L1FA6:      nop                    ; EA
L1FA7:      lda L1FA5              ; AD A5 1F
            sta L008A              ; 85 8A
            cmp L008C              ; C5 8C
            beq L1F9E              ; F0 EE
            cmp L008D              ; C5 8D
            beq L1F9E              ; F0 EA
            rts                    ; 60

;--------------------------------------------
;--------------------------------------------

L1FB5:      lda #<L7280            ; Guard data
            sta L1E04
            lda #>L7280
            sta L1E05

            lda #$EA               ; A9 EA
            ldx #$00               ; Wait loop
L1FC3:      nop                    ; EA
            nop                    ; EA
            nop                    ; EA
            nop                    ; EA
            nop                    ; EA
            nop                    ; EA
            inx                    ; E8
            cpx #$04               ; E0 04
            bne L1FC3              ; D0 F5

            ldx L0080              ; Get level nr
            lda L20E5,X            ; BD E5 20
            sta L008A              ; 85 8A

; Set pointer to guards according to level

            ldx #$01               ; A2 01
L1FD7:      cpx L008A              ; E4 8A
            bne no_jump
	jmp L1FF0              ; F0 15
no_jump:
            lda L1E04              ; AD 04 1E
            clc                    ; 18
            adc #$80               ; 69 80
            sta L1E04              ; 8D 04 1E
            lda L1E05              ; AD 05 1E
            adc #$00               ; 69 00
            sta L1E05              ; 8D 05 1E
            inx                    ; E8

            jmp L1FD7              ; 4C D7 1F

	.repeat $2200-*
	  .byte 0
	.endrep

; Copy guard data to ext_font

L1FF0:      ldx #$00               ; A2 00
L1FF2:      jsr L1E03              ; Get data
            sta ext_font,X            ; 9D 00 0C
            inx                    ; E8
            cpx #$80               ; E0 80
            bne L1FF2              ; D0 F5

            ldy #$00               ; A0 00
L1FFF:      lda ext_font,Y            ; B9 00 0C
            sty L20A6              ; 8C A6 20
            jsr L208A              ; 20 8A 20
            ldy L20A6              ; AC A6 20
            sta ext_font+$80,Y            ; 99 80 0C
            iny                    ; C8
            cpy #$80               ; C0 80
            bne L1FFF              ; D0 EC

; Set pointer to ?? according to level

            lda #<L22FF               ; A9 FF
            sta L1E04              ; 8D 04 1E
            lda #>L22FF               ; A9 22
            sta L1E05              ; 8D 05 1E

            ldy #$00               ; A0 00
            ldx #$00               ; A2 00
L2021:      lda L1E04              ; AD 04 1E
            clc                    ; 18
            adc #$01               ; 69 01
            sta L1E04              ; 8D 04 1E
            lda L1E05              ; AD 05 1E
            adc #$00               ; 69 00
            sta L1E05              ; 8D 05 1E

            jsr L1E03              ; Get data

            cmp #$FF               ; C9 FF
            beq L203C              ; F0 03

            jmp L2021              ; 4C 21 20

L203C:      iny                    ; C8
            cpy L0080              ; Get level nr
            bne L2021              ; D0 E0

            ldy #$00               ; A0 00
            ldx #$01               ; A2 01

L2045:      jsr L1E03              ; Get data
            jsr L2070              ; 20 70 20

            iny                    ; C8
            iny                    ; C8
            jsr L2070              ; 20 70 20
            inx                    ; E8
            dey                    ; 88
            jsr L1E03              ; Get data
            jsr L2070              ; 20 70 20
            inx                    ; E8
            iny                    ; C8
            iny                    ; C8
            jsr L1E03              ; Get data
            jsr L2070              ; 20 70 20
            inx                    ; E8
            jsr L1E03              ; Get data
            iny                    ; C8
            cmp #$FF               ; C9 FF
            bne L2045              ; D0 DB
            jsr L2070              ; 20 70 20
            jmp L2074              ; 4C 74 20

;--------------------------------------------

L2070:      sta L0D80,Y            ; 99 80 0D
            rts                    ; 60

;------------------------------------------------
; Switch #0Exx with #0Cxx
;------------------------------------------------

L2074:      ldx #$00               ; A2 00
L2076:      lda ext_font,X            ; BD 00 0C
            tay                    ; A8
            lda L0E00,X            ; BD 00 0E
            sta ext_font,X           ; 9D 00 0C
            tya                    ; 98
            sta L0E00,X            ; 9D 00 0E
            inx                    ; E8
            cpx #$FF               ; E0 FF
            bne L2076              ; D0 ED
            rts                    ; 60

;------------------------------------------------

L208A:      sta L20A5              ; 8D A5 20
            ldy #$00               ; A0 00
            ldx #$00               ; A2 00
L2091:      lda L20A5              ; AD A5 20
            clc                    ; 18
            rol A                  ; 2A
            sta L20A5              ; 8D A5 20
            bcs L20A7              ; B0 0C
            txa                    ; 8A
            clc                    ; 18
L209D:      ror A                  ; 6A
            tax                    ; AA
            iny                    ; C8
            cpy #$08               ; C0 08
            bne L2091              ; D0 ED
            rts                    ; 60

L20A5:      nop                    ; EA
L20A6:      nop                    ; EA

L20A7:      txa                    ; 8A
            sec                    ; 38
            jmp L209D              ; 4C 9D 20

L20AC:      .byte $EA

L20AD:      sta L20AC              ; 8D AC 20
            lda L0319              ; AD 19 03
            clc                    ; 18
            adc #$02               ; 69 02
            cmp L25FF              ; YPOS Exit
            bne L20D0              ; D0 15
L20BB:      lda L0318              ; AD 18 03
            cmp L25FE              ; XPOS Exit
            beq L20CB              ; F0 08
            sec                    ; 38
            sbc #$01               ; E9 01
            cmp L25FE              ; XPOS Exit
            bne L20DB              ; D0 10

L20CB:      lda #$09               ; Move cursor forward 1 pos
            jmp OSWRCH             ; 4C EE FF

L20D0:      sec                    ; 38
            sbc #$01               ; E9 01
            cmp L25FF              ; YPOS Exit
            bne L20DB              ; D0 03
            jmp L20BB              ; 4C BB 20

L20DB:      lda L20AC              ; AD AC 20
	cmp #$e0
	bcc is_space
	ldx #$80
	stx guardflag
is_space:
            jsr OSWRCH             ; Print character
	ldx #$00
	stx guardflag
	rts

;--------------------------------------------
; Colours
;--------------------------------------------

L20E1:      .byte $03,$02,$01,$03

;--------------------------------------------

L20E5:      .byte $EA,$01,$02,$03,$04,$05,$06,$07
            .byte $08,$09,$0A,$0B,$08,$0C,$00,$0D
            .byte $0E,$0F,$09,$10,$01

;--------------------------------------------
;
;--------------------------------------------

L20FA:      jsr L2227              ; 20 27 22

            ldx #$00               ; A2 00
L20FF:      lda L0D80,X            ; BD 80 0D
            sta L0D90,X            ; 9D 90 0D
            inx                    ; E8
            cpx #$05               ; E0 05
            bne L20FF              ; D0 F5

            lda L227C              ; AD 7C 22
            sec                    ; 38
            sbc #$05               ; E9 05
            asl A                  ; 0A
            asl A                  ; 0A
            sta L0D80              ; 8D 80 0D

            lda L227D              ; AD 7D 22
            clc                    ; 18
            adc #$01               ; 69 01
            sta L0D81              ; 8D 81 0D

            lda #$FF               ; A9 FF
            sta L0D84              ; 8D 84 0D

            jsr L68DF              ; 20 DF 68

            ldx #$00               ; A2 00
L2128:      lda L0D90,X            ; BD 90 0D
            sta L0D80,X            ; 9D 80 0D
            inx                    ; E8
            cpx #$05               ; E0 05
            bne L2128              ; D0 F5

            jsr L2204              ; 20 04 22
            inc L227D              ; EE 7D 22

	lda L227C              ; AD 7C 22
	sec
	sbc #4
	sta XPOS
	lda L227D              ; AD 7D 22
	and #$01               ; 29 01
	sta L003F              ; 85 3F
	lda L227D              ; AD 7D 22
	cmp #$00               ; C9 00
	bne L2165              ; D0 09
	clc                    ; 18
	adc #$01               ; 69 01
	sta YPOS

            jmp L216D              ; 4C 6D 21

L2165:
	sta YPOS

            lda #$20               ; A9 20
            jsr L221A              ; 20 1A 22

L216D:      lda L227D              ; AD 7D 22
            cmp L227B              ; CD 7B 22
            beq L2188              ; F0 13

L2175:      lda #$E0               ; A9 E0
            clc                    ; 18
            adc L003F              ; 65 3F
            tay                    ; A8
            jsr L221A              ; 20 1A 22
            tya                    ; 98
            clc                    ; 18
            adc #$02               ; 69 02
            jsr OSWRCH             ; Print character
            jmp L2204              ; 4C 04 22

L2188:      inc L227E              ; EE 7E 22
            dec L227D              ; CE 7D 22
            lda L227E              ; AD 7E 22
            cmp #$04               ; C9 04
            beq L21AA              ; F0 15
            cmp #$01               ; C9 01
            beq L2175              ; F0 DC
            cmp #$02               ; C9 02
            beq L21F7              ; F0 5A
            lda #$E5               ; A9 E5
            jsr L221A              ; 20 1A 22

            lda #$E7               ; A9 E7
            jsr OSWRCH             ; Print character
            jmp L2204              ; 4C 04 22

L21AA:      lda #$00               ; A9 00
            sta L227E              ; 8D 7E 22
            lda #$FF               ; A9 FF
            sta L227D              ; 8D 7D 22
            lda #$20               ; A9 20
            jsr L221A              ; 20 1A 22

            lda #$20               ; Print space
            jsr OSWRCH             ; 20 EE FF

            inc L227F              ; EE 7F 22
            lda L227F              ; AD 7F 22
            and #$0F               ; 29 0F
            tax                    ; AA
            lda L2280,X            ; BD 80 22
            tay                    ; A8
            and #$1F               ; 29 1F
            clc                    ; 18
            adc #$04               ; 69 04
            sta L227C              ; 8D 7C 22
            tya                    ; 98
            and #$E0               ; 29 E0
            lsr A                  ; 4A
            lsr A                  ; 4A
            lsr A                  ; 4A
            lsr A                  ; 4A
            lsr A                  ; 4A
            clc                    ; 18
            adc #$03               ; 69 03
            sta L227B              ; 8D 7B 22
            lda L227C              ; AD 7C 22
            cmp #$19               ; C9 19
            beq L21EF              ; F0 07
            cmp #$1A               ; C9 1A
            beq L21EF              ; F0 03
            jmp L2204              ; 4C 04 22

L21EF:      lda #$0B               ; A9 0B
            sta L227B              ; 8D 7B 22
            jmp L2204              ; 4C 04 22

L21F7:      lda #$E4               ; A9 E4
            jsr L221A              ; 20 1A 22

            lda #$E6               ; A9 E6
            jsr OSWRCH             ; Print character
            jmp L2204              ; 4C 04 22

L2204:      ldx #$00               ; A2 00
L2206:      lda L22C0,X            ; BD C0 22
            tay                    ; A8
            lda ext_font,X            ; BD 00 0C
            sta L22C0,X            ; 9D C0 22
            tya                    ; 98
            sta ext_font,X            ; 9D 00 0C
            inx                    ; E8
            cpx #$40               ; E0 40
            bne L2206              ; D0 ED
            rts                    ; 60

;--------------------------------------------

L221A:      jsr OSWRCH             ; Print character

            lda #$0A               ; Move cursor down 1 pos
            jsr OSWRCH             ; 20 EE FF

            lda #$08               ; Move cursor back 1 pos
            jmp OSWRCH             ; 4C EE FF

L2227:      lda L7EED              ; AD ED 7E
            and #$10               ; 29 10
            cmp #$00               ; C9 00
            beq L223E              ; F0 0E

;------------------------
; AANPASSEN
;------------------------

            ldx #>$862b               ; A2 3F
            ldy #<$862b               ; A0 F2
            jsr L2241              ; 20 41 22

            ldx #>$8a2b               ; A2 49
            ldy #<$8a2b               ; A0 F2
            jsr L2241              ; 20 41 22

;------------------------

L223E:      jmp L7E80              ; 4C 80 7E

L2241:      stx L2279              ; 8E 79 22
            sty L2278              ; 8C 78 22

            ldx #$00               ; A2 00
            jsr L2277              ; 20 77 22
            and #$80               ; 29 80
            cmp #$00               ; C9 00
            bne L2274              ; Death

            ldx #$20               ; A2 07
            jsr L2277              ; 20 77 22
            and #$01               ; 29 01
            cmp #$00               ; C9 00
            bne L2274              ; Death

            ldx #$09               ; A2 90
            jsr L2277              ; 20 77 22
            and #$80               ; 29 80
            cmp #$00               ; C9 00
            bne L2274              ; Death

            ldx #$29               ; A2 97
            jsr L2277              ; 20 77 22
            and #$01               ; 29 01
            cmp #$00               ; C9 00
            bne L2274              ; Death
            rts                    ; 60

L2274:      jmp L67D6              ; Death

L2277:      lda LFFFF,X            ; BD FF FF
            rts                    ; 60

L227B:      .byte $06

L227C:      .byte $08
L227D:      .byte $FF

L227E:      .byte $00
L227F:      .byte $00

L2280:      .byte $64,$1B,$28,$A9,$16,$1D,$02,$58
            .byte $65,$57,$27,$D9,$AA,$1C,$15,$63

;--------------------------------------------
; Set RTS instruction in print bottomline routine
; to skip printing bottomline
; Print level name
;--------------------------------------------

L2290:      lda #$60               ; RTS instruction
            sta L2500              ; 8D 00 25

            jsr L2EF0              ; Print level name
            jmp L2503              ; Print bottom line

;--------------------------------------------
; Set RTS instruction in print bottomline routine
; to skip printing bottomline + set vars
;--------------------------------------------

L229B:
            lda #$20               ; JSR instruction
            sta L2500              ; 8D 00 25

            lda #$08               ; A9 08
            sta L227C              ; 8D 7C 22
            lda #$FF               ; A9 FF
            sta L227D              ; 8D 7D 22

            lda #$06               ; A9 06
            sta L227B              ; 8D 7B 22

            lda #$00               ; A9 00
            sta L227F              ; 8D 7F 22

            lda #$F0               ; A9 F0
            sta L7EED              ; 8D ED 7E

            jmp L2427              ; 4C 27 24

;--------------------------------------------

            .byte $7C,$6B,$4C,$E8

L22C0:      .byte $00,$00,$22,$91,$4A,$91,$4A,$12
            .byte $00,$20,$2A,$4A,$4A,$51,$22,$14
            .byte $48,$1C,$2E,$7D,$57,$7D,$36,$1C
            .byte $42,$3C,$36,$5F,$7D,$6F,$3A,$1C
            .byte $00,$00,$00,$00,$00,$22,$91,$4A
            .byte $00,$00,$00,$00,$00,$00,$00,$40
            .byte $91,$4A,$12,$48,$1C,$2E,$7D,$57
            .byte $09,$20,$14,$40,$28,$02,$22

; Horizontal guard data

L22FF:      .byte $5D

            .byte $FF,$1A,$87,$3A					; Level 1
            .byte $FF,$47,$03,$01, $72,$0D,$2D				; Level 2
            .byte $FF,$3F,$03,$01, $4A,$0D,$01, $45,$83,$72		; Level 3
            .byte $FF,$01,$8D,$26, $15,$8D,$3A				; Level 4
            .byte $FF,$0C,$87,$2F, $2F,$03,$01				; Level 5
            .byte $FF,$14,$88,$32, $34,$88,$52, $19,$8D,$4E, $5D,$8D,$72; Level 6
            .byte $FF,$38,$81,$72, $27,$08,$05, $41,$8D,$72		; Level 7
            .byte $FF,$22,$0D,$01, $29,$AB,$3A, $45,$87,$52		; Level 8
            .byte $FF,$31,$83,$46, $31,$AA,$46				; Level 9
            .byte $FF,$41,$85,$52, $20,$87,$36, $0D,$8D,$66, $36,$2A,$1C; Level 10
            .byte $FF,$14,$8D,$4A, $38,$83,$5B, $35,$A7,$49		; Level 11
            .byte $FF,$26,$AB,$3A, $22,$0D,$02, $5E,$86,$6E
            .byte $FF,$1A,$81,$6E, $6E,$24,$1A, $62,$07,$26, $5A,$2A,$1A
            .byte $FF
            .byte $FF,$40,$AD,$4B
            .byte $FF,$65,$A5,$72, $4A,$0D,$02, $45,$87,$5E, $02,$8A,$1E
            .byte $FF,$10,$AD,$1F, $2C,$8D,$62
            .byte $FF,$2E,$A3,$46, $46,$06,$2E, $2E,$AA,$46, $42,$0D,$2E
            .byte $FF,$4A,$0B,$1E, $72,$0D,$5A, $1A,$0D,$02
            .byte $FF,$1A,$83,$2E, $4A,$21,$30, $29,$29,$05
            .byte $FF,$29,$05
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF

;--------------------------------------------
; Game entry
;--------------------------------------------

L23C0:

; Set lives = 2

	lda #$02
	sta L67BE

; Wait loop for ca. 7 sec

	lda #$E4
	sta L0070
	tax
	tay
	sta L0070
L23FA:
	inx
	bne L23FA
	iny
	bne L23FA
	stx L0071
	sty L0072

; Wait for keypress

;	jsr $fe71
;	cpy #$0D		; Check RETURN key
	ldx #2
	jsr readkey
	bne L2424

	ldy L0072
	ldx L0071
	inc L0070
	bne L23FA


; No key pressed, start demo

	lda #$00
	sta L3098		; Set hb music counter

	jsr L62E3		; Start music
	jmp L309A		; Show demo screen

; Key pressed, start game

L2424:
	jmp L6200		; Start game

;--------------------------------------------
; Set var
;--------------------------------------------

L2427:      lda #$FF               ; A9 FF
            sta L6B7C              ; 8D 7C 6B

            jmp L1CE8              ; 4C E8 1C

;--------------------------------------------

L242F:      .byte $00

;--------------------------------------------
; Info Screen data top
;--------------------------------------------

L2430:
	.byte 14,$02				; Cursor at 19,2
	.byte "SOFTWARE PROJECTS",0
	.byte 19,$04				; Cursor at 23,4
	.byte "Presents",0
	.byte 17,$09				; Cursor at 26,9
	.byte "ATOM VERSION",0
	.byte 15,$0B				; Cursor at 21,11
	.byte "BY KEES VAN OSS",0
	.byte 14,$0F				; Cursor at 19,15
	.byte "ORIGINAL PROGRAM",0,$ff

L2477:
            .byte $1F,$00,$00				; Cursor at 0,0
            .byte $00,$00,$00,$00,$00
            .byte $00,$00

;------------------------------------------------
; Level data >level 8
;------------------------------------------------

L2480:      .byte $85,$0D,$CB,$0D,$94,$0D,$D9,$0D	; Level 9
            .byte $00,$00,$00,$00,$00,$00,$00,$00	; Level 10

L2490:      .byte $83,$4D,$8C,$07,$95,$6D,$DA,$0D	; Level 11
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF	; Level 12
            .byte $85,$1D,$FF,$FF,$FF,$FF,$FF,$FF	; Level 13
            .byte $C1,$09,$8B,$04,$D5,$07,$FF,$FF	; Level 14
            .byte $89,$4D,$8F,$5D,$D5,$4D,$FF,$FF	; Level 15
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF	; Level 16
            .byte $83,$8D,$4A,$C0,$13,$80,$DB,$0C	; Level 17
            .byte $C5,$1D,$8A,$1D,$D4,$1D,$99,$1D	; Level 18
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF	; Level 19
            .byte $82,$06,$DA,$4D,$FF,$FF,$FF,$FF	; Level 20

;--------------------------------------------
; Info Screen data bottom
;--------------------------------------------

L24E0:
	.byte 14,17				; Cursor at 19,15
	.byte "BY MATTHEW SMITH",0
	.byte 16,19
	.byte "BBC  VERSION",0
	.byte 14,21
	.byte "BY D.J.COATHUPE",0,$ff

;--------------------------------------------

L24F5:      .byte $00,$00,$00

;--------------------------------------------
; Reset score
;--------------------------------------------

L24F8:
	lda #0
	tax
L24F9:
	sta L67BA,x
	inx
	cpx #$03
	bne L24F9
	jmp L3190

;--------------------------------------------

            .byte $00,$00,$00,$00,$00

L2500:      jsr L2290              ; Skip bottomline 

; Print "Score     Lives    Level 18"

L2503:      lda L0080              ; Get level nr
            cmp #$0A               ; C9 0A
            bne L2511              ; D0 08
            lda #$FF               ; A9 FF
            sta L25A6              ; 8D A6 25
            jmp L252E              ; 4C 2E 25

L2511:      ldy L0080              ; Get level nr
            lda L25A7,Y            ; B9 A7 25
            and #$80               ; 29 80
            clc                    ; 18
            adc L0071              ; 65 71
            clc                    ; 18
            adc #$05               ; 69 05
            sta L25A4              ; 8D A4 25
            lda L0072              ; A5 72
            clc                    ; 18
            adc #$01               ; 69 01
            sta L25A5              ; 8D A5 25
            lda L0073              ; A5 73
            sta L25A6              ; 8D A6 25

; Print line "Score         Lives      Level 18" at 4,19

L252E:
	lda #$04-4
	sta XPOS
	lda #$13
	sta YPOS

            ldy #$00               ; A0 00
L253F:      lda L25A8,Y            ; B9 A8 25
            and #$7F               ; 29 7F
            jsr OSWRCH             ; Print character
            iny                    ; C8
            cpy #$20               ; C0 20
            bne L253F              ; D0 F3
            rts                    ; 60

;--------------------------------------------
; Scroll conveyor
;--------------------------------------------

L254D:
	jsr L646D		; Set vars in demo mode

	lda L0080		; Get level nr
	cmp #$12		; Check level 18
	beq L259B		; Jump if level 18

	inc L25A7
	lda L25A6
	cmp #$FF
	beq L259B

	lda L25A4
	and #$80
	cmp #$80
	beq L259C

	lda L25A7
L2576:
	tax

	lda L25A4		; Set cursor pos
	and #$7F
	sec
	sbc #$04
	sta XPOS
	lda L25A5
	sta YPOS

; Scroll conveyor

	ldy #$00               ; A0 00
	txa                    ; 8A
	and #$03               ; 29 03
	clc                    ; 18
	adc #$EB               ; 69 EB
L2592:
	and #$8f
	jsr OSWRCH             ; Print character
	iny                    ; C8
	cpy L25A6              ; CC A6 25
	bne L2592              ; D0 F7
L259B:
	rts                    ; 60

L259C:
	lda L25A7              ; AD A7 25
	eor #$03               ; 49 03
	jmp L2576              ; 4C 76 25

L25A4:		.byte $EA
L25A5:		.byte $EA
L25A6:		.byte $EA
L25A7:		.byte $EA

;--------------------------------------------
;        01234567890123456789012345678901
; Print "Score         Lives     Level 18"
;
; Conveyor direction info:
; ------------------------
; L25A8 = level01, L25A9 = level02, etc
;   Bit 7=0 -> conveyor scroll left
;   Bit 7=1 -> conveyor scroll right
;--------------------------------------------

L25A8:	.byte $53,$E3,$6F,$F2,$65,$20,$09,$89
	.byte $89,$09,$09,$89,$A0,$20,$4C,$69
	.byte $F6,$65,$F3,$20,$09,$09,$20,$20
	.byte $4C,$65,$76,$65,$6C,$20,$31,$38

;--------------------------------------------
; Print 2 digit level nr
;--------------------------------------------

L25C8:
	lda #$FF               ; A9 FF
	jsr L673C              ; 20 3C 67

	lda #$22-4               ; A9 22
	sta XPOS
	lda #$13               ; A9 13
	sta YPOS

	lda L0080              ; Get level nr
	tax                    ; AA
	ldy #$00               ; A0 00
	jsr L25E9              ; 20 E9 25
	txa                    ; 8A
	tay                    ; A8
	jmp L25F4              ; 4C F4 25
L25E9:
	cmp #$0A               ; C9 0A
	bcc L25F4              ; 90 07
	iny                    ; C8
	sec                    ; 38
	sbc #$0A               ; E9 0A
	jmp L25E9              ; 4C E9 25
L25F4:
	tax                    ; AA
	tya                    ; 98
	clc                    ; 18
	adc #$30               ; 69 30
	jmp OSWRCH             ; Print number

;--------------------------------------------

L25FC:      .byte $74,$68

L25FE:      .byte $13		; XPOS Exit
L25FF:      .byte $07		; YPOS Exit

;--------------------------------------------

L2600:      lda LFFFF,X            ; BD FF FF
            rts                    ; 60

            lda #$80               ; A9 80
            sta L2601              ; 8D 01 26
            lda #$26               ; A9 26
            sta L2602              ; 8D 02 26
            lda #$00               ; A9 00
            sta L2693              ; 8D 93 26

            ldx #$00               ; A2 00
L261F:      jsr L2600              ; 20 00 26
            cmp #$20               ; C9 20
            bcc L2631              ; 90 0B
L2626:      inx                    ; E8
            cpx #$00               ; E0 00
            bne L261F              ; D0 F4
            inc L2602              ; EE 02 26
            jmp L261F              ; 4C 1F 26
L2631:      inc L2693              ; EE 93 26
            lda L0080              ; Get level nr
            cmp L2693              ; CD 93 26
            bne L2626              ; D0 EB

            jsr L2600              ; 20 00 26
;	sec
;	sbc #4
	sta XPOS
	lda #$11
	sta YPOS

L264E:      inx                    ; E8
            jsr L2600              ; 20 00 26
            cmp #$20               ; C9 20
            bcc L265C              ; 90 06
            jsr OSWRCH             ; Print character
            jmp L264E              ; 4C 4E 26

L265C:      lda #$00               ; A9 00
            sta L2695              ; 8D 95 26
            lda #$5A               ; A9 5A
            sta L2696              ; 8D 96 26
            ldy #$C0               ; A0 C0
            lda #$B9               ; A9 B9
            sta L2694              ; 8D 94 26
            jsr L2694              ; 20 94 26
            eor #$FF               ; 49 FF
            tax                    ; AA
            lda #$99               ; A9 99
            sta L2694              ; 8D 94 26
            txa                    ; 8A
            jsr L2694              ; 20 94 26
            iny                    ; C8
            cpy #$C0               ; C0 C0
            .byte $F0

;--------------------------------------------
; Level names
; First byte is nr of spaces
; From 2nd byte on, level name
;--------------------------------------------

L2680:      .byte $09
            .byte "Central Cavern"			; Level  1

            .byte $09
L2690:
            .byte "The Cold Room"			; Level  2

            .byte $09
            .byte "The Menagerie"			; Level  3

            .byte $03
            .byte "Abandoned Uranium Workings"		; Level  4

            .byte $09
            .byte "Eugene's Lair"			; Level  5

            .byte $08
            .byte "Processing Plant"			; Level  6

            .byte $0C
            .byte "The Vat"				; Level  7

            .byte $00
            .byte "Miner Willy meets the Kong Beast"	; Level  8

            .byte $07
            .byte "Wacky Amoebatrons"			; Level  9

            .byte $06
            .byte "The Endorian Forest"			; Level 10

            .byte $00
            .byte "Attack of the Mutant Telephones"	; Level 11

            .byte $01
            .byte "Return of the Alien Kong Beast"	; Level 12

            .byte $0A
            .byte "Ore Refinery"			; Level 13

            .byte $07
            .byte "Skylab Landing Bay"			; Level 14

            .byte $0C
            .byte "The Bank"				; Level 15

            .byte $06
            .byte "The Sixteenth Cavern"		; Level 16

            .byte $09
            .byte "The Warehouse"			; Level 17

            .byte $06
            .byte "Amoebatrons' Revenge"		; Level 18

            .byte $07
            .byte "The Meteor Storm     "		; Level 19

            .byte $07
            .byte "The Final Barrier"			; Level 20
            .byte $0D,$07
            .byte "Th"

L2800:      .byte $EA

;--------------------------------------------
; Clear screen
;--------------------------------------------

; Switch to CLEAR4

L2821:
	lda #$F0		; Switch to CLEAR4 mono
	sta $B000

; Clear screen ($8000-$97FF)

	lda #>$8000	
	sta L283C	
	lda #<$8000	
	sta L283B	

	ldx #$00	
L2838:
	lda #$00	
L283A:
	sta $8000,X	
	inx
	beq L2843
	jmp L2838
L2843:
	inc L283C
	lda L283C
	cmp #>$9800
	bcc L2838

	lda #$20
	ldy #0
clr_loop1:
	sta charmap,y
	sta charmap+$100,y
	sta charmap+$200,y
	iny
	bne clr_loop1
	rts

;--------------------------------------------
; Entry level 8
;--------------------------------------------

L2852:      lda #$E1               ; A9 E1
            sta L2C52              ; Conveyor tile
            lda #$02               ; A9 02
            sta L2C55              ; 8D 55 2C
            sta L2C56              ; 8D 56 2C
            lda #$03               ; A9 03
            sta L2C57              ; 8D 57 2C
            jmp L28F2              ; 4C F2 28

;--------------------------------------------
; Entry level 8,12
; Print switch left (&F8)
;--------------------------------------------

L2867:
	lda #$0A-4               ; A9 0A
	sta XPOS
	lda #$01               ; A9 01
	sta YPOS

            lda #$F8               ; Print switch
            jsr OSWRCH             ; 20 EE FF

            ldx #$00               ; Print 10 spaces
            lda #$20               ; A9 20
L287F:      inx                    ; E8
            jsr OSWRCH             ; 20 EE FF
            cpx #$0B               ; E0 0B
            bne L287F              ; D0 F8

            lda #$F8               ; Print switch
            jsr OSWRCH             ; 20 EE FF
            jmp L28D3              ; 4C D3 28

;--------------------------------------------
; Entry level 13
;--------------------------------------------

L288F:      lda #$F5               ; A9 F5
            sta L2C50              ; Sinking floor tile
            lda #$03               ; A9 03
            sta L2C55              ; 8D 55 2C
            jmp L28F2              ; 4C F2 28

;--------------------------------------------
; Reset colour in A to colour 0
; VDU 19,X,0,0,0,0
;--------------------------------------------

L289C:
;            tay                    ; A8
;            lda #$13               ; VDU19
;            jsr OSWRCH             ; 20 EE FF
;            txa                    ; 8A
;            jsr OSWRCH             ; 20 EE FF
;            tya                    ; 98
;            ldy #$00               ; A0 00
;L28A9:      jsr OSWRCH             ; 20 EE FF
;            iny                    ; C8
;            cpy #$04               ; C0 04
;            bne L28A9              ; D0 F8
	rts                    ; 60

;--------------------------------------------
; Get screendata
;--------------------------------------------

L28B2:      lda L2C00,X            ; BD 00 2C
            rts                    ; 60

;--------------------------------------------

            sta L0080              ; Set level nr

;--------------------------------------------
; Plot screen
;--------------------------------------------

L28B8:
	jsr L2821		; Clear screen

	lda #>L6C00		; Set hb>L6C00 
	sta L28B4

	lda #$eB		; Bush tile $eb
	sta L2C52

	lda L0080		; Get levelnr
	cmp #$0A
	beq L2852		; If levelnr=10, jump L2852

	cmp #$08
	beq L2867		; If levelnr=08, jump L2867

	cmp #$0C
	beq L2867		; If levelnr=12, jump L2867

; Entry all other screens

L28D3:
	lda #$eB		; Bush tile $eb
	sta L2C52

	lda #$03
	sta L2C56
	lda #$01
	sta L2C55
	lda #$02
	sta L2C57
	
	lda L0080		; Get levelnr
	cmp #$0D
	beq L288F		; If levelnr=13, jump L288F

	lda #$E2
	sta L2C50		; Sinking floor tile
L28F2:
	ldx #0

	lda #<L6C00
	sta L28B3		; Set lb=<L6C00
	stx L2800		; 8E 00 28

; Skip screens to point to current screen

L28FA:
	jsr L28B2		; Get screendata

	inx
	cpx #$00
	beq L2909

	cmp #$FF
	beq L290F

	jmp L28FA
L2909:
	inc L28B4		; Next screendata address
	jmp L28FA
L290F:
	jsr L28B2		; Get screendata
	cmp #$FF
	bne L28FA

	inc L2800
	lda L2800
	cmp L0080		; Get level nr
	bne L28FA

	jmp L2927		; Data found, build screen

;---------------------------------------------
; Read data
;---------------------------------------------

L2923:
	lda L2C00,X		; Get screen layout data
	rts

;---------------------------------------------
; Read parameters of screen data to build screen
;
; B0 = L0081	; L-nibble = colour 0
;		; H-nibble = colour 1
; B1 = L0082	; L-nibble = colour 2
;		; H-nibble = ?
;
; B2 = L0083	; L-nibble = char right
;		; H-nibble = char left
; B3 = L0084
; B4 = L0085	; H/L nibble
; B5 = L0086
;---------------------------------------------

; Set startaddress screendata

L2927:
	inx                    
	stx L2924		; Set lb screendata address
	lda L28B4
	sta L2925		; Set hb screendata address

; Read parameters B0, B1

	ldx #$00		; Read B0
	jsr L2923		; Read data
	sta L0081

	inx			; Read B1
	jsr L2923		; Read data
	sta L0082

; Reset colours

	ldx #$00		; Set colour nr
	lda #$00		; Set colour
L2942:
	jsr L289C		; Reset colour
	inx
	cpx #$04
	bne L2942		; Repeat for all colours

; Read parameters B2, B5

	ldx #$02		; Set pointer
L294C:
	jsr L2923		; Read B2-B7
	sta L0081,X
	inx
	cpx #$06
	bne L294C		; Repeat

; Highnibble = char $80/$81 = 8x8 tile

	lda L0083		; Get B2
	and #$F0		; Filter high nibble
	clc
	ror A
	tax			; Set data ptr to multiple8

	ldy #$00		; Set font pointer
L295F:
	lda L0B00,X		; Get char data
	sta ext_font,Y		; Copy into font
	inx			; Inc data ptr
	iny			; Inc font ptr
	cpy #$10		; Both chars copied
	bne L295F		; If not repeat

; Lownibble  = char $82 = 8x8 tile

	lda L0083		; Get B2
	and #$0F		; Filter low nibble
	clc
	rol A
	rol A
	rol A
	tax			; Set data ptr to multiple8

	ldy #$00		; Set font pointer
L2976:
	lda L0B80,X		; Get char data
	sta ext_font+$10,Y	; Copy into font
	iny			; Inc data ptr
	inx			; Inc font ptr
 	cpy #$08		; Char copied?
	bne L2976		; If not repeat

; Create sinking tile char $82 -> char $83-$8A

	lda #$01		; Set sink factor
	sta L2800

	lda #<(ext_font+$18)		; Set font char ptr
	sta L2995
	lda #>(ext_font+$18)		; Set font char ptr
	sta L2995+1

L298C:
	ldx #$00		; Set data ptr
	ldy L2800		; Set font ptr
L2991:
	lda ext_font+$10,X	; Get char data
L2994:
	sta ext_font+$18,Y	; Copy into font
	inx			; Inc data ptr
	iny			; Inc font ptr
	cpy #$08		; Char copied?
	bne L2991		; If not repeat

	inc L2800		; Decrease sink factor
	lda L2995		; Point to next char
	clc
	adc #$08
	sta L2995
	lda L2995+1
	adc #0
	sta L2995+1

	lda L2800
	cmp #$08		; 8 Sinking tiles created?
	bne L298C		; No, repeat

            lda L0084              ; A5 84
            and #$7F               ; 29 7F
            clc                    ; 18
            rol A                  ; 2A
            rol A                  ; 2A
            rol A                  ; 2A
            rol A                  ; 2A
            rol A                  ; 2A
            tax                    ; AA

            ldy #$00               ; A0 00
L29BD:      lda L0BA0,X            ; BD A0 0B
            sta ext_font+$58,Y            ; 99 58 0C
            inx                    ; E8
            iny                    ; C8
            cpy #$20               ; C0 20
            bne L29BD              ; D0 F4

            lda L0085              ; A5 85
            and #$F0               ; 29 F0
            clc                    ; 18
            ror A                  ; 6A
            tax                    ; AA

            ldy #$00               ; A0 00
L29D2:      lda L0B40,X            ; BD 40 0B
            sta ext_font+$78,Y            ; 99 78 0C
            iny                    ; C8
            inx                    ; E8
            cpy #$08               ; C0 08
            bne L29D2              ; D0 F4

            lda L0085              ; A5 85
            and #$0F               ; 29 0F
            clc                    ; 18
            rol A                  ; 2A
            rol A                  ; 2A
            rol A                  ; 2A
            tax                    ; AA

            ldy #$00               ; A0 00
L29E9:      lda L0AB0,X            ; BD B0 0A
            sta ext_font+$80,Y            ; 99 80 0C
            iny                    ; C8
            inx                    ; E8
            cpy #$08               ; C0 08
            bne L29E9              ; D0 F4

            jsr L29FB              ; 20 FB 29

            jmp L2B85              ; 4C 85 2B

;-------------------------------------------

L29FB:      lda L0086              ; A5 86
            and #$C0               ; 29 C0
            clc                    ; 18
            cmp #$00               ; C9 00
            beq L2A22              ; F0 1E

            cmp #$80               ; C9 80
            beq L2A43              ; F0 3B

            lda L0086              ; A5 86
            and #$3F               ; 29 3F
            clc                    ; 18
            rol A                  ; 2A
            rol A                  ; 2A
            rol A                  ; 2A
            rol A                  ; 2A
            rol A                  ; 2A
            tax                    ; AA

            ldy #$00               ; A0 00
L2A15:      lda L0900,X            ; BD 00 09
            sta ext_font+$88,Y            ; 99 88 0C
            inx                    ; E8
            iny                    ; C8
            cpy #$20               ; C0 20
            bne L2A15              ; D0 F4

            rts                    ; 60

;-------------------------------------------

L2A22:      lda L0086              ; A5 86
            and #$07               ; 29 07
            clc                    ; 18
            rol A                  ; 2A
            rol A                  ; 2A
            rol A                  ; 2A
            tax                    ; AA
            ldy #$00               ; A0 00
L2A2D:      lda L0980,X            ; BD 80 09
            sta ext_font+$88,Y            ; 99 88 0C
            sta ext_font+$90,Y            ; 99 90 0C
            sta ext_font+$98,Y            ; 99 98 0C
            sta ext_font+$A0,Y            ; 99 A0 0C
            inx                    ; E8
            iny                    ; C8
            cpy #$08               ; C0 08
            bne L2A2D              ; D0 EB
            rts                    ; 60

L2A43:      lda #$09               ; A9 09
            sta L2A63              ; 8D 63 2A
            lda L0086              ; A5 86
            and #$3F               ; 29 3F
            clc                    ; 18
            rol A                  ; 2A
            rol A                  ; 2A
            rol A                  ; 2A
            rol A                  ; 2A
            clc                    ; 18
            adc #$98               ; 69 98
            sta L2A62              ; 8D 62 2A
            lda L2A63              ; AD 63 2A
            adc #$00               ; 69 00
            sta L2A63              ; 8D 63 2A
            ldy #$00               ; A0 00
L2A61:      lda L0998              ; AD 98 09
            sta ext_font+$88,Y            ; 99 88 0C
            lda L2A62              ; AD 62 2A
            clc                    ; 18
            adc #$01               ; 69 01
            sta L2A62              ; 8D 62 2A
            lda L2A63              ; AD 63 2A
            adc #$00               ; 69 00
            sta L2A63              ; 8D 63 2A
            iny                    ; C8
            cpy #$10               ; C0 10
            bne L2A61              ; D0 E4

            ldx #$00               ; A2 00
L2A7F:      lda ext_font+$90,X            ; BD 90 0C
            sta ext_font+$98,X            ; 9D 98 0C
            inx                    ; E8
            cpx #$08               ; E0 08
            bne L2A7F              ; D0 F5

            ldx #$00               ; A2 00
L2A8C:      lda ext_font+$88,X            ; BD 88 0C
            stx L2AB0              ; 8E B0 2A
            jsr L2AB1              ; 20 B1 2A
            ldx L2AB0              ; AE B0 2A
            sta ext_font+$90,X            ; 9D 90 0C
            lda ext_font+$98,X            ; BD 98 0C
            stx L2AB0              ; 8E B0 2A
            jsr L2AB1              ; 20 B1 2A
            ldx L2AB0              ; AE B0 2A
            sta ext_font+$A0,X            ; 9D A0 0C
            inx                    ; E8
            cpx #$08               ; E0 08
            bne L2A8C              ; D0 DD
            rts                    ; 60

L2AB0:      nop                    ; EA
L2AB1:      sta L2ACC              ; 8D CC 2A
            ldy #$00               ; A0 00
            ldx #$00               ; A2 00
L2AB8:      lda L2ACC              ; AD CC 2A
            clc                    ; 18
            rol A                  ; 2A
            sta L2ACC              ; 8D CC 2A
            bcs L2ACD              ; B0 0B
            txa                    ; 8A
            clc                    ; 18
L2AC4:      ror A                  ; 6A
            tax                    ; AA
            iny                    ; C8
            cpy #$08               ; C0 08
            bne L2AB8              ; D0 ED
            rts                    ; 60
L2ACC:      nop                    ; EA
L2ACD:      txa                    ; 8A
            sec                    ; 38
            jmp L2AC4              ; 4C C4 2A

;--------------------------------------------
; Print exit
;--------------------------------------------

L2AD2:

; Read coordinates to plot exit

	ldx #$07
	jsr L2923		; Read data B7
	sta L0070		; X-pos exit
	inx
	jsr L2923		; Read data B8
	sta L0071		; Y-pos exit

; Set X,Y coordinates

	lda L0070		; X-pos exit
	sec
	sbc #$04
	sta XPOS
	lda L0071		; Y-pos exit
	sec
	sbc #$02
	sta YPOS

; Print exit

	ldx #$00		; Data pointer
L2AF3:	lda L2AFF,X 		; Get tile
	jsr OSWRCH		; Print character
	inx
	cpx #$08-1
	bne L2AF3		; Next tile

	rts

; Exit tile data

L2AFF:
	.byte $F1,$F2,$0A,$08,$08,$F3,$F4,$00

;--------------------------------------------
; Exit read screen data + plot routine,
; all stripes drawn
;--------------------------------------------

L2B07:
;            lda #$00		; $A9,$00
;            jsr OSWRCH		; $20,$EE,$FF
            jsr L6577           ; Draw air gauge

            jsr L254D              ; Scroll conveyor
            jsr L2AD2              ; 20 D2 2A

; Reset colours
; - Colour 0 = low nibble L0081
; - Colour 1 = high nibble L0081
; - Colour 2 = low nibble L0082
; - Colour 3 = 3

            ldx #$00               ; A2 00
            lda L0081              ; A5 81
            and #$0F               ; 29 0F
            jsr L289C              ; Reset colours

            lda L0081              ; A5 81
            and #$F0               ; 29 F0
            clc                    ; 18
            ror A                  ; 6A
            ror A                  ; 6A
            ror A                  ; 6A
            ror A                  ; 6A
            ldx #$01               ; A2 01
            jsr L289C              ; Reset colours

            lda L0082              ; A5 82
            and #$0F               ; 29 0F
            ldx #$02               ; A2 02
            jsr L289C              ; Reset colours

            ldx #$03               ; A2 03
            lda #$03               ; A9 03
            jsr L289C              ; Reset colours

            jmp L2074              ; 4C 74 20

;--------------------------------------------
; End of stripe marker
; Chartype: 0 = Solid floor
;           1 = Sinking floor
;           2 = Wall
;           3 = Conveyor
;--------------------------------------------

L2B49:      stx L0070              ; 86 70
            lda L0079              ; A5 79
            cmp #$05               ; C9 05
            beq L2B07              ; F0 B6
            inc L0079              ; E6 79
            jmp L2B90              ; 4C 90 2B

;--------------------------------------------
; Reset char type
;--------------------------------------------

L2B56:      inx                    ; E8
            jsr L2923              ; Read data
            sta L0079              ; 85 79
            stx L0070              ; 86 70
            jmp L2B90              ; 4C 90 2B

;--------------------------------------------
; Vertical stripe marker
; Read X,Y,W,H
;--------------------------------------------

L2B61:
	inx                    ; E8
	ldy #$00               ; A0 00
L2B64:
	jsr L2923              ; Read data
	sta L0071,Y            ; Save parameters
	inx                    ; E8
	iny                    ; C8
	cpy #$04               ; C0 04
	bne L2B64              ; D0 F4

	dex                    ; CA
	stx L0070              ; 86 70

	jsr L2B79              ; Draw vertical stripe

	jmp L2B90              ; 4C 90 2B

;--------------------------------------------
; Plot vertical stripe
;
; L0070 = data pointer
; L0072 = Y-pos
; L0074 = Heigth
;--------------------------------------------

L2B79:
	jsr L2BFF		; Plot tile
	inc L0072		; Pos down
	lda L0072
	cmp L0074		; Check if all tiles plot
	bne L2B79		; If no, repeat
	rts

;--------------------------------------------
; Read screen data and plot stripe
;--------------------------------------------

L2B85:      jsr L2C5C              ; Build walls left + right + floor

            lda #$08               ; Set data pointer to first stripe
            sta L0070              ; 85 70

            lda #$00               ; 
            sta L0079              ; Solid floor tile

L2B90:      inc L0070              ; E6 70

            ldx L0070              ; A6 70
            jsr L2923              ; Read data

            cmp #$FF               ; Check for end of stripe marker
            beq L2B49              ; F0 AE

            cmp #$FE               ; Check for vertical stripe marker
            beq L2B61              ; F0 C2

            cmp #$FD               ; Reset char type
            beq L2B56              ; F0 B3

            ldy #$00               ; A0 00
            ldx L0070              ; A6 70
L2BA7:      jsr L2923              ; Read data
            sta L0071,Y            ; 99 71 00
            iny                    ; C8
            inx                    ; E8
            cpy #$03               ; C0 03
            bne L2BA7              ; D0 F4

            dex                    ; CA
            stx L0070              ; 86 70
            jsr L2BFF              ; Plot horizontal stripe

            jmp L2B90              ; 4C 90 2B

L2BBC:      lda L0079              ; A5 79
            cmp #$01               ; C9 01
            bne L2C09              ; D0 47

            jmp L2C16              ; 4C 16 2C

;--------------------------------------------
; Plot sprite + mirrored sprite in level 14
;--------------------------------------------

L2BCF:
	lda L0079
	cmp #$00
	bne L2C09

	lda L0071		; Set X-pos
	clc
	adc #$05-4
	sta XPOS

	lda L0072		; Set Y-pos
	clc
	adc #$01
	sta YPOS

	lda #$E0		; Character left
	jsr OSWRCH		; Print character
	lda #$E1		; Character right
	jsr OSWRCH		; Print character
	rts

;--------------------------------------------
; Plot horizontal stripe
;
; L0071 = X-pos
; L0072 = Y-pos
; L0073 = Nr of horizontal characters to plot
; L0074 = Nr of vertical characters to plot
; L0079 = Character pointer
;--------------------------------------------

L2BFF:
	lda L0080		; Get level nr

	cmp #$07
	beq L2BBC		; Jump if level=7

	cmp #$0E
	beq L2BCF		; Jump if level=14

L2C09:
L2C16:
	lda L0071		; Set X-pos
	clc
	adc #$05-4
	sta XPOS

	lda L0072		; Set Y-pos
	clc
	adc #$01
	sta YPOS

	ldx L0079		; Get char pointer
	lda L2C4F,X		; Get character
	ldy #$00		; Set counter
L2C32:
	jsr OSWRCH		; Print character

	iny			; Move left
	cpy L0073		; Check if all chars plotted
	bne L2C32		; If not repeat

	lda L0079		; Get char pointer
	cmp #$03
	beq L2C41

	rts

L2C41:      lda L0080              ; Get level nr
            cmp #$0A               ; C9 0A
            beq L2C4C              ; Jump if level=10

            lda #$F6               ; A9 F6
            sta L2C52              ; Conveyor tile

L2C4C:      jmp L2500              ; 4C 00 25

;--------------------------------------------
; Screen tile types
;--------------------------------------------

L2C4F:      .byte $E0		; Solid floor tile
L2C50:      .byte $E2		; Sinking floor tile
            .byte $EF		; Wall tile
L2C52:      .byte $EB		; Bush tile $eb
L2C53:      .byte $20		; Rock tile

;--------------------------------------------
; Textcolour setting
;--------------------------------------------

L2C54:      .byte $01
L2C55:      .byte $01
L2C56:      .byte $03
L2C57:      .byte $02,$03,$00,$00,$00

;--------------------------------------------
; Build walls left + right + floor
;--------------------------------------------

L2C5C:

; Build wall left

	lda #$FF		; X pos-1
	sta L0071
	lda #$00		; Y pos-1
	sta L0072
	lda #$01		; Char count hor
	sta L0073
	lda #$10		; Char count ver
	sta L0074
	lda #$02		; Character pointer
	sta L0079
	jsr L2B79		; Plot vertical stripe

; Build wall right

	lda #$1E		; X pos-1
	sta L0071
	lda #$00		; Y pos-1
	sta L0072
	lda #$10		; Char count ver
	sta L0074
	jsr L2B79		; Plot vertical stripe

; Build floor

	lda #$00		; Character pointer
	sta L0079
	lda #$00		; X pos-1
	sta L0071
	lda #$0F		; Y pos-1
	sta L0072
	lda #$1E		; Char count hor
	sta L0073
	jsr L2BFF		; Plot horizontal stripe

	rts

;--------------------------------------------

L2C96:      .byte $0D
L2C97:      .byte $03

;--------------------------------------------
; Get data from bush/key/rocks table
;--------------------------------------------

L2C98:      lda $ffff
            rts                    ; 60

;--------------------------------------------

L2C9C:      jsr L2500              ; 20 00 25
            jmp L2CB2              ; 4C B2 2C

;--------------------------------------------
; Plot bush + keys + rocks
;--------------------------------------------

L2CA2:      lda #$00               ; A9 00
            sta L2E89              ; 8D 89 2E

            lda #>L716F               ; A9 71
            sta L2C98+2              ; 8D 9A 2C

            lda L0080              ; Get level nr
            cmp #$12               ; C9 12
            beq L2C9C              ; F0 EA

L2CB2:      lda #$00               ; A9 00
            sta L2DFE              ; Set temp. level nr

            lda #<L716F               ; A9 6F
            sta L2C98+1              ; 8D 99 2C

; Find data address current level

L2CBC:      jsr L2E18              ; Increment datatable address
            jsr L2C98              ; Get data bush/key table
            cmp #$FF               ; Check 
            beq L2CC9              ; F0 03

            jmp L2CBC              ; 4C BC 2C

L2CC9:      inc L2DFE              ; Inc temp. level nr

            lda L2DFE              ; Get temp. level nr
            cmp L0080              ; Get level nr
            bne L2CBC              ; Repeat if different

; Point to right address

            jsr L2E18              ; Increment datatable address
            jsr L2C98              ; Get data bush/key table
            sta L2E02              ; 8D 02 2E

            lda L2E02              ; AD 02 2E
            and #$3F               ; 29 3F
            sta L2E03              ; bit 0-5=

            lda L2E02              ; AD 02 2E
            and #$C0               ; 29 C0
            clc                    ; 18
            rol A                  ; 2A
            rol A                  ; 2A
            rol A                  ; 2A
            sta L2E02              ; bit 6-7= nr of items

            inc L2E02              ; EE 02 2E

            lda #$f0               ; Set Key tile
            sta L2DFD              ; 8D FD 2D

	lda #0
	sta chr_filter

            jsr L2DF7              ; Set XPOS=5

            ldx #$00               ; A2 00
            jmp L2D69              ; 4C 69 2D

chr_filter:	.byte 0

;--------------------------------------------
; Display switches in level 8 + 12
;--------------------------------------------

L2D00:

	lda #0
	sta chr_filter

            lda L0080              ; Get level nr
            cmp #$08               ; C9 08
            beq L2D0F              ; F0 09
            cmp #$0C               ; C9 0C
            beq L2D0F              ; F0 05
            ldx #$00               ; A2 00
            jmp L2E04              ; 4C 04 2E

L2D0F:      lda #$06-4             ; Set left switch
            sta XPOS
            lda #$01
            sta YPOS

	lda #$10
	sta chr_filter

            lda #$EC               ; Switch off symbol
            jsr OSWRCH             ; Print character

            lda #$09               ; Jump to position right switch
            ldx #$00               ; A2 00
L2D31:      inx                    ; E8
            jsr OSWRCH             ; 20 EE FF
            cpx #$07               ; E0 07
            bne L2D31              ; D0 F8

            lda #$EC               ; Switch off symbol
            jsr OSWRCH             ; Print character


            ldx #$00               ; A2 00
	stx chr_filter
            jmp L2E04              ; 4C 04 2E

;--------------------------------------------
; Set value for bush symbol
;--------------------------------------------

L2D43:      jsr L2DF1              ; Set L2E01=$15
            jmp L2D69              ; 4C 69 2D

;--------------------------------------------
; Set value for rock symbol
;--------------------------------------------

L2D49:      jsr L2DF7              ; Set L2E01=$05
            lda L2DFD              ; Get sprite tile
            sec                    ; 38
            adc L2E03              ; 6D 03 2E
            sta L2DFD              ; 8D FD 2D
            jmp L2D69              ; 4C 69 2D

L2D59:      jsr L2DF7              ; Set L2E01=$05

            ldx #$00               ; A2 00
            jsr L2E04              ; Switch ext font

            lda #$eB               ; Set Bush tile $eb
            sta L2DFD              ; 8D FD 2D

	lda #$10
	sta chr_filter


            jmp L2D69              ; 4C 69 2D

;------------------------------------------------------
; Read data from bush/rock table
;------------------------------------------------------

L2D69:      jsr L2E18              ; Increment datatable address
            jsr L2C98              ; Get data bush/key table
            sta L2DFE              ; 8D FE 2D

            cmp #$FF               ; Check end of table
            beq L2D00              ; Check display switches

            cmp #$FE               ; Plot on right side of screen
            beq L2D43              ; Plot bush

            cmp #$FD               ; Plot on left side of screen
            beq L2D49              ; F0 CB

; Item was key

            dec L2E02              ; CE 02 2E

            lda L2DFE              ; AD FE 2D
            and #$F0               ; 29 F0
            clc                    ; 18
            ror A                  ; 6A
            ror A                  ; 6A
            ror A                  ; 6A
            ror A                  ; 6A
            sta L2DFF              ; Calculate dX

            lda L2DFE              ; AD FE 2D
            and #$0F               ; 29 0F
            sta L2E00              ; Calculate Y

	lda L2DFF              ; AD FF 2D
	clc                    ; 18
	adc L2E01              ; 6D 01 2E
	sec
	sbc #$04
	sta XPOS

	lda L2E00              ; AD 00 2E
	clc                    ; 18
	adc #$01               ; 69 01
	sta YPOS

            lda L2DFD              ; AD FD 2D
            cmp #$eE               ; Spider + web tile
            beq L2E2A              ; Plot spider + web

            cmp #$f0               ; Key tile
            beq L2DD7              ; F0 14

            cmp #$eB               ; Bush tile $eb
            bne L2DE4              ; D0 1D

L2DC7:      lda L2DFD              ; AD FD 2D
            jsr OSWRCH             ; Print character

            lda L2E02              ; AD 02 2E
            cmp #$FF               ; C9 FF
            beq L2D59              ; F0 85

            jmp L2D69              ; 4C 69 2D

;--------------------------------------------
; Plot key
;--------------------------------------------

L2DD7:
            jmp L2E55              ; 4C 55 2E

;--------------------------------------------
; Plot bush
;--------------------------------------------

L2DE4:
            jmp L2DC7              ; 4C C7 2D

;--------------------------------------------
; Set value for bush
;--------------------------------------------

L2DF1:      lda #$15               ; A9 15
            sta L2E01              ; 8D 01 2E
            rts                    ; 60

;--------------------------------------------
; Set value for rock
;--------------------------------------------

L2DF7:      lda #$05               ; A9 05
            sta L2E01              ; 8D 01 2E
            rts                    ; 60

;--------------------------------------------

L2DFD:      nop                    ; Sprite tile
L2DFE:      nop                    ; EA
L2DFF:      nop                    ; XPOS
L2E00:      nop                    ; YPOS
L2E01:      nop                    ; dX POS
L2E02:      nop                    ; EA
L2E03:      nop                    ; EA

;--------------------------------------------
; Switch L0A00 with L0C00
;--------------------------------------------

L2E04:      lda ext_font,X            ; BD 00 0C
            tay                    ; A8
            lda L0A00,X            ; BD 00 0A
            sta ext_font,X            ; 9D 00 0C
            tya                    ; 98
            sta L0A00,X            ; 9D 00 0A
            inx                    ; E8
            cpx #$FF               ; E0 FF
            bne L2E04              ; D0 ED
            rts                    ; 60

;--------------------------------------------
; Increment address at L2C98+1/2C9A
;--------------------------------------------

L2E18:      lda L2C98+1              ; AD 99 2C
            clc                    ; 18
            adc #$01               ; 69 01
            sta L2C98+1              ; 8D 99 2C
            lda L2C98+2              ; AD 9A 2C
            adc #$00               ; 69 00
            sta L2C98+2              ; 8D 9A 2C
            rts                    ; 60

;--------------------------------------------
; Plot spider + web
;--------------------------------------------

L2E2A:      jsr L2E18              ; Increment datatable address
            jsr L2C98              ; Get data bush/key table
            sta L2DFE              ; 8D FE 2D

            ldx #$00               ; A2 00
L2E35:      cpx L2DFE              ; EC FE 2D
            beq L2E4D              ; F0 13

            lda #$F5               ; Set spiderweb symbol
            jsr OSWRCH             ; Print character

            lda #$0A               ; Move cursor 1 pos down
            jsr OSWRCH             ; 20 EE FF

            lda #$08               ; Move cursor 1 pos back
            jsr OSWRCH             ; 20 EE FF

            inx                    ; E8
            jmp L2E35              ; 4C 35 2E

L2E4D:      lda #$CE               ; Set spider symbol
            jsr OSWRCH             ; Print character
            jmp L2D69              ; 4C 69 2D

;--------------------------------------------

L2E55:      lda L2E89              ; AD 89 2E
            cmp #$0A               ; C9 0A
            bcc L2E5F              ; 90 03

            jmp L2DC7              ; 4C C7 2D

L2E5F:      lda L2DFF              ; AD FF 2D
            clc                    ; 18
            adc L2E01              ; 6D 01 2E
            ldy L2E89              ; AC 89 2E
            sta L2E7F,Y            ; 99 7F 2E
            iny                    ; C8
            lda L2E00              ; AD 00 2E
            clc                    ; 18
            adc #$01               ; 69 01
            sta L2E7F,Y            ; 99 7F 2E
            inc L2E89              ; EE 89 2E
            inc L2E89              ; EE 89 2E
            jmp L2DC7              ; 4C C7 2D

;--------------------------------------------
; Rotate colours of keys
;--------------------------------------------

L2E7F:
	.byte $EA		; X-pos key1
	.byte $EA		; Y-pos key1

	.byte $EA		; X-pos key2
	.byte $EA		; Y-pos key2

	.byte $EA		; X-pos key3
	.byte $EA		; Y-pos key3

	.byte $EA		; X-pos key4
	.byte $EA		; Y-pos key4

	.byte $EA		; X-pos key5
	.byte $EA		; Y-pos key5

L2E89:	.byte $0F		; Number of keys on screen * 2
L2E8A:	.byte $16		; Temp. X-reg save
L2E8B:	.byte $EA		; Colour counter

L2E8C:
	lda #$00		; Reset key pointer
	tax
L2E8F:
	inc L2E8B		; Incr.colour counter

	lda L2E7F,X		; Get X-pos key
	sec
	sbc #4
	sta XPOS

	inx
	lda L2E7F,X		; Get Y-pos key
	sta YPOS

	inx			; Point to next key data
	stx L2E8A		; Store X-reg

	lda #$87		; Read char at current position in X
	jsr OSBYTE
	cpx #$90		; Check if key
	beq L2ECE		; If key, jump
L2EB1:
	ldx L2E8A		; Get X-reg
	txa
	cmp L2E89		; Check if all keys plotted
	bcs L2ECD		; Yes, end routine

	lda L2E89		; Get key pointer
	lsr A
	and #$01		; Check bit0
	cmp #$00		; If 0, next colour
	beq L2EC7

	jmp L2E8F		; Repeat
L2EC7:
	inc L2E8B		; Incr.colour counter
	jmp L2E8F		; Repeat
L2ECD:
	rts			; End of routine

; Plot key

L2ECE:
L2EDC:
	lda L109B
	pha
	lda L2E8B
	and #3
	beq L2EDD
	lda #$ff
L2EDD:
	sta L109B

	lda #$90		; Key char
	jsr OSWRCH		; Print character

	pla
	sta L109B

	jmp L2EB1		; Return to key plot routine

;--------------------------------------------
; ???
;--------------------------------------------

L2EE7:
	lda #$03               ; A9 03
	jmp L2EDC              ; 4C DC 2E

;--------------------------------------------
; Change code to point to right level name
;--------------------------------------------

L2EEC:
	lda LFFFF,X		; Pointer to level name text
	rts

;--------------------------------------------
; Print level name
;--------------------------------------------

L2EF0:
	lda #<L2680		; Set pointer to level name text start
	sta L2EED
	lda #>L2680
	sta L2EEE

	lda #$00		; Set current level to 0
	sta L2FF6

	lda #$04-4		; Cursor at 0,17
	sta XPOS
	lda #$11
	sta YPOS

; Clear level name on screen

	lda #$20
	ldx #$00	
L2F12:
	jsr OSWRCH		; Print character
	inx
	cpx #$20		; Print 32 spaces
	bne L2F12

; Point to right level name

	ldx #$00
L2F26:
	jsr L2EEC		; Get level character
	cmp #$20
	bcc L2F38		; Check for first byte (nr of spaces)
L2F2D:
	inx
	cpx #$00
	bne L2F26

	inc L2EEE
	jmp L2F26		; Repeat
L2F38:
	inc L2FF6

	lda L0080		; Get level nr
	cmp L2FF6
	bne L2F2D

; Set cursor to center level name

	jsr L2EEC              ; Get level name x-pos
	sta XPOS
	lda #$11
	sta YPOS

; Print level name

L2F55:
	inx
	jsr L2EEC
	cmp #$20
	bcc L2F62
	jsr OSWRCH		; Print character

	jmp L2F55

; Invert line with level name

L2F62:
	ldx#0
L2F63:
	lda $9100,x
	eor #$ff
	sta $9100,x
	inx
	bne L2F63

; Draw white+black line above level name

	ldx #0
L2F64:
	lda #0
	sta $90C0,x		; Black line
	lda #$FF
	sta $90E0,x		; White line
	inx
	cpx #32
	bne L2F64

	rts

;--------------------------------------------

L2FC2:      ldx #$00               ; A2 00
L2FC4:      lda L0A58,X            ; BD 58 0A
            sta ext_font+$D8,X            ; 9D D8 0C
            inx                    ; E8
            cpx #$08               ; E0 08
            bne L2FC4              ; D0 F5

            lda L2E03              ; AD 03 2E
            asl A                  ; 0A
            asl A                  ; 0A
            asl A                  ; 0A
            tax                    ; AA

            ldy #$00               ; A0 00
L2FD8:      lda L0A60,X            ; BD 60 0A
            sta ext_font+$E0,Y            ; 99 E0 0C
            inx                    ; E8
            iny                    ; C8
            cpy #$08               ; C0 08
            bne L2FD8              ; D0 F4

            lda L2E89              ; AD 89 2E
            cmp #$04               ; C9 04
            beq L2FF0              ; F0 05

            lsr A                  ; 4A
            sta L2FFF              ; Nr of keys
            rts                    ; 60

L2FF0:      lda #$01               ; A9 01
            sta L2FFF              ; Nr of keys
            rts                    ; 60

;--------------------------------------------

L2FF6:      .byte $ea              ; Current level

;--------------------------------------------

L2FF7:      lda LFFFF,X            ; BD FF FF
            rts                    ; 60

            .byte $00
            .byte "FX"
            .byte $00

L2FFF:      .byte $00		; Nr of keys

L3000:      pha                    ; 48
            php                    ; 08
            txa                    ; 8A
            pha                    ; 48
            tya                    ; 98
            pha                    ; 48
            jsr L303B              ; Musicroutine
            lda L3099              ; AD 99 30
            cmp #$FF               ; C9 FF
            beq L3033              ; F0 23
            lda L3097              ; Get lb music counter
            cmp #$FF               ; C9 FF
            beq L3033              ; F0 1C
            lda #$B0               ; A9 B0
            jsr L3075              ; Sound output
            lda #$A0               ; A9 A0
            jsr L3075              ; Sound output
            lda L3099              ; AD 99 30
            jsr L3075              ; Sound output
            lda #$FF               ; A9 FF
            sta L3099              ; 8D 99 30
L302C:      pla                    ; 68
            tay                    ; A8
            pla                    ; 68
            tax                    ; AA
            plp                    ; 28
            pla                    ; 68
            rts                    ; 60

L3033:      lda #$BF               ; A9 BF
            jsr L3075              ; Sound output
            jmp L302C              ; 4C 2C 30

;--------------------------------------------
; Music counter routine
; If sound is off, L303B: RTS
; If sound is on , L303B: INC L3097
;--------------------------------------------

L303B:
	inc L3097		; Inc lb music counter
	lda L3097		; Get lb music counter
	cmp #$01
	beq L3070
	cmp #$06
	beq L304A
	rts
L304A:
	lda #$00
	sta L3097		; Reset lb music counter
	inc L3098		; Inc hb music counter

	lda #$92
	jsr L3075		; Sound output

	lda #$80
	jsr L3075		; Sound output

	lda L3098		; Get hb music counter
	lsr A
	tax
	lda $00,X
	cmp #$00
	beq L306A
	jmp L3075		; Sound output
L306A:
	lda #$FF
	sta L3098		; Reset hb music counter
	rts
L3070:
	lda #$9F
	jmp L3075		; Sound output

;--------------------------------------------
; Play tone in A
;--------------------------------------------

L3075:
	rts

;--------------------------------------------

L3097:      .byte $EC		; Music counter lb (0-6)
L3098:      .byte $00		; Music counter hb (0-7C)
L3099:      .byte $FF		; Shoe sink counter

;--------------------------------------------
; Demo level entry
;--------------------------------------------

L309A:

; Init

	lda #$01		; Reset level
	sta L0080

	lda #$02		; Reset lives
	sta L67BE

; Reset score

	lda #$00				
	ldx #$00
L30A7:
	sta L67BA,X
	inx
	cpx #$03
	bne L30A7

; Set vars

L30AF:
	lda L0080		; Get levelnr
	jsr L62C3		; Build screen

	lda #$00
	sta L30E9		; Level show counter

; Show screen

L30B9:
	jsr L254D		; Scroll conveyor

	jsr L1E0D		; Show guards
	jsr L1980		; Plot monsters in levels

; Wait loop
	ldx #$00 
	ldy #$D0
L30C6:
	inx
	bne L30C6
	iny
	bne L30C6

	inc L30E9		; Level show counter
	lda L30E9		; Level show counter
	cmp #$40		; Show level for 64 ticks
	beq L30EA

;	jsr $fe71		; Read key
;	cpy #$0d		; Return
	ldx #2
	jsr readkey
	bne L30E6		; Return key pressed

	jmp L30B9		; Loop demo
L30E6:
	jmp L6200		; Start game

L30E9:
	.byte $EA		; Level show counter

; Next level

L30EA:
	inc L0080              ; Next level nr
	lda L0080              ; Get level nr
	cmp #$13               ; C9 13
	beq L30F5              ; F0 03
	jmp L30AF              ; 4C AF 30
L30F5:
	nop                    ; EA
	nop                    ; EA
	nop                    ; EA
	nop                    ; EA
	jmp L3190              ; 4C 90 31

;--------------------------------------------
; If in freezemode
; Check for typing "A SECRET"
; to set cheatmodeflag
;--------------------------------------------

L30FC:
;            lda L00ED              ; Check if 1 key pressed
;            cmp #$00               ; C9 00
;            bne L3118              ; If not end
;
;            lda L00EC              ; Check pressed key
;            and #$7F               ; 29 7F
;            cmp #$00               ; C9 00
;            beq L313A              ; If nothing, end
	lda #$f0
	sta $b000
	jsr $fe71
	cpy #$ff
	beq L313A
	tya

            ldx L313B              ; Get cheatpointer
            cmp L313C,X            ; Compare key with code
            beq L311E              ; If ok, jump
            dex                    ; If wrong decr.cheatpointer
            cmp L313C,X            ; Check with code
            beq L313A              ; If wrong end

L3118:      lda #$00               ; Reset cheatpointer
            sta L313B              ; 8D 3B 31
            rts                    ; 60

L311E:      inc L313B              ; Point to next code char
            lda L313B              ; Get cheatpointer
            cmp #$08               ; Check if code complete
            beq L3129              ; If yes, set cheatflag
            rts                    ; 60

L3129:
            lda L6B7F              ; Get cheatmodeflag
            eor #$01               ; Make <>0
            sta L6B7F              ; Set cheatmodeflag


; Make sound

	lda #$40
	sta tmp_note
snd_loop:
	lda tmp_note
	ldy #8
	jsr sound
	lda #$20
	ldy #8
	jsr sound
	dec tmp_note
	lda tmp_note
	cmp #$20
	bne snd_loop

	rts
;            lda #$01               ; A9 03
;            ldx #$64               ; A2 64
;            ldy #$03               ; A0 03
;            jmp L68AC              ; Make sound

tmp_note:	.byte 0

L313A:      rts                    ; 60

L313B:      .byte $00		; Cheatpointer

; Cheatcode    A  SPC  S   E   C   R   E   T 
L313C:
;       .byte $41,$62,$51,$22,$52,$33,$22,$23
	.byte $21,$00,$33,$25,$23,$32,$25,$34

            rts                    ; 60

;---------------------------------------------

            rts                    ; 60

;---------------------------------------------
;
;---------------------------------------------

L3146:

	jsr L1980 		; Plot monsters in levels

	lda L184B		; Check Miner jump flag
	cmp #$01
	bne L3160		; Jump if miner not jumping

	lda L184D		; Check Miner jump position
	cmp #$01
	bne L3160		; Jump if miner in the air

;	lda #$02
;	ldx #$64
;	ldy #$02
;	jmp L68AC		; Make sound

;no_jump_sound:
	rts

L3160:
	lda L184B		; Check Miner jump flag
	cmp #$01
	beq L318A		; Jump if miner is jumping

	lda L6B7C              ; AD 7C 6B
	cmp #$00               ; C9 00
	bne L318A              ; D0 1C

	lda #$FF               ; A9 FF
	sta L6B83              ; 8D 83 6B

	lda L183D              ; Y-coordinaat Miner in pixels new
	sec                    ; 38
	sbc L184C              ; ED 4C 18
	asl A                  ; 0A
	asl A                  ; 0A
;	eor #$7F               ; 49 7F

;            tax                    ; AA
;	sta $9b00
            ldy #$10               ; A0 01
            jsr sound              ; Make sound

            lda #$00               ; A9 00
            sta L6B83              ; 8D 83 6B
L318A:      rts                    ; 60

            .byte $38,$3a,$4a,$53,$52

;============================================
; Program entry
;============================================

; Init

L3190:

	jsr joyinit

	jsr L2821		; Clear screen
	jsr L62E9		; Stop music

; Print text on intro screen

	ldx #<L2430		; Top lines
	ldy #>L2430
	jsr PUTSTRING

	ldx #<L24E0		; Bottom line
	ldy #>L24E0
	jsr PUTSTRING

	jsr L325F		; Switch L0Cxx with L07xx

; Print "Manic Miner (c)"

	lda #14
	sta XPOS
	lda #7
	sta YPOS

	ldx #$80
L31BF:
	txa
	jsr PRINTCHAR		; Print character
	inx
	cpx #$91
	bne L31BF

; Set backgroundcolour block to green

	lda #<$860e		; Screenaddress top left
	sta L31C1+1
	sta L31C2+1
	lda #>$860e
	sta L31C1+2
	sta L31C2+2

	ldy #55			; Vertical lines
L31C0:
	ldx #17			; Horizontal bytes
L31C1:
	lda $860e,x
	cpx #17
	bne L31C4
	eor #$f0
	jmp L31C2
L31C4:
	eor #$ff
L31C2:
	sta $860e,x
	dex
	bpl L31C1

	dey
	beq L31C3

	clc
	lda L31C1+1
	adc #$20
	sta L31C1+1
	sta L31C2+1
	lda L31C1+2
	adc #0
	sta L31C1+2
	sta L31C2+2
	jmp L31C0

L31C3:	
	jsr L325F		; Switch L0Cxx with L07xx

	jmp L3244		; Skip logo for now

; Plot graphic shape

            ldx #$FF               ; A2 FF
L3200:      jsr L325A              ; 20 5A 32
            cmp #$FF               ; C9 FF
            beq L3244              ; F0 3D
            cmp #$FE               ; C9 FE
            beq L3247              ; F0 3C

            sta L3274              ; 8D 74 32
            jsr L325A              ; 20 5A 32
            tay                    ; A8
            lsr A                  ; 4A
            lsr A                  ; 4A
            lsr A                  ; 4A
            lsr A                  ; 4A
            lsr A                  ; 4A
            lsr A                  ; 4A
            sta L3276              ; 8D 76 32
            tya                    ; 98
            asl A                  ; 0A
            asl A                  ; 0A
            sta L3275              ; 8D 75 32
            jsr L325A              ; 20 5A 32
            tay                    ; A8
            lsr A                  ; 4A
            lsr A                  ; 4A
            lsr A                  ; 4A
            lsr A                  ; 4A
            lsr A                  ; 4A
            lsr A                  ; 4A
            sta L3278              ; 8D 78 32
            tya                    ; 98
            asl A                  ; 0A
            asl A                  ; 0A
            sta L3277              ; 8D 77 32

            ldy #$00               ; Execute PLOT command
L3236:      lda L3273,Y            ; B9 73 32
            jsr OSWRCH             ; 20 EE FF
            iny                    ; C8
            cpy #$06               ; C0 06
            bne L3236              ; D0 F5

            jmp L3200              ; 4C 00 32

L3244:
	jmp L23C0              ; Jump to game entry

;--------------------------------------------

; Define graphics colour

L3247:      lda #$12               ; A9 12
            jsr OSWRCH             ; 20 EE FF
            lda #$00               ; A9 00
            jsr OSWRCH             ; 20 EE FF
            jsr L325A              ; 20 5A 32
            jsr OSWRCH             ; 20 EE FF
            jmp L3200              ; 4C 00 32

; Get plot parameters

L325A:      inx                    ; E8
            lda L0790,X            ; BD 90 07
            rts                    ; 60

;--------------------------------------------
; Switch L0Cxx with L07xx
; With Atomfont, switch char $80-$9F
;--------------------------------------------

L325F:
	ldx #$00
L3261:
	lda L0700,X
	tay
	lda ext_font,X
	sta L0700,X
	tya
	sta ext_font,X
	inx
	bne L3261
	rts

;--------------------------------------------
; OSBYTE
;--------------------------------------------
L3235:
	ldx #0
	rts

;--------------------------------------------
; PLOT command
;--------------------------------------------

L3273:      .byte $19
L3274:      .byte $EA
L3275:      .byte $EA
L3276:      .byte $EA
L3277:      .byte $EA
L3278:      .byte $EA

;--------------------------------------------

L3279:
            .byte $00,$00,$00,$00,$00,$00,$00

;--------------------------------------------
; Subroutine at $0050
;	.byte $1F,$13,$01,$20,$20,$0A,$08,$08
;--------------------------------------------


L0050:
	lda #$13-4
	sta XPOS
	lda #$01
	sta YPOS
L0053:
	lda #$20
	jsr OSWRCH
	lda #$20
	jsr OSWRCH
	lda #$0A
	jsr OSWRCH
	lda #$08
	jsr OSWRCH
	lda #$08
	jmp OSWRCH

;--------------------------------------------
; Subroutine at $0060 level 8 when hit switch
;	.byte $99,$1F,$15,$0C,$20,$0A,$08,$20
;--------------------------------------------

L0060:
	lda #$99		; Print turned switch
	jsr OSWRCH

	lda #$15-4		; Make hole in wall
	sta XPOS	
	lda #$0c
	sta YPOS

	lda #$20
	jsr OSWRCH
	lda #$0A
	jsr OSWRCH
	lda #$08
	jsr OSWRCH
	lda #$20
	jmp OSWRCH


; for debugging 

marker:
;	rts

	pha
	tya
	pha

	clc
	lda YPOS
	adc #$80
	sta $92
	lda XPOS
	sta $91
	ldy #$0
	lda ($91),y
	eor #$ff
	sta ($91),y
	jsr $fe66
	eor #$ff
	sta ($91),y

	pla
	tay
	pla
	rts