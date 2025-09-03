// Implement the Binary search algorithm regarded as a fast search algorithm with run-time
// complexity of Ο(log n) in comparison to the Linear Search. 

#include <iostream>

using namespace std;

int binarySearch(int arr[], int size, int key) 
{
    int start = 0;
    int end = size - 1;
    int mid;
    while (start <= end)
    {

        mid = start + (end - start)/2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            start = mid + 1;
        else
            end = mid - 1;

    }

    return -1;
}

int main()
{
    cout << "Enter the size of the array: ";
    int size;
    cin >> size;
    int arr[255];

    cout << "Enter the elements of the array in sorted order: ";
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    cout << "Enter the element to be searched: ";
    int key;
    cin >> key;

    int result = binarySearch(arr, size, key);

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found in the array" << endl;

    return 0;  
}