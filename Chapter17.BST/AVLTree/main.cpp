#include <iostream>

class Node {
public:
    int key{};
    Node *left;
    Node *right;
    int height;
public:
    Node(int x) {
        key = x;
        left = nullptr;
        right = nullptr;
    }
};

Node *insert(Node *root, int key);
int findHeight(Node *node);
int balanceFactor(Node *node);
void inOrderTraversal(Node *root);
Node *leftRotate(Node *root);
Node *rightRotate(Node *root);

int main() {

    Node *root = nullptr;
    root = insert(root, 10);
    inOrderTraversal(root);
    std::cout << "\n";

    root = insert(root, 20);
    inOrderTraversal(root);
    std::cout << "\n";

    root = insert(root, 30);
    inOrderTraversal(root);
    std::cout << "\n";

    root = insert(root, 40);
    inOrderTraversal(root);
    std::cout << "\n";

    root = insert(root, 50);
    inOrderTraversal(root);
    std::cout << "\n";

    root = insert(root, 25);
    inOrderTraversal(root);
    std::cout << "\n";

    return 0;
}

Node *leftRotate(Node *root) {
    // Get T2 and x
    Node *T2 = root->right->left;
    Node *x = root->right;

    // Rotate
    root->right = T2;
    x->left = root;

    // Update height of x and root
    x->height = 1 + std::max(findHeight(x->left), findHeight(x->right));
    root->height = 1 + std::max(findHeight(root->left), findHeight(root->right));
    return x;
}

Node *rightRotate(Node *root) {
    // Get T2 and x
    Node *T2 = root->left->right;
    Node *y = root->left;

    // Rotate
    y->right = root;
    root->left = T2;

    // Update height of x and root
    y->height = 1 + std::max(findHeight(y->left), findHeight(y->right));
    root->height = 1 + std::max(findHeight(root->left), findHeight(root->right));
    return y;
}

Node *insert(Node *root, int key) {

    // Step 1. Insert key
    if (root == nullptr) {
        return new Node(key);
    }

    if (root->key > key) {
        root->left = insert(root->left, key);
    } else if (root->key < key) {
        root->right = insert(root->right, key);
    } else {
        return root;
    }

    // Step 2. Update root height
    root->height = 1 + std::max(findHeight(root->left), findHeight(root->right));

    // Step 3. Get balance factor
    int bf = balanceFactor(root);

    if (bf > 1 && root->left->key > key) {// Left-Left: Right Rotate
        return rightRotate(root);
    }
    else if (bf > 1 && root->left->key < key) { // Left-Right: Left Rotate, then Right Rotate
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    else if (bf < -1 && root->right->key < key) { // Right-Right: Left Rotate
        return leftRotate(root);
    }
    else if (bf < -1 && root->right->key > key) { // Right-Left: Righte Rotate, then Left Rotate
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

int findHeight(Node *node) {
    if (node == nullptr)
        return 0;

    return node->height;
}

int balanceFactor(Node *node) {
    if (node == nullptr)
        return 0;

    int leftH = 0;
    if (node->left != nullptr)
        leftH = 1 + findHeight(node->left);
    int rightH = 0;
    if (node->right != nullptr)
        rightH = 1 + findHeight(node->right);

    return leftH - rightH;
}

void inOrderTraversal(Node *root) {
    if (root == nullptr)
        return;
    std::cout << root->key << " ";
    inOrderTraversal(root->left);
    inOrderTraversal(root->right);
}

