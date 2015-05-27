global	_ft_iscntrl

section	.text

_ft_iscntrl:
	cmp		rdi, 0
	jl		not_cntrl
	cmp		rdi, 32
	jl		is_cntrl
	cmp		rdi, 127
	jl		not_cntrl
	je		is_cntrl

not_cntrl:
	mov		rax, 0
	ret

is_cntrl:
	mov		rax, 1
	ret