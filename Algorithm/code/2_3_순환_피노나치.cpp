//문제2: n번쨰 피보나치 숫자는? 1,1,2,3,5,8,13
#include <stdio.h>
#if 0
int main() {
	int arr[1000] = { 0 };
	arr[1] = 1;
	arr[2] = 1;
	int n = 20;
	for (int i = 3; i <= n; i++)
	{
			arr[i] += arr[i - 1] + arr[i - 2];
	}
	printf("%d", arr[n]);
}
#endif

#if 0  //반복으로 짜기
#include <stdio.h>
int fib(int n) {
	int pprev = 1;
	int prev = 1;
	int result = 0;

	if ((n == 1) || (n == 2)) {
		return 1;
	}
	for (int i = 3; i <= n; i++) {
		result = pprev + prev;
		pprev = prev;
		prev = result;
	}
	return result;
}
int main() {
	printf("%d", fib(30));
}
#endif

#if 0 //recursion으로 짜기
int fibo(int n) {
	if ((n == 1) || (n == 2)) {
		return 1;
	}
	return fibo(n - 1) + fibo(n - 2);
}

int main(){
	printf("%d", fibo(20));
}
#endif

