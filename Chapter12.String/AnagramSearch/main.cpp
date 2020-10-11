#include <iostream>
#include <string>

void anagramSearch(std::string txt, std::string pat);

int main() {
    anagramSearch("geeksforgeeks", "frog");
    anagramSearch("geeksforgeeks", "rseek");
    return 0;
}

void anagramSearch(std::string txt, std::string pat) {
    int sumPattern = 0;
    for (int i =0 ; i < pat.length(); i++) {
        sumPattern += static_cast<int>(pat[i]);
    }

    int flag = 0;
    int sumText = 0;
    for (int i = 0; i < pat.length(); i++) {
        sumText += txt[i];
    }

    for (int i = pat.length()-1; i < txt.length(); i++) {

        if (i >= pat.length())
            sumText = sumText - txt[i- pat.length()] + txt[i];

        if (sumText == sumPattern) {
            std::cout << i << " ";
            flag = 1;
        }

    }

    if (flag == 0)
        std::cout << -1 << " ";
    std::cout << std::endl;

}
