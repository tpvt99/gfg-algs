#include <iostream>
#include <string>

void improvedNaiveSearch(std::string txt, std::string pat);

int main() {
    improvedNaiveSearch("abcabcdabcd", "abcd");
    improvedNaiveSearch("abcaaad", "abd");
    improvedNaiveSearch("aaaaa", "aaa");
    return 0;
}

void improvedNaiveSearch(std::string txt, std::string pat) {
    bool flag= false;
    for (int i =0; i<= txt.length()-pat.length();) {
        int j;
        for (j = 0; j < pat.length(); j++) {
            if (pat[j] != txt[i+j]) {
                break;
            }
        }
        if (j == pat.length()) {
            std::cout << i << " ";
            flag = true;
        }
        i = (j == 0) ? i + 1: i + j;
    }
    if (!flag) {
        std::cout << -1;
    }
    std::cout << std::endl;
}
