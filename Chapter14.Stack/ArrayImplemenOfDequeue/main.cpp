#include <iostream>

class Dequeue {
private:
    int *arr;
    int cap;
    int currentSize;
    int front;
    int rear;
public:
    Dequeue(int capacity) {
        arr = new int[capacity];
        cap = capacity;
        currentSize = 0;
        front = -1;
        rear = -1;
    }

    void insertFront(int x) {
        if (isFull()) {
            std::cout << "Dequeue overflow." << std::endl;
            return;
        }
        if (currentSize == 0) {
            front = 0;
            rear = 0;
            arr[front] = x;
            currentSize++;
            return;
        }
        front -= 1;
        if (front == -1)
            front = cap-1;
        arr[front] = x;
        currentSize++;
    }

    void insertRear(int x) {
        if (isFull()) {
            std::cout << "Dequeue overflow." << std::endl;
            return;
        }
        if (currentSize == 0) {
            front = 0;
            rear = 0;
            arr[front] = x;
            currentSize++;
            return;
        }
        rear = (rear + 1) % cap;
        arr[rear] = x;
        currentSize++;
    }

    void deleteFront() {
        if (isEmpty()) {
            std::cout << "Dequeue underflow.\n";
            return;
        }
        front = (front+1) % cap;
        currentSize--;
    }

    void deleteRear() {
        if (isEmpty()) {
            std::cout << "Dequeue underflow.\n";
            return;
        }
        rear--;
        if (rear == -1)
            rear = cap-1;
        currentSize--;
    }

    int getFront() {
        if (isEmpty()) {
            std::cout << "Dequeue underflow.\n";
            return -1;
        }
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) {
            std::cout << "Dequeue underflow.\n";
            return -1;
        }
        return arr[rear];
    }

    bool isFull() {
        return currentSize == cap;
    }

    bool isEmpty() {
        return currentSize == 0;
    }

    int size() {
        return currentSize;
    }
};

int main() {
    Dequeue dq(3);
    std::cout << dq.isEmpty() << std::endl;
    std::cout << dq.isFull() << std::endl;
    std::cout << dq.size() << std::endl;
    std::cout << dq.getFront() << std::endl;
    std::cout << dq.getRear() << std::endl;
    std::cout << "----" << std::endl;

    dq.insertFront(10);
    std::cout << dq.isEmpty() << std::endl;
    std::cout << dq.isFull() << std::endl;
    std::cout << dq.size() << std::endl;
    std::cout << dq.getFront() << std::endl;
    std::cout << dq.getRear() << std::endl;
    std::cout << "----" << std::endl;

    dq.insertFront(20);
    std::cout << dq.isEmpty() << std::endl;
    std::cout << dq.isFull() << std::endl;
    std::cout << dq.size() << std::endl;
    std::cout << dq.getFront() << std::endl;
    std::cout << dq.getRear() << std::endl;
    std::cout << "----" << std::endl;

    dq.insertFront(30);
    std::cout << dq.isEmpty() << std::endl;
    std::cout << dq.isFull() << std::endl;
    std::cout << dq.size() << std::endl;
    std::cout << dq.getFront() << std::endl;
    std::cout << dq.getRear() << std::endl;
    std::cout << "----" << std::endl;

    dq.deleteRear();
    std::cout << dq.isEmpty() << std::endl;
    std::cout << dq.isFull() << std::endl;
    std::cout << dq.size() << std::endl;
    std::cout << dq.getFront() << std::endl;
    std::cout << dq.getRear() << std::endl;
    std::cout << "----" << std::endl;

    dq.deleteFront();
    std::cout << dq.isEmpty() << std::endl;
    std::cout << dq.isFull() << std::endl;
    std::cout << dq.size() << std::endl;
    std::cout << dq.getFront() << std::endl;
    std::cout << dq.getRear() << std::endl;
    std::cout << "----" << std::endl;

    dq.deleteFront();
    std::cout << dq.isEmpty() << std::endl;
    std::cout << dq.isFull() << std::endl;
    std::cout << dq.size() << std::endl;
    std::cout << dq.getFront() << std::endl;
    std::cout << dq.getRear() << std::endl;
    std::cout << "----" << std::endl;

    dq.insertRear(30);
    std::cout << dq.isEmpty() << std::endl;
    std::cout << dq.isFull() << std::endl;
    std::cout << dq.size() << std::endl;
    std::cout << dq.getFront() << std::endl;
    std::cout << dq.getRear() << std::endl;
    std::cout << "----" << std::endl;

}
