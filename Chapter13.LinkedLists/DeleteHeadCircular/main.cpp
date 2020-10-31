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
void naiveDelete(Node **head);
void efficientDelete(Node **head);

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

    std::cout << "Delete head . . .\n";
//    naiveDelete(&head);
//    printNode(head);
//    naiveDelete(&head);
//    printNode(head);
//    naiveDelete(&head);
//    printNode(head);
//    naiveDelete(&head);
//    printNode(head);
    efficientDelete(&head);
    printNode(head);
    efficientDelete(&head);
    printNode(head);
    efficientDelete(&head);
    printNode(head);
    efficientDelete(&head);
    printNode(head);

    return 0;
}

void efficientDelete(Node **head) {
    if (*head == nullptr) {
        return;
    }
    if ((*head)->next == *head) {
        delete *head;
        *head = nullptr;
        return;
    }
    std::swap((*head)->data, (*head)->next->data);
    Node *head_next_next = (*head)->next->next;
    delete (*head)->next;
    (*head)->next = head_next_next;


}

void naiveDelete(Node **head) {

    if (*head == nullptr) { // 0 node to delete
        return;
    }

    Node *cur = *head;
    while (cur->next != *head) {
        cur = cur->next;
    }

    if (cur == *head) { // 1 node
        delete *head;
        *head = nullptr;
        return;
    }

    // >= 2 nodes
    cur->next = (*head)->next;
    delete *head;
    *head = cur->next;
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