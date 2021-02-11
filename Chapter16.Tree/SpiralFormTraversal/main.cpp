#include <iostream>
#include <deque>

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

void traversalSpiral(Node *root);

int main() {
    Node *node1 = new Node(10);
    Node *node2 = new Node(20);
    Node *node3 = new Node(30);
    Node *node4 = new Node(40);
    Node *node5 = new Node(50);
    Node *node7 = new Node(70);
    Node *node8 = new Node(80);
    Node *node9 = new Node(90);
    Node *node6 = new Node(60);

    node1->left = node2;
    node1->right=node3;
    node2->left=node4;
    node2->right=node5;
    node3->left=node6;
    node3->right=node7;
    node4->left=node8;
    node4->right=node9;
    traversalSpiral(node1);
    return 0;
}

void traversalSpiral(Node *root) {
    if (root== nullptr)
        return;
    std::deque<Node *> s;

    s.push_front(root);
    s.push_back(nullptr);

    int iter = 0;
    while(s.size()>1) {
        Node *top;
        if (iter%2==0) { // popfront, pushback from left->right
            top = s.front();
            s.pop_front();
        } else {
            top = s.back();
            s.pop_back();
        }
        if (top == nullptr) {
            if (iter%2==0)
                s.push_front(top);
            else
                s.push_back(top);
            iter++;
            continue;
        }
        std::cout << top->key << " ";
        if (iter%2==0) { // pushback left->right
            if (top->left!= nullptr)
                s.push_back(top->left);
            if(top->right!= nullptr)
                s.push_back(top->right);
        } else { //pushfront right->left
            if (top->right!= nullptr)
                s.push_front(top->right);
            if(top->left!= nullptr)
                s.push_front(top->left);
        }

    }
}
