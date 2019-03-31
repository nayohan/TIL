//하노이탑
#include <stdio.h>
void hanoi(int n, char from, char to, char tmp) {
	//탈출
	if (n == 1) {
		printf("%c ----> %c,, 1개 옮김", from, to);
		return;
	}
	//지속
	hanoi(n - 1, from, tmp, to);
	printf("%c ----> %c,, 1개 옮김", from, to);
	hanoi(n - 1, tmp, to, from);

}
int main() {
// 3개를 A폴대에서 C폴더로 옮긴다. B폴대는 임시로 사용해도ㄷ디
	hanoi(5, 'A', 'C', 'B');
	return 0;
}


#if 0
#include <stdio.h>
void hanoi(int n, char from, char tmp, char to) {
	if (n == 1) {
		printf("원판 1을 %c에서 %c로 옮긴다.\n", from, to);
	}
	else {
		hanoi(n - 1, from, to, tmp);
		printf("원판 %d을 %c에서 %c로 옮긴다.\n", n, from, to);
		hanoi(n - 1, tmp, from, to);
	}
}
int main() {
	hanoi(3, 'A', 'B', 'C');
}
#endif