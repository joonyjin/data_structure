#include <iostream>
using namespace std;

// recursive한 피보나치 계산 함수는 n이 커질 수록 stack을 많이 차지하게 되고 결국
// overflow가 일어나기 때문에 성능을 효율적으로 향상시키지는 않는다.

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