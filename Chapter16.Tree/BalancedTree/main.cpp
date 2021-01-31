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

bool isBalancedTree(Node *root);
int heightTree(Node *root);

int main() {
    Node *node1 = new Node(18);
    Node *node2 = new Node(4);
    Node *node3 = new Node(20);
    Node *node4 = new Node(13);
    Node *node5 = new Node(70);
    Node *node6 = new Node(60);
    Node *node7 = new Node(3);
    node1->left = node2;
    node1->right = node3;
    node3->left = node4;
    node3->right = node5;
    node2->left = node6;
    node6->right = node7;

    std::cout << isBalancedTree(node1);
    return 0;
}

int heightTree(Node *root) {
    if (root == nullptr)
        return 0;
    int leftHeight = heightTree(root->left);
    int rightHeight = heightTree(root->right);
    if (leftHeight == -1 || rightHeight == -1)
        return -1;
    if (std::abs(leftHeight-rightHeight) >1)
        return -1;

    return std::max(1+leftHeight, 1+rightHeight);
}

bool isBalancedTree(Node *root) {
    if (heightTree(root) != -1)
        return true;
    return false;
}
