#include "QueType.h"
#include <iostream>
using namespace std;


int main() {
	QueType que(9);
	int deq;
	que.Enqueue(2);
	que.Enqueue(6);
	que.Enqueue(7);
	que.Enqueue(4);
	que.Enqueue(5);
	que.Enqueue(6);
	que.Enqueue(10);
	que.Enqueue(15);
	que.Enqueue(6);
	que.Dequeue(deq);
	que.Dequeue(deq);
	que.Dequeue(deq);
	que.Dequeue(deq);
	que.Enqueue(2);
	que.Enqueue(6);
	que.Enqueue(7);
	que.Enqueue(4);
	
	int in;
	while (!que.IsEmpty()) {
		que.Dequeue(in);
		cout << in;
	}

}