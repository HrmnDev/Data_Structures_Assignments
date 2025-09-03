//Find Missing Number in Sorted Array

#include <iostream>

using namespace std;

int main()
{
    cout << "Enter Size of the array: ";
    int size;
    cin >> size;
    int arr[255];

	cout << "Enter the Sorted Array";
	for(int i=0;i<10;i++)
		cin>>arr[i];

	cout << "Enter the Element to be found";
	int key;
	cin >> key;

	for(int i=0;i<size;i++)
	{
		if(arr[i]==key)
		{
			cout << "Element found at position = " << i+1;
			break;
		}
	}
}