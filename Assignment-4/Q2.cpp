//Menu Programm for Circular Queues

#include <iostream>

using namespace std;

void push(int p,int a[],int &f,int &e,int size)
{
	if((f==-1) && (e==-1))
	{
		f++;
		e++;
		a[e] = p;
	}
	else if(f == (e+1)%size)
	{
		cout << "Overflow" << endl;
	}

	else
	{
		e = (e+1)%size;
		a[e] = p;
	}
	
}

void deq(int a[],int &f,int &e,int size)
{
	if((f==-1))
	{
		cout << "Underflow" << endl;
	}

	else
	{
		f = (f+1)%size;
	}
}

void isEmpty(int a[],int &f,int &e,int size)
{
	if(f<e)
	{
		cout << "Empty" << endl;
	}
	else
	{
		cout << "Number of Elements that can be added = " << size-e-1;
	}
	
}

void isFull(int a[],int &f,int &e,int size)
{
	if(f == (e+1)%size)
	{
		cout<<"Overflow" << endl;
	}
	
}

int peek(int a[],int &f,int &e,int size)
{
    return a[f];
}

void display(int a[],int &f,int &e,int size)
{
    int i=f;
    while(f>-1)
    {
        cout << a[i] << endl;
        if(i == e)
            break;
        i = (i+1)%size;
    }
}

int main ()
{
	cout << "Enter the Size of your Queue: ";
	int n;
	cin >> n;
	int q[n];
	int front=-1;
	int end=-1;

	while (front >= -1)
	{
		cout<<"----------MENU----------"<<endl;
		cout<<"Enter the Operation you want to Perform: "<<endl;
		cout<<"1. Enqueue"<<endl;
		cout<<"2. Dequeue"<<endl;
		cout<<"3. Check if Queue is Full"<<endl;
		cout<<"4. Check if Queueis Empty"<<endl;
		cout<<"5. Print the Top Most Element"<<endl;
		cout<<"6. Display the Elements"<<endl;
		cout<<"7. Exit the Program"<<endl;

		int ch;
		cin>>ch;

		if(ch==1)
		{	int v;
		    int s;
			
			cout << "Enter the Number of elements to be Added: ";
			cin >> v;
			for(int i=0;i<v;i++)
			{	
			cout<<"Enter the Element to be added: ";
			cin>>s;
			
			push(s,q,front,end,n);
		    }
		}
		
        else if(ch==2)
		{
			int p;
			cout<<"Enter the Number of element to be Deleted: ";
			cin>>p;

			for(int i=0;i<p;i++)
			{
			    deq(q,front,end,n);
		    }
		}

		else if(ch==3)
		{
			isFull(q,front,end,n);
		}

		else if(ch==4)
		{
			isEmpty(q,front,end,n);
		}

		else if(ch==5)
		{
			cout<<peek(q,front,end,n)<<endl;
		}

		else if(ch==6)
		{
		display(q,front,end,n);
		
		}

		else if(ch==7)
		{
			break;
		}
    }
}