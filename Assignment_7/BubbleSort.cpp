//SIMPLE BUBBLE SORT 
//TIME COMPLEXITY: O(N)
#include<iostream>
using namespace std;
int main ()
{
  int n;
  cout<<"Enter Size of Array: ";
  cin>>n;
  cout<<"Enter Elements of Array:"<<endl;
	for(int k=0; k<n; k++)
  {
      cin>>a[k];
  }
	for(int i=0; i<n-1; i++)  //traversal from 0 to n-1
	{
		for(int j=0; j<n-1-i; j++)  //traversal from 0 to n-1-i
		{
			if(a[j] > a[j+1])
			{
				int temp ;
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	cout<<"Sorted array is :\n";
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<endl;
	}
}
