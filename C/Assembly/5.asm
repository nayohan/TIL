MAIN   SEGMENT
   ASSUME   CS:MAIN, DS:MAIN

   MOV   ax,cs
   MOV   ds,ax
   MOV CX, 0000h

   MOV   di, offset ARRAY
   MOV   ax, [di]
   MOV   largest, ax
   MOV   smallest, ax
   
A1:
   CMP CX, 6
   JE EXIT
   MOV   ax, [di]
   CMP   ax, smallest
   JGE   A2
   MOV   smallest, ax
   
A2:
   cmp   ax, largest
   JLE   A3
   MOV   largest, ax
   
A3:   
   ADD   di, 2 ; WORD단위라서 2를 증가
   INC CX
   JMP   A1

EXIT:   MOV   CX, smallest
   ADD   CX, 48
   MOV   DL, CL
   MOV   ah, 2
   INT   21h

   MOV   CX, largest
   ADD   CX, 48
   MOV   DL, CL
   MOV   ah, 2
   INT   21h
   
   MOV AH, 4CH
   INT 21H

ARRAY   dw   0, 5, 8, 9, 6, 2 ;출력하지 않을것 word단위여서
largest   dw   ?
smallest   dw   ?


MAIN   ENDS
   END