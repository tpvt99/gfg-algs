#include <iostream>

struct Node {
    int item;
    struct Node *next;
    Node (int x) {
        item = x;
        next = nullptr;
    }
};

void deleteLastNode(Node **head);
Node *deleteLastNode(Node *head);
void printNode(Node *node);

int main() {
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    printNode(head);
    deleteLastNode(&head);
    printNode(head);
    deleteLastNode(&head);
    printNode(head);
    deleteLastNode(&head);
    printNode(head);
    deleteLastNode(&head);
    printNode(head);
    deleteLastNode(&head);

    head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    printNode(head);
    head = deleteLastNode(head);
    printNode(head);
    head = deleteLastNode(head);
    printNode(head);
    head = deleteLastNode(head);
    printNode(head);
    head = deleteLastNode(head);
    printNode(head);
    head = deleteLastNode(head);
    return 0;
}

void printNode(Node *head) {
    while (head!=nullptr) {
        std::cout << head->item << "->";
        head = head->next;
    }
    std::cout << "NULL\n";
}

void deleteLastNode(Node **head) {
    Node *cur = *head;
    if (*head == nullptr) // head is null
        return;

    if ((*head)->next == nullptr) { // contain 1 node
        delete *head;
        *head = nullptr;
        return;
    }

    // has more than 1 node
    while (cur->next->next != nullptr) {
        cur = cur->next;
    }

    delete cur->next;
    cur->next = nullptr;
}

Node *deleteLastNode(Node *head) {
    Node *cur = head;

    if (head == nullptr) {
        return nullptr;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return nullptr;
    }

    while (cur->next->next != nullptr) {
        cur = cur->next;
    }

    delete cur->next;
    cur->next = nullptr;
    return head;
}