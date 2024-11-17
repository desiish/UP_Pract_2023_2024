#include <iostream>

const int MAX_ROWS = 10;
const int MAX_COLS = 10;

bool is_valid_index(size_t N, size_t M,
	int x, int y)
{
	return x >= 0 && y >= 0 && x < N && y < M;
}

bool is_center(int matrix[MAX_ROWS][MAX_COLS],
	size_t N, size_t M,
	int x, int y)
{
	if (!is_valid_index(N, M, x, y))
		return false;

	int sum = 0;

	int indexes[8][2] = {
		{x, y - 1},
		{x, y + 1},
		{x - 1, y},
		{x + 1, y},
		{x + 1, y - 1},
		{x + 1, y + 1},
		{x - 1, y + 1},
		{x - 1, y - 1},
	};

	unsigned count = 0;
	for (size_t i = 0; i < 8; i++)
	{
		int current_x = indexes[i][0];
		int current_y = indexes[i][1];

		if (is_valid_index(N, M, current_x, current_y))
		{
			++count;
			sum += matrix[current_x][current_y];
		}
	}

	double avg = (double)sum / count;

	return (avg < matrix[x][y]);
}

void print_center(int matrix[MAX_ROWS][MAX_COLS],
	size_t N,
	size_t M)
{
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			if (is_center(matrix, N, M, i, j))
			{
				std::cout << i << " " << j << std::endl;
			}
		}
	}
}

int main()
{
	unsigned N = 0;
	unsigned M = 0;

	std::cin >> N >> M;

	int matrix[MAX_ROWS][MAX_COLS]{};

	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			std::cin >> matrix[i][j];
		}
	}

	print_center(matrix, N, M);
}