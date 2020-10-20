#include <iostream>

struct Node {
    int item;
    struct Node *next;
    Node (int x) {
        item = x;
        next = nullptr;
    }
};

void deleteFirstNode(Node **head);
Node *deleteFirstNode(Node *head);
void printNode(Node *head);

int main() {
    Node *head1 = new Node(10);
    head1->next = new Node(20);
    head1->next->next = new Node(30);
    printNode(head1);
    deleteFirstNode(&head1);
    printNode(head1);
    deleteFirstNode(&head1);
    printNode(head1);
    deleteFirstNode(&head1);
    printNode(head1);
    deleteFirstNode(&head1);
    printNode(head1);
    deleteFirstNode(&head1);

    head1 = new Node(10);
    head1->next = new Node(20);
    head1->next->next = new Node(30);
    printNode(head1);
    head1 = deleteFirstNode(head1);
    printNode(head1);
    head1 = deleteFirstNode(head1);
    printNode(head1);
    head1 = deleteFirstNode(head1);
    printNode(head1);
    head1 = deleteFirstNode(head1);
    printNode(head1);
    head1 = deleteFirstNode(head1);
    return 0;
}

void printNode(Node *head) {
    while(head != nullptr) {
        std::cout << head->item << "->";
        head = head->next;
    }
    std::cout << "NULL\n";
}

void deleteFirstNode(Node **head) {
    if (*head == nullptr)
        return;

    Node *next = *head;
    *head = (*head)->next;
    delete next;
}

Node *deleteFirstNode(Node *head) {
    if (head == nullptr)
        return head;

    Node *next = head;
    head = head->next;
    delete next;
    return head;
}