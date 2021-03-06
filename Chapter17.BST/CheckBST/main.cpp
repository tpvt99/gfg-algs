#include <iostream>
#define MAXX 100000;

struct Node {
    int key;
    struct Node *left;
    struct Node *right;
    Node (int x) {
        key = x;
        left = nullptr;
        right = nullptr;
    }
};

bool checkBSTHelper(Node *node, int max, int min);
bool checkBSTMethod2(Node *node);

int main() {
    Node *root = new Node(20);
    std::cout << checkBSTHelper(root, 10000, -10000) << std::endl;
    std::cout << checkBSTMethod2(root) << std::endl;

    Node *node8 = new Node(8);
    root->left =node8;
    Node *node30 = new Node(30);
    Node *node18 = new Node(18);
    Node *node35 = new Node(35);

    root->right = node30;
    node30->left = node18;
    node30->right = node35;

    std::cout << checkBSTHelper(root, 10000, -10000)<< std::endl;;
    std::cout << checkBSTMethod2(root) << std::endl;

    return 0;
}

bool checkBSTHelper(Node *node, int max, int min) {
    if (node == nullptr)
        return true;
    if (min <= node->key && node->key <= max) {
        bool isLeft = checkBSTHelper(node->left, node->key, min);
        bool isRight = checkBSTHelper(node->right, max, node->key);
        return isLeft & isRight;
    }
    return false;
}

int prev = INT32_MIN;

bool checkBSTMethod2(Node *node) {
    if (node == nullptr)
        return true;
    bool left = checkBSTMethod2(node->left);
    if (node->key > prev) {
        prev = node->key;
    } else {
        return false;
    }
    return left && checkBSTMethod2(node->right);
}
