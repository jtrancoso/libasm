			global start

			section .text
start:		mov		rax, 0x02000004
			mov		rdi, 1
			mov		rsi, message
			mov		rdx, 11
			syscall
			mov		rax, 0x02000001
			xor		rdi, rdi
			syscall

			section .data
message:	db		"Hello, Ana", 10