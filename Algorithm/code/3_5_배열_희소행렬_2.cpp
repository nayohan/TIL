#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 10

//����� ��� ����ü
typedef struct {	
	int row;
	int col;
	int value;
}element;

//���+ ����� ũ��� ���� ������ ��� ����ü
typedef struct {	
	element data[MAX_TERMS];
	int rows;
	int cols;
	int terms;
}SparseMatrix;

//A�� B����� ������ �ϴ� �Լ�
SparseMatrix sparse_matrix_add2(SparseMatrix a, SparseMatrix b) {	
	SparseMatrix c;
	if (a.rows != b.rows || a.cols != b.cols) {
		fprintf(stderr, "�࿭�� ũ�Ⱑ ��ġ���� �ʽ��ϴ�.");
		exit(1); //������ ���� ����
	}

	//C�� ���ũ�� ����
	c.rows = a.rows;	
	c.cols = a.cols;
	c.terms = 0;

	//���� ����ĵ��� ����ġ
	int ca = 0, cb = 0, cc = 0;

	//����ġ�� �ϳ��� ���� �����ϸ� ����
	while (ca < a.terms || cb < b.terms) {
		//���° ������� Ȯ��
		int da = a.data[ca].col * a.cols + a.data[ca].row;	
		int db = b.data[cb].col * b.cols + b.data[ca].row;
		int dc = 0;

		//A����� �迭�� ��ǥ�� ������
		if (da < db) { 
			c.data[cc++] = a.data[ca++];
		}
		//A�� B����� ��ǥ�� ������
		else if (da == db) {
			c.data[cc].row = a.data[ca].row;
			c.data[cc].col = a.data[ca].col;
			c.data[cc++].value = a.data[ca++].value + b.data[cb++].value;
		}
		//B����� ��ǥ�� ������
		else {
			c.data[cc++] = b.data[cb++];
		}
	}
	
	//������ ������� �����ϰ�, �ϳ��� ����� �Ϸ�Ǿ�����, ������ ��� ��ü C�� ����
	for (; ca < a.terms; ca++) {
		c.data[cc++] = a.data[ca++];
	}
	for (; cb < b.terms; cb++) {
		c.data[cc++] = b.data[cb++];
	}

	//C�� ���� ���� ������Ʈ
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