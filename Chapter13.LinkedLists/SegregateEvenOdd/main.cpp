#include <iostream>

struct Node {
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void segregateEvenOdd(Node *head); // using Lumoto Partition
void printNode(Node *head);
void efficientMethod(Node *head);

int main() {
    Node *head = nullptr;
    head = new Node(10);
    head->next = new Node(17);
    head->next->next = new Node(19);
    head->next->next->next = new Node(20);
    head->next->next->next->next = new Node(21);
    head->next->next->next->next->next = new Node(28);
    head->next->next->next->next->next->next = new Node(1);
    head->next->next->next->next->next->next->next = new Node(2);
    head->next->next->next->next->next->next->next->next = new Node(3);

    printNode(head);

    efficientMethod(head);
    printNode(head);

    return 0;
}

void printNode(Node *head) {
    while (head != nullptr) {
        std::cout << head->data << "->";
        head = head->next;
    }
    printf("NULL\n");
}

void segregateEvenOdd(Node *head) {
    Node *cur = head;
    Node *evenPointer = head;
    while (cur != nullptr) {
        if (cur->data % 2 == 0) {
            std::swap(cur->data, evenPointer->data);
            evenPointer = evenPointer->next;
        }
        cur = cur->next;
    }
}

void efficientMethod(Node *head) {
    Node *even_begin = nullptr;
    Node *even_end = nullptr;
    Node *odd_begin = nullptr;
    Node *odd_end = nullptr;
    while (head != nullptr) {
        if (head->data % 2 == 0) {
            if (even_begin == nullptr)
                even_begin = head;
            if (even_end == nullptr)
                even_end = head;
            else {
                even_end->next = head;
                even_end = head;
            }
        } else {
            if (odd_begin == nullptr)
                odd_begin = head;
            if (odd_end == nullptr)
                odd_end = head;
            else {
                odd_end->next = head;
                odd_end = head;
            }
        }
        head = head->next;
    }
    if (even_end == nullptr || odd_end == nullptr) // true if no nodes or only odd or only evens
        return;
    even_end->next = odd_begin;
    odd_end->next = nullptr;
}
