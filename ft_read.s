			section		.text
			global		_ft_read
			extern		___error

_ft_read:
			mov			rax, 0x2000003					; we put read syscall to rax
			syscall										; we call syscall, it does read
			jc			failure							; if error carry flag, we jump to failure
			ret											; we return read in rax

failure:
			mov			rcx, rax						; copy rax to rcx
			push		rcx								; we save rcx
			call		___error						; we call error, it puts errno in rax
			pop			rcx								; we get rcx back
			mov			DWORD[rax], ecx					; we move the errno to rax
			mov			rax, -1							; then we return -1
			ret