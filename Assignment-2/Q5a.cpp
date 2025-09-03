//Program for Diagonal Matrix

#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "Enter the Number of Diagonal Elements: ";
	cin >> n;

	cout << "Enter the  Elements: ";
	int arr[n];

	for(int i=0; i<n; i++)
		cin >> arr[i];

	int k=0;

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(i == j)
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