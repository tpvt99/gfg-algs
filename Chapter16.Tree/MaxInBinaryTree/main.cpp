#include <iostream>
#include <limits>

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

int maxInBinaryTree(Node *root);

int main() {
    Node *node1 = new Node(10);
    Node *node2 = new Node(2999);
    Node *node3 = new Node(300);
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

    int result = maxInBinaryTree(node1);

    if (result == std::numeric_limits<int>::min()) {
        std::cout << -std::numeric_limits<float>::infinity() << std::endl;
    } else {
        std::cout << result;
    }
    return 0;
}

int maxInBinaryTree(Node *root) {
    if (root == nullptr) {
        return std::numeric_limits<int>::min();
    }
    int maxLeft = maxInBinaryTree(root->left);
    int maxRight = maxInBinaryTree(root->right);
    return std::max(root->key, std::max(maxLeft, maxRight));
}


