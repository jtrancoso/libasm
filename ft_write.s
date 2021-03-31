			section		.text
			global		_ft_write
			extern		___error

_ft_write:
			mov			rax, 0x2000004					; we put write syscall to rax
			syscall										; we call syscall, it does write
			cmp			rax, -1
			je			failure
			ret											; the array to write is returned in rax

failure:
			mov			r8, -1
			call		___error
			mov			[rax], r8
			ret