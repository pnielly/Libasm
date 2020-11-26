	global	ft_strdup
;rdi = s
extern ft_strlen
;rdi = s
extern malloc
;rdi = size
extern ft_strcpy
	section .text
ft_strdup:
	cmp	rdi, 0	; s = NULL?
	je	str_is_null	; jmp to strnull

ft_strlen:
	call	ft_strlen
	push	rdi	; saving rdi, cause it will be used for malloc
	inc	rax	; +1 for the '\0'
	mov	rdi, rax	; return from ft_strlen become 1st arg for malloc
	call	malloc
	cmp	dword rax, dword 0 ; comparing int here, so size = dword
	je	error_malloc
	pop	rdi	; getting back rdi saved value
	mov	rsi, rdi	; rdi value become 2nd arg for ft_strcpy
	mov	rdi, rax	; return from malloc is 1st arg for ft_strcpy
	call	ft_strcpy
	ret

error_malloc:
	;DEAL ERROR WITH ERRNO

str_is_null:
	mov	rax, 0
	ret
