#include <iostream>

using namespace std;

int rod_cutting(int length, int a, int b, int c);
int rod_cutting_v2(int length, int a, int b, int c);

int main()
{
    int x = rod_cutting_v2(23, 11, 9, 12);
    cout << x;
    return 0;
}

int rod_cutting_v2(int length, int a, int b, int c) {
    if (length < 0)
        return -1;
    else if (length == 0)
        return 0;
    int cut_a = rod_cutting_v2(length-a, a, b, c);
    int cut_b = rod_cutting_v2(length-b, a, b, c);
    int cut_c = rod_cutting_v2(length-c, a, b, c);
    int max_number = cut_a;
    if (cut_b > max_number)
        max_number = cut_b;
    if (cut_c > max_number)
        max_number = cut_c;
    if (max_number >= 0)
        return max_number+1;
    return max_number;
}

int rod_cutting(int length, int a, int b, int c) { // a< b < c
    int x = 0;
    if (length == 0)
        return 0;
    else if (length >= a) {
        x = rod_cutting(length-a, a, b, c);
        if (x == -1) {
            if(length >= b) {
                x = rod_cutting(length - b, a, b ,c);
                if (x==-1) {
                    if (length >= c) {
                        x = rod_cutting(length -c, a, b, c);
                        if (x==-1)
                            return -1;
                        else
                            return x+1;
                    } else
                        return -1;
                } else
                    return x+1;
            } else
                return -1;
        }
        else
            return 1 + x;
    }
    else
        return -1;
}
