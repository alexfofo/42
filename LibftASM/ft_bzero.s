global		_ft_bzero

section		.text

_ft_bzero:
	mov		rax, rdi
	cmp     rax, 0
	je		end
	cmp		rsi, 0
	jle		end

bzero_loop:
	cmp		rsi, 0
	je		end
	mov		byte[rax], 0
	inc		rax
	dec		rsi
	jmp		bzero_loop


end:
	ret