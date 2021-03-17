#include <iostream>
#include <set>

int main() {
    std::set<int> s;
    s.insert(20);
    s.insert(5);
    s.insert(10);

    for (auto i : s) {
        std::cout << i << " ";
    }
    std::cout << "\n";
    s.clear();
    for(std::set<int>::iterator it = s.begin(); it != s.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    std::set<int, std::greater<int>> m;
    m.insert(10);
    m.insert(5);
    m.insert(20);

    for (auto i : m) {
        std::cout << i << " ";
    }
    std::cout << "\n";
    for(std::set<int>::iterator it = m.begin(); it != m.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    for(std::set<int>::reverse_iterator it = m.rbegin(); it != m.rend(); it++) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    auto lb = m.lower_bound(6);
    if (lb != m.end()) {
        std::cout << *lb << std::endl;
    }
    return 0;
}
