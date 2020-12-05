#include <iostream>

class MyStack {
private:
    int *arr;
    int *next;
    int freetop;
    int *top;
    int capacity;
    int slots;

public:
    MyStack(int size, int k) {
        arr = new int [size];
        next = new int [size];
        freetop = 0;
        top = new int [size];
        capacity = size;
        slots = k;

        for (int i = 0 ; i < k; i++)
            top[i] = -1;
        for (int i = 0; i < size; i++)
            next[i] = i+1;
        next[size-1] = -1;
    }

    void push(int value, int sn) {
        if (isFull()) {
            std::cout << "Stack Full. Cannot add.\n";
            return;
        }
        int i = freetop;
        arr[i] = value;
        freetop = next[i];
        next[i] = top[sn];
        top[sn] = i;
    }

    int pop(int sn) {
        if (isEmpty(sn)) {
            std::cout << "Stack Empty. Cannot pop.\n";
            return -1;
        }
        int i = top[sn];
        top[sn] = next[i];
        next[i] = freetop;
        freetop = i;
        arr[i] = 0; // Make this 0 for visualization only.
        return arr[i];
    }

    void print() {
        for (int i = 0; i < capacity; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    bool isFull() {
        return freetop == -1;
    }

    bool isEmpty(int sn) {
        return top[sn] == -1;
    }
};

int main() {
    MyStack m(6, 3);
    m.print();
    m.push(100, 0);
    m.print();
    m.push(200, 0);
    m.print();
    m.push(300, 0);
    m.print();
    m.push(400, 1);
    m.push(500, 1);
    m.push(600, 1);
    m.print();
    m.pop(0);
    m.pop(1);
    m.pop(0);
    m.print();
    m.push(900, 2);
    m.push(1000, 2);
    m.push(1200, 1);
    m.print();
    return 0;
}
