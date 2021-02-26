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
void iterativeMethod2(Node *root);

int main() {
    Node *node1 = new Node(2);
    Node *node2 = new Node(2);
    Node *node3 = new Node(7);
    Node *node4 = new Node(10);
    Node *node5 = new Node(5);
    Node *node6 = new Node(2);
    Node *node7 = new Node(14);
    Node *node8 = new Node(13);
    Node *node9 = new Node(13);

    node1->left=node2;
    node1->right=node9;
    node2->left=node3;
    node2->right=node4;
    node3->left=node5;
    node3->right = node6;
    node5->left = node8;
    node4->right = node7;

    iterativeInorderTraversal(node1);
    std::cout << "\n";
    iterativeMethod2(node1);
    return 0;
}

void iterativeInorderTraversal(Node *root) {
    if (root == nullptr)
        return;
    std::stack<Node *> s;
    Node *curr = root;

    while (curr != nullptr || !s.empty()) {
        while (curr != nullptr) {
            s.push(curr);
            std::cout << curr->key << " ";
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        curr=curr->right;
    }
}

void iterativeMethod2(Node *root) {
    if (root == nullptr) {
        return;
    }
    std::stack<Node *> s;
    Node *curr = root;
    s.push(root);
    while (!s.empty()) {
        s.pop();
        while (curr != nullptr) {
            if (curr->right != nullptr)
                s.push(curr->right);
            std::cout << curr->key << " ";
            curr = curr->left;
        }
        if (!s.empty())
            curr = s.top();
    }
}
