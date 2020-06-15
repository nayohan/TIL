CODE SEGMENT
	ASSUME CS:CODE,DS:DATA
	
	MOV AX, DATA
	MOV DS, AX
	MOV CX, 3
	
A1:	
	;1.BL에 최종결과값을 업데이트
	MOV DL, [ARRAY+DI]
	CMP BL, DL
	JA EN ;숫자가 크면 지나치고
	MOV BL, DL ; 숫자가 작으면 업데이트한다.
	
EN: INC DI
	LOOP A1
	
	MOV AX, BX ;최종값 저장
	;숫자 출력
	
	CMP		DL, 10			;10보다 큰지 확인
	JAE		TWO				;크거나 같으며 두자리출력
	
ONE:;10보다 작으면 그냥 한자리 출력
	ADD		DL, 48			
	MOV 	AH, 2			
	INT		21H
	RET
	
TWO:;10보다 크면 두자리를 출력		;DIV 명령어는
	MOV		DL, 10			;AX:피제수(14)를, DL:제수(10)로 나누어 
	DIV		DL				;몫은 AL, 나머지는 AH에 저장시킨다
	
	MOV		BX, AX			;일단 결과를 BX에 저장	
	MOV		DL, BL			;BL에서 10의 자리 가져오고,
	ADD		DL, 48			;10의 자리(몫) 출력
	MOV 	AH, 2			
	INT		21H		
	
	MOV		DL,  BH			;BH에 있는 1의자리숫자를 DL로 옮기고,
	ADD		DL, 48			;1의 자리(나머지) 출력
	MOV 	AH, 2			
	INT		21H

	
EX:	MOV AH, 4CH
	INT 21H

CODE ENDS

DATA SEGMENT
	ARRAY DB 41,21,31

DATA ENDS
END