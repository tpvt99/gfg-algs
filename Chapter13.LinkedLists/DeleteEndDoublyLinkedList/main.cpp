#include <iostream>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
    Node (int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};

void insertAtEnd(Node **head, int data);
void deleteLastNode(Node **head);
Node *deleteLastNode(Node *head);
void printNode(Node *head);

int main() {
    Node *head = nullptr;
    printNode(head);
    insertAtEnd(&head, 10);
    printNode(head);
    insertAtEnd(&head, 20);
    printNode(head);
    insertAtEnd(&head, 30);
    printNode(head);

    printf("\n Delete nodes \n");

//    deleteLastNode(&head);
//    printNode(head);
//    deleteLastNode(&head);
//    printNode(head);
//    deleteLastNode(&head);
//    printNode(head);

    head = deleteLastNode(head);
    printNode(head);
    head = deleteLastNode(head);
    printNode(head);
    head = deleteLastNode(head);
    printNode(head);
}

void deleteLastNode(Node **head) {

    if (*head == nullptr) // 0 node
        return;

    if ((*head)->next == nullptr) { // 1 node
        delete *head;
        *head = nullptr;
        return;
    }

    // >= 2 nodes
    Node *cur = *head;
    while (cur->next->next != nullptr) {
        cur = cur->next;
    }

    delete cur->next;
    cur->next = nullptr;
}

Node *deleteLastNode(Node *head) {
    if (head == nullptr) {
        return nullptr;
    }

    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }

    Node *cur = head;
    while (cur->next!= nullptr) { // No need cur->next->next because this is doubly linked list
        cur = cur->next;
    }
    cur->prev->next = nullptr;
    delete cur;
    return head;
}

void insertAtEnd(Node **head, int data) {
    Node *node {new (std::nothrow) Node(data)};
    if (node == nullptr) {
        std::cout << "Cannot allocate memory.\n";
        return;
    }
    if (*head == nullptr) { // 0 node
        *head = node;
        return;
    }

    Node *curr = *head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = node;
    node->prev = curr;
}


void printNode(Node *head) {
    printf("Forward: ");
    Node *end = nullptr;

    while (head != nullptr) {
        std::cout << head->data << "->";

        if (head != nullptr) {
            end = head;
        }
        head = head->next;
    }
    printf("Null\n");
    printf("Backward: ");
    while (end != nullptr) {
        std::cout << end->data << "->";
        end = end->prev;
    }
    printf("Null\n");
}
