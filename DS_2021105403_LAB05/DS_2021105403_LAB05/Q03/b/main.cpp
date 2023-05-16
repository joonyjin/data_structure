#include "QueType.h"
#include <iostream>
using namespace std;


int main() {
	QueType que(9);
	QueType que2(9);
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
	cout << que.Identical(que2);

}