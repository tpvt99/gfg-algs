#include <iostream>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
    Node (int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};

void insertAtEnd(Node **head, int data);
Node *insertAtEnd(Node *head, int data);
void printNode(Node *head);

int main() {
    Node *head = nullptr;
    printNode(head);
    insertAtEnd(&head, 10);
    printNode(head);
    insertAtEnd(&head, 20);
    printNode(head);
    insertAtEnd(&head, 30);
    printNode(head);

    Node *head2 = nullptr;
    printNode(head2);
    head2= insertAtEnd(head2, 10);
    printNode(head2);
    head2 = insertAtEnd(head2, 20);
    printNode(head2);
    head2 = insertAtEnd(head2, 30);
    printNode(head2);
    return 0;
}

void insertAtEnd(Node **head, int data) {
    Node *node {new (std::nothrow) Node(data)};
    if (node == nullptr) {
        std::cout << "Cannot allocate memory.\n";
        return;
    }
    if (*head == nullptr) { // 0 node
        *head = node;
        return;
    }

    Node *curr = *head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = node;
    node->prev = curr;
}

Node *insertAtEnd(Node *head, int data) {
    Node *node {new (std::nothrow) Node(data)};
    if (node == nullptr) {
        std::cout << "Cannot allocate memory.\n";
        return head;
    }
    if (head == nullptr) { // 0 node
        return node;
    }

    Node *curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = node;
    node->prev = curr;
    return head;
}

void printNode(Node *head) {
    printf("Forward: ");
    Node *end = nullptr;

    while (head != nullptr) {
        std::cout << head->data << "->";

        if (head != nullptr) {
            end = head;
        }
        head = head->next;
    }
    printf("Null\n");
    printf("Backward: ");
    while (end != nullptr) {
        std::cout << end->data << "->";
        end = end->prev;
    }
    printf("Null\n");
}
