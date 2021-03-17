			section		.text
			global		_ft_strdup
			extern		_malloc
			extern		_ft_strlen
			extern		_ft_strcpy

ft_strdup:
			xor			rcx, rcx
			call		_ft_strlen
			mov			rcx, rax
			

done:
			ret