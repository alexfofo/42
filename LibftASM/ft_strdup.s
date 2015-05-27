global		_ft_strdup
extern		_ft_strlen
extern		_ft_memcpy
extern		_malloc

section		.text

_ft_strdup:
	call	_ft_strlen
	inc		rax			; rajoute 1 a strlen pour prendre en compte le \0
	push	rax
	mov		rsi, 8		; pour multiplier rax (le retour de strlen) par la taille dun char, soit 8bits
	mul		rsi			; fait la multiplication et stock ca dans rax
	push	rdi
	mov		rdi, rax
	call	_malloc

	pop		rsi
	pop		rdx
	mov		rdi, rax
	call	_ft_memcpy

end:
	ret