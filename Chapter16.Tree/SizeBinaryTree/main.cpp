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

int sizeOfTree(Node *root);

int main() {
    Node *node1 = new Node(10);
    Node *node2 = new Node(20);
    Node *node3 = new Node(30);
    Node *node4 = new Node(8);
    Node *node5 = new Node(7);
    Node *node6 = new Node(9);
    Node *node7 = new Node(15);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node5->left = node6;
    node5->right = node7;
    node3->right = new Node(6);

    std::cout << sizeOfTree(node1);
    return 0;
}

int sizeOfTree(Node *root) {
    if (root == nullptr)
        return 0;
    return 1 + sizeOfTree(root->left) + sizeOfTree(root->right);
}