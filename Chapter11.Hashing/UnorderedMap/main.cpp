#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, int> m;
    m["gfg"] = 20;
    m["course"] = 10;
    m.insert({"ide", 12});
    auto it = m.find("ide"); // find returns iterations
    auto s = m.count("gfg");
    m.erase("course");
    std::cout << "size: " << m.size() << std::endl;
    if (it != m.end()) {
        std::cout << "Found with value: " << it->second << std::endl;
    } else {
        std::cout << "Not Found\n";
    }
    for (auto x : m) {
        std::cout << x.first << " " << x.second << std::endl;
    }
    std::cout << std::endl;
    for (auto it = m.begin(); it != m.end(); it++) {
        std::cout << it->first << " " << it->second << std::endl;
    }
    return 0;
}
