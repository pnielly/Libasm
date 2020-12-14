	global ft_strcmp
;rdi = s1, rsi = s2
	section .text
ft_strcmp:
	xor	rcx, rcx ; initialize rcx to 0
while:
	mov	al, byte [rdi + rcx] ; comparing s1[rcx] and s2[rcx] 
	cmp	al, byte [rsi + rcx]  ;  using a 8-bit registry as intermediary
;	jg	greater
;	jl	lower
	jne	end
	cmp	al, byte 0	; reached the end of s1
	je	end
	inc	rcx
	jmp	while

;greater:
;	mov	rax, 1
;	ret

;lower:
;	mov	rax, -1
;	ret

end:
	mov	rax, [rdi + rcx]
	sub	rax, [rsi + rcx]
	ret
