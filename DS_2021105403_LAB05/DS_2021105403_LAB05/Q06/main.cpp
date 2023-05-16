#include "QueType.h"
#include <iostream>
using namespace std;


int main() {
	QueType que(6);
	que.Enqueue(5);
	que.Enqueue(4);
	que.Enqueue(2);
	que.Enqueue(3);
	que.Enqueue(1);
	que.Enqueue(8);
	
	int in;
	que.MinDequeue(in);
	cout << in << endl;
	que.Enqueue(6);
	for (int i = 0; i < 6; i++) {
		que.MinDequeue(in);
		cout << in;
	}
	

}