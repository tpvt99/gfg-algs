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

int diameter(Node *root);
int maxLength = 0;

int main() {
    Node *node1 = new Node(10);
    Node *node2 = new Node(20);
    Node *node3 = new Node(30);
    Node *node4 = new Node(40);
    Node *node5 = new Node(50);
    Node *node6 = new Node(60);
    Node *node7 = new Node(70);
    Node *node8 = new Node(80);
    Node *node9 = new Node(90);


    node1->left = node2;
    node1->right=node3;
    node3->left=node4;
    node3->right=node5;
    node4->left=node6;
    node4->right=node7;
    diameter(node1);
    std::cout << maxLength << std::endl;
    return 0;
}

int diameter(Node *root) {
    if (root == nullptr)
        return 0;
    int leftLength = diameter(root->left);
    int rightLength = diameter(root->right);
    maxLength = std::max(maxLength, leftLength+rightLength+1);
    return std::max(leftLength, rightLength)+1;
}
