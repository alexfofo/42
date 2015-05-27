global	_ft_isupper

section	.text

_ft_isupper:
	cmp		rdi, 65
	jl		not_upper
	cmp		rdi, 90
	jle		is_upper

not_upper:
	mov		rax, 0
	ret

is_upper:
	mov		rax, 1
	ret