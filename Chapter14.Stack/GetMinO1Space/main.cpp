#include <iostream>

class MyStack {
private:
    int *arr;
    int minElement;
    int capacity;
    int top;
public:
    MyStack(int maxCap) {
        arr = new int[maxCap];
        minElement = 0;
        capacity = maxCap;
        top = 0;
    }

    void push(int x) {
        if (top == capacity) {
            std::cout << "Stack Overflow.\n";
            return;
        }

        if (top == 0) {
            minElement = x;
            arr[top++] = x;
        }
        else {
            if (x > minElement) {
                arr[top++] = x;
            } else {
                arr[top++] = x - minElement;
                minElement = x;
            }
        }
    }

    int pop() {
        if (top == 0) {
            std::cout << "Stack Underflow.\n";
            return -1;
        }
        if (arr[top-1] > 0)
            return arr[--top];

        int prevMin = minElement;
        minElement = minElement - arr[top-1];
        top--;
        return prevMin;

    }

    int getMin() {
        if (top == 0) {
            std::cout << "Stack Underflow.\n";
            return -1;
        }

        return minElement;
    }
};

int main() {
    MyStack stack(10);
    stack.push(10);
    std::cout << stack.getMin() << std::endl;
    stack.push(10);
    std::cout << stack.getMin() << std::endl;
    stack.push(20);
    std::cout << stack.getMin() << std::endl;
    stack.push(7);
    std::cout << stack.getMin() << std::endl;
    stack.push(6);
    std::cout << stack.getMin() << std::endl;
    stack.push(4);
    std::cout << stack.getMin() << std::endl;
    stack.pop();
    std::cout << stack.getMin() << std::endl;
    stack.pop();
    std::cout << stack.getMin() << std::endl;
    stack.pop();
    std::cout << stack.getMin() << std::endl;
    stack.push(2);
    std::cout << stack.getMin() << std::endl;
    stack.pop();
    std::cout << stack.getMin() << std::endl;
    stack.push(1);
    std::cout << stack.getMin() << std::endl;
    stack.pop();
    std::cout << stack.getMin() << std::endl;
    stack.pop();
    std::cout << stack.getMin() << std::endl;

    return 0;
}
