#include<iostream>
using namespace std;
class Node
{
	 public:
	int data;
	  
	Node* next;
	
	 Node(int x)
	    {
	      data=x;
	         next=NULL;
		}
};
class List
{
	Node* Head;
	   public:
	List()
	    {
	     Head=NULL;
	   }
	      void insertbeg(int x)
	         {
	         	   if(Head==NULL)
	         	         {       Node* newnode=new Node(x);
	         	         	      Head=newnode;
	         	         	               return;
					}
				else
				{
					            Node* newnode=new Node(x);
								Node* temp =Head;
					            while(temp->next!=NULL)
					            {
				               	 temp=temp->next;
				               	 
								}
								temp->next=newnode;
								newnode->next=Head;
								 Head=newnode;
					}	
					               
		  }
		        void deletebeg()
		              {
		              	      Node* temp=Head;
		              	               while(temp->next!=Head)
		              	                        {
		              	                        	         temp=temp->next;
										 }
										    temp->next=Head->next;
										     Head=Head->next;
										     delete temp;
				}
				            void insert(int x,int pos)
				                        {
				                                  if(Head==NULL)
				                    		       {
				                    		       	                  Node* newnode=new Node(x);
				                    		       	                  Head=newnode;
														}
												else
												{        Node* newnode=new Node(x);
													 Node* temp=Head;
			                                    int c=0;
													 while(temp->next!=NULL||c!=pos)
													 {
														c++;
														temp=temp->next;
													 }
													      newnode->next=temp->next;
													           temp->next=newnode;
														}		
							}
		        void display()
		    	{       int c=0;
		Node* temp=Head;
		      while(temp->next!=Head)
		            {
		            	        c++;
		        cout<<temp->data<<"->"; 	
		              temp=temp->next;
			  }
			           cout<<"Total elements in list are"<<c;
				}
};
int main ()
{
	List ll;
	   ll.insertbeg(10);
	       ll.insertbeg(300);
	          
	      ll.insertbeg(20);
	         ll.insert(5,2);
	         ll.deletebeg();
	         ll.display();
}
