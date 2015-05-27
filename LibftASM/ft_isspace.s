global	_ft_isspace

section	.text

_ft_isspace:
	cmp		rdi, 9
	jl		not_space
	cmp		rdi, 13
	jle		is_space
	cmp		rdi, 32
	je		is_space

not_space:
	mov		rax, 0
	ret

is_space:
	mov		rax, 1
	ret