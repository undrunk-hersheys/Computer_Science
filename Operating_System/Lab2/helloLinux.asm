;helloLinux.asm written by gyuho tae

section .data

msg:
DB 'Hello Linux', 10 ;10 defines new line \n in ASCII CODE

msgSize EQU $-msg ;EQU represent the define
global start

section .text

start:
mov rax, 4 ;write system call 4 (write) into register rax
mov rbx, 1 ;write output location1 (stdout) into register rbx
mov rcx, msg ;copy the location of the message into register rcx
mov rdx, msgSize ;copy the size of message into register rdx
int 0x80 ;make a linux system call

mov rax, 1 ;write system call 1 (exit) into register rax
mov rbx, 0 ;write number 0 into the register rbx
int 0x80 

ret

;overall rax rbx rcx rdx each register has own works to do
;and seems like
;rax is systemcall
;rbx is more specific call
;rcx contains data
;rdx contains size
;and int 0x80 make linux system call to activate
