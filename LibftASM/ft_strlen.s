global		_ft_strlen

section		.text

_ft_strlen:
	push rdi
	push rsi

	mov		rsi, rdi
	mov		rax, 0
	repne	scasb

	sub		rdi, rsi
	sub		rdi, 1
	mov		rax, rdi

	pop rsi
	pop rdi
	ret
;# 	push	rcx
;# 	xor		rcx, rcx

;# strlen_next:
;# 	cmp		[rdi], byte 0
;# 	jz		strlen_null
;# 	inc		rcx
;# 	inc		rdi
;# 	jmp		strlen_next

;# strlen_null:
;# 	mov		rax, rcx

;# 	pop		rcx
;# 	ret