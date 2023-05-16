#include <cstring>
#include "StrType.h"

RelationType StrType::ComparedTo(StrType& otherString) {
	int result = strcmp(this->letters, otherString.letters);
	switch (result)
	{
	case -1:return LESS;
	case 0: return EQUAL;
	case 1: return GREATER;
	}
}

