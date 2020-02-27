#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 10

//행렬을 담는 구조체
typedef struct {	
	int row;
	int col;
	int value;
}element;

//행렬+ 행렬의 크기와 항의 갯수를 담는 구조체
typedef struct {	
	element data[MAX_TERMS];
	int rows;
	int cols;
	int terms;
}SparseMatrix;

//A와 B행렬의 덧셈을 하는 함수
SparseMatrix sparse_matrix_add2(SparseMatrix a, SparseMatrix b) {	
	SparseMatrix c;
	if (a.rows != b.rows || a.cols != b.cols) {
		fprintf(stderr, "행열의 크기가 일치하지 않습니다.");
		exit(1); //에러로 인한 종료
	}

	//C의 행렬크기 지정
	c.rows = a.rows;	
	c.cols = a.cols;
	c.terms = 0;

	//현재 각행렬들의 항위치
	int ca = 0, cb = 0, cc = 0;

	//행위치중 하나라도 끝에 도달하면 종료
	while (ca < a.terms || cb < b.terms) {
		//몇번째 요소인지 확인
		int da = a.data[ca].col * a.cols + a.data[ca].row;	
		int db = b.data[cb].col * b.cols + b.data[ca].row;
		int dc = 0;

		//A행렬의 배열의 좌표가 작을때
		if (da < db) { 
			c.data[cc++] = a.data[ca++];
		}
		//A와 B행렬의 좌표가 같을때
		else if (da == db) {
			c.data[cc].row = a.data[ca].row;
			c.data[cc].col = a.data[ca].col;
			c.data[cc++].value = a.data[ca++].value + b.data[cb++].value;
		}
		//B행렬의 좌표가 작을때
		else {
			c.data[cc++] = b.data[cb++];
		}
	}
	
	//위에서 순서대로 나열하고, 하나의 행렬이 완료되었을때, 나머지 행렬 전체 C에 삽입
	for (; ca < a.terms; ca++) {
		c.data[cc++] = a.data[ca++];
	}
	for (; cb < b.terms; cb++) {
		c.data[cc++] = b.data[cb++];
	}

	//C의 항의 갯수 업데이트
	c.terms = cc;
	return c;
}

int main() {
	SparseMatrix m1 = { {{ 1,1,5 }, { 2,2,9 }}, 3,3,2 };
	SparseMatrix m2 = { {{ 0,0,5 }, { 2,2,9 }}, 3,3,2 };
	SparseMatrix m3;
	m3 = sparse_matrix_add2(m1, m2);
	printf("%d", m3.terms);
	return 0;
}