#include <iostream>

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

Node *first, *middle, *last, *current;

void inorderTraversal(Node *root);
void inorderTraversalForSwapNode(Node *root);
void swapNode(Node *root);

int main() {
    Node *node1 = new Node(61);
    Node *node2 = new Node(93);
    Node *node3 = new Node(9);
    Node *node4 = new Node(87);
    Node *node5 = new Node(9);
    Node *node6 = new Node(20);
    Node *node7 = new Node(100);
    node1->left = node2;
    node1->right = node3;
    node3->left = node4;
    //node2->left = node3;
    //node2->right = node4;
    //node5->left = node6;
    //node5->right = node7;
    std::cout << "Before swap" << std::endl;
    inorderTraversal(node1);
    std::cout << std::endl;
    swapNode(node1);
    std::cout << "Afater swap" << std::endl;
    inorderTraversal(node1);
    std::cout << std::endl;
    return 0;
}

void inorderTraversal(Node *root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    std::cout << root->key << " ";
    inorderTraversal(root->right);
}

void inorderTraversalForSwapNode(Node *root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversalForSwapNode(root->left);
    if (current == nullptr) {
        current = root;
    }
    else if (root->key > current->key) {
        current = root;
    }
    else if (root->key < current->key) {
        if (first == nullptr) {
            first = current;
            middle = root;
            current = root;
        } else {
            last = root;
        }
    }
    inorderTraversalForSwapNode(root->right);

}

void swapNode(Node *root) {
    inorderTraversalForSwapNode(root);
    if (first != nullptr) {
        std::cout << "First is: " << first->key << std::endl;
    }
    if (middle != nullptr) {
        std::cout << "Middle is: " << middle->key << std::endl;
    }
    if (last != nullptr) {
        std::cout << "Last is: " << last->key << std::endl;
    }
    if (last == nullptr) {
         int temp = first->key;
         first->key = middle->key;
         middle->key = temp;
    } else {
        int temp = first->key;
        first->key = last->key;
        last->key = temp;
    }
}