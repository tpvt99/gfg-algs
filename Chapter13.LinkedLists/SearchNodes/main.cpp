#include <iostream>

struct Node {
    int item;
    struct Node *next;
    Node(int x) {
        item = x;
        next = nullptr;
    }
};

int searchNode(Node *head, int x);
int searchNode(Node *head, int x, int index);

int main() {
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(5);
    std::cout << "Using iterative method: " << std::endl;
    std::cout << searchNode(head, 5) << std::endl;
    std::cout << searchNode(head, 10) << std::endl;
    std::cout << searchNode(head, -10) << std::endl;
    Node *head2 = nullptr;
    std::cout << searchNode(head2, 5) << std::endl;
    std::cout << "Using recursive method: " << std::endl;
    std::cout << searchNode(head, 5, 0) << std::endl;
    std::cout << searchNode(head, 10,0) << std::endl;
    std::cout << searchNode(head, -10,0) << std::endl;
    std::cout << searchNode(head2, 5,0) << std::endl;
    return 0;
}

int searchNode(Node *head, int x) {
    int index = 0;
    while (head != nullptr) {
        if (head->item == x) {
            return index;
        }
        head = head->next;
        index++;
    }
    return -1;
}

int searchNode(Node *head, int x, int index) {
    if (head != nullptr) {
        if (head->item == x) {
            return index;
        }
        return searchNode(head->next, x, index+1);
    }
    return -1;
}