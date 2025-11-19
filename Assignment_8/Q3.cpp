#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

// insertionn 
Node* insert(Node* root, int val) {
    if (root == NULL)
        return new Node(val);
//check for duplicatess
    if (val == root->data) {
        cout << "Duplicate value " << val<<endl;
        return root;
    }
    else if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// deletion
Node* findMin(Node* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
    	//no child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
     //ek child
        else if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } 
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        //two child
        else {
            Node* temp = findMin(root->right);
            root->data = temp->data; // Copy successor's data
            root->right = deleteNode(root->right, temp->data); // Delete successor
        }
    }
    return root;
}

// max depth
int maxDepth(Node* root) {
    if (root == NULL)
        return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

// min depth
int minDepth(Node* root) {
    if (root == NULL)
        return 0;
    if (!root->left && !root->right)
        return 1;
    if (!root->left)
        return 1 + minDepth(root->right);
    if (!root->right)
        return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left), minDepth(root->right));
}


void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;

    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++)
        root = insert(root, arr[i]);

    cout << "Inorder traversal of BST: ";
    inorder(root);
    cout << endl;

    // Delete operation
    cout << "\nEnter element to delete: ";
    int key;
    cin >> key;
    root = deleteNode(root, key);

    cout << "Inorder traversal after deletion: ";
    inorder(root);
    cout << endl;

    // Depth calculations
    cout << "\nMaximum Depth of BST: " << maxDepth(root);
    cout << "\nMinimum Depth of BST: " << minDepth(root);
    cout << endl;

    return 0;
}
