	.file	"helloName.c"
gcc2_compiled.:
__gnu_compiled_c:
.text
.LC0:
	.ascii "Hello, Gyuho Tae\0"
	.even
.globl PilotMain
PilotMain:
	link.w %a6,#-24
	tst.w 8(%a6)
	jbne .L3
	move.w #150,-(%sp)
	move.w #80,-(%sp)
	move.w #16,-(%sp)
	lea .LC0(%pc),%a0 /*SPECIAL_FRED*/
	move.l %a0,-(%sp)
#APP
	trap #15; dc.w 0xA220
#NO_APP
	lea (10,%sp),%sp
	.even
.L4:
	pea -1.w
	moveq.l #-24,%d0
	add.l %a6,%d0 /*JANE2*/
	move.l %d0,-(%sp)
#APP
	trap #15; dc.w 0xA11D
#NO_APP
	addq.l #8,%sp
	moveq.l #-24,%d0
	add.l %a6,%d0 /*JANE2*/
	move.l %d0,-(%sp)
#APP
	trap #15; dc.w 0xA0A9
#NO_APP
	addq.l #4,%sp
.L6:
	cmp.w #22,-24(%a6)
	jbne .L7
	bra .L3
	.even
.L7:
	bra .L4
	.even
.L5:
.L3:
	moveq.l #0,%d0
	bra .L2
	.even
.L2:
	unlk %a6
	rts
