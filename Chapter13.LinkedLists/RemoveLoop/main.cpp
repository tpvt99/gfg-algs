#include <iostream>
#include <unordered_set>

struct Node {
    int data;
    Node *next;
    Node (int x) {
        data = x;
        next = nullptr;
    }
};

void removeLoop(Node *head);
bool isLoopFloydCircleDetection(Node *head);
void removeLoopFloyd(Node *head);

int main() {
    Node *head = nullptr;
    std::cout << "Is Loop: " << isLoopFloydCircleDetection(head) << std::endl;
    removeLoopFloyd(head);
    std::cout << "Is Loop: " << isLoopFloydCircleDetection(head) << std::endl;

    Node *temp = new Node(10);
    head = temp;
    std::cout << "Is Loop: " << isLoopFloydCircleDetection(head) << std::endl;
    removeLoopFloyd(head);
    std::cout << "Is Loop: " << isLoopFloydCircleDetection(head) << std::endl;

    Node *temp1 = new Node(20);
    head->next = temp1;
    temp1->next = temp;
    std::cout << "Is Loop: " << isLoopFloydCircleDetection(head) << std::endl;
    removeLoopFloyd(head);
    std::cout << "Is Loop: " << isLoopFloydCircleDetection(head) << std::endl;

    Node *temp2 = new Node(30);
    head->next->next = temp2;
    temp2->next = head;
    std::cout << "Is Loop: " << isLoopFloydCircleDetection(head) << std::endl;
    removeLoopFloyd(head);
    std::cout << "Is Loop: " << isLoopFloydCircleDetection(head) << std::endl;

    Node *temp3 = new Node(40);
    head->next->next->next = temp3;
    temp3->next = temp2;
    std::cout << "Is Loop: " << isLoopFloydCircleDetection(head) << std::endl;
    removeLoopFloyd(head);
    std::cout << "Is Loop: " << isLoopFloydCircleDetection(head) << std::endl;

    return 0;
}

void removeLoop(Node *head) {
    std::unordered_set<Node *> m;
    Node *prev = nullptr;
    Node *cur = head;
    while (cur != nullptr) {
        if (m.find(cur) != m.end()) {
            prev->next = nullptr;
            return;
        }
        m.insert(cur);
        prev = cur;
        cur = cur->next;
    }
}

void removeLoopFloyd(Node *head) {
    Node *slow = head;
    Node *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            break;
        }
    }
    if ((slow != nullptr) && (slow == fast)) {
        slow = head;
    } else {
        return;
    }
    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = nullptr;
}

bool isLoopFloydCircleDetection(Node *head) {
    Node *slow = head;
    Node *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}