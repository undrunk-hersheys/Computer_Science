	lw 0 0 zero
	lw 0 1 init
	lw 0 2 mcand
	lw 0 3 mplier
	lw 0 4 index
	lw 0 5 large
	lw 0 6 zero
	lw 0 7 one
loop	nor 3 3 3
	nor 4 4 4
	nor 3 4 6
	nor 3 3 3
	nor 4 4 4
	beq 0 6 point
point	add 4 4 4
	add 2 2 2
	beq 4 5 fin
	beq 0 0 loop
fin	halt
mcand	.fill 27252
index	.fill 67852
index	.fill 1
init	.fill 0
zero	.fill 0
one	.fill 1
large	.fill 32768
