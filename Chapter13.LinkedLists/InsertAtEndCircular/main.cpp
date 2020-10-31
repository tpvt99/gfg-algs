#include <iostream>

struct Node {
    int data;
    struct Node *next;
    Node (int x) {
        data = x;
        next = nullptr;
    }
};

void printNode(Node *head);
void efficientInsertEnd(Node **head, int x);

int main() {
    Node *head = nullptr;
    printNode(head);
    efficientInsertEnd(&head, 10);
    printNode(head);
    efficientInsertEnd(&head, 20);
    printNode(head);
    efficientInsertEnd(&head, 5);
    printNode(head);
    efficientInsertEnd(&head,15);
    printNode(head);

    return 0;
}

void efficientInsertEnd(Node **head, int x) {
    Node *node {new (std::nothrow) Node(x)};
    if (node == nullptr) {
        std::cout << "Cannot allocate node.\n";
        return;
    }

    if (*head == nullptr) {
        *head = node;
        node->next = node;
        return;
    }

    node->next = (*head)->next;
    (*head)->next = node;
    std::swap((*head)->data, node->data);
    *head = node;

}

void printNode(Node *head) {
    if (head == nullptr) {
        printf("NULL\n");
        return;
    }
    std::cout << head->data << "->";
    for (Node *cur = head->next; cur != head; cur = cur->next) {
        std::cout << cur->data << "->";
    }
    printf("...\n");
}