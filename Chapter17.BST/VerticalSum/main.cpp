#include <iostream>
#include <vector>

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

void verticalSum(Node *root, int index, std::vector<int> &results);

int main() {
    Node *node1 = new Node(10);
    Node *node2 = new Node(15);
    Node *node3 = new Node(25);
    Node *node4 = new Node(35);
    Node *node5 = new Node(20);
    Node *node6 = new Node(40);
    Node *node7 = new Node(75);
    Node *node8 = new Node(80);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node4->left = node6;
    node5->right = node7;
    node7->right = node8;
    std::vector<int> results;
    verticalSum(node1, 0, results);

    for (auto i : results) {
        std::cout << i << " ";
    }

    return 0;
}

int minIndex = INT16_MIN;

void verticalSum(Node *root, int index, std::vector<int> &results) {
    if (root == nullptr) {
        if (minIndex == INT16_MIN)
            minIndex = index+1;
        return;
    }
    verticalSum(root->left, index-1, results);
    int trueIndex = index -minIndex;
    if (trueIndex == results.size()) {
        results.push_back(root->key);
    } else {
        results[trueIndex] += root->key;
    }

    verticalSum(root->right, index+1, results);

}
