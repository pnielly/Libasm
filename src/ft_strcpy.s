	global ft_strcpy
; rdi = dest, rsi = src

	section .text
ft_strcpy:
	xor	rcx, rcx		; rcx initialized

while:
	cmp	byte [rsi + rcx], byte 0 ; did we encounter a null byte?
	jz	end_while 		; yes, get out from the loop
	mov	al, [rsi + rcx] 	; no, cpy the current char from src into dest
	mov	[rdi + rcx], al 	; ...using an 8-bits sized register as intermediary
	inc	rcx			; i++
	jmp	while			; go back up

end_while:
	mov	byte [rdi + rcx], byte 0	; dest[len] = 0
	mov	rax, rdi		; put value of rdi into rax (return)
	ret
