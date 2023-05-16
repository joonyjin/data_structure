#include <iostream>
#include "SortedType.h"
using namespace std;

int main() {
	SortedType<int> yeap;

	yeap.InsertItem(3);
	yeap.InsertItem(1);
	yeap.InsertItem(2);
	yeap.PrintReverse();
}
