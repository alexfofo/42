global		_ft_memset
extern		_ft_puts

section		.text

_ft_memset:
	push	rdi
	push	rcx

	mov		rax, rsi
	mov		rcx, rdx
	cld
	rep		stosb

	pop		rcx
	pop		rax
	ret