#include <iostream>

void getCountOfDigits(int counter[], unsigned n)
{
	if (n == 0)
	{
		counter[0]++;
		return;
	}

	while (n != 0)
	{
		int lastDigit = n % 10;
		counter[lastDigit]++;
		n /= 10;
	}
}

bool isSubset(unsigned n, unsigned k)
{
	int countOfDigitsN[10] = { 0 };
	int countOfDigitsK[10] = { 0 };

	getCountOfDigits(countOfDigitsN, n);
	getCountOfDigits(countOfDigitsK, k);

	for (int i = 0; i < 10; i++)
	{
		if (countOfDigitsN[i] < countOfDigitsK[i])
			return false;
	}

	return true;
}

int main()
{
	unsigned n, k;
	std::cin >> n >> k;

	std::cout << isSubset(n, k);
}