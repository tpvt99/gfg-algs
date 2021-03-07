#include <iostream>

class Node {
public:
    int key{};
    Node *left;
    Node *right;
public:
    Node(int x) {
        key = x;
        left = nullptr;
        right = nullptr;
    }
};

void recursiveInsert(Node **root, int key);
void iterativeInsert(Node **root, int key);
void inOrderTraversal(Node *root);

int main() {
    Node *node1 = new Node(10);
    Node *node2 = new Node(20);
    Node *node3 = new Node(5);
    Node *node4 = new Node(15);
    Node *node5 = new Node(18);


    node1->right=node2;
    node1->left=node3;
    node2->left=node4;
    node4->right = node5;

    Node *node7 = nullptr;

    iterativeInsert(&node1, 13);
    inOrderTraversal(node1);

    return 0;
}

void recursiveInsert(Node **root, int key) {
    if (*root == nullptr) {
        Node *node = new Node(key);
        *root = node;
        return;
    }
    if ((*root)->key == key)
        return;
    else if ((*root)->key > key) {
        recursiveInsert(&((*root)->left), key);
    } else {
        recursiveInsert(&((*root)->right), key);
    }
}

void iterativeInsert(Node **root, int key) {
    while(*root != nullptr) {
        if ((*root)->key == key)
            return;
        else if ((*root)->key > key)
            root = &((*root)->left);
        else
            root = &((*root)->right);
    }
    *root = new Node(key);
}

void inOrderTraversal(Node *root) {
    if (root == nullptr)
        return;
    std::cout << root->key << " ";
    inOrderTraversal(root->left);
    inOrderTraversal(root->right);
}
