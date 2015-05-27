global	_ft_isascii

section	.text

_ft_isascii:
	cmp		rdi, 0
	jl		not_it
	cmp		rdi, 127
	jle		is_ascii

not_it:
	mov		rax, 0
	ret

is_ascii:
	mov		rax, 1
	ret