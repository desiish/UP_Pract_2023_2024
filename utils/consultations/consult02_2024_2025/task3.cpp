#include <iostream>

bool isSuffix(unsigned n, unsigned k)
{
	if (k == 0)
		return (n % 10 == 0);

	while (n >= k && k > 0)
	{
		int lastDigitN = n % 10;
		int lastDigitK = k % 10;

		if (lastDigitN != lastDigitK)
			return false;

		n /= 10;
		k /= 10;
	}

	return true;
}

bool isInfix(unsigned n, unsigned k)
{
	while (n >= k)
	{
		if (isSuffix(n, k))
			return true;

		n /= 10;
	}

	return false;
}

int main()
{
	unsigned k;
	std::cin >> k;

	int n;
	std::cin >> n;

	while (n != 0)
	{
		std::cout << isInfix(n, k) << '\n';
		std::cin >> n;
	}
}