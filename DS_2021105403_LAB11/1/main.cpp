#include <iostream>
using namespace std;
#include "PQType.h"

int main() {

	PQType<int> pq(16);

	pq.Enqueue(5);
	pq.Enqueue(6);
	pq.Enqueue(3);
	pq.Enqueue(2);
	pq.Enqueue(7);
	pq.Enqueue(8);


	while (!pq.IsEmpty()) {

		int tempItem;
		pq.Dequeue(tempItem);
		cout << tempItem << " ";
	}



	return 0;
}