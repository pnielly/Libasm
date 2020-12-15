	global ft_strlen
	
	section .text
ft_strlen:
	xor	rcx, rcx ; elegant way to put rcx to 0, rcx will be our counter

_while:
	cmp	[rdi], byte 0 ; are we looking at the null byte?
	jz	_end_while	;yes, go return rcx
	inc	rcx 		;no, increment rcx...
	inc	rdi		;...and move to next char
	jmp	_while		;and do it again

_end_while:
	mov	rax, rcx	; rax holds the return value
	ret
