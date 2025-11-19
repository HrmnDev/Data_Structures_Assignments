//INSERTION SORT
#include<iostream>
using namespace std;
int main ()
{
	int a[5] = {3,2,5,4,1};
	for(int i=1; i<5; i++)
	{
		int temp;
		temp = a[i];
		int j = i;
		while((j > 0)  &&  (a[j-1] > temp))
		{
			a[j] = a[j-1];
			j--;
		
						
		}
			a[j] = temp;
	}
	cout<<"The sorted array is:\n";
	for(int i=0; i<5; i++)
	{
		cout<<a[i]<<endl;
	}
}
