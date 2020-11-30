#include <iostream>

class MyStack {
public:
    int *values;
    int top;
    int max_size;
    MyStack(int size) {
        max_size = size;
        top = 0;
        values = new int[size];
    }

    void push(int x) {
        if (top == max_size) {
            std::cout << "Stack Overflow. Cannot insert elements." << std::endl;
            return;
        }
        values[top] = x;
        top++;
    }

    int size() {
        return top;
    }

    int peek() {
        if (top == 0) {
            std::cout << "Stack Underflow. Cannot peek elements." << std::endl;
            return -1;
        }
        return values[top-1];
    }

    int pop() {
        if (top == 0) {
            std::cout << "Stack Underflow. Cannot peek elements." << std::endl;
            return -1;
        }
        top--;
        return values[top];
    }

    bool isFull() {
        return top == max_size;
    }
};

int main() {
    MyStack m(10);
    m.push(5);
    m.push(15);
    m.push(25);
    std::cout << m.size() << std::endl;
    std::cout << m.peek() << std::endl;
    std::cout << m.pop() << std::endl;
    m.push(35);
    std::cout << m.peek() << std::endl;
    std::cout << m.isFull() << std::endl;

    return 0;
}
