	.export __uputc
	.export __uputw
	.export __ugetc
	.export __ugetw
	.export __uzero
	.export __uget
	.export __uput

	.setcpu	6800
	.common

__uputc:
	tsx
	ldab 5,x
	ldx 2,x
	jsr map_process_always
	stab 0,x
	jsr map_kernel
	jmp ret4

__uputw:
	ldaa 4,x
	tsx
	ldab 5,x
	ldx 2,x
	jsr map_process_always
	staa 0,x
	stab 1,x
	jsr map_kernel
	jmp ret4

__ugetc:
	tsx
	ldx 2,x
	jsr map_process_always
	ldab 0,x
	clra
	jsr map_kernel
	jmp ret2

__ugetw:
	tsx
	ldx 2,x
	jsr map_process_always
	ldaa 0,x
	ldab 1,x
	jsr map_kernel
	jmp ret2

__uzero:
	tsx
	ldaa 2,x
	ldab 3,x
	ldx 4,x
	jsr map_process_always
	; Optimize, unroll etc ?
	pshb
uzeropg:
	tsta
	beq	endwipe
	clrb
	bsr	uzerolp
	deca
	bra	uzeropg
endwipe:
	pulb
	tstb
	beq	enduz
	bsr	uzerolp
enduz:
	jsr map_kernel
	jmp ret4

	
uzerolp:
	clr 0,x
	inx
	decb
	bne uzerolp
	rts

__uget:
	; This one is harder as we've got to juggle two pointers
	; We can optimize this a lot by abusing the stack etc but
	; start simple. Take care as tmp/to/from are kernel mapped
	tsx
	ldx 2,x
	stx @tmp
	tsx
	ldx 4,x	; to
	stx @to
	tsx
	ldx 6,x		; from
	stx @from
ugetl:
	ldx @from
	jsr map_process_always
	ldab ,x
	inx
	jsr map_kernel
	stx @from
	ldx @to
	stab ,x
	inx
	stx @to
	ldx @tmp
	dex
	stx @tmp
	; On 6800 only Z bit is affected by DEX, but that will do us fine
	bne ugetl
	clrb
	clra
	jmp ret6

__uput:
	; This one is harder as we've got to juggle two pointers
	; We can optimize this a lot by abusing the stack etc but
	; start simple. Take care as tmp/to/from are kernel mapped
	tsx
	ldx 2,x
	stx @tmp
	tsx
	ldx 4,x
	stx @to
	tsx
	ldx 6,x		; from
	stx @from
uputl:
	ldx @from
	ldab ,x
	inx
	stx @from
	ldx @to
	jsr map_process_always
	stab ,x
	jsr map_kernel
	inx
	stx @to
	ldx @tmp
	dex
	stx @tmp
	bne uputl
	clrb
	clra
	jmp ret6

	.zp

;
;	We should be ok not saving these on IRQ as we don't allow IRQs to
;	poke user space
;
to:
	.word 0
from:
	.word 0
