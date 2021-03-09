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

Node *deleteBST(Node *root, int x);
Node * inorderSuccessor(Node *root);
void inOrderTraversal(Node *root);

int main() {
    Node *node1 = new Node(10);
    Node *node2 = new Node(20);
    Node *node3 = new Node(5);
    Node *node4 = new Node(15);
    Node *node5 = new Node(25);
    Node *node6 = new Node(7);
    Node *node7 = new Node(17);


    node1->right=node2;
    node1->left=node3;
    node2->left=node4;
    node2->right = node5;
    node3->left = node6;
    node4->right = node7;


    Node *root = deleteBST(node1, 20);
    inOrderTraversal(root);
    return 0;
}

void inOrderTraversal(Node *root) {
    if (root == nullptr)
        return;
    std::cout << root->key << " ";
    inOrderTraversal(root->left);
    inOrderTraversal(root->right);
}

Node * inorderSuccessor(Node *root) {
    if (root == nullptr)
        return nullptr;

    if (root->left == nullptr)
        return root;
    return inorderSuccessor(root->left);
}

Node *deleteBST(Node *root, int x) {
    if (root == nullptr)
        return nullptr;
    if (root->key == x) {
        // If x is a leaf node
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        // If x has 1 node
        else if (root->left != nullptr && root->right == nullptr) {
            root->key = root->left->key;
            delete root->left;
            root->left = nullptr;
            return root;
        }
        else if (root->right != nullptr && root->left == nullptr) {
            root->key = root->right->key;
            delete root->right;
            root->right = nullptr;
            return root;
        }
        // If x has 2 nodes
        else {
            Node *inorderSucc = inorderSuccessor(root->right);
            if (inorderSucc == nullptr) {
                delete root;
                return nullptr;
            }
            root->key = inorderSucc->key;
            //Check to delete inorderSucc
            // If inorderSucc is a leaf node, we need to find its parent, then delete
            if (inorderSucc->left == nullptr && inorderSucc->right == nullptr) {
                if (root->right == inorderSucc) { // the immediate descendant is inorder successor
                    delete root->right;
                    root->right = nullptr;
                } else {
                    Node *temp = root->right;
                    while (temp->left != inorderSucc)
                        temp = temp->left;
                    delete inorderSucc;
                    temp->left = nullptr;
                }
            }
            // If inorderSucc has 1 node
            else if (inorderSucc->left != nullptr && inorderSucc->right == nullptr) {
                inorderSucc->key = inorderSucc->left->key;
                delete inorderSucc->left;
                inorderSucc->left = nullptr;
            }
            else if (inorderSucc->right != nullptr && inorderSucc->left == nullptr) {
                inorderSucc->key = inorderSucc->right->key;
                delete inorderSucc->right;
                inorderSucc->right = nullptr;
            }
        }
    }
    else if (root->key > x) {
        root->left = deleteBST(root->left, x);
    } else
        root->right = deleteBST(root->right, x);
    return root;
}