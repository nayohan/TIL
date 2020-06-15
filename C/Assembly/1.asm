; 문자를 출력하는 프로그램
;두가지 방법중 쉬운걸로(양식_)
;같으면 같은 이름을 써도됌 
; CV /S 1.EXE

MAIN 	SEGMENT			; 처음시작할떄 세그먼트 설정
	ASSUME CS:MAIN, DS:MAIN
	
	MOV 	AX, CS		
	MOV 	DS, AX     	;DS CS이런식으로 쓰는것을 막아놨다
	
	MOV 	BX, OFFSET L1	;세그먼트 주소로부터 얼마나 떨어져 있는지가 					;오프셋L1의 주소를 알아야함	L1 시작점 BX 가
	MOV 	DL, [BX]		;[]주소에 있는 값을 DL에 넣고
	MOV 	AH,2		;ASCII로
	INT	21H  		;화면에 출력

	MOV 	DL, [BX+1]	;DB라 1을 더함  DW이면 2를 더해야함.
	MOV 	AH,2		;
	INT	21H  		;화면에 출력

	MOV 	DL, [BX+2]	;
	MOV 	AH,2		;
	INT	21H  		;
	
	MOV 	AH,4CH		;종료를 하고 OS에게 제어권을 넘겨줌
	INT 	21H
L1	DB	'A','B','C'		;출력	

MAIN	ENDS			;세그먼트가 끝남
	END


;0584 세그먼트 주소 CS:0584
;오프셋은 0으로 시작 001f OFFSET1