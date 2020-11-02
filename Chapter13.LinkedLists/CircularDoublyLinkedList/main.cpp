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

void insertAtHead(Node **head, int x);
void printForwardNode(Node *head);
void printBackwardNode(Node *head);

int main() {
    Node *head = nullptr;
    printForwardNode(head);
    printBackwardNode(head);

    insertAtHead(&head, 10);
    printForwardNode(head);
    printBackwardNode(head);

    insertAtHead(&head, 20);
    printForwardNode(head);
    printBackwardNode(head);

    insertAtHead(&head, 30);
    printForwardNode(head);
    printBackwardNode(head);
    return 0;
}

void insertAtHead(Node **head, int x) {
    Node *node = new (std::nothrow) Node(x);
    if (node == nullptr) {
        std::cout << "Cannot allocate memory.\n";
        return;
    }
    if (*head == nullptr) {
        node->next = node;
        node->prev = node;
        *head = node;
        return;
    }
    node->next = *head;
    Node *last = (*head)->prev;
    (*head)->prev = node;
    last->next = node;
    node->prev = last;
    *head = node;
}

void printForwardNode(Node *head) {
    std::cout << "Forward: ";
    if (head == nullptr) {
        std::cout << "NULL\n";
        return;
    }
    std::cout << head->data << "->";
    for (Node *cur = head->next; cur != head; cur = cur->next) {
        std::cout << cur->data << "->";
    }
    std::cout << "...\n";
}

void printBackwardNode(Node *head) {
    std::cout << "Backward: ";
    if (head == nullptr) {
        std::cout << "NULL\n";
        return;
    }
    Node *last = head->prev;
    std::cout << last->data << "->";
    for (Node *cur = last->prev; cur != last; cur = cur->prev) {
        std::cout << cur->data << "->";
    }
    std::cout << "...\n";
}
