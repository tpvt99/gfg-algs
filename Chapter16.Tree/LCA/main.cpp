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

bool lcaHelper(Node *root, Node *node1, Node *node2, Node **ancestor);
Node *lca(Node *root, Node *node1, Node *node2);



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
    node5->right=node8;
    node5->left = node7;
    Node *ancestor = lca(node1, node7, node2);
    if (ancestor!= nullptr)
        std::cout << ancestor->key << std::endl;
    return 0;
}

Node *lca(Node *root, Node *node1, Node *node2) {
    Node *ancestor {nullptr};
    bool hasLCA = lcaHelper(root, node1, node2, &ancestor);
    if (!hasLCA)
        return nullptr;
    return ancestor;
}

bool lcaHelper(Node *root, Node *node1, Node *node2, Node **ancestor) {
    if (root == nullptr)
        return false;
    bool isOnLeft = lcaHelper(root->left, node1, node2, ancestor);
    bool isOnRight = lcaHelper(root->right, node1, node2, ancestor);
    if (isOnLeft && isOnRight) {
        *ancestor = root;
        return true;
    }
    if (isOnRight || isOnLeft) {
        if (root->key == node1->key || root->key == node2->key) {
            *ancestor = root;
            return true;
        }
        return true;
    }
    if (root->key == node1->key || root->key == node2->key) {
        *ancestor = root; // This line is to make the node itself is ancestor if the other node does not exists
        return true;
    }
    return false;
}

