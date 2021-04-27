#include <iostream>
#include <map>
#include <vector>
#include <queue>

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

std::map<int, std::vector<int>> verticalTraversal(Node *root);

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
    std::map<int, std::vector<int>> results = verticalTraversal(node1);

    for (auto it = results.begin(); it != results.end(); it++) {
        std::vector<int> m = it->second;
        for (auto xxx : m) {
            std::cout << xxx << " ";
        }
        std::cout << "\n";
    }
    return 0;
}

std::map<int, std::vector<int>> verticalTraversal(Node *root) {
    std::queue<std::pair<int, Node *>> q;
    std::map<int, std::vector<int>> results;

    q.push({0, root});

    while (q.size() != 0) {
        std::pair<int, Node*> m = q.front();
        q.pop();
        results[m.first].push_back((m.second)->key);

        if ((m.second)->left != nullptr)
            q.push({m.first-1, (m.second)->left});
        if ((m.second)->right != nullptr)
            q.push({m.first+1, (m.second)->right});
    }
    return results;
}

