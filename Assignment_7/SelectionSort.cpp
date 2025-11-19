//SELECTION SORT
// CONCEPT USED:- START FROM FIRST ELEMENT AND TRAVERSE THE REST OF THE ARRAY, IF ANY MIN FOUND SWAP 
#include<iostream >
using namespace std;
int main ()
{
	int a[5]={2,3,5,4,1};
	for(int i=0;i<4;i++)
	{
		int min=i;
		for(int j=i+1;j<5;j++)
		{
			if(a[min]>a[j])
			{
				min=j;
			}
		}
		if(min!=i)
		{
			int temp ;
			temp=a[i];
			a[i]=a[min];
			a[min]=temp;
		}
	}
	cout<<"sorted array =\n";
	for(int i=0;i<5;i++)
	{
		cout<<a[i]<<endl;
	}
}
