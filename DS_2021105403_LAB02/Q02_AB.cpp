/*

A)

DeletedItem (ItemType item)

기능 : 리스트 내의 요소 중 item과 일치하는 요소를 삭제한다.
조건 : 리스트의 초기화
결과 : 리스트 내부에 item과 같은 값이 존재할 경우 그 값은 사라지고, 그 외의
	   경우에는 아무일도 일어나지 않는다. 
*/

//B)

#include "unsorted.h"

void UnsortedType::DeleteItem(ItemType item)
{
	int location = 0;
	bool deleted = false;

	while (!deleted && location < length) {
		if (item.ComparedTo(info[location]) == EQUAL) {
			info[location] = info[length - 1];
			length--;
			deleted = true;
		}
		else {
			location++;
		}
	}
}

