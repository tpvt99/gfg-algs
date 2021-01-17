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

int heightOfTree(Node *root, int currentHeight);

int main() {
    Node *node1 = new Node(10);
    Node *node2= new Node(20);
    Node *node3= new Node(30);
    Node *node4= new Node(40);
    Node *node5= new Node(50);
    node1->left = node2;
    node2->left = node3;
    node3->left = node4;
    node1->right = node5;

    std::cout << heightOfTree(node1, 0);

    return 0;
}

int heightOfTree(Node *root, int currentHeight) {
    if (root != nullptr) {
        int leftHeight = heightOfTree(root->left, currentHeight+1);
        int rightHeight = heightOfTree(root->right, currentHeight+1);
        return std::max(leftHeight, rightHeight);
    }
    return currentHeight;
}