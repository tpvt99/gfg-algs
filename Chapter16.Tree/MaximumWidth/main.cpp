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


int maximumWidth(Node *root);

int main() {
    Node *node1 = new Node(10);
    Node *node2 = new Node(20);
    Node *node3 = new Node(30);
    Node *node4 = new Node(40);
    Node *node5 = new Node(50);
    Node *node6 = new Node(60);
    Node *node7 = new Node(70);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node3->left = node5;
    node3->right = node6;
    node4->right = node7;

    std::cout << maximumWidth(node1);

    return 0;
}

int maximumWidth(Node *root) {
    std::queue<Node *> q;
    if (root == nullptr)
        return 0;
    q.push(root);
    q.push(nullptr);
    int maxWidth = 1;
    int currentWidth = 0;
    while(q.size() > 1) {
        Node *front = q.front();
        q.pop();
        if (front == nullptr) {
            maxWidth = std::max(maxWidth, currentWidth);
            currentWidth = 0;
            q.push(nullptr);
            continue;
        }
        currentWidth += 1;
        if (front->left != nullptr)
            q.push(front->left);
        if (front->right != nullptr)
            q.push(front->right);
    }
    maxWidth = std::max(maxWidth, currentWidth); // Cover the maxWidth if it is at final height
    return maxWidth;
}
