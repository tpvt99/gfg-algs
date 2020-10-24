#include <iostream>

struct Node {
    int data;
    Node *next;
    Node *prev;
    Node (int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};

void insertAtBegin(Node **head, int data);
Node *insertAtBegin(Node *head, int data);
void printNode(Node *head);

int main() {
    Node *head = nullptr;
    insertAtBegin(&head, 10);
    printNode(head);
    insertAtBegin(&head, 20);
    printNode(head);
    insertAtBegin(&head, 30);
    printNode(head);

    Node *head2 = nullptr;
    head2 = insertAtBegin(head2, 10);
    printNode(head2);
    head2 = insertAtBegin(head2,50);
    printNode(head2);
    head2 = insertAtBegin(head2,60);
    printNode(head2);
    return 0;
}

void insertAtBegin(Node **head, int data) {
    Node *node {new (std::nothrow) Node(data)};
    if (node == nullptr) {
        std::cout << "Cannot allocate memory for new data.\n";
        return;
    }
    if (*head == nullptr) {
        *head = node;
        return;
    }
    (*head)->prev = node;
    node->next = *head;
    *head = node;
    return;
}

Node *insertAtBegin(Node *head, int data) {
    Node *node {new (std::nothrow) Node(data)};
    if (node == nullptr) {
        std::cout << "Cannot allocate memory for new data.\n";
        return head;
    }
    if (head == nullptr) {
        return node;
    }
    head->prev = node;
    node->next = head;
    return node;
}

void printNode(Node *head) {
    printf("Forward: ");
    Node *cur;
    while (head != nullptr) {
        std::cout << head->data << "->";
        head = head->next;
        if (head != nullptr) {
            cur = head;
        }
    }
    printf("Null\n");
    head = cur;
    printf("Backward: ");
    while (head != nullptr) {
        std::cout << head->data << "->";
        head = head->prev;
    }
    printf("Null\n");
}
