#include <iostream>

struct Node {
    int data;
    Node *next;
    Node (int x) {
        data = x;
        next = nullptr;
    }
};

Node * recursiveReverse(Node *head);
void outerCall(Node **head);
void printNode(Node *head);

int main() {
    Node *head = nullptr;
    printNode(head);
    outerCall(&head);
    printNode(head);

    head = new Node(10);
    printNode(head);
    outerCall(&head);
    printNode(head);

    head->next = new Node(20);
    printNode(head);
    outerCall(&head);
    printNode(head);

    head->next->next = new Node(30);
    printNode(head);
    outerCall(&head);
    printNode(head);

    head->next->next->next = new Node(40);
    printNode(head);
    outerCall(&head);
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

Node * recursiveReverse(Node *head) {
    if (head->next->next != nullptr) {
        Node *tail = recursiveReverse(head->next);

        Node *next = head->next;
        next->next = head;
        return tail;
    }

    Node *tail = head->next;
    tail->next = head; // reverse tail to head

    return tail;
}

void outerCall(Node **head) {
    if (*head == nullptr || (*head)->next == nullptr) {
        return;
    }
    Node *tail = recursiveReverse(*head);
    (*head)->next = nullptr;
    *head = tail;
}
