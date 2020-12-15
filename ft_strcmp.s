	global ft_strcmp
;rdi = s1, rsi = s2
	section .text
ft_strcmp:
	xor	rcx, rcx ; initialize rcx to 0
while:
	mov	bl, byte [rdi + rcx] ; comparing s1[rcx] and s2[rcx] 
	mov	dl, byte [rsi + rcx]  ;  using a 8-bit registry as intermediary
	cmp	bl, dl  ;  using 8-bit registries as intermediary since parameters are const
;	jg	greater ; old version of strcmp
;	jl	lower 	; old version of strcmp
	jne	end
	cmp	bl, byte 0	; reached the end of s1 (and therefore of s2 since s1[i] = s2[i])
	je	end
	inc	rcx
	jmp	while

;greater: 	old version
;	mov	rax, 1
;	ret

;lower: 	old version
;	mov	rax, -1
;	ret

end:
	sub	bl, dl ; return (s1[i] - s2[i])
	movsx	rax, bl ; movsx allows to copy a smaller register in a bigger register and keep sign
	ret
