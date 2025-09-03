//Program for Symmetric Matrix

#include <iostream>

using namespace std;

int main() 
{
    int n;
    
    cout << "Enter the Order of the Matrix: ";
    cin >> n;

    int size = n*(n+1)/2;

    int a[size], k=0;

    for(int i=0; i<n; i++) 
    {
        for(int j=0; j<=i; j++) 
        {
            cin >> a[k++];
        }
    }

    cout << "Enter the Row and Column to be accessed: ";
    int r, c;
    cin >> r >> c;

    if(r >= c) 
        cout<<a[r*(r-1)/2+c-1];
    else 
        cout<<a[c*(c-1)/2+r-1];

    return 0;
}