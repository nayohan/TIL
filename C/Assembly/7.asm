CODE SEGMENT
	ASSUME CS:CODE,DS:DATA
	
	MOV AX, DATA
	MOV DS, AX
	MOV CX, 100
	
A1:	
	;문자를 차례로 불러오고
	MOV DL, [ARRAY+DI]
	
	;1.문자아닌지 구별
	CMP DL, 41H
	JB EX
	CMP DL, 7AH
	JA EX
	
	;2.대문자인지 소문자인지 
	CMP DL, 5AH
	JB PR ;대문자이면 출력
	SUB DL, 20H ;소문자이면 20H뺄셈후 출력
	MOV DL, [ARRAY+DI]
	
	;3.문자 출력
PR:	MOV AH, 2
	INT 21H
	
	INC DI ;다음문자열로
	LOOP A1
	
EX:	MOV AH, 4CH
	INT 21H

CODE ENDS

DATA SEGMENT
	ARRAY	DB	'HelloWORLD'

DATA ENDS
END