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
Node *merge(Node* head1, Node *head2);

int main() {
    Node *head1 = new Node(10);
    head1->next = new Node(20);
    head1->next->next = new Node(30);

    Node *head2 = new Node(5);
    head2->next = new Node(15);
    head2->next->next = new Node(20);

    Node *head = merge(head1, head2);
    printNode(head);
    return 0;
}

Node *merge(Node *head1, Node *head2) {
    if (head1 == nullptr)
        return head2;
    if (head2 == nullptr)
        return head1;

    Node *head;
    Node *cur;
    if (head1->data < head2->data) {
        head = head1;
        cur = head1;
        head1 = head1->next;
    } else {
        head = head2;
        cur = head2;
        head2 = head2->next;
    }
    while(head1 != nullptr && head2 != nullptr) {
        if (head1->data < head2->data) {
            cur->next = head1;
            cur = cur->next;
            head1 = head1->next;
        } else {
            cur->next = head2;
            cur=cur->next;
            head2 = head2->next;
        }
    }
    if (head1 == nullptr)
        cur->next = head2;
    else
        cur->next = head1;
    return head;

}

void printNode(Node *head) {
    while (head!=nullptr) {
        std::cout << head->data << "->";
        head = head->next;
    }
    std::cout << "NULL\n";
}