#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 101
struct {			//구조체이름 생략가능
	float coef;		//직접대입해서 terms를 구조체변수 이름으로 사용
	int expon;
} terms[MAX_TERMS] = { {8,3}, {7,1}, {1,0}, {10,3}, {3,2}, {1,0} };
int avail = 6;		//C를 삽입가능한 공간위치

char compare(int a, int b) {
	if (a > b)
		return '>';
	else if (a == b)
		return '=';
	else
		return '<';
}

void attach(float coef, int expon) {
	if (avail > MAX_TERMS) {
		fprintf(stderr, "항의 갯수가 너무 많음\n");
		exit(1);
	}
	terms[avail].coef = coef;
	terms[avail++].expon = expon;
}

void poly_add2(int as, int ae, int bs, int be, int* cs, int* ce) {
	float tempcoef;
	*cs = avail;

	while ( as <= ae && bs <= be) {
		switch (compare(terms[as].expon, terms[bs].expon)) {
		case '>':
			attach(terms[as].coef, terms[as].expon);
			as++;	break;
		case '=':
			tempcoef = terms[as].coef + terms[bs].coef;
			attach(tempcoef, terms[as].expon);
			as++; bs++;	break;

		case '<':
			attach(terms[bs].coef, terms[bs].expon);
			bs++;	break;
		}
	}
	
	for (; as <= ae; as++) {
		attach(terms[as].coef, terms[as].expon);
	}
	for (; bs <= be; bs++) {
		attach(terms[bs].coef, terms[bs].expon);
	}

	*ce = avail - 1;
}

int main() {
	int cs, ce;
	poly_add2(0, 2, 3, 5, &cs, &ce);

	printf("%d\n", terms[cs].expon);
	printf("%f\n", terms[cs].coef);
	printf("%d\n",cs);
	printf("%d\n",ce);
	return 0;
}
