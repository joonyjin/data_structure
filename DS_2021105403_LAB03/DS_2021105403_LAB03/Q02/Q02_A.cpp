#include <iostream>
using namespace std;

int BinarySearch(int array[], int sizeOfArray, int value) {
	int first = 0;
	int last = sizeOfArray - 1;
	bool search = (first <= last);
	bool found = false;
	int result = -1;
	while (search && !found) {
		int midpoint = (first + last) / 2;
		if (value < array[midpoint]) {
			search = (first <= last);
			last = midpoint - 1;
		}
		else if (value > array[midpoint]) {
			search = (first <= last);
			first = midpoint + 1;
		}
		else if (value == array[midpoint]) {
			result = midpoint;
			found = true;
		}
	}
	return result;
}

int main() {
	int list[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int result = BinarySearch(list, 10, 11);
	cout << result << endl;
	result = BinarySearch(list, 10, 7);
	cout << result << endl;
	return 0;
}