
 /*SquarMatrix ADT Specification 

���� : N * N�� 2���� ���

����:
  1. MakeEmpty(n)
    ���: Matrix�� n �� �� ���θ� 0���� �ʱ�ȭ
    ����: N�� �ִ� ũ��� 50
    ���: N ���� �� ���� 0���� �ʱ�ȭ

  2. StoreValue(i, j, value)
    ��� : value�� i��°��, j��° ���� ��ġ�� �����Ѵ�.
    ���� : i�� j�� �ִ� 50����
    ��� : i�� j�� ��ġ�� ���� value�� ����

  3. Add (SquareMatrix1, SquareMatrix2, result)
    ��� : �� ����� �Բ� ���� ��, result�� ����
    ���� : �� ����� ���� ũ���� ���� ����
    ��� : �� ����� ���� ���ο� ����� result�� ����

  4. Subtract (SquareMatrix1, SquareMatrix2, result)
    ��� : SqaureMatrix1�� SquareMatrix2 ��ķκ��� �� �� result�� ����
    ���� : �� ����� ���� ũ���� ���� ����
    ��� : �� ��Ŀ��� �ٸ� ����� ���� ����� result�� ����

  5. Copy (SquareMatrix1, SquareMatrix2)
    ��� : SquareMatrix1�� SquareMatrix2�� �����Ѵ�.
    ���� : SquareMatrix2�� �ʱ�ȭ�� ������ ��
    ��� : SquareMatrix1�� SquareMatrix2�� ���� ��� ����

  6. printMatrix
    ��� : ����� Ŀ�ο� ����Ʈ �Ѵ�.
    ���� : �ùٸ� ����϶�
    ��� : �� ��� ���� �Ҵ�� ������ ���ʴ�� ����Ʈ �Ѵ�.
  7. SquareMatrix(n)
    ��� : Constructor of SquareMatrix Class
    ���� : class ���� private �������� �ʱ�ȭ�� �ؾ���
    ��� : SquareMatrix Ŭ������ ��ü�� �����ϰ� �ɹ� �Լ� ��밡���� �� ����*/

#include <iostream>

using namespace std;

const int MAX_ROWS = 50;
const int MAX_COLS = 50;

class SquareMatrix
{
private:
    int matrix[MAX_ROWS][MAX_COLS];
    int size;

public:
    void MakeEmpty(int);
    void StoreValue(int, int, int);
    void Add(SquareMatrix&, SquareMatrix*);
    void Subtract(SquareMatrix&, SquareMatrix*);
    void Copy(SquareMatrix&);
    void printMatrix();
    SquareMatrix (int);
};

SquareMatrix::SquareMatrix(int r) {
    if (r >= MAX_ROWS) {
        cout << "Error: Out of Range";
        exit(222);
    }
    this->size = r;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < r; j++) {
            int ran = rand() % 101;
            this->matrix[i][j] = ran;
        }
    }
}

void SquareMatrix::MakeEmpty(int n) {
    if (n > MAX_COLS) {
        cout << "Error: Out Of Range";
        exit(222);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }
}

void SquareMatrix::StoreValue(int i, int j, int value) {
    matrix[i][j] = value;
}

void SquareMatrix::Add(SquareMatrix& mat, SquareMatrix* result) {
    if ((this->size) != mat.size) {
        cout << "Error: Size not Right";
        exit(222);
    }
    else {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                (*result).matrix[i][j] = (this->matrix)[i][j] + (mat.matrix)[i][j];
            }
        }
    }
}

void SquareMatrix::Subtract(SquareMatrix& mat, SquareMatrix* result) {
    if ((this->size) != mat.size) {
        cout << "Error: Size not Right";
        exit(222);
    }
    else {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                (*result).matrix[i][j] = (this->matrix)[i][j] - (mat.matrix)[i][j];
            }
        }
    }
}

void SquareMatrix::Copy(SquareMatrix& mat) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            (this->matrix)[i][j] = (mat.matrix)[i][j];
        }
    }
}

void SquareMatrix::printMatrix() {
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            cout << this->matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    SquareMatrix matrix1(10);
    SquareMatrix matrix2(10);
    SquareMatrix matrix3(10);
    SquareMatrix matrix4(11);
    SquareMatrix result(10);
    //SquareMatrix matrix5(51); 
    //MAX_ROW or MAX_COL ���� ���� ���϶� ����

    cout << "Matrix 1" << endl;
    matrix1.printMatrix();
    cout << endl;

    cout << "Emptying untill 5th rows & cols" << endl;
    matrix1.MakeEmpty(5);
    matrix1.printMatrix();
    cout << endl;

    cout << "Storing 17 in row 3, col 2" << endl;
    matrix1.StoreValue(2, 1, 17);
    matrix1.printMatrix();
    cout << endl;

    cout << "Matrix 2" << endl;
    matrix2.printMatrix();
    cout << endl;

    //matrix4.Add(matrix3, &result);
    // matrix4.Subtract(matrix3, &result);
    // �ٸ� �������� ��Ʈ�������� ����� ����

    matrix1.Add(matrix2,&result);
    cout << "Matrix1 + Matrix2" << endl;
    result.printMatrix();
    cout << endl;

    matrix2.Subtract(matrix1, &result);
    cout << "Matrix2 - Matrix1" << endl;
    result.printMatrix();
    cout << endl;

    cout << "Matrix3" << endl;
    matrix3.printMatrix();
    cout << endl;

    matrix2.Copy(matrix3);
    cout << "Copying Matrix3 to Matrix2" << endl;
    matrix2.printMatrix();
}