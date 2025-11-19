#include <iostream>
using namespace std;
class DoublyLinkedList {
private:
    struct Node {
        char data;
        Node* prev;
        Node* next;
    };
    Node* head;
    Node* tail;
public:
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }
   void insert(char ch) {
        Node* newNode = new Node{ch, NULL, NULL};
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    int Palindrome() {
        if (head == NULL)
            return 1;
        Node* left = head;
        Node* right = tail;
        while (left != right && right->next != left) {
            if (left->data != right->data)
                return 0;
            left = left->next;
            right = right->prev;
        }
        return 1;
    }
    void display() {
        Node* temp = head;
        cout << "Doubly Linked List: ";
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL";
    }
};
int main() {
    DoublyLinkedList dll;
        dll.insert('a');
        dll.insert('b');
        dll.insert('a');
    dll.display();
    if (dll.Palindrome()==1)
        cout << "The list is a palindrome";
    else
        cout << "The list is NOT a palindrome";

    return 0;
}
