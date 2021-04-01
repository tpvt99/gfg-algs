#include <iostream>
#include <unordered_set>

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

std::unordered_set<int> m;
bool isPairWithSum(Node *root, int sum);

int main() {
    Node *node1 = new Node(10);
    Node *node2 = new Node(8);
    Node *node3 = new Node(20);
    Node *node4 = new Node(4);
    Node *node5 = new Node(9);
    Node *node6 = new Node(11);
    Node *node7 = new Node(30);
    Node *node8 = new Node(25);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;
    node7->left = node8;

    std::cout << isPairWithSum(node1, 19);
    return 0;
}

bool isPairWithSum(Node *root, int sum) {
    if (root == nullptr)
        return false;
    bool l = isPairWithSum(root->left, sum);
    if (l)
        return l;
    if (m.empty()) {
        m.insert(root->key);
    } else {
        if (m.find(sum - root->key) != m.end()) {
            return true;
        } else {
            m.insert(root->key);
        }
    }
    return isPairWithSum(root->right, sum);
}
