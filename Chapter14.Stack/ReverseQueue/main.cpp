#include <iostream>
#include <stack>
#include <queue>

void reverseQueue(std::queue<int> &q);
std::queue<int> reverseQueueRecursive(std::queue<int> &q);
void printQueue(std::queue<int> q);

int main() {
    std::queue<int> x;
    x.push(10);
    x.push(20);
    x.push(30);
    x.push(40);
    std::cout << "Before reverse: " << std::endl;
    printQueue(x);
    std::queue<int> newq = reverseQueueRecursive(x);
    std::cout << "After reverse: " << std::endl;
    printQueue(newq);
    return 0;
}

void reverseQueue(std::queue<int> &q) {
    std::stack<int> m;
    while (! q.empty()) {
        m.push(q.front());
        q.pop();
    }
    while (! m.empty()) {
        q.push(m.top());
        m.pop();
    }
}

std::queue<int> reverseQueueRecursive(std::queue<int> &q) {
    if (! q.empty()) {
        int x = q.front();
        q.pop();
        std::queue<int> newq = reverseQueueRecursive(q);
        newq.push(x);
        return newq;
    } else {
        std::queue<int> z;
        return z;
    }
}

void printQueue(std::queue<int> q) {
    while (! q.empty()) {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << "\n";
}