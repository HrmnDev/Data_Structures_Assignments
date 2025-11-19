#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

// Inorder traversal: ensure sequence is strictly increasing.
// `prev` holds the previous visited value, `hasPrev` signals whether prev is valid.
bool isBSTUtil(Node* root, int &prev, bool &hasPrev) {
    if (root == nullptr) return true;

    // left
    if (!isBSTUtil(root->left, prev, hasPrev)) return false;

    // visit current
    if (hasPrev) {
        if (root->val <= prev) return false; // must be strictly greater
    }
    prev = root->val;
    hasPrev = true;

    // right
    return isBSTUtil(root->right, prev, hasPrev);
}

bool isBST(Node* root) {
    int prev = 0;
    bool hasPrev = false;
    return isBSTUtil(root, prev, hasPrev);
}

// Helper to create example trees
Node* sampleBST() {
    //     8
    //    / \
    //   3  10
    //    \   \
    //     6  14
    Node* r = new Node(8);
    r->left = new Node(3);
    r->right = new Node(10);
    r->left->right = new Node(6);
    r->right->right = new Node(14);
    return r;
}

Node* sampleNonBST() {
    //    8
    //   / \
    //  3  10
    //     /
    //    5   <-- 5 in right subtree of 8 violates BST
    Node* r = new Node(8);
    r->left = new Node(3);
    r->right = new Node(10);
    r->right->left = new Node(5);
    return r;
}

int main() {
    Node* t1 = sampleBST();
    cout << "t1 is " << (isBST(t1) ? "a BST\n" : "NOT a BST\n");

    Node* t2 = sampleNonBST();
    cout << "t2 is " << (isBST(t2) ? "a BST\n" : "NOT a BST\n");

    // Note: memory freeing omitted for brevity
    return 0;
}
