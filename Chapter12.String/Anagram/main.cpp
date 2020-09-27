#include <iostream>
#include <string>

bool isAnagram(std::string s1, std::string s2);

int main() {
    std::string s1 = "listen";
    std::string s2 = "silent";
    isAnagram(s1, s2);
    s1 = "aab";
    s2 = "bab";
    isAnagram(s1, s2);
    return 0;
}


bool isAnagram(std::string s1, std::string s2) {
    if (s1.length() != s2.length()) {
        std::cout << "Two string have different length. Could"
        "not be anagram.\n";
        return false;
    }

    int temp[26] = {0};
    for (auto i: s1) {
        temp[i - 'a'] += 1;
    }
    for (auto i: s2) {
        temp[i - 'a'] -= 1;
    }
    for (auto i : temp) {
        if (i != 0) {
            std::cout << "Two strings are not anagram.\n";
            return false;
        }
    }
    std::cout << "Two strings are anagram.\n";
    return true;
}