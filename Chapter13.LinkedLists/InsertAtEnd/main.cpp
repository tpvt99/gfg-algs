#include <iostream>

struct Node {
    int item;
    struct Node *next;
    Node(int x) {
        item = x;
        next = nullptr;
    }
};

void printNode(Node *head);
void insertAtEnd(Node **head, int x);
Node *insertAtEnd(Node *head, int x);

int main() {
    Node *head = nullptr;
    insertAtEnd(&head, 10);
    printNode(head);
    insertAtEnd(&head, 20);
    printNode(head);
    insertAtEnd(&head, 30);
    printNode(head);

    Node *head2 = nullptr;
    head2 = insertAtEnd(head2, 40);
    printNode(head2);
    head2 = insertAtEnd(head2, 50);
    printNode(head2);
    head2 = insertAtEnd(head2, 60);
    printNode(head2);
    return 0;
}

void insertAtEnd(Node **head, int x) {
    Node *node {new (std::nothrow) Node(x)};
    if (node == nullptr) {
        std::cout << "Cannot allocate for new Node.\n";
        return;
    }

    if (*head == nullptr) {
        *head = node;
        return;
    }

    Node *top = *head;
    while (top->next != nullptr) {
        top = top->next;
    }

    top->next = node;
    return;
}

Node *insertAtEnd(Node *head, int x) {
    Node *node {new (std::nothrow) Node(x)};
    if (node == nullptr) {
        std::cout << "Cannot allocate for new Node.\n";
        return nullptr;
    }

    if (head == nullptr) {
        return node;
    }

    Node *top = head;
    while (top->next != nullptr) {
        top = top->next;
    }
    top->next = node;
    return head;
}

void printNode(Node  *head) {
    while (head != nullptr) {
        printf("%d->", head->item);
        head = head->next;
    }
    printf("NULL\n");
}
