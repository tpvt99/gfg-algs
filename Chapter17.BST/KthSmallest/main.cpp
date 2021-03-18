#include <iostream>

struct Node {
    int key;
    struct Node *left;
    struct Node *right;
    int leftCounts;
    Node (int x) {
        key = x;
        left = nullptr;
        right = nullptr;
        leftCounts=0;
    }
};

Node *insert(Node *root, int key);
void inorderTraversal(Node *root);
void kthSmallest(Node *root, int k);

int main() {
    Node *root = nullptr;
    root = insert(root, 50);
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 100);
    root = insert(root, 70);
    root = insert(root, 120);
    root = insert(root, 60);
    root = insert(root, 80);
    //inorderTraversal(root);
    kthSmallest(root, 9);
    return 0;
}

Node *insert(Node *root, int key) {
    if (root == nullptr)
        return new Node(key);
    if (root->key == key)
        return root;
    else if (root->key > key) {
        root->left = insert(root->left, key);
        root->leftCounts += 1;
    } else {
        root->right = insert(root->right, key);
    }
    return root;
}

void kthSmallest(Node *root, int k) {
    if (root->leftCounts + 1 == k) {
        std::cout << root->key;
        return;
    } else if (root->leftCounts + 1 > k) {
        kthSmallest(root->left, k);
    } else {
        kthSmallest(root->right, k-1-root->leftCounts);
    }
}

void inorderTraversal(Node *root) {
    if (root == nullptr)
        return;
    inorderTraversal(root->left);
    std::cout << root->key << " with counts: " << root->leftCounts << "\n";
    inorderTraversal(root->right);
}