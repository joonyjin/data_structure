#include <iostream>
using namespace std;

const int MAX_ITEMS = 200;

class doublestack {
private:
	int top_small;
	int top_big;
	int items[MAX_ITEMS];

public:
	doublestack();
	void Push(int item);
	bool IsFull();
	void Print();

};



doublestack::doublestack() : top_small(-1), top_big(MAX_ITEMS) {}

bool doublestack::IsFull() {
	return (top_small + 1 == top_big);
}


void doublestack::Push(int item) {

	if (IsFull()) { cout << "IsFUll"; exit(222); }
	else if (item <= 1000) {
		top_small++;
		items[top_small] = item;
	}
	else if (item > 1000) {
		top_big--;
		items[top_big] = item;
	}
}

void doublestack::Print() {

	int ind = MAX_ITEMS - 1;

	while (top_small != -1) {
		cout << items[top_small] << endl;
		top_small--;
	}

	while (top_big != MAX_ITEMS) {
		cout << items[top_big] << endl;
		top_big++;
	}
	
}

int main() {
	doublestack stack;
	stack.Push(1);
	stack.Push(2);
	stack.Push(3);
	stack.Push(4);
	stack.Push(1002);
	stack.Push(10003);
	stack.Push(1003);
	stack.Print();

}

