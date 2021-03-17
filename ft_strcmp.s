			section		.text
			global		_ft_strcmp

_ft_strcmp:
			xor			r8, r8									; i = 0
			xor			rcx, rcx								; x = 0
			xor			rax, rax								; ret = 0
			jmp			compare

compare:
			mov			al, BYTE[rdi + r8]						; aux = s1[i]
			mov			cl, BYTE[rsi + r8]						; aux2 = s2[i]

			cmp			al, 0									; if s1[i]
			je			end_loop								; go to end

			cmp			al, cl									; if s1[i] != s2[i]
			jne			end_loop								; go to end

			inc			r8										; i++ and loop again
			jmp			compare

end_loop:
			sub			rax, rcx								; return s2 - s1
			ret