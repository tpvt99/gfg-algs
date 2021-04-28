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

std::map<int, int> verticalTraversal(Node *root);

int main() {
    Node *node1 = new Node(10);
    Node *node2 = new Node(20);
    Node *node3 = new Node(50);
    Node *node4 = new Node(30);
    Node *node5 = new Node(40);
    Node *node6 = new Node(60);
    Node *node7 = new Node(70);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;
    std::map<int, int> results = verticalTraversal(node1);

    for (auto it = results.begin(); it != results.end(); it++) {
        std::cout << it->second << " ";

    }
    return 0;
}

std::map<int, int> verticalTraversal(Node *root) {
    std::queue<std::pair<int, Node *>> q;
    std::map<int, int> results;

    q.push({0, root});

    while (q.size() != 0) {
        std::pair<int, Node*> m = q.front();
        q.pop();
        if (results.find(m.first) == results.end())
            results[m.first] = (m.second)->key;

        if ((m.second)->left != nullptr)
            q.push({m.first-1, (m.second)->left});
        if ((m.second)->right != nullptr)
            q.push({m.first+1, (m.second)->right});
    }
    return results;
}

