// Matrix Multiplication WITHOUT using inbuilt functions

#include <iostream>
using namespace std;

// Step 1: Input Matrix
void inputMatrix(int matrix[100][100], int rows, int cols, char name)
{
    cout << "\nEnter elements of Matrix " << name << ":\n";

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << name << "[" << i + 1 << "][" << j + 1 << "] = ";
            cin >> matrix[i][j];
        }
    }
}

// Step 2: Print Matrix
void printMatrix(int matrix[100][100], int rows, int cols, char name)
{
    cout << "\nMatrix " << name << ":\n";

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

// Step 3: Multiply Matrices
void multiplyMatrix(int A[100][100], int B[100][100],
                    int result[100][100],
                    int rows1, int cols1, int cols2)
{
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            result[i][j] = 0;

            for (int k = 0; k < cols1; k++)
            {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Step 4: Main Function
int main()
{
    int A[100][100], B[100][100], result[100][100];
    int rows1, cols1, rows2, cols2;

    cout << "Matrix Multiplication\n";

    cout << "Enter rows and cols of Matrix A: ";
    cin >> rows1 >> cols1;

    cout << "Enter rows and cols of Matrix B: ";
    cin >> rows2 >> cols2;

    if (cols1 != rows2)
    {
        cout << "Multiplication not possible!\n";
        return 0;
    }

    inputMatrix(A, rows1, cols1, 'A');
    inputMatrix(B, rows2, cols2, 'B');

    multiplyMatrix(A, B, result, rows1, cols1, cols2);

    printMatrix(A, rows1, cols1, 'A');
    printMatrix(B, rows2, cols2, 'B');
    printMatrix(result, rows1, cols2, 'R');

    return 0;
}
/*
Matrix Multiplication
Enter rows and cols of Matrix A: 2 3
Enter rows and cols of Matrix B: 3 2

Enter elements of Matrix A:
A[1][1] = 1
A[1][2] = 2
A[1][3] = 3
A[2][1] = 4
A[2][2] = 5
A[2][3] = 6

Enter elements of Matrix B:
B[1][1] = 7
B[1][2] = 8
B[2][1] = 9
B[2][2] = 10
B[3][1] = 11
B[3][2] = 12

Matrix A:
1	2	3
4	5	6

Matrix B:
7	8
9	10
11	12

Matrix R:
58	64
139	154

*/