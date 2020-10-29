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
    Node *temp3 = new Node(20);
    head->next = temp1;
    temp1->next = temp2;
    temp2->next = temp3;
    temp3->next = head;

    printNode(head);

    return 0;
}

void printNode(Node *head) {
    Node *cur = head;
    for (int i = 0; i < 8; i++) {
        std::cout << cur->data << "->";
        cur = cur->next;
    }


}