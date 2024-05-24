;myName.asm written by gyuho tae

section .data

msg:
DB 'Gyuho Tae', 10

msgSize EQU $-msg
global start

section .text

start:
mov rax, 4 ;write system call 4 (write) into register rax
mov rbx, 1 ;write output location1 (stdout) into register rbx
mov rcx, msg 
mov rdx, msgSize
int 0x80 ;make a linux system call

mov rax, 1
mov rbx, 0
int 0x80 

ret
