;;hello_bios.asm written by Gyuho Tae

%include "colors.asm"
%include "ascii_codes.asm"
%include "init_segment_registers.asm"

main:
	call print_hello
end_loop:
	jmp end_loop
	
	
;al current character to print
;bl colour
print_hello:
	mov bl, GREEN
	mov al, CHAR_H
	call bios_print_char
	mov bl, GREEN
	mov al, CHAR_e
	call bios_print_char
	mov bl, GREEN
	mov al, CHAR_l
	call bios_print_char
	mov bl, GREEN
	mov al, CHAR_l
	call bios_print_char
	mov bl, GREEN
	mov al, CHAR_l
	call bios_print_char
	mov bl, GREEN
	mov al, CHAR_o
	call bios_print_char
	mov al, CHAR_SPACE
	call bios_print_char
	ret

;print single character with bios call
bios_print_char:
	mov ah, 0x0E
	int 0x10
	ret
	
times 510-($-$$) db 0
dw 0AA55h
