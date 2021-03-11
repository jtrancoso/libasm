			section		.text
			global		_ft_strlen

_ft_strlen:
			xor			rax, rax				; clear rax
			jmp			compare
increment:
			inc			rax						; i++
compare:	
			cmp			BYTE [rdi + rax], 0		; str[i] == 0
			jne			increment				; if != 0, i++
done:
			ret									; return i
