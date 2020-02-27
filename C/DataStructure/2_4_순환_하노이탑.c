//�ϳ���ž
#include <stdio.h>
void hanoi(int n, char from, char to, char tmp) {
	//Ż��
	if (n == 1) {
		printf("%c ----> %c,, 1�� �ű�", from, to);
		return;
	}
	//����
	hanoi(n - 1, from, tmp, to);
	printf("%c ----> %c,, 1�� �ű�", from, to);
	hanoi(n - 1, tmp, to, from);

}
int main() {
// 3���� A���뿡�� C������ �ű��. B����� �ӽ÷� ����ص�����
	hanoi(5, 'A', 'C', 'B');
	return 0;
}


#if 0
#include <stdio.h>
void hanoi(int n, char from, char tmp, char to) {
	if (n == 1) {
		printf("���� 1�� %c���� %c�� �ű��.\n", from, to);
	}
	else {
		hanoi(n - 1, from, to, tmp);
		printf("���� %d�� %c���� %c�� �ű��.\n", n, from, to);
		hanoi(n - 1, tmp, from, to);
	}
}
int main() {
	hanoi(3, 'A', 'B', 'C');
}
#endif