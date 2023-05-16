#include <iostream>
#include "TextEditor.h"

int main() {

	TextEditor editor;
	char text1[] = "Hello";
	char text2[] = "World";
	editor.InsertItem(text1);
	editor.InsertItem(text2);
	editor.PrintItem();
	
}