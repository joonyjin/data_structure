#include <cstring>
#include "StrType.h"

RelationType StrType::ComparedTo(StrType& otherString) {
	int count = 0;
	bool equal = true;
	RelationType result;
	while (this->letters[count] != '\0' && equal) {
		if (this->letters[count] != otherString.letters[count]) {
			equal = false;
		}
		else count++;
	}
	if (equal && otherString.letters[count] == '\0') result = EQUAL;
	else if (equal && otherString.letters[count] != '\0') result = LESS;
	else if (this->letters[count] < otherString.letters[count]) result = LESS;
	else result = GREATER;
	return result;
}