	global	ft_atoi_base
;rdi = char *s, rsi = char *base

;my variables :
;r8 = length of base
;r9 = sign

	extern	ft_strlen
;rdi = char *base

	section .text

ft_atoi_base:
	cmp	rdi, 0	; rdi = NULL?
	je	no_nb ; return (0) 
	xor	rcx, rcx	; will use rcx as index; i = 0

; GETTING BASE LENGTH
base_length:
	push	rdi	; saving rdi (will use the register to call ft_strlen)
	mov	rdi, rsi	; char *base is #1 arg for ft_strlen()
	call	ft_strlen
	pop	rdi		; getting back value of *s into rdi
	cmp	rax, 1		; checking error : base_length =< 1
	jle	error
	mov	r8, rax		; r8 is the length of the base
	xor	rcx, rcx	; rcx = 0 just in case (necessary for label below)

; CHECKING BASE FOR ERRORS
checking_duplicate:	; if a char appears more than once in base : error
	mov	r10b, byte [rsi + rcx]	; r10 will hold the currently checked char (r10b is 8-bit)
	mov	r11, rcx	; saving current index of base
	cmp	r10, 43	; r10 = '+'?
	je	error	; base can't harbor '+' or '-'
	cmp	r10, 45	; r10 = '-'?
	je	error	; base can't harbor '+' or '-'
	cmp	r10, 32	; r10 = ' '?
	je	error	; base can't harbor whitespace
	cmp	r10, 12	; r10 = '\f'?
	je	error	; base can't harbor whitespace
	cmp	r10, 9	; r10 = '\t'?
	je	error	; base can't harbor whitespace
	cmp	r10, 10	; r10 = '\n'?
	je	error	; base can't harbor whitespace
	cmp	r10, 13	; r10 = '\r'?
	je	error	; base can't harbor whitespace
	cmp	r10, 11	; r10 = '\v'?
	je	error	; base can't harbor whitespace

loop_dup:
	inc	rcx	; i++
	cmp	r10b, byte [rsi + rcx] ; do we have a duplicate?
	je	error			; got a duplicate --> error
	cmp	byte [rsi + rcx], 0	; reached the end of base?
	je	next_loop_dup
	jmp	loop_dup

next_loop_dup:
	inc	r11	; index++ (will check the next char of base)
	mov	rcx, r11
	cmp	byte [rsi + rcx], 0	; checked whole base ?
	je	end_loop_dup
	jmp	checking_duplicate
	
end_loop_dup:
	mov	rcx, -1 ; useful for the skip_spaces label

; SKIPPING SPACES
skip_spaces:
	inc	rcx	; i++
	cmp	byte [rdi + rcx], 32	; s[i] = ' ' ?
	je	skip_spaces
	cmp	byte [rdi + rcx], 12	; s[i] = '\f' ?
	je	skip_spaces
	cmp	byte [rdi + rcx], 9	; s[i] = '\t' ?
	je	skip_spaces
	cmp	byte [rdi + rcx], 10	; s[i] = '\n' ?
	je	skip_spaces
	cmp	byte [rdi + rcx], 13	; s[i] = '\r' ?
	je	skip_spaces
	cmp	byte [rdi + rcx], 11	; s[i] = '\v' ?
	je	skip_spaces
; if we reach this point, all spaces are skipped

; GETTING THE SIGN
get_sign:
;	cmp	byte [rdi + rcx], 43	; s[i] = '+' ?
	cmp	byte [rdi + rcx], 45	; s[i] = '-' ?
	je	sign_neg
	jmp	sign_pos

sign_neg:
	mov	r9, -1	; if negative, sign = -1
	jmp	read_number

sign_pos:
	mov	r9, 1		; sign = 1
	dec	rcx		; i-- to cancel the i++ in the loop
	jmp	read_number

; READING THE NUMBER
read_number:
	xor	rax, rax	; rax = 0. rax is ret
	xor	r11, r11	; r11 = 0. r11 is n-th char in base
	jmp	loop

get_value:
	cmp	byte [rsi, r11], 0 ; did we reach end of base (meaning s[i] doesn't belong to base...)
	je	end_loop
	mov	dl, byte [rsi + r11] ; s[rcx] == base[r11] ? (dl is used as intermediary)
	cmp	byte [rdi + rcx], dl ; s[rcx] == base[r11] ?
	je	loop	; yes, go back to loop
	inc	r11	; will check next base char, r11++
	jmp	get_value

loop:
	inc	rcx	; i++
	mul	r8	; rax = rax * base_length
	add	rax, r11 ; rax = rax + r11
	xor	r11, r11	; r11 = index of base, here we reinitialize it to 0
	cmp	byte [rdi + rcx], 0 	; did we reach end of string ?
	je	end_loop
	jmp	get_value

end_loop:
	cmp	r9, 0
	jg	return
	neg	rax

return:
	ret

no_nb:
	xor	rax, rax	; rax = 0
	ret			; return (0)

; ERROR CASES
error:
	xor	rax, rax	; rax = 0
	ret			; return (0)
