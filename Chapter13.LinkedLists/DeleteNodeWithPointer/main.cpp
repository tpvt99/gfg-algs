#include <iostream>

struct Node {
    int data;
    Node *next;
    Node (int x) {
        data = x;
        next = nullptr;
    }
};

void removeNode(Node *ref);
void printNode(Node *head);

int main() {
    Node *head = nullptr;
    printNode(head);
    removeNode(head);
    printNode(head);

    Node *temp = new Node(10);
    head = temp;

    Node *temp2 = new Node(20);
    head->next = temp2;

    Node *temp3 = new Node(30);
    head->next->next = temp3;

    Node *temp4 = new Node(40);
    head->next->next->next = temp4;

    Node *temp5 = new Node(50);
    head->next->next->next->next = temp5;

    printNode(head);

    removeNode(temp3);
    printNode(head);

    removeNode(temp5);
    printNode(head);

    return 0;
}

void removeNode(Node *ref) {
    if (ref == nullptr) // no nodes to delete
        return;

    if (ref->next == nullptr) { // deleted node is the last node
        Node *cur = ref;
        cur = nullptr;
        delete ref;
        return;
    }

    Node *next = ref->next;
    Node *far = ref->next->next;
    std::swap(next->data, ref->data);
    delete next;
    ref->next = far;
}

void printNode(Node *head) {
    while (head != nullptr) {
        std::cout << head->data << "->";
        head=head->next;
    }
    std::cout << "NULL\n";
}