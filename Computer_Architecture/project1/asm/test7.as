	lw 0 2 photo
	lw 0 3 shot
	lw 0 4 neg
loop beq 0 3 done
	add 1 2 1
	add 3 4 3
	beq 0 0 loop
done halt
photo .fill 5544
shot .fill 3322
neg .fill -1
