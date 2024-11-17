#include <iostream>

const size_t MAX_SIZE = 10;

int getColSum(int matrix[][MAX_SIZE], size_t rows, size_t colIdx)
{
	int sum = 0;
	for (int i = 0; i < rows; i++)
		sum += matrix[i][colIdx];

	return sum;
}

bool hasTwoColsWithSumK(int matrix[][MAX_SIZE], 
	size_t rows, size_t cols, int k)
{
	int sums[MAX_SIZE];

	for (int i = 0; i < cols; i++)
	{
		sums[i] = getColSum(matrix, rows, i);
	}

	size_t beg = 0, end = cols - 1;

	while (beg != end)
	{
		int sumOfCols = sums[beg] + sums[end];

		if (sumOfCols == k)
			return true;

		else if (sumOfCols > k)
			end--;
		else
			beg++;
	}

	return false;
}

int main()
{
	int matrix[MAX_SIZE][MAX_SIZE];

	size_t rows, cols;
	std::cin >> rows >> cols;

	if (rows <= 0 || rows > 10 || cols <= 0 || cols > 10)
	{
		std::cout << "Invalid arguments";
		return -1;
	}

	int k;
	std::cin >> k;

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
			std::cin >> matrix[i][j];
	}

	std::cout << hasTwoColsWithSumK(matrix, rows, cols, k);
}