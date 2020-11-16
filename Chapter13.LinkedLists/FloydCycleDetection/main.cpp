#include <iostream>
#include <unordered_set>
#include <cstdint>
#include <iterator>

struct Node {
    int data;
    Node *next;
    Node (int x) {
        data = x;
        next = nullptr;
    }
};

bool isLoop(Node *head);
bool isLoopFloydCycle(Node *head);

int main() {
    Node *head = nullptr;
    std::cout << "Using hashset: " << isLoop(head) << std::endl;
    std::cout << "Using floyd: " << isLoopFloydCycle(head) << std::endl;

    Node *temp1 = new Node(10);
    head = temp1;
    std::cout << "Using hashset: " << isLoop(head) << std::endl;
    std::cout << "Using floyd: " << isLoopFloydCycle(head) << std::endl;

    Node *temp2 = new Node(20);
    head->next = temp2;
    std::cout << "Using hashset: " << isLoop(head) << std::endl;
    std::cout << "Using floyd: " << isLoopFloydCycle(head) << std::endl;

    Node *temp3 = new Node(30);
    head->next->next = temp3;
    std::cout << "Using hashset: " << isLoop(head) << std::endl;
    std::cout << "Using floyd: " << isLoopFloydCycle(head) << std::endl;

    temp3->next = temp2;
    std::cout << "Using hashset: " << isLoop(head) << std::endl;
    std::cout << "Using floyd: " << isLoopFloydCycle(head) << std::endl;

    temp3->next = nullptr;
    std::cout << "Using hashset: " << isLoop(head) << std::endl;
    std::cout << "Using floyd: " << isLoopFloydCycle(head) << std::endl;

    Node *temp4 = new Node(30);
    head->next->next->next = temp4;
    std::cout << "Using hashset: " << isLoop(head) << std::endl;
    std::cout << "Using floyd: " << isLoopFloydCycle(head) << std::endl;

    temp4->next = head;
    std::cout << "Using hashset: " << isLoop(head) << std::endl;
    std::cout << "Using floyd: " << isLoopFloydCycle(head) << std::endl;

    return 0;
}

bool isLoop(Node *head) {
    std::unordered_set<std::uintptr_t> m;
    while (head != nullptr) {
        auto it = m.find(reinterpret_cast<std::uintptr_t>(head));
        if (it != std::end(m)) {
            return true;
        }
        m.insert(reinterpret_cast<std::uintptr_t>(head));
        head = head->next;
    }
    return false;
}

bool isLoopFloydCycle(Node *head) {
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