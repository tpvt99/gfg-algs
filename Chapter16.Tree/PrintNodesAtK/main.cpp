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

void printNodesAtK(Node *root, int k);

int main() {
    Node *node1 = new Node(10);
    Node *node2= new Node(20);
    Node *node3= new Node(30);
    Node *node4= new Node(40);
    Node *node5= new Node(50);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->right = new Node(70);

    printNodesAtK(node1, 2);

    return 0;
}

void printNodesAtK(Node *root, int k) {
    if (root != nullptr && k==0) {
        std::cout << root->key << " ";
        return;
    }
    if (root != nullptr) {
        printNodesAtK(root->left, k-1);
        printNodesAtK(root->right, k-1);
    }
}