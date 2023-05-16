#include "sorted.h"
#include "ItemType.h"
#include <iostream>


void MergeList(SortedType list1, SortedType list2, SortedType& result);

int main() {
	SortedType s_list1, s_list2, s_list3;
	ItemType item1, item2, item3, item4, item5;
	item1.Initialize(1);
	item2.Initialize(3);
	item3.Initialize(2);
	item4.Initialize(5);
	item5.Initialize(4);
	s_list1.InsertItem(item1);
	s_list1.InsertItem(item2);
	s_list1.InsertItem(item3);
	s_list2.InsertItem(item4);
	s_list2.InsertItem(item5);

	MergeList(s_list1, s_list2, s_list3);
	int length = s_list3.LengthIs();
	for (int i = 0; i < length; i++) {
		ItemType item;
		s_list3.GetNextItem(item);
		item.Print(std::cout);
		std::cout << " ";
	}
	return 0;
}

void MergeList(SortedType list1, SortedType list2, SortedType& result) {
	list1.ResetList(), list2.ResetList(), result.ResetList();

	int length1 = list1.LengthIs(),length2 = list2.LengthIs();

	for (int i = 0; i < length1; i++) {
		ItemType item;
		list1.GetNextItem(item);
		result.InsertItem(item);
	}

	for (int i = 0; i < length2; i++) {
		ItemType item;
		list2.GetNextItem(item);
		result.InsertItem(item);
	}
}