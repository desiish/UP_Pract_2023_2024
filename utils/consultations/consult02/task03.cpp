#include <iostream>
using namespace std;
const int SIZE = 100;

bool isPrefix(const int* list, size_t listSize, const int* prefix, size_t prefixSize) {
	//приемаме, че nullptr отговаря на празен списък, празен списък винаги е префикс
  if (!list || !prefix) {
		return prefix == nullptr;
	}
	if (prefixSize > listSize) {
		return false;
	}

	while (prefixSize--) {
		if (*list != *prefix) {
			return false;
		}
		++list;
		++prefix;
	}
	return true;
}

//проверяваме дали за някой списък има префикс в префиксите, тоест дали някой отт префиксите е префикс на списъка
bool containsPrefixes(const int* list, size_t listSize, const int prefixes[][SIZE], size_t rowSize, size_t colSize) {
	for (int i = 0; i < rowSize; i++) {
		if (isPrefix(list, listSize, prefixes[i], colSize)) {
			return true;
		}
	}
	return false;
}

//за всеки от списъците проверяваме дали ще намерим префикс
int countOfPrefixes(const int list[][SIZE], size_t lRowSize, size_t lColSize,
					const int prefixes[][SIZE], size_t pRowSize, size_t pColSize) {
	int count = 0;
	for (int i = 0; i < lRowSize; i++) {
		count += containsPrefixes(list[i], lColSize, prefixes, pRowSize, pColSize);
	}

	return count;
}

int main()
{
	int list[][SIZE] = { {1, 2, 3}, {2, 3, 4}, {3, 4, 5} };
	int prefixes[][SIZE] = { {3, 4}, {2, 4}, {1, 2} };
	cout << countOfPrefixes(list, 3, 3, prefixes, 3, 2);
}
