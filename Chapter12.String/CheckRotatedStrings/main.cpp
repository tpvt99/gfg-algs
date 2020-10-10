#include <iostream>
#include <string_view>

bool checkRotateString(std::string s1, std::string s2);
void fillLSP(std::string txt, int *arrLSP);
bool KMP(std::string txt, std::string pat);

int main() {
    std::cout << checkRotateString("ABCD", "CDAB") << std::endl;
    std::cout << checkRotateString("ABAAA", "BAAAA") << std::endl;
    std::cout << checkRotateString("ABAB", "ABBA") << std::endl;
    return 0;
}

bool checkRotateString(std::string s1, std::string s2) {
    std::string temp = static_cast<std::string>(s1) + static_cast<std::string>(s2);
    return KMP(temp, s1);
}

bool KMP(std::string txt, std::string pat)  {
    int *arrayLSP = (int *) malloc(sizeof(int) * txt.length());
    fillLSP(txt, arrayLSP);

    int N = txt.length();
    int M = pat.length();
    int i =0; int j = 0;
    while (i < N) {
        if (txt[i] == pat[j]) {
            i++;
            j++;
        }
        if (j == M) {
            j = arrayLSP[j-1];
            return true; // Return immediately, no need to reset j because we return first index
        }
        if (txt[i] != pat[j]) {
            if (j == 0) {
                i++;
            }  else {
                j = arrayLSP[j-1];
            }
        }
    }
    return false;
}

void fillLSP(std::string txt, int *arrLSP) {
    arrLSP[0] = 0;
    int i = 1;
    int len = arrLSP[0];
    while (i < txt.length()) {
        if (txt[i] == txt[len]) {
            i++;
            arrLSP[i] = len+1;
            len++;
        } else {
            if (len == 0) {
                arrLSP[i] = 0;
                i++;
            } else {
                len = arrLSP[len-1];
            }
        }
    }
}