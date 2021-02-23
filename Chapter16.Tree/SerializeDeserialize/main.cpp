#include <iostream>
#include <vector>
#include <algorithm>

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

void serialize(Node *root, std::vector<int> &arr);
Node *deserialize(std::vector<int> &arr);
void inOrderTraversal(Node *root);
void preOrderTraversal(Node *root);

Node *rootNode{nullptr};

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

    node1->left=node2;
    node1->right=node3;
    node2->left=node4;
    node2->right=node5;
    node3->left=node6;
    node4->right=node7;

    std::vector<int> v;
    serialize(node1, v);
    std::reverse(v.begin(), v.end());
    Node *root = deserialize(v);
    inOrderTraversal(root);
    std::cout << "\n";
    preOrderTraversal(root);

    return 0;
}

void serialize(Node *root, std::vector<int> &arr) {
    if (root == nullptr) {
        arr.push_back(-1);
        return;
    }

    arr.push_back(root->key);

    serialize(root->left, arr);
    serialize(root->right, arr);
}



Node *deserialize(std::vector<int> &arr) {
    if (arr.empty())
        return nullptr;

    if (arr.back() == -1) {
        arr.pop_back();
        return nullptr;
    }

    int m = arr.back();
    arr.pop_back();
    Node * prevNode = new Node(m);

    prevNode->left = deserialize(arr);
    prevNode->right = deserialize(arr);
    return prevNode;
}

void inOrderTraversal(Node *root) {
    if (root != nullptr) {
        inOrderTraversal(root->left);
        std::cout << root->key << " ";
        inOrderTraversal(root->right);
    }
}

void preOrderTraversal(Node *root) {
    if (root != nullptr) {
        std::cout << root->key << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}