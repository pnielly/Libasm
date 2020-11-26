	global	ft_write
	extern	errno_location
; rdi = fd , rsi = *buf, rdx = size
section .text

ft_write:
	mov	rax, 1	; syscall for write
	syscall
	cmp	rax, 0 ; checking if syscall returned < 0 (error)
	jl	error ; if yes --> error label
	ret

error:
	mov	rdi, rax
	mov	eax, -1
	mul	rdi
	call	errno_location
