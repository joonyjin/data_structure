#include <iostream>
using namespace std;

int BinarySearch(int array[], int sizeOfArray, int value) {
	int first = 0;
	int last = sizeOfArray - 1;
	bool search = (first <= last);
	bool found = false;
	int result = -1;
	while (search && !found) {
		if (value > array[last]) { result = array[last]; break; }
		int midpoint = (first + last) / 2;
		if (value < array[midpoint]) {
			search = (first <= last);
			last = midpoint - 1;
			if (value > array[last]) { result = array[last]; break; }
		}
		else if (value > array[midpoint]) {
			search = (first <= last);
			first = midpoint + 1;
			if (value < array[first]) { result = array[first-1]; break; }
		}
		else if (value == array[midpoint]) {
			result = midpoint;
			found = true;
		}
	}
	return result;
}

int main() {
	int list[7] = { 2,4,5,6,8,9,10 };
	int result = BinarySearch(list, 7, 11);
	cout << result << endl;
	result = BinarySearch(list, 7, 7);
	cout << result << endl;
	return 0;
}