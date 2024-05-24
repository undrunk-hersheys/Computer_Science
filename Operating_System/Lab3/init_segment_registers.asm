;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; =============================================================
;; init_segment_registers.asm		Written by David Wagner
;; =============================================================
;;
;; Initialize the segment registers when the program starts
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;  Initialization Routines
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

init:
	;; Segment Map

	;-------------------------- <--- 0x00000 (FS)
	;| Interrupt Vector Table |
	;-------------------------- <--- 0x00400
	;|                        |
	;-------------------------- <--- 0x007C0 (DS)
	;|    Boot Sector Code    |
	;-------------------------- <--- 0x009C0
	;|                        |
	;|                        |
	;-------------------------- <--- 0x0B800 (ES)
	;|   Text Video Memory    |
	;-------------------------- <--- 0x0BA00 


	.init_segment_registers:

	;; Interrupt Vector Table (FS) = 0x0000
		xor ax, ax ; mov ax, 0
		mov fs, ax ; mov fs, 0

	;; Boot Sector Code (DS) = 0x07C0
		push 0x07C0
		pop ds 	; mov ds, 0x07C0

	;; Text Video Memory (ES) = 0xB800
		push 0xB800
		pop es  ; mov es, 0xB800


