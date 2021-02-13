			section		.text
			global		_ft_strcpy

_ft_strcpy:									; dst = rdi, src = rsi
			xor		rcx, rcx				; clear rcx i = 0
			cmp		rsi, 0					; if !src
			je		return					; return dest
			jmp		copy
increment:
			inc		rcx						; i++
copy:
			mov		dl, BYTE[rsi + rcx]		; aux[i] = src[i]
			mov		BYTE[rdi + rcx], dl		; dest[i] = aux[i]
			cmp		dl, 0					; if dest[i], i++
			jne		increment
return:		
			mov		rax, rdi				; return dest
			ret