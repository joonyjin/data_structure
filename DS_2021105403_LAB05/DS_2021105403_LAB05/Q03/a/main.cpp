#include "QueType.h"
#include <iostream>
using namespace std;

bool Identical(QueType que1, QueType que2) {
	int item1, item2;
	int count1 = 0, count2 = 0;
	bool is = true;
	while (!que1.IsEmpty()) {
		que1.Dequeue(item1);
		que2.Dequeue(item2);
		is = (item1 == item2);
	}
	is = (que1.IsEmpty() == que2.IsEmpty());
	return is;
}
int main() {
	QueType que(9);
	QueType que2(10);
	que.Enqueue(2);
	que.Enqueue(6);
	que.Enqueue(7);
	que.Enqueue(4);
	que.Enqueue(5);
	que.Enqueue(6);
	que.Enqueue(10);
	que.Enqueue(15);
	que.Enqueue(6);
	
	que2.Enqueue(2);
	que2.Enqueue(6);
	que2.Enqueue(7);
	que2.Enqueue(4);
	que2.Enqueue(5);
	que2.Enqueue(6);
	que2.Enqueue(10);
	que2.Enqueue(15);
	que2.Enqueue(6);
	que2.Enqueue(1);
	cout << Identical(que, que2);

}