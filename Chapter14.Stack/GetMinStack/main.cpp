#include <iostream>

class MyStack {
private:
    int *arr;
    int *minArr;
    int capacity;
    int top;
public:
    MyStack(int maxCap) {
        arr = new int[maxCap];
        minArr = new int[maxCap];
        capacity = maxCap;
        top = 0;
    }

    void push(int x) {
        if (top == capacity) {
            std::cout << "Stack Overflow.\n";
            return;
        }
        arr[top]=x;
        if (top == 0)
            minArr[top]=x;
        else
            if (x < minArr[top-1])
                minArr[top] = x;
            else
                minArr[top] = minArr[top-1];
        top++;
    }

    int pop() {
        if (top == 0) {
            std::cout << "Stack Underflow.\n";
            return -1;
        }
        return arr[--top];
    }

    int getMin() {
        if (top == 0) {
            std::cout << "Stack Underflow.\n";
            return -1;
        }

        return minArr[top-1];
    }
};

int main() {
    MyStack stack(10);
    stack.push(5);
    std::cout << stack.getMin() << std::endl;
    stack.push(10);
    std::cout << stack.getMin() << std::endl;
    stack.push(20);
    std::cout << stack.getMin() << std::endl;
    stack.push(2);
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
