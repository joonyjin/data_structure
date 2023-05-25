#include <iostream>
using namespace std;
#include "StackType.h"

int main() {

	StackType pqueue;
	pqueue.Push(5);
	pqueue.Push(4);
	pqueue.Push(3);
	pqueue.Push(2);
	pqueue.Push(1);
	cout << pqueue.Top() << endl;
	pqueue.Pop();
	cout << pqueue.Top();
	return 0;
}