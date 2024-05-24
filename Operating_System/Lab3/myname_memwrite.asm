%include "colors.asm"
%include "ascii_codes.asm"

start:
%include "init_segment_registers.asm"

main:
	mov byte [xpos], 0 ;starting in 0th column
	mov byte [ypos], 8 ;starting in 8th row
	mov byte [color], GREEN
	call print_hello

end_loop:
	jmp end_loop
	
print_hello:
	mov byte [char], CHAR_G
	call memwrite_print_char
	add byte [ypos], 1
	mov byte [char], CHAR_y
	call memwrite_print_char
	add byte [ypos], 1
	mov byte [char], CHAR_u
	call memwrite_print_char
	add byte [ypos], 1
	mov byte [char], CHAR_h
	call memwrite_print_char
	add byte [ypos], 1
	mov byte [char], CHAR_o
	call memwrite_print_char
	ret

;al character to print
;bl colour

;cx char and colour
;ax row offset
;bx column offset
;di total offset in video memory

memwrite_print_char:
	mov ah, [color]
	mov al, [char]
	mov cx, ax
	movzx ax, byte [ypos]
	mov dx, 160
	mul dx
	movzx bx, byte [xpos]
	shl bx, 1
	mov di, 0
	add di, ax
	add di, bx
	
	mov ax, cx
	stosw
	
	ret
xpos db 0
ypos db 0
color db 0
char db 0

times 510-($-$$) db 0
dw 0AA55h
