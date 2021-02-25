#include <iostream>
#include <stack>

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

void iterativeInorderTraversal(Node *root);

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
//node4->right=node7;

    iterativeInorderTraversal(node1);
    return 0;
}

void iterativeInorderTraversal(Node *root) {
    if (root == nullptr)
        return;
    std::stack<Node *> s;
    s.push(root);
    Node *curr = root;

    while (!s.empty()) {
        while (curr->left != nullptr) {
            curr = curr->left;
            s.push(curr);
        }
        curr = s.top();
        s.pop();
        std::cout << curr->key << " ";
        if (curr->right != nullptr) {
            curr = curr->right;
            s.push(curr);
        }

    }
}