#include <iostream>
using namespace std;
class CircularList
 {
    struct Node {
        int data;
        Node* next;
    };
    Node* head;
public:
       CircularList() {
        head = nullptr;
    }

    void insert(int value) {
        Node* newNode = new Node;
        newNode->data = value;
     
        if (head == nullptr) {
            head = newNode;
            newNode->next = head; 
        } else {
            Node* temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
    }
    void display() {
        if (head == nullptr) {
            cout << "List is empty";
            return;
        }
        Node* temp = head;
        cout << "Circular Linked List";
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);

        cout << head->data << endl;
    }
};
int main() {
    CircularList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    list.display();
    return 0;
}
