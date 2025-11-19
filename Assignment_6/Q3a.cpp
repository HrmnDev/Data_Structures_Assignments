#include <iostream>
using namespace std;
class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;
    };
    Node* head;
public:
    DoublyLinkedList() {
        head = nullptr;
    }
    void insert(int value) {
        Node* newNode = new Node{value, nullptr, nullptr};
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }
    int size() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }
  void display() {
        Node* temp = head;
        cout << "Doubly Linked List";
        while (temp != nullptr) {
            cout << temp->data << "<-> ";
            temp = temp->next;
}
    }
};
int main() {
    DoublyLinkedList dll;
    dll.insert(10);
    dll.insert(20);
    dll.insert(30);
    dll.display();
    cout << "Size of Doubly Linked List "<<dll.size();

    return 0;
}
