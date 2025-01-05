#include <iostream>
#include <fstream>
using namespace std;

int countCols(ifstream& ifs) {
	char ch;

	int count = 0;

	while (true) {
		ch = ifs.get();

		if (ch == ' ') {
			count++;
		}

		if (ch == '\n') {
			count++;
			break;
		}
	}

	return count;
}

int getCharOccurance(ifstream& ifs, char target) {
	char current;

	int result = 0;

	while (true) {
		current = ifs.get();

		if (ifs.eof()) {
			break;
		}

		if (current == target) {
			result++;
		}
	}

	return result + 1;
}

int countRows(ifstream& ifs) {
	return getCharOccurance(ifs, '\n');
}

void calculateDimensions(const char* inputFile, int& rows, int& cols) {
	ifstream ifs(inputFile);

	if (!ifs.is_open()) {
		return;
	}

	int currentPos = ifs.tellg();
	cols = countCols(ifs);
	ifs.seekg(0, currentPos);
	rows = countRows(ifs);
	ifs.close();
}

int** readMatrix(const char* file, int rows, int cols) {
	int** matrix = new int*[rows];
	for (int i = 0; i < rows; i++) {
		matrix[i] = new int[cols];
	}

	ifstream ifs(file);

	if (!ifs.is_open()) {
		return nullptr;
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			ifs >> matrix[i][j];
		}
	}

	return matrix;
}

double** createCopy(const int* const* matrix, int startingRow, int startingCol, int size) {
	double** temp = new double* [size];
	for (int i = 0; i < size; i++) {
		temp[i] = new double[size];
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			temp[i][j] = matrix[startingRow + i][startingCol + j];
		}
	}
	return temp;
}

double determinant(const int* const* matrix, int startingRow, int startingCol, int size) {
	double det = 1;
	double** temp = createCopy(matrix, startingRow, startingCol, size);

	for (int i = 0; i < size; i++) {
		if (temp[i][i] == 0) return 0;

		for (int j = i + 1; j < size; j++) {
			double factor = temp[j][i] / temp[i][i];

			for (int k = i; k < size; k++) {
				temp[j][k] -= temp[i][k] * factor;
			}
		}

		det *= temp[i][i];
	}

	for (int i = 0; i < size; i++) {
		delete[] temp[i];
	}
	delete[] temp;

	return det;
}

void findRang(const int* const* matrix, int rows, int cols, int& resultRow, 
	int& resultCol, int& resultSize) {
	double resDet = 1.0;

	int maxRang = min(rows, cols);

	for (int size = 1; size <= maxRang; size++) {
		for (int i = 0; i <= rows - size; i++) {
			for (int j = 0; j <= cols - size; j++) {
				double det = determinant(matrix, i, j, size);

				bool isBetter = size > resultSize || (size == resultSize && abs(det) > abs(resDet));

				if (det != 0 && isBetter) {
					resultRow = i;
					resultCol = j;
					resultSize = size;
				}
			}
		}
	}
}

void saveMinor(const char* resultFile, const int* const* matrix,
	int resultRow, int resultCol, int resultSize) {
	ofstream ofs(resultFile);

	if (!ofs.is_open()) {
		cout << "Could not open file";
		return;
	}

	for (int i = 0; i < resultSize; i++) {
		for (int j = 0; j < resultSize; j++) {
			ofs << matrix[resultRow + i][resultCol + j] << " ";
		}
		ofs << endl;
	}
}

void freeMatrix(int** matrix, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		delete[] matrix[i];
	}

	delete[] matrix;
}

int main() {
	const char* inputFile = "matrix.txt";
	const char* outputFile = "result.txt";

	int rows = 0, cols = 0;

	calculateDimensions(inputFile, rows, cols);

	if (rows == 0 || cols == 0) {
		cout << "Could not read";
		return 0;
	}

	int** matrix = readMatrix(inputFile, rows, cols);

	int resultRow = 0, resultCol = 0, resultSize = 0;

	findRang(matrix, rows, cols, resultRow, resultCol, resultSize);

	saveMinor(outputFile, matrix, resultRow, resultCol, resultSize);

	freeMatrix(matrix, rows, cols);
}