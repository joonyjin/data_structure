/*

A)

DeletedItem (ItemType item)

��� : ����Ʈ ���� ��� �� item�� ��ġ�ϴ� ��Ҹ� �����Ѵ�.
���� : ����Ʈ�� �ʱ�ȭ
��� : ����Ʈ ���ο� item�� ���� ���� ������ ��� �� ���� �������, �� ����
	   ��쿡�� �ƹ��ϵ� �Ͼ�� �ʴ´�. 
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

