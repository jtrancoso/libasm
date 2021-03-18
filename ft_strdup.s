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
			call		_ft_strcpy
done:
			ret

failure:
			mov			r8, 12
			call 		___error
			mov			[rax], r8
			pop			rdi
			ret