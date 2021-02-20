#include <iostream>
#include <vector>
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

bool findPath(Node *root, std::vector<Node *> &vec, Node *destination);
int burnTree(Node *root, Node *destination);

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

//  output: 3 if chosen node5
//    node1->left = node2;
//    node2->left=node3;
//    node3->left=node4;
//    node3->right=node5;

// Output: 4 if chosen node5
//    node1->left=node2;
//    node1->right=node3;
//    node2->left=node4;
//    node2->right=node5;
//    node3->right=node6;

    node1->left=node2;
    node2->left=node3;
    node3->left=node4;
    node3->right=node5;
    node4->left=node6;
    node6->left=node7;

    int s = burnTree(node1, node7);
    std::cout << s << std::endl;

    return 0;
}

bool findPath(Node *root, std::vector<Node *> &vec, Node *destination) {
    if (root == nullptr)
        return false;
    vec.push_back(root);
    if (root->key == destination->key)
        return true;
    bool onLeft = findPath(root->left, vec, destination);
    bool onRight = findPath(root->right, vec, destination);
    if (!onLeft && !onRight) {
        vec.pop_back();
        return false;
    }
    return true;
}

int burnTree(Node *root, Node *destination) {
    std::vector<Node *> vec;
    bool x = findPath(root, vec, destination);
    if (!x) {
        return -1;
    }
    if (vec.size() == 1)
        return 0;
    Node *prevInVec = vec.back();
    vec.pop_back();
    Node *nodeInVec = vec.back();
    vec.pop_back();

    std::queue<Node *> q;
    q.push(nodeInVec);
    q.push(nullptr);
    int size = 1;
    while (q.size() > 1 || vec.size() > 0) {
        Node *node = q.front();
        q.pop();
        if (node == nullptr) {
            size++;
            if (vec.size() > 0) {
                prevInVec = nodeInVec;
                nodeInVec = vec.back();
                vec.pop_back();
                q.push(nodeInVec);
            }
            q.push(nullptr);
            continue;
        }
        if (node->left != nullptr && node->left != prevInVec)
            q.push(node->left);
        if (node->right != nullptr && node->right != prevInVec)
            q.push(node->right);
    }
    return size;

}