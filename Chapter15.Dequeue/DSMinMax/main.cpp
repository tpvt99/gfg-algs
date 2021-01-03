#include <iostream>
#include <deque>

class DSMinMax{
private:
    std::deque<int> dq;
public:
    void insertMin(int x) {
        if (dq.empty()) {
            dq.push_front(x);
        }
        if (x < dq.front())
            dq.push_front(x);
    }

    void insertMax(int x) {
        if (dq.empty()) {
            dq.push_back(x);
        }
        if (x > dq.back())
            dq.push_back(x);
    }

    int getMin() {
        if (! dq.empty())
            return dq.front();
        return -1;
    }

    int getMax() {
        if (!dq.empty())
            return dq.back();
        return -1;
    }

    void extractMin() {
        if (!dq.empty())
            dq.pop_front();
    }

    void extractMax() {
        if (!dq.empty())
            dq.pop_back();
    }
};

int main() {
    DSMinMax dq;
    dq.insertMin(5);
    dq.insertMax(10);
    dq.insertMin(6);
    dq.insertMax(12);
    std::cout << dq.getMin() << std::endl;
    std::cout << dq.getMax() << std::endl;
    dq.insertMin(2);
    dq.insertMax(15);
    std::cout << dq.getMin() << std::endl;
    std::cout << dq.getMax() << std::endl;
    dq.extractMax();
    dq.extractMin();
    std::cout << dq.getMin() << std::endl;
    std::cout << dq.getMax() << std::endl;
    return 0;
}
