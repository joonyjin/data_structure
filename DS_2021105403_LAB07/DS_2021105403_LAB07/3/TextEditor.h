#pragma once

#include <iostream>
#include <string.h>
using namespace std;

typedef char ItemType;

struct LineType {
	ItemType info[80];
	LineType* next;
	LineType* back;
};

class TextEditor {

private:
	LineType* listData;
	int length;
	LineType* currentLine;
	LineType* header;
	LineType* tailer;

public:
	TextEditor();
	~TextEditor();
	void GoToTop();
	void GoToBottom();
	void InsertItem(ItemType* item);
	void PrintItem();
};
