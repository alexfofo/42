global	_ft_isalpha

section	.text

_ft_isalpha:
	cmp		rdi, 65
	jl		not_alpha
	cmp		rdi, 90
	jle		is_alpha
	cmp		rdi, 97
	jl		not_alpha
	cmp		rdi, 122
	jle		is_alpha

not_alpha:
	mov		rax, 0
	ret

is_alpha:
	mov		rax, 1
	ret