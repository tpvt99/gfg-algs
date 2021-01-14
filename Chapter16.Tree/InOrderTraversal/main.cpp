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

void inOrderTraversal(Node *root);

int main() {
    Node *node1 = new Node(10);
    Node *node2= new Node(20);
    Node *node3= new Node(30);
    Node *node4= new Node(40);
    Node *node5= new Node(50);
    Node *node6= new Node(60);
    Node *node7= new Node(70);
    Node *node8= new Node(80);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node5->left = node7;
    node5->right = node8;
    node3->right = node6;

    inOrderTraversal(node1);

    return 0;
}

void inOrderTraversal(Node *root) {
    if (root != nullptr) {
        inOrderTraversal(root->left);
        std::cout << root->key << " ";
        inOrderTraversal(root->right);
    }
}