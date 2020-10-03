#include <iostream>
#include <string>

void naivePatternSearching(std::string txt, std::string pat);

int main() {
    naivePatternSearching("ABABABCD", "ABAB");
    naivePatternSearching("ABCD", "CE");
    naivePatternSearching("AAAAA", "AAA");
    naivePatternSearching("geeksforgeeks", "eks");
    return 0;
}

void naivePatternSearching(std::string txt, std::string pat) {
    int yes = false;
    for (int i = 0; i < txt.length() - pat.length()+1; i++) {
        int flag = true;
        for (int j = 0; j < pat.length(); j++) {
            if (pat[j] != txt[i + j]) {
                flag = false;
                break;
            }
        }
        if (flag == true) {
            yes = true;
            std::cout << i << " ";
        }
    }
    if (yes == false) {
        std::cout << -1;
    }
    std::cout << std::endl;
}