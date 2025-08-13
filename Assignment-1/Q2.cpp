//Program to Remove Duplicates from an Array

#include <iostream>
using namespace std;

void removeDuplicates(int arr[], int &size)
{
    if(size == 0 || size == 1) 
    {
        return; // No duplicates in an empty or single-element array
    }

    for(int i = 0; i < size; i++)
    {
        for(int j = i+1; j<size; j++)
        {
            if(arr[i] == arr[j])
            {
                for(int k = j; k < size-1; k++)
                {
                    arr[k] = arr[k+1]; // Shift elements to the left
                }
                size--;
                j--;
            }
        }
    }
}

int main()
{

    cout << "Enter the number of elements in the array: ";
    int size;
    cin >> size;
    
    int arr[size];
    cout << "Enter the elements of the array:\n";
    for(int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    removeDuplicates(arr, size);
    cout << "Array after removing duplicates:\n";
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}