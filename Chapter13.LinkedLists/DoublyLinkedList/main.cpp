#include <iostream>

struct Node {
    int data;
    Node *next;
    Node *prev;
    Node (int d) {
        data = d;
        prev = nullptr;
        next = nullptr;
    }
};

void printNode(Node *head);

int main() {
    Node *head = new Node(10);
    Node *temp = new Node(20);
    head->next = temp;
    temp->prev = head;
    temp = new Node(30);
    head->next->next = temp;
    temp->prev = head->next;
    printNode(head);
    return 0;
}

void printNode(Node *head) {
    std::cout << "In forward: ";
    Node *curr;
    while (head != nullptr) {
        std::cout << head->data << "->";
        head = head->next;
        if (head != nullptr) {
            curr = head;
        }
    }
    std::cout << "NULL\n";

    std::cout << "In backward: ";
    head = curr;
    while (head != nullptr) {
        std::cout << head->data << "->";
        head = head->prev;
    }
    std::cout << "NULL\n";

}
