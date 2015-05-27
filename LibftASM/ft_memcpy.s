global		_ft_memcpy

section		.text

_ft_memcpy:
	push	rdi
	push	rcx

	mov		rax, rdi
	mov		rcx, rdx
	rep		movsb

	pop		rcx
	pop		rax
	ret