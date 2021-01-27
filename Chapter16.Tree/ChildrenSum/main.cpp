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

bool isChildrenSum(Node *root);

int main() {
    Node *node1 = new Node(20);
    Node *node2 = new Node(12);
    Node *node3 = new Node(8);
    Node *node4 = new Node(3);
    Node *node5 = new Node(50);
    Node *node6 = new Node(60);
    Node *node7 = new Node(3);
    node1->right = node2;
    node1->left = node3;
    node3->left = node4;
    node3->right = node7;


    std::cout << isChildrenSum(node1) << std::endl;
    return 0;
}

bool isChildrenSum(Node *root) {
    if (root == nullptr)
        return true;

    if (root->left == nullptr && root->right == nullptr) {
        return true;
    }
    if (root->left != nullptr && root->right != nullptr) {
        int val = root->left->key + root->right->key;
        if (val == root->key) {
            return isChildrenSum(root->left) & isChildrenSum(root->right);
        } else
            return false;
    }
    if (root->left != nullptr) {
        if (root->key == root->left->key)
            return isChildrenSum(root->left);
        return false;
    }

    if (root->right != nullptr) {
        if (root->key == root->right->key)
            return isChildrenSum(root->right);
        return false;
    }
}