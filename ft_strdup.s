			section		.text
			global		_ft_strdup
			extern		_malloc
			extern		_ft_strcpy
			extern		_ft_strlen
			extern		___error

_ft_strdup:
			push		rdi						; we save rdi in the stack
			call		_ft_strlen
			mov			rdi, rax
			inc			rdi
			call		_malloc					; call malloc, it goes to rax
			cmp			rax, 0					; if !rax, we return 0
			je			failure
			mov			rdi, rax				; we move malloc pointer to rdi
			pop			rsi						; 
			call		_ft_strcpy				; we call strcpy
			ret

failure:
			mov			r8, 12					; we move the 12 to get that errno in r8
			call 		___error				; we call error, it returns a the error message number 12
			mov			[rax], r8				; we then move r8 to rax
			pop			rdi						; we align the stack
			ret