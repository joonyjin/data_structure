#include "TextEditor.h"

TextEditor::TextEditor() {
	length = 0;
	header = new LineType;
	tailer = new LineType;
	
	header->next = tailer;
	header->back = NULL;
	tailer->next = NULL;
	tailer->back = header;
	
	strcpy_s(header->info, sizeof("--- Top of file ---"), "--- Top of file ---");
	strcpy_s(tailer->info, sizeof("--- Bottom of file ---"), "--- Bottom of file ---");

	currentLine = header;
	listData = header;
}

TextEditor::~TextEditor() {
	while (listData != NULL) {
		LineType* temp = listData;
		listData = listData->next;
		delete [] temp;
	}
	length = 0;
}

void TextEditor::GoToTop() {
	currentLine = header->next;
}

void TextEditor::GoToBottom() {
	currentLine = tailer->back;
}

void TextEditor::InsertItem(ItemType *newline) {
	GoToBottom();
	LineType* line = new LineType;
	strcpy_s(line->info, newline);
	line->next = tailer;
	line->back = currentLine;
	currentLine->next = line;
	tailer->back = line;
	currentLine = line;
	length++;
}

void TextEditor::PrintItem() {
	GoToTop();
	for (int i = 0; i < length; i++) {
		for (int i = 0; currentLine->info[i] != '\0'; i++) {
			cout << currentLine->info[i];
		}
		cout << endl;
		currentLine = currentLine->next;
	}
}



