#include <iostream>

struct Node {
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printNode(Node *head);
void insertBegin(Node **head, int x);
void efficientInsertBegin(Node **head, int x);

int main() {
    Node *head = nullptr;
    printNode(head);
    insertBegin(&head, 10);
    printNode(head);
    insertBegin(&head, 5);
    printNode(head);
    insertBegin(&head, 20);
    printNode(head);
    insertBegin(&head, 15);
    printNode(head);

    Node *head2 = nullptr;
    printNode(head2);
    efficientInsertBegin(&head2, 10);
    printNode(head2);
    efficientInsertBegin(&head2, 5);
    printNode(head2);
    efficientInsertBegin(&head2, 20);
    printNode(head2);
    efficientInsertBegin(&head2, 15);
    printNode(head2);

    return 0;
}

void insertBegin(Node **head, int x) {
    Node *node{new (std::nothrow) Node(x)};
    if (node == nullptr) {
        std::cout << "Cannot allocate memory.\n";
        return;
    }

    if (*head == nullptr) { // 0 node
        *head = node;
        node->next = node;
        return;
    }

    // Find the end node

    Node *cur = *head;
    while (cur->next != *head) {
        cur = cur->next;
    }

    cur->next = node;
    node->next = *head;
    *head = node;
}

void efficientInsertBegin(Node **head, int x) {
    Node *node{new (std::nothrow) Node(x)};
    if (node == nullptr) {
        std::cout << "Cannot allocate memory.\n";
        return;
    }
    if (*head == nullptr) {
        *head = node;
        node->next = node;
        return;
    }

    node->next = (*head)->next;
    (*head)->next = node;
    std::swap((*head)->data, node->data);
}

void printNode(Node *head) {
    if (head == nullptr) {
        printf("NULL\n");
        return;
    }
    std::cout << head->data << "->";
    for (Node *cur = head->next; cur != head; cur = cur->next) {
        std::cout << cur->data << "->";
    }
    printf("...\n");
}
