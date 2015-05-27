%define buflen 2

global		_ft_cat
extern		_ft_puts

section .bss
	buffer:	resb	buflen


section		.text

_ft_cat:
	mov		r8, rdi

file_read:
	mov		rdi, r8
	mov		rax, 0x2000003		; syscall for read = 3
	lea		rsi, [rel buffer]	; our 2kb byte buffer
	mov		rdx, buflen			; the size of our buffer
	syscall
	jc		exit				; if read failed, exit.
	push	rax

file_out:
	mov		rdx, rax			; read returns amount of bytes read
	mov		rax, 0x2000004		; syscall write = 4
	mov		rdi, 1				; stdout = 1
	lea		rsi, [rel buffer]	; move buffer into the arguments
	syscall
	pop		rax
	cmp		rax, 1
	jge		file_read

exit:
	ret