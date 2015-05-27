global	_ft_isprint

section	.text

_ft_isprint:
	cmp		rdi, 32
	jl		not_print
	cmp		rdi, 127
	jl		is_print

not_print:
	mov		rax, 0
	ret

is_print:
	mov		rax, 1
	ret