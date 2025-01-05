#include <iostream>

bool isCapitalLetter(char ch)
{
	return ch >= 'A' && ch <= 'Z';
}

bool isLowerLetter(char ch)
{
	return ch >= 'a' && ch <= 'z';
}

bool isDigit(char ch)
{
	return ch >= '0' && ch <= '9';
}

bool isValidSymbol(char ch)
{
	return isCapitalLetter(ch) || isLowerLetter(ch) || isDigit(ch);
}

int getCntOfWords(const char* str)
{
	if (!str)
		return 0;

	int cnt = 0;

	if (isValidSymbol(*str))
		cnt++;

	while (*str)
	{
		if (!isValidSymbol(*str) && isValidSymbol(*(str + 1)))
			cnt++;

		str++;
	}

	return cnt;
}

int main()
{
	std::cout << getCntOfWords("a bc");
}

