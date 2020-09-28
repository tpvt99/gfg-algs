#include <iostream>
#include <string>
#include <unordered_map>

int leftMostRepeatingCharacter(std::string str);
int usingHashMap(std::string str);
int betterMethodHashMap(std::string str);

int main() {
    using std::string;
    string str1 = "geeksforgeeks";
    std::cout << leftMostRepeatingCharacter(str1) << std::endl;
    string str2 = "abbcc";
    std::cout << leftMostRepeatingCharacter(str2) << std::endl;
    string str3 = "abcd";
    std::cout << leftMostRepeatingCharacter(str3) << std::endl;
    std::cout << "Using Hash Map" << std::endl;
    std::cout << usingHashMap(str1) << std::endl;
    std::cout << usingHashMap(str2) << std::endl;
    std::cout << usingHashMap(str3) << std::endl;
    std::cout << "Using better hash map" << std::endl;
    std::cout << betterMethodHashMap(str1) << std::endl;
    std::cout << betterMethodHashMap(str2) << std::endl;
    std::cout << betterMethodHashMap(str3) << std::endl;
    return 0;
}

int leftMostRepeatingCharacter(std::string str) {
    int temp[26] = {0};
    for (auto c : str) {
        temp[c - 'a']++;
    }
    for (int i = 0; i < str.length(); i++) {
        if (temp[str[i] - 'a'] >= 2) {
            return i;
        }
    }
    return -1;
}

int usingHashMap(std::string str) {
    using std::unordered_map;
    unordered_map<int, int> m;

    for (auto c : str) {
        m[c - 'a']++;
    }

    for (int i = 0; i < str.length(); i++) {
        auto it = m.find(str[i] - 'a');
        if (it != m.end()) {
            if (it->second >= 2) {
                return i;
            }
        }
    }
    return -1;
}

int betterMethodHashMap(std::string str) {
    using std::unordered_map;
    unordered_map<int, int> m;
    int firstIndex = str.length();
    for (int i = 0; i < str.length(); i++) {
        auto it = m.find(str[i]);
        if (it != m.end()) {
            firstIndex = std::min(firstIndex, it->second);
        } else {
            m.insert({str[i],i });
        }
    }
    return firstIndex == str.length() ? -1 : firstIndex;
}