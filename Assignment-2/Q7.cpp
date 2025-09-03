//Program to Count No. of Inversions in an array

#include <iostream>

using namespace std;

int main()
{
    int arr[100], n, i, j, count = 0;

    cout << "Enter Number of Elements: ";
    cin >> n;

    cout << "Enter Elements of Array: ";
    for(i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    for(i = 0; i < n; ++i)
    {
        for(j = i + 1; j < n; ++j)
        {
            if(arr[i] > arr[j])
            {
                count++;
            }
        }
    }

    cout << "Number of inversions are: " << count;

    return 0;
}