#include <iostream>

struct Node {
    int item;
    struct Node *next;

    Node (int x) {
        item = x;
        next = nullptr;
    }
};

void insertAtBeginning(Node **head, int item); // Insert and change the head ptr's value
Node *insertAtBeginning(Node *head, int item); // Insert and return new pointer point to head
void printLinkedList(Node *head);

int main() {
    Node *head = nullptr;
    insertAtBeginning(&head, 10);
    printLinkedList(head);
    insertAtBeginning(&head, 20);
    printLinkedList(head);
    insertAtBeginning(&head, 30);
    printLinkedList(head);

    Node *head2 = nullptr;
    head2 = insertAtBeginning(head2, 20);
    printLinkedList(head2);
    head2 = insertAtBeginning(head2, 30);
    printLinkedList(head2);
    head2 = insertAtBeginning(head2, 40);
    printLinkedList(head2);
    return 0;
}

void insertAtBeginning(Node **head, int item) {
    Node *node {new (std::nothrow) Node(item)};
    if (node == nullptr) {
        std::cout << "Cannot allocate memory.\n";
        return;
    }
    node->next = *head;
    *head = node;
}

Node *insertAtBeginning(Node  *head, int item) {
    Node *node {new (std::nothrow) Node(item)};
    if (node == nullptr) {
        std::cout << "Cannot allocate memory.\n";
        return nullptr;
    }
    node->next = head;
    return node;
}

void printLinkedList(Node *head) {
    for (;head != nullptr; head = head->next) {
        std::cout << head->item << "->";
    }
    std::cout << "NULL\n";
}