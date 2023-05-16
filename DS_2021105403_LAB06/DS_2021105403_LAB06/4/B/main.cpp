#include <iostream>
#include "UnsortedType.h"
using namespace std;


int main() {
	UnsortedType<int> list01;
	list01.InsertItem(1);
	list01.InsertItem(3);
	list01.InsertItem(5);
	list01.InsertItem(7);
	list01.InsertItem(9);
	list01.InsertItem(1);

	list01.DeleteItem(1);
	int mi;
	list01.ResetList();
	for (int i = 0; i < list01.LengthIs(); i++) {
		list01.GetNextItem(mi);
		cout << mi << endl;
	}
}
