#include"StackType.h"
#include<iostream>
using namespace std;

void ReplaceItem(StackType& st, int oldItem, int newItem) {
	StackType ex;
	while (!st.IsEmpty()) {
		int var = st.Top();
		st.Pop();
		if (var == oldItem) var = newItem;
		ex.Push(var);
	}
	while (!ex.IsEmpty()) {
		int var = ex.Top();
		ex.Pop();
		st.Push(var);
	}
}

int main() {
	StackType stack;
	stack.Push(3);
	stack.Push(5);
	stack.Push(7);
	stack.Push(3);
	stack.Push(8);
	stack.Push(9);
	stack.Push(3);
	stack.Push(8);

	ReplaceItem(stack, 3, 5);
	while (!stack.IsEmpty()) {
		int item = stack.Top();
		stack.Pop();
		cout << "Item: " << item << endl;
	}
	return 0;
}