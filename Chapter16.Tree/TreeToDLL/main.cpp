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

Node *shortVersion2(Node *root, Node *prev);
Node *shortVersion(Node *root);
Node *prev = nullptr;

void printDLL(Node *head);

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
    //node2->left = node4;
    //node3->left = node5;
    //node3->right = node6;
    //node4->right = node7;

    Node *head = shortVersion(node1);
    printDLL(head);

    return 0;
}

void printDLL(Node *head) {
    while (head->right != nullptr) {
        std::cout << head->key << " ";
        head = head->right;
    }
    std::cout << head->key;
    std::cout << "\n";
    Node *tail = head;
    while (tail->left != nullptr) {
        std::cout << tail->key << " ";
        tail = tail->left;
    }
    std::cout << tail->key;

}


Node *shortVersion(Node *root) {
    if (root == nullptr)
        return root;

    Node *head = shortVersion(root->left);
    if (prev == nullptr) {
        head = root;
    } else {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    shortVersion(root->right);
    return head;
}