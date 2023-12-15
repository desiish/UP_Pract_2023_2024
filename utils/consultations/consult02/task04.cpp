#include <iostream>
using namespace std;
const int SIZE = 8;
const int MAX_SIZE = 1024;

bool isValid(int x, int y, const int matrix[SIZE][SIZE]) {
	return x >= 0 && x < SIZE&& y >= 0 && y < SIZE && matrix[x][y] == 0;
}

void getPosition(const int positions[][2], int& get, int& x, int& y) {
	x = positions[get][0];
	y = positions[get][1];
	++get;
}

void putPosition(int positions[][2], int& put, int x, int y) {
	positions[put][0] = x;
	positions[put][1] = y;
	++put;
}

void mark(int matrix[][SIZE], int x, int y, int count, 
			int positions[][2], int& put) {
	if (!isValid(x, y, matrix)) {
		return;
	}
	matrix[x][y] = count;
	putPosition(positions, put, x, y);
}

int minMoves(int startX, int startY, int endX, int endY) {
	int matrix[SIZE][SIZE] = { {0} };
	int positions[SIZE*SIZE][2];

	int get, put;
	get = put = 0;

	matrix[startX][startY] = 1;
	putPosition(positions, put, startX, startY);

	while (get < put) {
		int currX, currY;
		getPosition(positions, get, currX, currY);

		if (currX == endX && currY == endY) {
			return matrix[endX][endY] - 1;
		}

		int count = matrix[currX][currY] + 1;
		mark(matrix, currX + 1, currY + 2, count, positions, put);
		mark(matrix, currX + 1, currY - 2, count, positions, put);
		mark(matrix, currX - 1, currY + 2, count, positions, put);
		mark(matrix, currX - 1, currY - 2, count, positions, put);
		mark(matrix, currX + 2, currY + 1, count, positions, put);
		mark(matrix, currX + 2, currY - 1, count, positions, put);
		mark(matrix, currX - 2, currY + 1, count, positions, put);
		mark(matrix, currX - 2, currY - 1, count, positions, put);
	}

	return matrix[endX][endY] - 1;
}

int main() {
	cout << minMoves(0, 0, 3, 2) << endl;
	cout << minMoves(0, 0, 5, 3) << endl;
}
