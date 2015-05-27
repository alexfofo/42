
global  _ft_toupper

section .text

_ft_toupper:

	cmp		rdi, 97
	jl		not_lower
	cmp		rdi, 122
	jg		not_lower
	sub		rdi, 32
	mov		rax, rdi
	ret


not_lower:
	mov		rax, rdi
	ret