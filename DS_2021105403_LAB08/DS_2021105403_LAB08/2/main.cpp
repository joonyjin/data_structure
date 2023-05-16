#include <iostream>
using namespace std;

// recursive�� �Ǻ���ġ ��� �Լ��� n�� Ŀ�� ���� stack�� ���� �����ϰ� �ǰ� �ᱹ
// overflow�� �Ͼ�� ������ ������ ȿ�������� ����Ű���� �ʴ´�.

int Fibonacci_recursive(int n) {
	if (n == 0 || n == 1) return n;
	else {
		return Fibonacci_recursive(n - 2) + Fibonacci_recursive(n - 1);
	}
}

int Fibonacci_non_recursive(int n) {
	int nn = 0;
	int nnn = 1;
	int result = 0;
	if (n < 2) return n;
	for (int i = 1; i < n ; i++) {
		result = nn + nnn;
		nn = nnn;
		nnn = result;
	}
	return result;
}

int main() {
	cout << Fibonacci_recursive(10) << endl;
	cout << Fibonacci_non_recursive(10) << endl;
}