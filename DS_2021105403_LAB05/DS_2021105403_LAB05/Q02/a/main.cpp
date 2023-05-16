#include "QueType.h"
#include <iostream>
using namespace std;

void ReplaceItem(QueType& queue, int oldItem, int newItem) {
	int value;
	QueType temp;
	while (!queue.IsEmpty()) {
		queue.Dequeue(value);
		if (value == oldItem) temp.Enqueue(newItem);
		else temp.Enqueue(value);
	}
	while (!temp.IsEmpty()) {
		temp.Dequeue(value);
		queue.Enqueue(value);
	}
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
	ReplaceItem(que, 6, 20);
	while (!que.IsEmpty()) {
		int item;
		que.Dequeue(item);
		cout << item << endl;
	}
}