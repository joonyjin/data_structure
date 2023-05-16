#include "QueType.h"
#include<iostream>
QueType::QueType(int max)
// Parameterized class constructor
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been dynamically
//       allocated.
{
    maxQue = max + 1;
    front = maxQue - 1;
    rear = maxQue - 1;
    items = new ItemType[maxQue];
    minimum_pos = 0;
}
QueType::QueType()          // Default class constructor
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been dynamically
//       allocated.
{
    maxQue = 501;
    front = maxQue - 1;
    rear = maxQue - 1;
    items = new ItemType[maxQue];
    minimum_pos = 0;
}
QueType::~QueType()         // Class destructor
{
    delete[] items;
}

void QueType::MakeEmpty()
// Post: front and rear have been reset to the empty state.
{
    front = maxQue - 1;
    rear = maxQue - 1;
}

bool QueType::IsEmpty() const
// Returns true if the queue is empty; false otherwise.
{
    return (rear == front);
}

bool QueType::IsFull() const
// Returns true if the queue is full; false otherwise.
{
    return ((rear + 1) % maxQue == front);;
}

void QueType::Enqueue(ItemType newItem)
// Post: If (queue is not full) newItem is at the rear of the queue;
//       otherwise a FullQueue exception is thrown.  
{
    for (int i = (front + 1) % maxQue; i < rear + 1; i++) {
        if (items[i] == -1) {
            items[i] = newItem;
            if (newItem < items[minimum_pos])
                minimum_pos = i;
            return;
        }

    }
    rear = (rear + 1) % maxQue;
    items[rear] = newItem;


}

void QueType::Dequeue(ItemType& item)
// Post: If (queue is not empty) the front of the queue has been 
//       removed and a copy returned in item; 
//       othersiwe a EmptyQueue exception has been thrown.
{
    if (IsEmpty())
        throw EmptyQueue();
    else
    {
        front = (front + 1) % maxQue;
        item = items[front];
    }
}

void QueType::MinDequeue(ItemType& item) {
    if (IsEmpty())
        throw EmptyQueue();
    else {
        int count = 0;
        int min = -1;
        for (int i = (front + 1) % maxQue; i < rear + 1; i++) {
            if (items[i] != -1 && min == -1) {
                min = items[i];
                minimum_pos = i;
            }
            else if (items[i] != -1 && min != -1) {
                if (items[i] < min) {
                    min = items[i];
                    minimum_pos = i;
                }
            }
        }
        item = items[minimum_pos];
        items[minimum_pos] = -1;
    }
}