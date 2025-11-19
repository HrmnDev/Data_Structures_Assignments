#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

// -------------------- FUNCTIONS --------------------

// Insert at beginning
void insertAtBeginning(Node** head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = *head;
    if (*head != nullptr)
        (*head)->prev = newNode;
    *head = newNode;
}

// Insert at end
void insertAtEnd(Node** head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    if (*head == nullptr) {
        newNode->prev = nullptr;
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// Insert after a node
void insertAfterNode(Node* prevNode, int data) {
    if (prevNode == nullptr) {
        cout << "Previous node cannot be NULL\n";
        return;
    }
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = prevNode->next;
    newNode->prev = prevNode;
    if (prevNode->next != nullptr)
        prevNode->next->prev = newNode;
    prevNode->next = newNode;
}

// Insert before a node
void insertBeforeNode(Node** head, Node* nextNode, int data) {
    if (nextNode == nullptr) {
        cout << "Next node cannot be NULL\n";
        return;
    }
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nextNode;
    newNode->prev = nextNode->prev;
    if (nextNode->prev != nullptr)
        nextNode->prev->next = newNode;
    else
        *head = newNode;
    nextNode->prev = newNode;
}

// Delete a node
void deleteNode(Node** head, int key) {
    if (*head == nullptr) {
        cout << "List is empty\n";
        return;
    }
    Node* temp = *head;
    while (temp != nullptr && temp->data != key)
        temp = temp->next;
    if (temp == nullptr) {
        cout << "Node not found\n";
        return;
    }
    if (temp == *head)
        *head = temp->next;
    if (temp->next != nullptr)
        temp->next->prev = temp->prev;
    if (temp->prev != nullptr)
        temp->prev->next = temp->next;
    delete temp;
    cout << "Node " << key << " deleted\n";
}

// Search a node
int searchNode(Node* head, int key) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == key)
            return 1; // found
        temp = temp->next;
    }
    return 0; // not found
}

// Display list
void display(Node* head) {
    Node* temp = head;
    if (temp == nullptr) {
        cout << "List is empty\n";
        return;
    }
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = nullptr;
    int choice, data, key;
    Node* temp;
    int flag;

    while (1) {
        cout << "\nMenu:\n";
        cout << "1. Insert at beginning\n2. Insert at end\n3. Insert after a node\n4. Insert before a node\n";
        cout << "5. Delete a node\n6. Search a node\n7. Display list\n8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter data to insert: ";
            cin >> data;
            insertAtBeginning(&head, data);
        }
        else if (choice == 2) {
            cout << "Enter data to insert: ";
            cin >> data;
            insertAtEnd(&head, data);
        }
        else if (choice == 3) {
            if (head == nullptr) { cout << "List is empty\n"; continue; }
            cout << "Enter node value after which to insert: ";
            cin >> key;
            cout << "Enter data to insert: ";
            cin >> data;
            temp = head; flag = 0;
            while (temp != nullptr) {
                if (temp->data == key) { flag = 1; break; }
                temp = temp->next;
            }
            if (flag == 1) insertAfterNode(temp, data);
            else cout << "Node not found\n";
        }
        else if (choice == 4) {
            if (head == nullptr) { cout << "List is empty\n"; continue; }
            cout << "Enter node value before which to insert: ";
            cin >> key;
            cout << "Enter data to insert: ";
            cin >> data;
            temp = head; flag = 0;
            while (temp != nullptr) {
                if (temp->data == key) { flag = 1; break; }
                temp = temp->next;
            }
            if (flag == 1) insertBeforeNode(&head, temp, data);
            else cout << "Node not found\n";
        }
        else if (choice == 5) {
            cout << "Enter node value to delete: ";
            cin >> key;
            deleteNode(&head, key);
        }
        else if (choice == 6) {
            cout << "Enter node value to search: ";
            cin >> key;
            flag = searchNode(head, key);
            if (flag == 1) cout << "Node found\n";
            else cout << "Node not found\n";
        }
        else if (choice == 7) display(head);
        else if (choice == 8) break;
        else cout << "Invalid choice\n";
    }

    return 0;
}
