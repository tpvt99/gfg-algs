#include "node.h"
#include <iostream>

void printNode(Node *head) {
    Node *last_node = nullptr;
    while (head != nullptr) {
        std::cout << head->data << "->";
        last_node = head;
        head = head->next;
    }
    std::cout << "NULL" << std::endl;

    while (last_node != nullptr) {
        std::cout << last_node->data << "->";
        last_node = last_node->prev;
    }
    std::cout << "NULL" << std::endl;

}

Node * addNodeAtBegin(Node **head, int data, Node **tail) {
    Node *node = new Node(data);
    if (*head == nullptr) {
        *head = node;
        *tail = node;
        return node;
    }
    node->next = *head;
    (*head)->prev = node;
    *head = node;
    return node;
}

void removeLastNode(Node **head, Node **tail) {
    if (*tail == nullptr) { // If tail is null
        return;
    }
    if ((*tail)->prev == nullptr) { // if tail == head
        delete *tail;
        *tail = nullptr;
        *head = nullptr;
        return;
    }

    Node *prev = (*tail)->prev;
    delete *tail;
    prev->next = nullptr;
    *tail = prev;
}

void moveANodeToHead(Node **head, Node *node, Node **tail) {
    if (*head == nullptr || (*head)->next == nullptr) { // 0 or 1 node, then do nothing
        return;
    }
    if (node == nullptr || node->prev == nullptr) // moved node is head node or moved node is empty node
        return;

    Node *prev = node->prev;
    Node *next = node->next;
    prev->next = next;
    if (next != nullptr) // if node is not the last node
        next->prev = prev;
    else // if node is the last node
        *tail = prev;
    node->next = *head;
    node->prev = nullptr;
    (*head)->prev = node;
    *head = node;
}

void testNodeImplementation() {
    //
    Node *head = nullptr;
    Node *tail;

    addNodeAtBegin(&head, 10, &tail);
    addNodeAtBegin(&head, 20, &tail);
    addNodeAtBegin(&head, 30, &tail);
    printNode(head);
    printf("Head: %d\n", head->data);
    printf("Tail: %d\n", tail->data);

    moveANodeToHead(&head, head->next, &tail);
    printf("After move:\n");
    printNode(head);
    printf("Head: %d\n", head->data);
    printf("Tail: %d\n", tail->data);

    removeLastNode(&head, &tail);
    printNode(head);
    printf("Head: %d\n", head->data);
    printf("Tail: %d\n", tail->data);

    removeLastNode(&head, &tail);
    printNode(head);
    printf("Head: %d\n", head->data);
    printf("Tail: %d\n", tail->data);

    removeLastNode(&head, &tail);
    printNode(head);
}
