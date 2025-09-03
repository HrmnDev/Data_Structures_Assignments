// Lower triangular Matrix (i>j)

#include<iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter the Order of the Matrix: ";
    cin >> n;
    int arr[50];

    cout << "Enter the Elements: ";

    int k=0;

    for(int i=0;i<n*(n+1)/2;i++)
        cin >> arr[i];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {	
            if(i == j || i > j)
            {
                cout << arr[k] << " ";
                k++;
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}