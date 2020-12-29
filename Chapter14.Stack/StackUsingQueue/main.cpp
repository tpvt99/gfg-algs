#include <iostream>
#include <queue>

class Stack {
private:
    std::queue<int> q1;
    std::queue<int> q2;
public:
    int size() {
        return q1.size();
    }

    int top() {
        if (q1.empty()) {
            std::cout << "Stack empty.\n";
            return -1;
        }
        return q1.front();
    }

    void pop() {
        if (q1.empty()) {
            std::cout << "Stack empty.\n";
            return;
        }
        q1.pop();
    }

    bool empty() {
        return q1.empty();
    }

    void push(int x) {
        while (! q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while (! q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }
};

class StackCostlyPop {
private:
    std::queue<int> q1;
    std::queue<int> q2;
public:
    int size() {
        return q1.size();
    }

    int top() {
        if (q1.empty()) {
            std::cout << "Stack empty.\n";
            return -1;
        }
        return q1.back();
    }

    void pop() {
        if (q1.empty()) {
            std::cout << "Stack empty.\n";
            return;
        }
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        while (! q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    bool empty() {
        return q1.empty();
    }

    void push(int x) {
        q1.push(x);
    }
};

int main() {
//    Stack s;
//    std::cout << s.size() << std::endl;
//    std::cout << s.top() << std::endl;
//    std::cout << s.empty() << std::endl;
//    std::cout << "-----" << std::endl;
//
//    s.push(10);
//    std::cout << s.size() << std::endl;
//    std::cout << s.top() << std::endl;
//    std::cout << s.empty() << std::endl;
//    std::cout << "-----" << std::endl;
//
//    s.push(20);
//    std::cout << s.size() << std::endl;
//    std::cout << s.top() << std::endl;
//    std::cout << s.empty() << std::endl;
//    std::cout << "-----" << std::endl;
//
//    s.push(30);
//    std::cout << s.size() << std::endl;
//    std::cout << s.top() << std::endl;
//    std::cout << s.empty() << std::endl;
//
//    s.pop();
//
//    std::cout << "-----" << std::endl;
//    std::cout << s.size() << std::endl;
//    std::cout << s.top() << std::endl;
//    std::cout << s.empty() << std::endl;
//    std::cout << "-----" << std::endl;
//
//    s.push(50);
//    std::cout << s.size() << std::endl;
//    std::cout << s.top() << std::endl;
//    std::cout << s.empty() << std::endl;

    std::cout << "New stack with costly pop" << std::endl;

    StackCostlyPop s;
    std::cout << s.size() << std::endl;
    std::cout << s.top() << std::endl;
    std::cout << s.empty() << std::endl;
    std::cout << "-----" << std::endl;

    s.push(10);
    std::cout << s.size() << std::endl;
    std::cout << s.top() << std::endl;
    std::cout << s.empty() << std::endl;
    std::cout << "-----" << std::endl;

    s.push(20);
    std::cout << s.size() << std::endl;
    std::cout << s.top() << std::endl;
    std::cout << s.empty() << std::endl;
    std::cout << "-----" << std::endl;

    s.push(30);
    std::cout << s.size() << std::endl;
    std::cout << s.top() << std::endl;
    std::cout << s.empty() << std::endl;

    s.pop();

    std::cout << "-----" << std::endl;
    std::cout << s.size() << std::endl;
    std::cout << s.top() << std::endl;
    std::cout << s.empty() << std::endl;
    std::cout << "-----" << std::endl;

    s.push(50);
    std::cout << s.size() << std::endl;
    std::cout << s.top() << std::endl;
    std::cout << s.empty() << std::endl;
    return 0;
}
