//Program to Find Sum of every Row and Column in a Matrix

#include <iostream>
using namespace std;

void MatrixSum(int rows, int cols)
{
    int matrix[rows][cols];
    int rowSum[rows] = {0};
    int colSum[cols] = {0};

    cout << "Enter elements of the matrix:\n";
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
            rowSum[i] += matrix[i][j];
            colSum[j] += matrix[i][j];
        }
    }

    cout << "Row sums:\n";
    for(int i = 0; i < rows; i++)
    {
        cout << "Row " << (i + 1) << ": " << rowSum[i] << endl;
    }

    cout << "Column sums:\n";
    for(int j = 0; j < cols; j++)
    {
        cout << "Column " << (j + 1) << ": " << colSum[j] << endl;
    }
}

int main()
{
    int rows, cols;
    cout << "Enter the Number of rows: ";
    cin >> rows;
    cout << "Enter the Number of columns: ";
    cin >> cols;

    MatrixSum(rows, cols);

    return 0;
}