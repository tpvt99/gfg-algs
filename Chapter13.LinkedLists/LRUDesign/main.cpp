#include <iostream>
#include <unordered_map>
#include "node.h"

struct Lru_design {
    int max_node;
    int current_length;
    std::unordered_map<int, Node*> m;
    Node* head;
    Node *tail;
    Lru_design(int max) {
        max_node = max;
        current_length = 0;
        head = nullptr;
        tail = nullptr;
    }
};

void print_lru(Lru_design &lru);

int main() {
    Lru_design lru(4);
    int sequence[] {10, 20, 10, 30, 40, 50, 30, 40, 60, 30};
    for (auto i : sequence) {
        if (lru.m.find(i) != lru.m.end()) { // exits -> move to head
            moveANodeToHead(&(lru.head), lru.m.find(i)->second, &(lru.tail));
        } else {
            // Add at begin
            Node *new_node= addNodeAtBegin(&(lru.head), i, &(lru.tail));
            lru.m.insert({i, new_node});
            // Increase current_length
            lru.current_length += 1;
            // If current_length > max_node, remove last node
            if (lru.current_length > lru.max_node) {
                lru.m.erase((lru.tail)->data);
                removeLastNode(&(lru.head), &(lru.tail));
                lru.current_length -= 1;
            }
        }
        print_lru(lru);
    }

    return 0;
}

void print_lru(Lru_design &lru) {
    std::cout << "Length nodes: " << lru.current_length << std::endl;
    Node *head = lru.head;
    while (head != nullptr) {
        std::cout << head->data << "->";
        head = head->next;
    }
    std::cout << "NULL" << std::endl;
}