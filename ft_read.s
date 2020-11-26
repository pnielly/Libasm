	global ft_read
section .text
ft_read:
	mov	rax, 0 ; syscall for read
	syscall
	cmp	rax, 0 ; error? (return < 0)
	jl	error ; yes, go to error
	ret	; no, return rax

error:
