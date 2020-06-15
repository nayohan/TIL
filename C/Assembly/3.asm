;7,3,4중에 제일 작은 걸 찾아보자

MAIN 	SEGMENT
	ASSUME	CS:MAIN, DS:MAIN

	MOV AX, CS
	MOV DS, AX

	;읽고 비교하고 점프
	;시작점 지정
	MOV SI, OFFSET VAL	;SI가  VAL의 시작주소를 가짐
	MOV AL,[SI]		;SI의 값7을 AL에 저장

	ADD SI, 1			;SI에 1을 저장
	CMP AL,[SI]		;7과 3을 비교한다.
	
	;분기 ;AL이 작거나 같으면 
	JBE	L1
	;그렇지 않으면
	MOV AL, [SI]
	;현재 AL이 가장 작은 값을 가짐

L1: CMP 	AL, [SI+1]
	JBE	L2
	MOV 	AL, [SI+1]

L2:	MOV	SMALL, AL ;완료되면 저장
	MOV	DL, AL	;출력을 해보자
	ADD	DL, 48	;ASCII코드를 출력하기위해 DEC48을더해서 0부터 시작
	MOV	AH, 2
	INT	21H

	MOV	AH, 4CH;
	INT 	21H	; 시스템 콜

SMALL	DB	? ;바이트단위로 쓰기
VAL	DB	7,3,4

MAIN 	ENDS
	END