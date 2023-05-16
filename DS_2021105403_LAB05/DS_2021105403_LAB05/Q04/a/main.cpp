#include "QueType.h"
#include <iostream>
using namespace std;

int Length(QueType& queue) {
	int count = 0;
	QueType que = queue;
	while (!queue.IsEmpty()) {
		int item;
		queue.Dequeue(item);
		count++;
	}
	queue = que;
	return count;
}

int main() {
	QueType que(9);
	que.Enqueue(2);
	que.Enqueue(6);
	que.Enqueue(7);
	que.Enqueue(4);
	que.Enqueue(5);
	que.Enqueue(6);
	que.Enqueue(10);
	que.Enqueue(15);
	que.Enqueue(6);
	
	cout << Length(que);

}