#include <stdio.h>
#define MAX(a,b) ((a)>(b) ? (a):(b))
#define MAX_DEGREE 101
typedef struct {
	int degree;
	float coef[MAX_DEGREE];
}polynomial;

polynomial poly_add1(polynomial A, polynomial B) {
	polynomial c;
	int Apos = 0, Bpos = 0, Cpos = 0;
	int degree_a = A.degree;
	int degree_b = B.degree;
	
	c.degree = MAX(A.degree, B.degree);

	while (Apos <= A.degree && Bpos <= B.degree) {
		if (degree_a > degree_b) {
			c.coef[Cpos++] = A.coef[Apos++];
			degree_a--;
		}

		if (degree_a == degree_b) {
			c.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
			degree_a--;
			degree_b--;
		}

		if (degree_a < degree_b) {
			c.coef[Cpos++] = B.coef[Bpos++];
			degree_b--;
		}
	}
	return c;
}
int main() {
	polynomial a = { 5, {3, 6, 0, 0, 0, 10} };
	polynomial b = { 4, {7, 0, 5, 0, 1} };

	polynomial c;
	c = poly_add1(a, b);
	printf("%d\n", c.degree);
	for (int i = 0; i <= c.degree; i++) {
		printf("%f ", c.coef[i]);
	}
}