/*
C)

DeletedItem (ItemType item)

기능 : 리스트 내부의 요소들 중 item과 일치하는 모든 값 삭제
조건 : 리스트의 초기화
결과 : 리스트 요소들 중 item과 일치하는 값은 없어짐
*/

//D)

#include "unsorted.h"

void UnsortedType::DeleteItem(ItemType item)
{
	int location = 0;

	for (int i = 0; i < length; i++) {
		if (item.ComparedTo(info[location]) == EQUAL && location < length) {
			info[location] = info[length - 1];
			length--;
		}
		else location++;
	}
}
