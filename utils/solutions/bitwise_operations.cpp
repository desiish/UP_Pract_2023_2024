#include <iostream>
using namespace std;

int getKthBitInN(int n, int k)
{
	if (k > 30) // 31 if n is unsigned
		return -1;

	int mask = 1;
	mask <<= k;

	return (n & mask) == mask;
}

int makeKthBitOne(int n, int k)
{
	if (k > 30)
		return n;

	int mask = 1;
	mask <<= k;

	return (n | mask);
}

int makeKthBitZero(int n, int k)
{
	if (k > 30)
		return n;
	int mask = 1;
	mask <<= k;
	mask = ~mask;

	return (n & mask);
}

int flipKthBit(int n, int k)
{
	if (k > 30)
		return n;
	int mask = 1;
	mask <<= k;

	return (n ^ mask);
}

int numWithKOnes(int k)
{
	if (k > 30)
		return 0;
	int mask = 1;
	mask <<= k;

	return mask - 1;
}

bool isPowOfTwo(unsigned n)
{
	if (n == 0)
		return false;

	int smaller = n - 1;
	return (smaller & n) == 0;
}
