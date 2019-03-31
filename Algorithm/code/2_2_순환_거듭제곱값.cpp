//����3: 2�� n���� ���Ͻÿ�.
#include <stdio.h>
#if 0
int power(int x, int n) {
	if (n == 0) {
		return 1;
	}
	return x * power(x, n - 1);
}

int main() {
	printf("%d", power(2, 5));
}
#endif

#if 1	//recursion ����
int power(int x, int n) {
	if (n == 0) {
		return 1;
	}
	if (n % 2 == 0) {
		return power(x * x, n / 2);
	}
	if (n % 2 == 1) {
		return power(x * x, (n - 1) / 2);
	}
}
int main() {
	printf("%d", power(2, 5));
}
#endif