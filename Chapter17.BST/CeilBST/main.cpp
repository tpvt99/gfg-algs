#include <iostream>

int MAX_HEIGHT = 10000;

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

int ceilBST(Node *root, int key);

int main() {
    Node *node1 = new Node(10);
    Node *node2 = new Node(20);
    Node *node3 = new Node(5);
    Node *node4 = new Node(15);
    Node *node5 = new Node(25);
    Node *node6 = new Node(7);
    Node *node7 = new Node(17);


    node1->right=node2;
    node1->left=node3;
    node2->left=node4;
    node2->right = node5;
    node3->right = node6;
    node4->right = node7;

    std::cout << ceilBST(node1, 50);
    return 0;
}


int ceilBST(Node *root, int key) {
    int max_height = -1;
    while(root != nullptr) {
        if (root->key == key) {
            return max_height;
        }
        else if (root->key < key) {
            root = root->right;
        } else {
            max_height = root->key;
            root = root->left;
        }
    }
    return max_height;
}