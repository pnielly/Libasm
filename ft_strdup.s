	global	ft_strdup
;rdi = s
extern ft_strlen
;rdi = s
extern malloc
;rdi = size
extern ft_strcpy
extern __errno_location
	section .text
ft_strdup:
	cmp	rdi, 0	; s = NULL?
	je	str_is_null	; jmp to strnull
	push	rdi		; saving rdi, cause it will be used by ft_strlen
	call	ft_strlen
	inc	rax		; +1 for the '\0'
	mov	rdi, rax	; return from ft_strlen become 1st arg for malloc
	call	malloc
	cmp	rax, 0 		; did malloc fail?
	je	error_malloc ; malloc failed
	pop	rdi		; getting back rdi saved value, will be used for ft_strcpy
	mov	rsi, rdi	; rdi value become 2nd arg for ft_strcpy
	mov	rdi, rax	; return from malloc is 1st arg for ft_strcpy
	call	ft_strcpy
	ret

error_malloc:
	mov	rdi, rax
	neg	rdi
	push	rdi ; save rdi cause it will be used for errno_location
	call	__errno_location
	mov	[rax], rdi ; ret of errno_location is an int*, setting right value to errno
	mov	rax, -1
	ret

str_is_null:
	xor	rax, rax
	ret
