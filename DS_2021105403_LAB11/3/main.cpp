#include <iostream>
using namespace std;
#include "PQType.h"

int main() {

	PQType<int> pqueue;
	pqueue.Enqueue(5);
	pqueue.Enqueue(4);
	pqueue.Enqueue(3);
	pqueue.Enqueue(2);
	pqueue.Enqueue(1);


	while (!pqueue.IsEmpty()) {
		int tempItem;

		pqueue.Dequeue(tempItem);

		cout << tempItem << ' ';

	}
	return 0;
}