#include "StackTType.h"
#include<iostream>
#include<iomanip>

using namespace std;

template<class Itemtype>

void Copy(StackType<Itemtype> A, StackType<Itemtype>& B) {
	StackType<Itemtype> C;
	while (!A.IsEmpty()) {
		Itemtype var = A.Top();
		A.Pop();
		C.Push(var);
	}
	while (!C.IsEmpty()) {
		Itemtype var = C.Top();
		C.Pop();
		B.Push(var);
	}
}

int main() {
	StackType<int> stackA;
	StackType<int> stackB;

	stackA.Push(9);
	stackA.Push(8);
	stackA.Push(4);
	stackA.Push(7);
	stackA.Push(5);
	stackA.Push(3);

	Copy(stackA, stackB);

	cout << "StackA" << setw(10) << "StackB" << endl;
	while (!stackA.IsEmpty()) {
		int result = stackA.Top();
		int result1 = stackB.Top();
		stackA.Pop();
		stackB.Pop();
		cout << result << setw(10) << result1 << endl;
	}
	

}