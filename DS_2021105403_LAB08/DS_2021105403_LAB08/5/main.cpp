#include <iostream>
#include "UnsortedType.h"
using namespace std;

int main() {
	UnsortedType<int> listData;
	listData.InsertItem(4);
	listData.InsertItem(1);
	listData.InsertItem(7);
	listData.InsertItem(3);
	listData.ResetList();
	int temp;
	for (int i = 0; i < listData.LengthIs(); i++) {

		listData.GetNextItem(temp);
		cout << temp << endl;
	}

	listData.doSort();
	listData.ResetList();
	for (int i = 0; i < listData.LengthIs(); i++) {

		listData.GetNextItem(temp);
		cout << temp << endl;
	}

	
}



