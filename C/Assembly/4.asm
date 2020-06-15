;ARRAY에서 제일 작은것과 제일큰것을 찾아서 DW저장하고 출력해보자.
MAIN 	SEGMENT
	ASSUME	CS:MAIN, DS:MAIN

	MOV 	AX,CS
	MOV 	DS,AX

	MOV 	DI, OFFSET ARRAY
	MOV 	AX, [DI]		;15를 읽음
	MOV		LARGEST,AX		;일단 첫번째 데이터를 불러옴
	MOV 	SMALLEST, AX
	MOV		CX, 6			;반복을 위한 카운트

;---------------------------;해당구간 6번 반복
A1:
	MOV 	AX, [DI]
	CMP		AX, SMALLEST
	JGE		A2				;
	MOV 	SMALLEST, AX

A2:							;SMALLEST가 제일 작은 값을 가진다.
	CMP		AX, LARGEST
	JLE		A3				;AX가 작거나 같으면  A3
	MOV 	LARGEST, AX 	;그렇지 않을때 LARGEST에 값 저장

A3:							;데이터위치가 안바뀌는 상황이 오면
	ADD		DI, 2			;ARRAY의 번지를 가리키는 DI를 DW(2)만큼 업
	LOOP	A1
;---------------------------
	MOV 	AX, SMALLEST
	MOV		DL, AL
	CMP		DL, 10			;10보다 큰지 확인
	JB		ONE				;작으면 한자리 출력
	;JAE		TWO				;크거나 같으며 두자리출력
	
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
	RET
			
ET: MOV	AH, 4CH				;종료
	INT	21H

ARRAY	DW	14, 5, 8, 9, 2, 6 	;워드단위(2바이트)
LARGEST DW	?
SMALLEST DW	?

MAIN  	ENDS
	END