			section		.text
			global		_ft_strcmp

_ft_strcmp:
			xor			rcx, rcx								; clear rcx i = 0
			jmp			compare

compare:
			mov			dl, BYTE[rsi + rcx]
			cmp			dl, BYTE[rdi + rcx]						; if s1[i] == s2[i]
			jl			greater
			jg			lower
			je			equal

lower:
			mov			rax, -1
			ret

greater:	mov			rax, 1
			ret

equal:		mov			rax, 0
			ret