#include <iostream>

struct Node {
    int data;
    Node *next;
    Node (int x) {
        data = x;
        next = nullptr;
    }
};

void reverseInGroupK(Node **head, int k);
void printNode(Node *head);

int main() {
    Node *head = nullptr;
    printNode(head);
    reverseInGroupK(&head, 1);
    printNode(head);

    head = new Node(10);
    printNode(head);
    reverseInGroupK(&head, 2);
    printNode(head);

    head->next = new Node(20);
    printNode(head);
    reverseInGroupK(&head, 3);
    printNode(head);

    head->next->next = new Node(30);
    printNode(head);
    reverseInGroupK(&head, 2);
    printNode(head);

    head->next->next->next = new Node(40);
    printNode(head);
    reverseInGroupK(&head, 2);
    printNode(head);

    head->next->next->next->next = new Node(50);
    printNode(head);
    reverseInGroupK(&head, 3);
    printNode(head);

    head->next->next->next->next->next = new Node(60);
    printNode(head);
    reverseInGroupK(&head, 3);
    printNode(head);

    return 0;
}

void printNode(Node *head) {
    if (head == nullptr) {
        std::cout << "NULL\n";
        return;
    }
    while (head != nullptr) {
        std::cout << head->data << "->";
        head = head->next;
    }
    std::cout << "NULL\n";
}

void reverseInGroupK(Node **head, int k) {
    if (*head == nullptr)
        return;

    Node *prev;
    Node *cur = *head;
    Node *tail_cache = cur;
    Node *new_tail_cache;
    int flag = 0;

    for (int outer = 0; ;outer++) {
        prev = nullptr;
        for (int i = 0; i <k; i++) {
            if (k == 0) {
                new_tail_cache = cur;
            }
            Node *next =cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            if (cur == nullptr) {
                flag = 1;
                break;
            }
        }

        if (outer >= 1) {
            tail_cache->next = prev;
            tail_cache = new_tail_cache;
        }

        if (outer == 0) {
            *head = prev;
        }
        if (flag == 1)
            break;
    }
}
