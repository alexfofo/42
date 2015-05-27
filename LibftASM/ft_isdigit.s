global	_ft_isdigit

section	.text

_ft_isdigit:
	cmp		rdi, 48
	jl		not_digit
	cmp		rdi, 57
	jle		is_digit

not_digit:
	mov		rax, 0
	ret

is_digit:
	mov		rax, 1
	ret