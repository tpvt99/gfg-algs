#include <iostream>

struct Node {
    int data;
    Node *next;
    Node (int x) {
        data = x;
        next = nullptr;
    }
};

void recursiveReverse(Node **head, Node *prev);
void printNode(Node *head);

int main() {
    Node *head = nullptr;
    printNode(head);
    recursiveReverse(&head, nullptr);
    printNode(head);

    head = new Node(10);
    printNode(head);
    recursiveReverse(&head, nullptr);
    printNode(head);

    head->next = new Node(20);
    printNode(head);
    recursiveReverse(&head, nullptr);
    printNode(head);

    head->next->next = new Node(30);
    printNode(head);
    recursiveReverse(&head, nullptr);
    printNode(head);

    head->next->next->next = new Node(40);
    printNode(head);
    recursiveReverse(&head, nullptr);
    printNode(head);
    return 0;
}

void printNode(Node *head) {
    if (head == nullptr) {
        std::cout << "NULL\n";
        return;
    }
    while (head != nullptr) {
        std::cout << head->data << "->";
        head = head->next;
    }
    std::cout << "NULL\n";
}

void recursiveReverse(Node **head, Node *prev) {
    if (*head == nullptr) {
        *head = prev;
        return;
    }

    Node *next = (*head)->next;
    (*head)->next = prev;
    prev = *head;
    *head = next;
    recursiveReverse(head, prev);
}
