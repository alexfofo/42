global	_ft_ispunct

section	.text

_ft_ispunct:
	cmp		rdi, 33
	jl		not_punct
	cmp		rdi, 47
	jle		is_punct
	cmp		rdi, 58
	jl		not_punct
	cmp		rdi, 64
	jle		is_punct
	cmp		rdi, 91
	jl		not_punct
	cmp		rdi, 96
	jle		is_punct
	cmp		rdi, 123
	jl		not_punct
	cmp		rdi, 126
	jle		is_punct

not_punct:
	mov		rax, 0
	ret

is_punct:
	mov		rax, 1
	ret