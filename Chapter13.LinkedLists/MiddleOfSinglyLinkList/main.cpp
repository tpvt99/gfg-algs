#include <iostream>

struct Node {
    int data;
    Node *next;
    Node (int x) {
        data = x;
        next = nullptr;
    }
};

void naiveMethod(Node *head);
void efficientMethod(Node *head);

int main() {
    Node *head = nullptr;
    std::cout << "Naive: "; naiveMethod(head);
    std::cout << "Efficient: "; efficientMethod(head);
    head = new Node(2);
    std::cout << "Naive: "; naiveMethod(head);
    std::cout << "Efficient: "; efficientMethod(head);
    head->next = new Node(10);
    std::cout << "Naive: "; naiveMethod(head);
    std::cout << "Efficient: "; efficientMethod(head);
    head->next->next = new Node(5);
    std::cout << "Naive: "; naiveMethod(head);
    std::cout << "Efficient: "; efficientMethod(head);
    head->next->next->next = new Node(15);
    std::cout << "Naive: "; naiveMethod(head);
    std::cout << "Efficient: "; efficientMethod(head);
    head->next->next->next->next = new Node(20);
    std::cout << "Naive: "; naiveMethod(head);
    std::cout << "Efficient: "; efficientMethod(head);
    head->next->next->next->next->next = new Node(100);
    std::cout << "Naive: "; naiveMethod(head);
    std::cout << "Efficient: "; efficientMethod(head);
    head->next->next->next->next->next->next = new Node(50);
    std::cout << "Naive: "; naiveMethod(head);
    std::cout << "Efficient: "; efficientMethod(head);
    return 0;
}

void naiveMethod(Node *head) {
    int count = 0;
    Node *cur = head;
    while (cur != nullptr) {
        cur = cur->next;
        count++;
    }

    if (count == 0) { // no nodes
        std::cout << "NULL\n";
        return;
    }

    // >= 1 node

    int desiredCount = count / 2;
    count = 0;
    cur = head;
    while (count < desiredCount) {
        cur = cur->next;
        count++;
    }
    std::cout << cur->data << "\n";
}

void efficientMethod(Node *head) {
    Node *slow = head;
    Node *fast = head;
    if (slow == nullptr) {
        std::cout << "NULL\n";
        return;
    }
    do {
        if (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        } else {
            break;
        }
        if (fast->next != nullptr) {
            fast = fast->next;
        } else {
            break;
        }
    } while (true);
    std::cout << slow->data << "\n";
}
