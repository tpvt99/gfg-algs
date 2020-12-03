#include <iostream>

class MyStack {
private:
    int *arr;
    int cap;
    int top1;
    int top2;
public:
    MyStack(int size) {
        cap = size;
        top1 = 0;
        top2 = size-1;
        arr = new int[size];
    }

    void push1(int x) {
        if (top1 > top2) {
            std::cout << "Max capacity reach.\n" << std::endl;
            return;
        }
        arr[top1++] = x;
    }
    void push2(int x) {
        if (top2 < top1) {
            std::cout << "Stack Overflow.\n" << std::endl;
            return;
        }
        arr[top2--] = x;
    }

    int attop1() {
        if (top1 == 0) {
            std::cout << "Stack Underflow.\n" << std::endl;
            return -1;
        }
        return arr[top1-1];
    }

    int attop2() {
        if (top2 == cap-1) {
            std::cout << "Stack Underflow.\n" << std::endl;
            return -1;
        }
        return arr[top2+1];
    }

    int pop1() {
        if (top1 == 0) {
            std::cout << "Stack Underflow.\n" << std::endl;
            return -1;
        }
        return arr[--top1];
    }

    int pop2() {
        if (top1 == 0) {
            std::cout << "Stack Underflow.\n" << std::endl;
            return -1;
        }
        return arr[++top2];
    }

};

int main() {
    MyStack m(6);
    m.push1(10);
    m.push1(20);
    m.push1(30);
    m.push1(40);
    m.push1(50);
    m.push2(1000);
    m.push2(2000);
    std::cout << m.attop1() << std::endl;
    std::cout << m.attop2() << std::endl;
    m.pop1();
    std::cout << m.attop1() << std::endl;
    m.push2(2000);
    std::cout << m.attop2() << std::endl;
    return 0;
}
