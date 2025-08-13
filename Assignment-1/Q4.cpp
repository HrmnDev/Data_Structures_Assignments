//Program to Reverse an Array, Find Matrix Transpose and Matrix Multiplication

#include <iostream>
using namespace std;

void ReverseArray(int arr[], int &size)
{
    int start = 0;
    int end = size - 1;

    while(start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        
        start++;
        end--;
    }
}

void MatrixTranspose()
{
    int size;
    cout << "Enter number of rows/columns: ";
    cin >> size;

    int matrix[size][size];

    cout << "Enter elements of the matrix:\n";
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            cin >> matrix[i][j];
        }
    }

    for(int i = 0; i < size; i++)
    {
        for(int j = i+1; j < size; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    cout << "Transposed matrix:\n";
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

}

void MatrixMultiplication()
{
    int r1, c1, r2, c2;
    cout << "Enter dimensions of first matrix (rows and columns): ";
    cin >> r1 >> c1;
    cout << "Enter dimensions of second matrix (rows and columns): ";
    cin >> r2 >> c2;

    if(c1 != r2)
    {
        cout << "Matrix multiplication not possible with these dimensions!" << endl;
        return;
    }

    int mat1[r1][c1], mat2[r2][c2], result[r1][c2];

    cout << "Enter elements of first matrix:\n";
    for(int i = 0; i < r1; i++)
    {
        for(int j = 0; j < c1; j++)
        {
            cin >> mat1[i][j];
        }
    }

    cout << "Enter elements of second matrix:\n";
    for(int i = 0; i < r2; i++)
    {
        for(int j = 0; j < c2; j++)
        {
            cin >> mat2[i][j];
        }
    }

    // Initialize result matrix
    for(int i = 0; i < r1; i++)
        for(int j = 0; j < c2; j++)
            result[i][j] = 0;

    // Matrix multiplication
    for(int i = 0; i < r1; i++)
    {
        for(int j = 0; j < c2; j++)
        {
            for(int k = 0; k < c1; k++)
            {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    cout << "Resultant matrix after multiplication:\n";
    for(int i = 0; i < r1; i++)
    {
        for(int j = 0; j < c2; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

}

int main()
{
    int choice;
    int size;
    int arr[100]; // Declare with a fixed size to avoid VLA issues

    do
    {
        cout << "----------------Menu----------------\n";
        cout << "1. Reverse an Array\n";
        cout << "2. Find Matrix Transpose\n";
        cout << "3. Matrix Multiplication\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Enter the number of elements in the array: ";
                cin >> size;

                cout << "Enter the elements of the array:\n";
                for(int i = 0; i < size; i++)
                {
                    cin >> arr[i];
                }

                ReverseArray(arr, size);

                cout << "Reversed Array:\n";
                for(int i = 0; i < size; i++)
                {
                    cout << arr[i] << " ";
                }
                cout << endl;

                break;

            case 2:
                MatrixTranspose();
                break;
            
            case 3:
                MatrixMultiplication();
                break;

            default:
                if(choice != 4)
                {
                    cout << "Invalid choice! Please try again.\n";
                }
                break;
        }
    }
    while(choice != 4);


    return 0;
}