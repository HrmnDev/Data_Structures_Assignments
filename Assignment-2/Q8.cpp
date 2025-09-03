//Program to Count Distinct Elements in an Array

#include<iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter Size of Array: ";
    cin >> n;

    int arr[n];
    cout << "Enter Array Elements: ";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int count = 0; 

    for (int i = 0; i < n; i++)
    {
        int flag = 0; 

        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0) 
        {
            count++;
        }
    }

    cout << "Total number ox distinct elements: " << count << endl;

    return 0;
}
