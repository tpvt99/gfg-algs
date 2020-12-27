#include <iostream>

class QueueArray {
private:
    int *arr;
    int front;
    int rear;
    int capacity;
    int currentCap;
public:
    QueueArray(int cap) {
        capacity = cap;
        front = -1;
        rear = -1;
        currentCap = 0;
        arr = new int[cap];
    }

    void enqueue(int x) {
        if (currentCap == 0) {
            front = 0;
            rear = 0;
            currentCap += 1;
            arr[0] = x;
            return;
        }
        if (isFull()) {
            std::cout << "Queue Overflow" << std::endl;
            return ;
        }
        rear = (rear + 1) % capacity;
        currentCap += 1;
        arr[rear] = x;
    }

    int dequeue() {
        if (currentCap == 0) {
            std::cout << "Queue Underflow" << std::endl;
            return -1;
        }
        int re = arr[front];
        front = (front + 1) % capacity;
        currentCap -= 1;
        return re;
    }

    int size() {
        return currentCap;
    }

    int getFront() {
        if (isEmpty()) {
            std::cout << "Empty queue.\n";
            return -1;
        }
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) {
            std::cout << "Empty queue.\n";
            return -1;
        }
        return arr[rear];
    }

    bool isFull() {
        return currentCap == capacity;
    }

    bool isEmpty() {
        return currentCap == 0;
    }
};

int main() {
    QueueArray q(3);
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
