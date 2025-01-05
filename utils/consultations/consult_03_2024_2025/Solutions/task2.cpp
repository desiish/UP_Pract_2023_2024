#include <iostream>

int getCntOfDiffBits(int m, int n)
{
	int res = m ^ n;

	int cnt = 0;
	while (res)
	{
		if (res & 1)
			cnt++;

		res >>= 1;
	}

	return cnt;
}

int main()
{
	int m, n;
	std::cin >> m >> n;

	std::cout << getCntOfDiffBits(m, n);
}