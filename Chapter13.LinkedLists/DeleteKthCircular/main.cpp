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
void deleteKthNodeUsingEfficientDelete(Node **head, int x);
void normalDeleteKthNode(Node **head, int k);
void efficientDelete(Node **head);
Node* naiveDelete(Node *head);

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

    normalDeleteKthNode(&head, 4);
    printNode(head);
    normalDeleteKthNode(&head, 2);
    printNode(head);
    normalDeleteKthNode(&head, 1);
    printNode(head);
    normalDeleteKthNode(&head, 4);
    printNode(head);
    normalDeleteKthNode(&head, 5);
    printNode(head);

    return 0;
}


void normalDeleteKthNode(Node **head, int k) {

    if (*head == nullptr) {
        return;
    }
    if ((*head)->next == *head) {
        delete *head;
        *head = nullptr;
        return;
    }

    Node *cur = *head;
    for (int i = 1; i < k; i++) {
        cur = cur->next;
    }

    std::swap(cur->data, cur->next->data);
    Node *next_next = cur->next->next;
    if (cur->next == *head) { // if delete node is the tail node, we have to reassign the node to the tail node
        *head = cur;
    }
    delete cur->next;
    cur->next = next_next;

}

void deleteKthNodeUsingEfficientDelete(Node **head, int k) {
    if (*head == nullptr) {
        return;
    }

    Node *cur = *head;
    for (int i = 1; i <k;i++) {
        cur = cur->next;
    }

    *head = naiveDelete(cur);
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

Node* naiveDelete(Node *head) {

    if (head == nullptr) { // 0 node to delete
        return nullptr;
    }

    Node *cur = head;
    while (cur->next != head) {
        cur = cur->next;
    }

    if (cur == head) { // 1 node
        delete head;
        return nullptr;
    }

    // >= 2 nodes
    cur->next = head->next;
    delete head;
    return cur->next;
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