#include "TreeType.h"
#include "UnsortedType.h"

bool MatchingItem_Unsorted(TreeType& tree, UnsortedType<ItemType>& list) {
	int list_length = list.LengthIs();
	int tree_length = tree.LengthIs();

	if (list_length != tree_length) {
		return false;
	}
	else {
		ItemType item;
		bool found;
		list.ResetList();
		for (int i = 0; i < list_length; i++) {
			list.GetNextItem(item);
			tree.RetrieveItem(item, found);
			if (!found)
				return false;
		}
		return true;
	}
}

int main() {
	UnsortedType<char> usl;
	TreeType tree;

	usl.InsertItem('a');
	usl.InsertItem('e');
	usl.InsertItem('b');
	usl.InsertItem('h');
	usl.InsertItem('z');
	usl.InsertItem('k');
	usl.InsertItem('g');

	tree.InsertItem('g');
	tree.InsertItem('b');
	tree.InsertItem('k');
	tree.InsertItem('a');
	tree.InsertItem('e');
	tree.InsertItem('h');
	tree.InsertItem('z');


	if (MatchingItem_Unsorted(tree,usl))
		cout << "Same." << endl;
	else
		cout << "Not Same." << endl;

	return 0;

}