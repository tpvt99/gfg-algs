#include <iostream>

struct Node {
    int data;
    Node *next;
    Node (int x) {
        data = x;
        next = nullptr;
    }
};

void reverseLinkedList(Node **head);
Node *findNthNode(Node *head, int n);
void printNode(Node *head);
void efficientReverse(Node **head);
void efficientReverse2(Node **head);

int main() {
    Node *head = nullptr;
    printNode(head);
    //reverseLinkedList(&head);
    efficientReverse2(&head);
    printNode(head);

    head = new Node(10);
    printNode(head);
    //reverseLinkedList(&head);
    efficientReverse2(&head);
    printNode(head);

    head->next = new Node(20);
    printNode(head);
    //reverseLinkedList(&head);
    efficientReverse2(&head);
    printNode(head);

    head->next->next = new Node(30);
    printNode(head);
    //reverseLinkedList(&head);
    efficientReverse2(&head);
    printNode(head);

    head->next->next->next = new Node(40);
    printNode(head);
    //reverseLinkedList(&head);
    efficientReverse2(&head);
    printNode(head);

    return 0;
}

void efficientReverse(Node **head) {
    if (*head == nullptr) { // 0 node
        return;
    }
    if ((*head)->next == nullptr) { // 1 node
        return;
    }
    // >= 2 nodes
    Node *prev = nullptr;
    Node *cur = *head;
    Node *next = (*head)->next;

    while (next != nullptr) {
        cur->next = prev;
        prev = cur;
        cur = next;
        next = next->next;
    }
    cur->next = prev;
    *head = cur;
}

void efficientReverse2(Node **head) {
    Node *prev = nullptr;
    Node *cur = *head;
    while (cur != nullptr) {
        Node *next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    *head = prev;
}

void reverseLinkedList(Node **head) {
    Node *cur = *head;
    for (int i = 1;;i++) {
        Node *nthNode = findNthNode(*head, i);
        if (cur == nthNode) // Odd number, stop when two nodes same address
            break;
        if (nthNode->next == cur) // Even number, stop when nthNode point to current node
            break;
        std::swap(cur->data, nthNode->data);
        cur = cur->next;
    }
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

Node *findNthNode(Node *head, int n) {
    Node *first = head;
    for (int i = 0; i <n;i++) {
        if (first == nullptr) {
            return nullptr;
        }
        first = first->next;

    }
    Node *second = head;
    while (first != nullptr) {
        second = second->next;
        first = first->next;
    }
    return second;

}