
run: 
	@echo "type 'make bios' or 'make memwrite' or "
	@echo "'make myname_bios' or 'make myname_memwrite' or 'make clean'"

bios: hello_bios.bin
	qemu-system-i386 -soundhw all -drive format=raw,file=hello_bios.bin
	rm hello_bios.bin

hello_bios.bin: hello_bios.asm colors.asm ascii_codes.asm init_segment_registers.asm
	nasm -fbin hello_bios.asm -o hello_bios.bin

memwrite: hello_memwrite.bin
	qemu-system-i386 -soundhw all -drive format=raw,file=hello_memwrite.bin
	rm hello_memwrite.bin

hello_memwrite.bin: hello_memwrite.asm colors.asm ascii_codes.asm init_segment_registers.asm
	nasm -fbin hello_memwrite.asm -o hello_memwrite.bin

myname_bios: myname_bios.bin
	qemu-system-i386 -soundhw all -drive format=raw,file=myname_bios.bin

myname_bios.bin: myname_bios.asm colors.asm ascii_codes.asm init_segment_registers.asm
	nasm -fbin myname_bios.asm -o myname_bios.bin

myname_memwrite: myname_memwrite.bin
	qemu-system-i386 -soundhw all -drive format=raw,file=myname_memwrite.bin

myname_memwrite.bin: myname_memwrite.asm colors.asm ascii_codes.asm init_segment_registers.asm
	nasm -fbin myname_memwrite.asm -o myname_memwrite.bin

clean:
	rm *.bin 

