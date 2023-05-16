#include "StackType.h"
#include <iostream>
using namespace std;

void ReplaceItem(StackType& stack, ItemType oldItem, ItemType newItem) {
	StackType temp_stack;
	ItemType temp_Item;
	while (!stack.IsEmpty()) {
		temp_Item = stack.Top();
		if (temp_Item == oldItem) temp_stack.Push(newItem);
		else temp_stack.Push(temp_Item);
		stack.Pop();
	}
	while (!temp_stack.IsEmpty()) {
		temp_Item = temp_stack.Top();
		stack.Push(temp_Item);
		temp_stack.Pop();
	}
}

int main() {
	StackType one;
	one.Push(1);
	one.Push(2);
	one.Push(3);
	one.Push(1);
	one.ReplaceItem(1, 5);
	while (!one.IsEmpty()) {
		int temp_item = one.Top();
		cout << temp_item << endl;
		one.Pop();
	}
}