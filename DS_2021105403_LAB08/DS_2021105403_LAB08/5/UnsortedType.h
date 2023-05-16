// Header file for Unsorted List ADT.
#include <iostream>
template <class ItemType>
struct NodeType;

template <class ItemType>
class UnsortedType
{
public:
    UnsortedType();     // Class constructor	
    ~UnsortedType();    // Class destructor

    bool IsFull() const;

    int  LengthIs() const;

    void MakeEmpty();

    void RetrieveItem(ItemType& item, bool& found);

    void InsertItem(ItemType item);

    void DeleteItem(ItemType item);

    void ResetList();

    void GetNextItem(ItemType& item);

    void Sort(NodeType<ItemType>* location);

    void doSort() {
        Sort(listData);
    }

protected:
    NodeType<ItemType>* MinLoc(NodeType<ItemType>* location, NodeType<ItemType>* minPtr);

private:
    NodeType<ItemType>* listData;
    int length;
    NodeType<ItemType>* currentPos;
};


template<class ItemType>
struct NodeType
{
    ItemType info;
    NodeType* next;
};

template <class ItemType>
UnsortedType<ItemType>::UnsortedType()  // Class constructor
{
    length = 0;
    listData = NULL;
}

template <class ItemType>
UnsortedType<ItemType>::~UnsortedType()
// Class destructor
{
    MakeEmpty();
}
template<class ItemType>
bool UnsortedType<ItemType>::IsFull() const
// Returns true if there is no room for another ItemType 
//  on the free store; false otherwise.
{
    NodeType<ItemType>* location;
    try
    {
        location = new NodeType<ItemType>;
        delete location;
        return false;
    }
    catch (std::bad_alloc exception)
    {
        return true;
    }
}
template <class ItemType>
int UnsortedType<ItemType>::LengthIs() const
// Post: Number of items in the list is returned.
{
    return length;
}
template <class ItemType>
void UnsortedType<ItemType>::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
    NodeType<ItemType>* tempPtr;

    while (listData != NULL)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
    length = 0;
}
template <class ItemType>
void UnsortedType<ItemType>::RetrieveItem(ItemType& item,
    bool& found)
{
    bool moreToSearch;
    NodeType<ItemType>* location;

    location = listData;
    found = false;
    moreToSearch = (location != NULL);

    while (moreToSearch && !found)
    {
        if (item == location->info)
        {
            found = true;
            item = location->info;
        }
        else
        {
            location = location->next;
            moreToSearch = (location != NULL);
        }
    }
}
template <class ItemType>
void UnsortedType<ItemType>::InsertItem(ItemType item)
// item is in the list; length has been incremented.
{
    NodeType<ItemType>* location;

    location = new NodeType<ItemType>;
    location->info = item;
    location->next = listData;
    listData = location;
    length++;
}
template <class ItemType>
void UnsortedType<ItemType>::DeleteItem(ItemType item)
{
    NodeType<ItemType>* location = listData;
    NodeType<ItemType>* tempLocation;

    // Locate node to be deleted.
    if (item == listData->info)
    {
        tempLocation = location;
        listData = listData->next;		// Delete first node.
    }
    else
    {
        while (!(item == (location->next)->info))
            location = location->next;

        // Delete node at location->next
        tempLocation = location->next;
        location->next = (location->next)->next;
    }
    delete tempLocation;
    length--;
}

template <class ItemType>
void UnsortedType<ItemType>::ResetList()
// Post: Current position has been initialized.
{
    currentPos = NULL;
}

template <class ItemType>
void UnsortedType<ItemType>::GetNextItem(ItemType&  item)
// Post:  Current position has been updated; item is current item.
{
    if (currentPos == NULL)
        currentPos = listData;
    else
        currentPos = currentPos->next;
    item = currentPos->info;
}

template <class ItemType>
NodeType<ItemType>* UnsortedType<ItemType>::MinLoc(NodeType<ItemType>* location,
    NodeType<ItemType>* minPtr) {
    if (location != NULL) {
        if (location->info < minPtr->info) {
            minPtr = location;
        }
        return (MinLoc(location->next, minPtr));
    }
    else {
        return minPtr;
    }
}

template <class ItemType>
void UnsortedType<ItemType> ::Sort(NodeType<ItemType>* location) {
    NodeType<ItemType>* minPtr;
    ItemType temp;
    if (location != NULL) {
        minPtr = MinLoc(location, location);
        temp = minPtr->info;
        minPtr->info = location->info;
        location->info = temp;
        Sort(location->next);
    }
}



