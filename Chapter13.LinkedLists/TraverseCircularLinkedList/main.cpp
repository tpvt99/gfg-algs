#include <iostream>

struct Node {
    int data;
    Node *next;
    Node (int x) {
        data = x;
        next = nullptr;
    }
};

void printNode(Node *head);

int main() {
    Node *head = new Node(10);
    Node *temp1 = new Node(5);
    Node *temp2 = new Node(15);
    head->next = temp1;
    temp1->next = temp2;
    temp2->next = temp2;
    temp2->next = head;

    printNode(head);

    Node *head2 = new Node(100);
    head2->next = head2;
    printNode(head2);

    Node *head3 = nullptr;

    printNode(head3);

    return 0;
}

void printNode(Node *head) {
    if (head == nullptr) {
        std::cout << "NULL";
        printf("\n");
        return;
    }

    Node *cur = head;
    do {
        std::cout << cur->data << "->";
        cur = cur->next;
    } while (cur != head);
    printf("\n");
}