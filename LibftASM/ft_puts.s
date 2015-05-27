global		_ft_puts
extern		_ft_strlen

section		.data
	nl	db	0x0a

section		.text

_ft_puts:
	cmp		rdi, 0
	je		end
	push	rdi
	call	_ft_strlen
	pop		rdi
	mov		rdx, rax
	mov		rax, 0x2000004
	mov		rsi, rdi
	mov		rdi, 1
	syscall
	mov		rax, 0x2000004
	mov		rdi, 1
	lea		rsi, [rel nl]
	mov		rdx, 2
	syscall

end:
	ret

