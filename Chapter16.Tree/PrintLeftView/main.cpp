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

int printLeftView(Node *node, int ,int maxPrint);
void printLeftViewIterative(Node *node);

int main() {
    Node *node1 = new Node(10);
    Node *node2 = new Node(20);
    Node *node3 = new Node(30);
    Node *node4 = new Node(40);
    Node *node5 = new Node(50);
    Node *node6 = new Node(60);
    Node *node7 = new Node(70);
    node1->right = node2;
    node1->left = node5;
    node2->left = node3;
    node2->right = node6;
    node3->right = node4;
    node6->left = node7;

    printLeftView(node1, 0, -1);
    std::cout << std::endl;
    printLeftViewIterative(node1);

    return 0;
}

int printLeftView(Node *node, int level, int maxPrint) {
    if (node == nullptr) {
        return maxPrint;
    }
    if (level > maxPrint) {
        std::cout << node->key << " ";
        maxPrint++;
    }
    int maxLeft = printLeftView(node->left, level+1, maxPrint);
    int maxRight = printLeftView(node->right, level+1, maxLeft);
    return std::max(maxLeft, maxRight);
}

void printLeftViewIterative(Node *node) {
    std::queue<Node *> q;
    if (node == nullptr)
        return;
    q.push(nullptr);
    q.push(node);
    while (q.size() > 1) {
        if (q.front() == nullptr) {
            q.pop();
            q.push(nullptr);
            Node *t = q.front();
            q.pop();
            if (t != nullptr) {
                std::cout << t->key << " ";
                if (t->left != nullptr)
                    q.push(t->left);
                if (t->right != nullptr)
                    q.push(t->right);
            }
        } else {
            Node *t = q.front();
            q.pop();
            if (t->left != nullptr)
                q.push(t->left);
            if (t->right != nullptr)
                q.push(t->right);
        }
    }
}

