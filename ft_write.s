			section		.text
			global		_ft_write
			extern		___error

_ft_write:
			mov			rax, 0x2000004					; we put write syscall to rax
			syscall										; we call syscall, it does write
			jc			failure
			ret											; the string to write is returned in rax

failure:
			mov			rcx, rax						; copy rax to rcx
			push		rcx								; we save rcx
			call		___error						; we call error, it puts errno in rax
			pop			rcx								; we get rcx back
			mov			DWORD[rax], ecx					; we move the errno to rax
			mov			rax, -1							; then we return -1
			ret