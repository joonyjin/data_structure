#include "QueType.h"
#include <iostream>
using namespace std;

int main() {
	QueType q1(10);
	for (int i = 0; i < 10; i++) {
		int ran = rand() %10;
		q1.Enqueue(ran);
	}
	while (!q1.IsEmpty()) {
		int item;
		q1.Dequeue(item);
		cout << item << endl;
	}
}