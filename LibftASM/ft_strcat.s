global		_ft_strcat

section		.text

_ft_strcat:
	cmp		rdi, 0
	je		end
	cmp		rsi, 0
	je		end
	mov		rdx, rdi

first_loop:
	cmp		byte[rdi], 0
	je		concat
	inc		rdi
	jmp		first_loop

concat:
	mov		rax, [rsi]
	mov		[rdi], rax
	inc		rdi
	inc		rsi
	cmp		byte[rsi], 0
	je		before_end
	jmp		concat

before_end:
	mov		rax, rdx

end:
	ret
