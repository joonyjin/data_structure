#include <iostream>
#include "StackType.h"
using namespace std;

int main() {
	StackType one;
	StackType two;
	one.Push(1);
	one.Push(2);
	one.Push(3);
	two.Copy(one);

	while (!two.IsEmpty()) {
		i = two.Top();
		two.Pop();
		cout << i << endl;
	}

}
