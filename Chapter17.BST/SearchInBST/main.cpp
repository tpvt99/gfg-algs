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

bool search(Node *root, int key);

int main() {
    Node *node1 = new Node(10);
    Node *node2 = new Node(20);
    Node *node3 = new Node(5);
    Node *node4 = new Node(15);
    Node *node5 = new Node(18);
    Node *node6 = new Node(12);
    Node *node7 = new Node(40);
    Node *node8 = new Node(50);
    Node *node9 = new Node(35);

    node1->right=node2;
    node1->left=node3;
    node2->left=node4;
    node4->right = node5;
    node4->left = node6;
    node2->right = node7;
    node7->right = node8;
    node7->left = node9;

    if (search(node1, 35))
        std::cout << "Key exists";
    else
        std::cout << "Key does not exist";
    return 0;
}

bool search(Node *root, int key) {
    if (root == nullptr)
        return false;
    if (root->key == key)
        return true;
    else if (root->key > key)
        return search(root->left, key);
    else
        return search(root->right, key);
}