//Program to count the Number of Occurrences of key in a SLL and Delete all Occurrences
//I/P: 1->2->3->2->4->2, Key = 2
//O/P: Count = 3, Modified List = 1->3->4

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

class SSL
{
    public:
        Node* head;
        
        SSL()
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
           
            if(pos == 0)
            {
                InsertBeg(value);
                return;
            }
           
            Node* temp = new Node(value);
            Node* current = head;
            Node* prev = NULL;
            int count = 0;
           
            while(current != NULL && count < pos)
            {
                prev = current;
                current = current -> next;
                count++;
            }
           
            if(count != pos)
            {
                cout << "Position out of bounds" << endl;
                delete temp;
                return;
            }
           
            prev -> next = temp;
            temp -> next = current;
        }
       
        void DeleteBeg()
        {
            if(head == NULL)
            {
                cout << "List is empty" << endl;
                return;
            }
           
            Node* temp = head;
            head = head -> next;
            delete temp;
        }
       
        void DeleteEnd()
        {
            if(head == NULL)
            {
                cout << "List is empty" << endl;
                return;
            }
           
            if(head -> next == NULL)
            {
                delete head;
                head = NULL;
                return;
            }
           
            Node* current = head;
            Node* prev = NULL;
           
            while(current -> next != NULL)
            {
                prev = current;
                current = current -> next;
            }
           
            prev -> next = NULL;
            delete current;
        }
       
        void DeleteValue(int value)
        {
            if(head == NULL)
            {
                cout << "List is empty" << endl;
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

        void Display()
        {
            if(head == NULL)
            {
                cout << "List is empty" << endl;
                return;
            }
           
            Node* current = head;
            while(current != NULL)
            {
                cout << current -> data << " -> ";
                current = current -> next;
            }
        }
};
int main()
{
    SSL ll;
    ll.InsertEnd(5);
    ll.InsertEnd(10);
    ll.InsertEnd(5);
    ll.InsertEnd(20);
    ll.InsertEnd(5);
    ll.InsertEnd(30);

    ll.Display();

    int key = 5;
    int count = 0;
    Node* current = ll.head;
    while(current != NULL)
    {
        if(current -> data == key)
        {
            count++;
        }
        current = current -> next;
    }
    cout << "\nCount of " << key << " is: " << count << endl;

    // Deleting all occurrences of key
    current = ll.head;
    while(current != NULL)
    {
        if(current -> data == key)
        {
            ll.DeleteValue(key);
            current = ll.head; // Restart from head after deletion
        }
        else
        {
            current = current -> next;
        }
    }
    ll.Display();
    return 0;
}