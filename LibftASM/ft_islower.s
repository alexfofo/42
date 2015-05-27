global	_ft_islower

section	.text

_ft_islower:
	cmp		rdi, 97
	jl		not_lower
	cmp		rdi, 122
	jle		is_lower

not_lower:
	mov		rax, 0
	ret

is_lower:
	mov		rax, 1
	ret