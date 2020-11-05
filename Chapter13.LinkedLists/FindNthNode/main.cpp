#include <iostream>

struct Node {
    int data;
    Node *next;
    Node (int x) {
        data = x;
        next = nullptr;
    }
};

void findNodeFromNth(Node *head, int n);
void twoPointerApproach(Node *head, int n);

int main() {
    Node *head = nullptr;

    std::cout << "Normal: "; findNodeFromNth(head, 1);
    std::cout << "TwoPointer: "; twoPointerApproach(head, 1);

    head = new Node(10);
    std::cout << "Normal: "; findNodeFromNth(head, 1);
    std::cout << "Normal: "; findNodeFromNth(head, 2);
    std::cout << "TwoPointer: "; twoPointerApproach(head, 1);
    std::cout << "TwoPointer: "; twoPointerApproach(head, 2);

    head->next = new Node(20);
    std::cout << "Normal: "; findNodeFromNth(head, 1);
    std::cout << "Normal: "; findNodeFromNth(head, 2);
    std::cout << "Normal: "; findNodeFromNth(head, 3);
    std::cout << "TwoPointer: "; twoPointerApproach(head, 1);
    std::cout << "TwoPointer: "; twoPointerApproach(head, 2);
    std::cout << "TwoPointer: "; twoPointerApproach(head, 3);

    head->next->next = new Node(30);
    std::cout << "Normal: "; findNodeFromNth(head, 1);
    std::cout << "Normal: "; findNodeFromNth(head, 2);
    std::cout << "Normal: "; findNodeFromNth(head, 3);
    std::cout << "Normal: "; findNodeFromNth(head, 4);
    std::cout << "TwoPointer: "; twoPointerApproach(head, 1);
    std::cout << "TwoPointer: "; twoPointerApproach(head, 2);
    std::cout << "TwoPointer: "; twoPointerApproach(head, 3);
    std::cout << "TwoPointer: "; twoPointerApproach(head, 4);


    return 0;
}

void findNodeFromNth(Node *head, int n) {
    int length = 0;
    Node *cur = head;
    while (cur != nullptr) {
        length++;
        cur = cur->next;
    }
    int index = length - n;
    if (index <0) {
        std::cout << "NULL" << std::endl;
        return;
    }

    while (index > 0) {
        index--;
        head = head->next;
    }
    std::cout << head->data << std::endl;
}

void twoPointerApproach(Node *head, int n) {
    Node *first = head;
    for (int i = 0; i <n;i++) {
        if (first == nullptr) {
            std::cout << "NULL\n";
            return;
        }
        first = first->next;

    }
    Node *second = head;
    while (first != nullptr) {
        second = second->next;
        first = first->next;
    }
    std::cout << second->data << "\n";

}