#include <iostream>

const unsigned int MAX_SIZE = 1000;

bool next(bool number[], size_t size)
{
	int idx = size - 1;

	while (idx >= 0 && number[idx] == true)
	{
		number[idx] = false;
		--idx;
	}

	if (idx == -1)
		return false;

	number[idx] = true;
	return true;
}

void print_number(int arr[MAX_SIZE], bool number[MAX_SIZE], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		if (number[i] == true)
		{
			std::cout << arr[size - i - 1] << " ";
		}
	}
	std::cout << std::endl;
}

void print_all_subsets(int arr[MAX_SIZE], size_t size)
{
	if (size >= MAX_SIZE)
		return;
	bool number[MAX_SIZE]{};

	do
	{
		print_number(arr, number, size);
	} while (next(number, size));
}

int main()
{
	for (size_t i = 0; i < 10; i++)
	{
		std::cout << i << " ";
	}
	int arr[] = { 1, 2, 3, 4 };
	print_all_subsets(arr, 4);
}