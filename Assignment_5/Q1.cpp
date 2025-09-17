//Menu Program to implement Singly Linked List

#include <iostream>

using namespace std;

class Node
{
    public:
        int data;
        Node* next;
   
        Node(int value)
        {
            data = value;
            next = NULL;
        }
};

class SLL
{
    private:
        Node* head;
   
    public:
        SLL()
        {
            head = NULL;
        }
   
        void InsertBeg(int value)
        {
            Node* temp = new Node(value);
            temp->next = head;
            head = temp;
        }
       
        void InsertEnd(int value)
        {
            Node* temp = new Node(value);
           
            if(head == NULL)
            {
                head = temp;
            }
            else
            {
                Node* current = head;
                while(current -> next != NULL)
                {
                    current = current -> next;
                }
                current -> next = temp;
            }
        }
       
        void InsertPos(int value, int pos)
        {
            if(pos < 0)
            {
                cout << "Invalid Position" << endl;
                return;
            }
           
            Node* temp = new Node(value);
           
            if(pos == 0)
            {
                temp -> next = head;
                head = temp;
            }
            else
            {
                Node* current = head;
                int currentPos = 0;
               
                while(current != NULL && currentPos < pos-1)
                {
                    current = current -> next;
                    currentPos++;
                }
               
                if(current == NULL)
                {
                    cout << "Position out of Range" << endl;
                    return;
                }
               
                temp -> next = current -> next;
                current -> next = temp;
            }
        }
       
        void DeleteBeg()
        {
            if(head == NULL)
                cout << "Nothing to Delete" << endl;
            else
            {
                Node* temp = head;
                head = head -> next;
                delete temp;
            }
        }
       
        void DeleteEnd()
        {
            if(head == NULL)
                cout << "Nothing to Delete" << endl;
           
            else if( head -> next == NULL)
            {
                delete head;
                head = NULL;
            }
           
            else
            {
                Node* current = head;
                Node* prev = NULL;
               
                while(current -> next != NULL)
                {
                    prev = current;
                    current = current -> next;
                }
                delete current;
                prev -> next = NULL;
            }
        }

        void DelNode(int value)
        {
            if(head == NULL)
            {
                cout << "Nothing to Delete" << endl;
                return;
            }
           
            if(head -> data == value)
            {
                Node* temp = head;
                head = head -> next;
                delete temp;
                return;
            }
           
            Node* current = head;
            Node* prev = NULL;
           
            while(current != NULL && current -> data != value)
            {
                prev = current;
                current = current -> next;
            }
           
            if(current == NULL)
            {
                cout << "Value not found" << endl;
                return;
            }
           
            prev -> next = current -> next;
            delete current;
        }

        void Search(int value)
        {
            Node* current = head;
            int pos = 0;
            while(current != NULL)
            {
                if(current -> data == value)
                {
                    cout << "Value found at position: " << pos << endl;
                    return;
                }
                current = current -> next;
                pos++;
            }
            cout << "Value not found" << endl;
        }
       
        void Display()
        {
            Node* current = head;
            while (current != NULL)
            {
                cout << current->data << " -> ";
                current = current->next;
            }
            cout << endl;
        }
};

int main()
{
    SLL ll;
    ll.InsertBeg(5);
    ll.InsertBeg(10);
    ll.InsertBeg(15);

    ll.InsertEnd(3);
    ll.InsertPos(4,2);

    ll.Display();
   
    ll.DeleteBeg();
    ll.DeleteEnd();

    ll.DelNode(4);
    ll.Search(10);

    ll.Display();
    
    return 0;
}