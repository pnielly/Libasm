	global ft_read
section .text
	extern __errno_location
ft_read:
	mov	rax, 0 ; syscall for read
	syscall
	cmp	rax, 0 ; error? (return < 0)
	jl	error ; yes, go to error
	ret	; no, return rax

error:
	mov rdx, rax
	neg rdx
	call __errno_location
	mov [rax], rdx
	mov rax, -1
	ret
