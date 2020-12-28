#include <iostream>

struct Node {
    int data;
    Node *next;
};

class Queue {
private:
    Node *front;
    Node *rear;
    int cap;
public:
    Queue() {
        front = nullptr;
        rear = nullptr;
        cap = 0;
    }

    void enqueue(int x) {
        Node *node {new (std::nothrow) Node};
        if (node == nullptr) {
            std::cout << "No allocation for memory" << std::endl;
            return;
        }
        node->data = x;
        node->next = nullptr;
        cap++;
        if (rear == nullptr) {
            rear = node;
            front = node;
            return;
        }
        rear->next = node;
        rear = node;
    }

    int dequeue() {
        if (front == nullptr) {
            std::cout << "Empty queue" << std::endl;
            return -1;
        }

        // Get the next node
        Node *next = front->next;
        int re = front->data;
        // Delete current front and assign front to next node
        delete front;
        front = next;
        // If front is null then rear should be null also
        if (front == nullptr)
            rear = nullptr;
        cap--;
        return re;
    }

    bool isFull() {
        return false;
    }

    bool isEmpty() {
        return cap == 0;
    }

    int getFront() {
        if (front == nullptr) {
            std::cout << "Empty queue" << std::endl;
            return -1;
        }
        return front->data;
    }

    int getRear() {
        if (rear == nullptr) {
            std::cout << "Empty queue" << std::endl;
            return -1;
        }
        return rear->data;
    }

    int size() {
        return cap;
    }
};

int main() {
    Queue q;
    std::cout << q.isEmpty() << std::endl;
    std::cout << q.isFull() << std::endl;
    std::cout << q.getFront() << std::endl;
    std::cout << q.getRear() << std::endl;
    std::cout << q.size() << std::endl;

    std::cout << "-----" << std::endl;
    q.enqueue(10);
    std::cout << q.isEmpty() << std::endl;
    std::cout << q.isFull() << std::endl;
    std::cout << q.getFront() << std::endl;
    std::cout << q.getRear() << std::endl;
    std::cout << q.size() << std::endl;

    std::cout << "-----" << std::endl;
    q.enqueue(20);
    std::cout << q.isEmpty() << std::endl;
    std::cout << q.isFull() << std::endl;
    std::cout << q.getFront() << std::endl;
    std::cout << q.getRear() << std::endl;
    std::cout << q.size() << std::endl;

    std::cout << "-----" << std::endl;
    q.enqueue(30);
    std::cout << q.isEmpty() << std::endl;
    std::cout << q.isFull() << std::endl;
    std::cout << q.getFront() << std::endl;
    std::cout << q.getRear() << std::endl;
    std::cout << q.size() << std::endl;

    std::cout << "-----" << std::endl;
    q.dequeue();
    std::cout << q.isEmpty() << std::endl;
    std::cout << q.isFull() << std::endl;
    std::cout << q.getFront() << std::endl;
    std::cout << q.getRear() << std::endl;
    std::cout << q.size() << std::endl;

    std::cout << "-----" << std::endl;
    q.dequeue();
    std::cout << q.isEmpty() << std::endl;
    std::cout << q.isFull() << std::endl;
    std::cout << q.getFront() << std::endl;
    std::cout << q.getRear() << std::endl;
    std::cout << q.size() << std::endl;

    std::cout << "-----" << std::endl;
    q.enqueue(100);
    std::cout << q.isEmpty() << std::endl;
    std::cout << q.isFull() << std::endl;
    std::cout << q.getFront() << std::endl;
    std::cout << q.getRear() << std::endl;
    std::cout << q.size() << std::endl;

    std::cout << "-----" << std::endl;
    q.enqueue(200);
    std::cout << q.isEmpty() << std::endl;
    std::cout << q.isFull() << std::endl;
    std::cout << q.getFront() << std::endl;
    std::cout << q.getRear() << std::endl;
    std::cout << q.size() << std::endl;
    return 0;
}
