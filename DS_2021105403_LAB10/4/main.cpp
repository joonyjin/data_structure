#include "TreeType.h"
#include "SortedType.h"

void AddElement(TreeType& tree, int Array[], int from, int to);
void MakeTree(TreeType& tree, SortedType<int>& list);

void MakeTree(TreeType& tree, SortedType<int> &list) {
	int length = list.LengthIs();
	int* array = new int[length];
	int item_info;
	int i;

	list.ResetList();
	for (i = 0; i < length; i++) {
		list.GetNextItem(item_info);
		array[i] = item_info;
	}
	
	AddElement(tree, array, 0, length - 1);

	delete[] array;
}

void AddElement(TreeType& tree, int Array[], int front, int rear) {
	int mid;
	if (front <= rear) {
		mid = (front+rear) / 2;
		tree.InsertItem(Array[mid]);
		cout << Array[mid] << endl;
		AddElement(tree, Array, mid + 1, rear);
		AddElement(tree, Array, front, mid - 1);
	}
}

int main() {
	SortedType<int> s;
	TreeType tree;

	s.InsertItem(1);
	s.InsertItem(2);
	s.InsertItem(3);
	s.InsertItem(4);
	s.InsertItem(5);
	s.InsertItem(6);
	s.InsertItem(7);

	MakeTree(tree, s);

	return 0;

}