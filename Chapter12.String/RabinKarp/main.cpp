#include <iostream>
#include <assert.h>
#include <cmath>

void rabinKarp(std::string txt, std::string pat, int d, int q);

int main() {
    rabinKarp("abcdbabcda", "abc", 3, 5000);
    rabinKarp("abcdbabcda", "dd", 3, 5000);
    return 0;
}

void rabinKarp(std::string txt, std::string pat, int d, int q) {
    // Calculating d^(m-1) for rolling hash
    int h = 1;
    for (int i = 1; i < pat.length(); i++) {
        h = (h * d)%q;
    }

//assert(h == static_cast<int>(pow(d, pat.length()-1)));

    // Calculating hash value of pat and 1st window of txt
    int t = txt[0];
    int p = pat[0];
    for (int i = 1; i < pat.length(); i++) {
        t = (t * d + txt[i]) % q;
        p = (p * d + pat[i]) % q;
    }

    // Compare
    bool yes = false;
    for (int i = 0; i <= txt.length() - pat.length();i++) {
        if (t == p) {
            bool flag = true;
            for (int j = 0; j < pat.length(); j++) {
                if (txt[i+j] != pat[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                yes = true;
                std::cout << i << " ";
            }
        }
        if (i < txt.length() - pat.length()) {
            t = (d * (t - txt[i] * h) + txt[i+pat.length()]) % q;
        }
    }
    if (!yes) {
        std::cout << -1;
    }
    std::cout << std::endl;
}
