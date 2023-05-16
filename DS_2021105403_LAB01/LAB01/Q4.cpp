
 /*SquarMatrix ADT Specification 

구조 : N * N의 2차원 행렬

연산:
  1. MakeEmpty(n)
    기능: Matrix의 n 행 열 내부를 0으로 초기화
    조건: N의 최대 크기는 50
    결과: N 안의 행 열은 0으로 초기화

  2. StoreValue(i, j, value)
    기능 : value를 i번째행, j번째 열의 위치에 저장한다.
    조건 : i와 j는 최대 50까지
    결과 : i와 j의 위치의 값을 value로 지정

  3. Add (SquareMatrix1, SquareMatrix2, result)
    기능 : 두 행렬을 함께 더한 후, result에 저장
    조건 : 두 행렬이 같은 크기일 때만 가능
    결과 : 두 행렬을 더한 새로운 행렬을 result에 저장

  4. Subtract (SquareMatrix1, SquareMatrix2, result)
    기능 : SqaureMatrix1을 SquareMatrix2 행렬로부터 뺀 후 result에 저장
    조건 : 두 행렬이 같은 크기일 때만 가능
    결과 : 한 행렬에서 다른 행렬이 빠진 행렬을 result에 저장

  5. Copy (SquareMatrix1, SquareMatrix2)
    기능 : SquareMatrix1에 SquareMatrix2를 복사한다.
    조건 : SquareMatrix2가 초기화된 상태일 때
    결과 : SquareMatrix1에 SquareMatrix2와 같은 행렬 저장

  6. printMatrix
    기능 : 행렬을 커널에 프린트 한다.
    조건 : 올바른 행렬일때
    결과 : 각 행과 열에 할당된 정수를 차례대로 프린트 한다.
  7. SquareMatrix(n)
    기능 : Constructor of SquareMatrix Class
    조건 : class 내부 private 변수들의 초기화를 해야함
    결과 : SquareMatrix 클래스의 객체를 생성하고 맴버 함수 사용가능할 수 있음*/

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
    //MAX_ROW or MAX_COL 보다 높은 값일때 에러

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
    // 다른 사이즈의 메트릭스끼리 연산시 오류

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