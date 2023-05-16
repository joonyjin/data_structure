#include "QueType.h"
#include <iostream>
using namespace std;

template <class ItemType>
void ReplaceItem(QueType<ItemType>& queue, ItemType oldItem, ItemType newItem) {
	QueType<ItemType>temp_que;
	ItemType temp;
	while (!queue.IsEmpty()) {
		queue.Dequeue(temp);
		if (temp == oldItem) {
			temp_que.Enqueue(newItem);
		}
		else temp_que.Enqueue(temp);
	}
	while (!temp_que.IsEmpty()) {
		temp_que.Dequeue(temp);
		queue.Enqueue(temp);
	}
}

int main() {
	QueType<int> one;
	one.Enqueue(2);
	one.Enqueue(1);
	one.Enqueue(1);
	one.Enqueue(2);
	one.ReplaceItem(2, 5);
	int mi;
	while (!one.IsEmpty()) {
		one.Dequeue(mi);
		cout << mi << endl;
	}
}
