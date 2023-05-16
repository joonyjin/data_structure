#include <iostream>
#include <cmath>
using namespace std;



int NumPathsA(int row, int col, int n) {
	if (row == n || col == n) return 1;
	else {
		return NumPathsA(row + 1, col, n) + NumPathsA(row, col + 1, n);
	}
}


const int MAX_ROWS = 5;
const int MAX_COLS = 5;

static int mat[MAX_ROWS][MAX_COLS];

int NumPathsB(int row, int col, int n) {
	if (mat[row][col] == -1) {
		if (row == n || col == n) { mat[row][col] = 1; return 1; }
		else {
			mat[row][col] =  NumPathsB(row + 1, col, n) + NumPathsB(row, col + 1, n);
			return mat[row][col];
		}
	}
	return mat[row][col];
}

int main() {
	cout << NumPathsA(1, 1, 5) << endl;

	for (int i = 0; i < MAX_ROWS; i++) {
		for (int j = 0; j < MAX_COLS; j++) {
			mat[i][j] = -1;
		}
	}
	cout << NumPathsB(1, 1, 5) << endl;

}