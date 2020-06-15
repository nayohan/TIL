;두번째 템플릿
;두개의 숫자를 더해서 저장

title 2.asm
.model small
.stack 100h

.data
a	db	2
b	db	5
sum 	db	?
;dw대신 생각하기편하게 db로 바굼
.code
main 	proc
	mov 	ax,@data
	mov	ds, ax
	
	;코드가 들어갈 부분----------------
	;mov 	ax, a
	;;mov	bx, b	;add ax,b b의값을 ax에다가 더해서 저장하는 방법도 있다
	;add 	ax, b
	;mov	sum, ax

	;db로 작성시
	mov 	al, a
	add 	al, b
	mov	sum, al
	
	add	al, '0'
	mov	dl, al
	mov 	ah, 2
	int	21h

	;-------------------------------------
	mov 	ax, 4c00h		;ah 4c al 00이 들어감
	int	21h

main	endp
	end	main