/*
C)

DeletedItem (ItemType item)

��� : ����Ʈ ������ ��ҵ� �� item�� ��ġ�ϴ� ��� �� ����
���� : ����Ʈ�� �ʱ�ȭ
��� : ����Ʈ ��ҵ� �� item�� ��ġ�ϴ� ���� ������
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
