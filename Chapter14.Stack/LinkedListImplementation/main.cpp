#include <iostream>

struct Node {
    int data;
    Node *prev;
    Node *next;
    Node (int x) {
        data = x;
        prev = nullptr;
        next = nullptr;
    }
};

class MyStack {
public:
    Node *head;
    int current_size;
    MyStack() {
        head = nullptr;
        current_size = 0;
    }

    void push(int x) {
        Node *node = new (std::nothrow) Node(x);
        if (node == nullptr) {
            std::cout << "Cannot allocate nodes.\n";
            return;
        }
        current_size++;
        if (head == nullptr) {
            head = node;
            return;
        }
        head->next = node;
        node->prev = head;
        head = node;
    }

    int size() {
        return current_size;
    }

    int peek() {
        if (head == nullptr) {
            std::cout << "Stack Underflow. Cannot peek elements." << std::endl;
            return -1;
        }
        return head->data;
    }

    int pop() {
        if (head == nullptr) {
            std::cout << "Stack Underflow. Cannot peek elements." << std::endl;
            return -1;
        }
        int data = head->data;
        Node *prev = head->prev;
        delete head;
        prev->next = nullptr;
        head = prev;
        return data;
    }

    bool isEmpty() {
        return current_size == 0;
    }
};

int main() {
    MyStack m;
    m.push(10);
    m.push(20);
    m.push(30);
    std::cout << m.size() << std::endl;
    std::cout << m.peek() << std::endl;
    std::cout << m.pop() << std::endl;
    m.push(40);
    std::cout << m.peek() << std::endl;
    std::cout << m.isEmpty() << std::endl;

    return 0;
}
