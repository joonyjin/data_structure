#include <iostream>
#include "SortedType.h"
using namespace std;

template <class ItemType>
void MergeLists(SortedType<ItemType>& l_a, SortedType<ItemType>& l_b, SortedType<ItemType>& result) {
	l_a.ResetList();
	l_b.ResetList();
	ItemType input;
	for (int i = 0; i < l_a.LengthIs(); i++) {
		l_a.GetNextItem(input);
		result.InsertItem(input);
	}
	for (int i = 0; i < l_b.LengthIs(); i++) {
		l_b.GetNextItem(input);
		result.InsertItem(input);
	}
}

int main() {
	SortedType<int> list01, list02;
	list01.InsertItem(1);
	list01.InsertItem(3);
	list01.InsertItem(5);
	list01.InsertItem(7);
	list01.InsertItem(9);
	list02.InsertItem(2);
	list02.InsertItem(4);
	list02.InsertItem(6);
	list02.InsertItem(8);
	list02.InsertItem(10);
	SortedType<int> result;
	list01.MergeLists(list02, result);
	int mi;
	result.ResetList();
	for (int i = 0; i < result.LengthIs(); i++) {
		result.GetNextItem(mi);
		cout << mi << endl;
	}
}
