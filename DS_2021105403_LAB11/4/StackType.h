// Linked Stack ADT
#include <cstddef>
#include <new>
typedef int ItemType;
struct NodeType;


class FullStack
{};

class EmptyStack
{};


class StackType
{
public:

  StackType();
  ~StackType();
  bool IsFull() const;
  bool IsEmpty() const;
  void Push(ItemType item);
  void Pop();
  void countTimeStamp();
  ItemType Top();
private:
  NodeType* topPtr;
  NodeType* MaxTime;
};

struct NodeType
{
  ItemType info;
  NodeType* next;
  int TimeStamp;
};

void StackType::countTimeStamp() {
    NodeType* location;
    location = topPtr;
    while (location != NULL) {
        location->TimeStamp += 1;
        location = location->next;
    }
}

void StackType::Push(ItemType newItem)

{
    if (IsFull())
        throw FullStack();
    else
    {
        countTimeStamp();
        NodeType* location;
        location = new NodeType;
        location->info = newItem;
        location->next = topPtr;
        location->TimeStamp = 1;
        topPtr = location;
    }
}
void StackType::Pop()
{
    if (IsEmpty())
        throw EmptyStack();
    else
    {
        NodeType* tempPtr;
        NodeType* location = topPtr;
        while (location->next != MaxTime) {
            location = location->next;
        }
        if ((location->next)->next != NULL)
            location->next = (location->next)->next;
        else
            location->next = NULL;
        tempPtr = location->next;
        delete tempPtr;
    }
}
ItemType StackType::Top()
{
    if (IsEmpty())
        throw EmptyStack();
    else {
        NodeType* prevPtr = topPtr;
        NodeType* location = topPtr;
        int MaxTimeStamp = location->TimeStamp;

        while (location->next != NULL) {
            if (MaxTimeStamp < (location->next)->TimeStamp) {
                MaxTimeStamp = (location->next)->TimeStamp;
                prevPtr = location;
            }
            location = location->next;
        }
        MaxTime = prevPtr->next;
        return MaxTime->info;
    }
}
bool StackType::IsEmpty() const

{
    return (topPtr == NULL);
}
bool StackType::IsFull() const

{
    NodeType* location;
    try
    {
        location = new NodeType;
        delete location;
        return false;
    }
    catch (std::bad_alloc)
    {
        return true;
    }
}

StackType::~StackType()

{
    NodeType* tempPtr;

    while (topPtr != NULL)
    {
        tempPtr = topPtr;
        topPtr = topPtr->next;
        delete tempPtr;
    }
}

StackType::StackType()
{
    topPtr = NULL;
    MaxTime = NULL;
}

