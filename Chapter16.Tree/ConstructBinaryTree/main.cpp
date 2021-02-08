#include <iostream>
#include <unordered_map>

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

Node *constructBinaryTree(int *in, int *pre, int inBegin, int inEnd, int prevLength, std::unordered_map<int, int> &m);
void inOrderTraversal(Node *root);
void preOrderTraversal(Node *root);

int main() {
    Node *node1 = new Node(10);
    Node *node2 = new Node(20);
    Node *node3 = new Node(30);
    Node *node4 = new Node(40);
    Node *node5 = new Node(50);
    Node *node7 = new Node(70);
    Node *node8 = new Node(80);
    Node *node9 = new Node(90);


    std::unordered_map<int, int> m;
    m.insert({10, 0});
    m.insert({20, 1});
    m.insert({30, 4});
    m.insert({40, 2});
    m.insert({50, 3});
    m.insert({70, 5});
    m.insert({80, 6});
    m.insert({90, 7});


    int *in {new int[8]};
    int *pre {new int [8]};
    pre[0]=10;
    pre[1]=20;
    pre[2]=40;
    pre[3]=50;
    pre[4]=30;
    pre[5]=70;
    pre[6]=80;
    pre[7]=90;

    in[0]=40;
    in[1]=20;
    in[2]=50;
    in[3]=10;
    in[4]=30;
    in[5]=80;
    in[6]=70;
    in[7]=90;
    Node *root = constructBinaryTree(in, pre, 0, 7, 8, m);

    inOrderTraversal(root);
    std::cout << std::endl;
    preOrderTraversal(root);
    std::cout << std::endl;

    return 0;
}

Node *constructBinaryTree(int *in, int *pre, int inBegin, int inEnd, int prevLength, std::unordered_map<int, int> &m) {
    if (inBegin > inEnd) // No inorder array so return nullptr
        return nullptr;

    int rootIndexInPre = prevLength;
    int rootIndexInIn = prevLength;
    for (int i = inBegin; i <= inEnd; i++) {
        int index = m.find(in[i])->second;
        if ( index< rootIndexInPre) {
            rootIndexInPre =index;
            rootIndexInIn = i;
        }
    }

    Node * root = new Node(pre[rootIndexInPre]);

    Node *leftNode = constructBinaryTree(in, pre, inBegin, rootIndexInIn-1, prevLength, m);
    Node *rightNode = constructBinaryTree(in, pre, rootIndexInIn+1, inEnd, prevLength, m);

    root->left = leftNode;
    root->right = rightNode;
    return root;
}

void inOrderTraversal(Node *root) {
    if (root != nullptr) {
        inOrderTraversal(root->left);
        std::cout << root->key << " ";
        inOrderTraversal(root->right);
    }
}

void preOrderTraversal(Node *root) {
    if (root != nullptr) {
        std::cout << root->key << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}