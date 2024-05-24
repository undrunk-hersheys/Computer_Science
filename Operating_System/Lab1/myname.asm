org 0x100
section .text
start:
mov dx,myname ; Write the location of the string ‘Hello DOS’ in register dx
mov ah,9 ; Write the number 9 in register ah
; 9 is the System Call to write a string to standard output
int 0x21 ; Make the System Call
mov ax,0x4c00 ; Write the number 0x4c00 in register ax
; 0x4c is the System Call to exit the program
int 0x21 ; Make the System Call
section .data
myname db 'GyuhoTAE', 13, 10, '$' ; The string ‘Hello DOS’ and a newline