#include <iostream>
using namespace std;
class CircularLinkedList {
private:
    struct Node {
        int data;
        Node* next;
    };
    Node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }
    void insert(int value) {
        Node* newNode = new Node{value, nullptr};

        if (head == nullptr) {
            head = newNode;
            newNode->next = head; // circular link
            return;
        }
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }
    int size() {
        if (head == nullptr)
            return 0;

        int count = 0;
        Node* temp = head;
        do {
            count++;
            temp = temp->next;
        } while (temp != head);

        return count;
    }
    void display() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << head->data << endl;
    }
};
int main() {
    CircularLinkedList cll;
    cll.insert(10);
    cll.insert(20);
    cll.insert(30);
    cll.insert(40);
    cll.display();
    cout << "Size of Circular Linked List ="<<cll.size();
}
