#include <stdio.h>
#include <stdlib.h>


int compareToMax(int* p_cmp) { //�迭 4���� ������ ���� ū���� �ε����� ����
	int max = 0;
	for (int i = 0; i < 4; i++) {
		if (max < p_cmp[i])
			max = i;
	}
	return max;
}


int mul(int _i, int _n, int* _arr) { //����, ��, ���� ������ġ) // ���ۺ��� ������ ���ؼ� �� ����
	if (_i == _n) return _arr[_n];
	return (_arr[_i] * mul(_i + 1, _n, _arr));
}

int sumAll(int _n, int _max, int cmp[4], int* _arr) { //����, ��, ���� ������ġ, ���Ѱ� ��ġ) 
	int ans = 0;

	for (int i = 0; i < _n; i++) {
		ans += _arr[i];
	}
	for (int j = _max; j <= _max + _n-4; j++){
		ans -= _arr[j];
	}
	ans += cmp[_max];
	//if (_i == _n) return _arr[_n];
	//return (_arr[_i] + sumAll(_i + 1, _n, max, _arr));
	return ans;
}

int main() {
	int n = 0;
	scanf_s("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);
	
	int max = 0;
	int ans = 0;

	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}

	int cmp[4] = { 0 };
	for (int i = 0; i < 4; i++) {
		cmp[i] = mul(i, i + (n - 4), arr); //n=5 0- 1-2 
	}

	max = compareToMax(cmp);
	ans = sumAll(n, max, cmp, arr);
	printf("%d", ans);
}