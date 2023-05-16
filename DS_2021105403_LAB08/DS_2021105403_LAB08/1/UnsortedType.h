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

    void PrintSumSquares();

private:
    NodeType<ItemType>* listData;
    int length;
    NodeType<ItemType>* currentPos;
};

template<class ItemType>
ItemType SumSquares_a(NodeType<ItemType>* list) {
    //return 0; return을 if문이 실행되기 전에 해주어서 바로 종료가 되었다.
    if (list != NULL)
        return (list->info * list->info) + SumSquares_a(list->next);
    return 0;
}

template<class ItemType>
ItemType SumSquares_b(NodeType<ItemType>* list) {
    int sum = 0;
    while (list != NULL) {
        sum = list->info*list->info + sum; // list->info의 제곱을 sum에 더해주어야 함
        list = list->next;
    }
    return sum;
}

template<class ItemType>
ItemType SumSquares_c(NodeType<ItemType>* list) {
    if (list == NULL)
        return 0;
    else
        return list->info * list->info + SumSquares_c(list->next);
}

template<class ItemType>
ItemType SumSquares_d(NodeType<ItemType>* list) {
    if (list->next == NULL)
        return list->info * list->info;
    else
        return list->info * list->info + SumSquares_d(list->next);
}

template<class ItemType>
ItemType SumSquares_e(NodeType<ItemType>* list) {
    if (list == NULL)
        return 0;
    else {
        return list->info * list->info + SumSquares_e(list->next);
    } //더해지고 있지 않음
}

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

template<class ItemType>
void UnsortedType<ItemType>::PrintSumSquares() {
    std::cout << SumSquares_a(listData) << std::endl;
    std::cout << SumSquares_b(listData) << std::endl;
    std::cout << SumSquares_c(listData) << std::endl;
    std::cout << SumSquares_d(listData) << std::endl;
    std::cout << SumSquares_e(listData) << std::endl;
}
