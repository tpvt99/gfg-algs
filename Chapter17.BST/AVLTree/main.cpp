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
Node *deleteBST(Node *root, int x);
Node * inorderSuccessor(Node *root);

int main() {

    Node *root = nullptr;
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);

    std::cout << "Preorder traversal of the "
            "constructed AVL tree is \n";
    inOrderTraversal(root);

    root = deleteBST(root, 10);


    std::cout << "\nPreorder traversal after"
         << " deletion of 10 \n";
    inOrderTraversal(root);

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
    root->height = 1 + std::max(findHeight(root->left), findHeight(root->right)); // Must update root->height first because y->height depends on root->height
    x->height = 1 + std::max(findHeight(x->left), findHeight(x->right));

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
    root->height = 1 + std::max(findHeight(root->left), findHeight(root->right)); // Must update root->height first because y->height depends on root->height
    y->height = 1 + std::max(findHeight(y->left), findHeight(y->right));

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
            // If x has 1 left child
        else if (root->left != nullptr && root->right == nullptr) {
            Node *temp = root->left;
            delete root;
            return temp;
        } // If x has 1 right child
        else if (root->right != nullptr && root->left == nullptr) {
            Node *temp = root->right;
            delete root;
            return temp;
        } // If x has 2 children
        else {
            Node *inorderSucc = inorderSuccessor(root->right);
            if (inorderSucc == nullptr) {
                delete root;
                return nullptr;
            }
            root->key = inorderSucc->key;
            root->right = deleteBST(root->right, inorderSucc->key);
        }
    }
    else if (root->key > x) {
        root->left = deleteBST(root->left, x);
    } else
        root->right = deleteBST(root->right, x);

    // Step 2. Update root height
    root->height = 1 + std::max(findHeight(root->left), findHeight(root->right));

    // Step 3. Get balance factor
    int bf = balanceFactor(root);

    if (bf > 1 && balanceFactor(root->left) >= 0) {// Left-Left: Right Rotate
        return rightRotate(root);
    }
    else if (bf > 1 && balanceFactor(root->left) < 0) { // Left-Right: Left Rotate, then Right Rotate
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    else if (bf < -1 && balanceFactor(root->right) <= 0) { // Right-Right: Left Rotate
        return leftRotate(root);
    }
    else if (bf < -1 && balanceFactor(root->right) > 0) { // Right-Left: Righte Rotate, then Left Rotate
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}
