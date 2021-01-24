#include <iostream>
#include <queue>

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

void levelOrderLineByLine(Node *root);



int main() {
    Node *node1 = new Node(10);
    Node *node2 = new Node(20);
    Node *node3 = new Node(30);
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

    levelOrderLineByLine(node1);

    return 0;
}

void levelOrderLineByLine(Node *root) {
    std::queue<Node *> q;
    if (root != nullptr) {
        q.push(root);
        q.push(nullptr);
    }
    while (q.size() > 1) {
        Node *top = q.front();
        q.pop();
        if (top == nullptr) {
            std::cout << std::endl;
            q.push(nullptr);
            continue;
        }
        std::cout << top->key << " ";
        if (top->left != nullptr)
            q.push(top->left);
        if (top->right != nullptr)
            q.push(top->right);

    }
}
