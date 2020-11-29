#include <iostream>
#include <unordered_set>

struct Node {
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printNode(Node *head);
void swapPair(Node *head);
void iterativeSwap(Node **head);

int main() {
    Node *head1 = nullptr;
    std::cout << "Before: ";printNode(head1);
    //swapPair(head1);
    iterativeSwap(&head1);
    std::cout << "After: ";printNode(head1);

    head1 = new Node(10);
    std::cout << "Before: ";printNode(head1);
    //swapPair(head1);
    iterativeSwap(&head1);
    std::cout << "After: ";printNode(head1);

    head1->next = new Node(17);
    std::cout << "Before: ";printNode(head1);
    //swapPair(head1);
    iterativeSwap(&head1);
    std::cout << "After: ";printNode(head1);

    head1->next->next = new Node(19);
    std::cout << "Before: ";printNode(head1);
    //swapPair(head1);
    iterativeSwap(&head1);
    std::cout << "After: ";printNode(head1);

    head1->next->next->next = new Node(99);
    std::cout << "Before: ";printNode(head1);
    //swapPair(head1);
    iterativeSwap(&head1);
    std::cout << "After: ";printNode(head1);

    head1->next->next->next->next = new Node(21);
    std::cout << "Before: ";printNode(head1);
    //swapPair(head1);
    iterativeSwap(&head1);
    std::cout << "After: ";printNode(head1);

    return 0;
}

void printNode(Node *head) {
    while (head != nullptr) {
        std::cout << head->data << "->";
        head = head->next;
    }
    printf("NULL\n");
}

void swapPair(Node *head) {
    Node *cur = head;
    while (cur != nullptr && cur->next != nullptr) {
        std::swap(cur->data, cur->next->data);
        cur = cur->next->next;
    }
}

void iterativeSwap(Node **head) {
    if (*head == nullptr || (*head)->next == nullptr)
        return;

    Node *cur = *head;
    Node *prev = *head;
    Node *next = (*head)->next;
    Node *far = next->next;
    next->next = cur;
    cur = far;
    *head = next;
    while (cur != nullptr && cur->next != nullptr) {
        next = cur->next;
        far = cur->next->next;
        next->next = cur;
        prev->next = next;
        prev = cur;
        cur = far;
    }
    prev->next = far;
}


