#include <iostream>

int get_num_len(int num)
{
	if (num == 0)
		return 1;

	int cnt = 0;
	while (num)
	{
		cnt++;
		num /= 10;
	}

	return cnt;
}

int* my_itoa(int num, int& len)
{
	len = get_num_len(num);

	int* numArr = new int[len];

	int idx = len - 1;
	while (idx >= 0)
	{
		numArr[idx--] = num % 10;
		num /= 10;
	}

	return numArr;
}

int my_atoi(const int* beg, const int* end)
{
	int res = 0;

	while (beg <= end)
	{
		res *= 10;
		res += *beg;
		beg++;
	}

	return res;
}

bool isDivByT(int num, int t)
{
	return num % t == 0;
}

bool doesExistSubnumDivByT(int n, int k, int t)
{
	int len;
	int* numArr = my_itoa(n, len);

	if (k > len)
	{
		delete[] numArr;
		return false;
	}

	int* beg = numArr, * end = numArr + k - 1;

	for (int i = 0; i < len - k + 1; i++)
	{
		if (isDivByT(my_atoi(beg, end), t))
		{
			delete[] numArr;
			return true;
		}

		beg++;
		end++;
	}

	delete[] numArr;
	return false;
}


int main()
{
	int n, k, t;
	std::cin >> n >> k >> t;

	std::cout << doesExistSubnumDivByT(n, k, t);

}