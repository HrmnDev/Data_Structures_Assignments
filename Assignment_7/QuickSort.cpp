//QUICK SORT
#include<iostream>
using namespace std;
int partition(int a[],int p,int r)
{
	int x=a[r];  //setting last as pivot
	int i=p-1;
	for(int j=p;j<r;j++)
	{
		if(a[j]<=x)  //comparing the pivot with others to swap
		{
			i++;
			swap(a[i],a[j]);  //place smaller to left
		}
	}
		swap(a[i+1],a[r]);  //pivot in the correct position
	
	return i++;
}
void quicksort(int a[],int p,int r)
{
	if(p<r)
	{
int q=partition(a,p,r);
quicksort(a,p,q-1);
quicksort(a,q+1,r);	
}
}
int main()
{
	int a[5]={5,2,1,3,4};

	quicksort(a,0,4);
	cout<<"sorted array :\n";
	for(int i=0;i<5;i++)
	{
		cout<<a[i]<<endl;
	}
}
