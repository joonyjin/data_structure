#include "QueType.h"
#include <iostream>
using namespace std;

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
	que.ReplaceItem(6, 20);
	while (!que.IsEmpty()) {
		int item;
		que.Dequeue(item);
		cout << item << endl;
	}
}