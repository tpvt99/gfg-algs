#include <bits/stdc++.h>

using namespace std;

#define ll long long


ll binexp_recursive(ll a, ll b) {
    // Calculate a^b
    if (b == 0)
        return 1;
    ll result = binexp_recursive(a, b/2);
    if (b % 2 == 0) { // If even number 
        std::cout << "Returning even at b: " << b << " result: "<< result*result << std::endl; 
        return result * result; // a^7 = a^3 * a^3
    }
    else {
        std::cout << "Returning odd at b: " << b << " result: "<< result*result*a << std::endl; 
        return result * result * a; // a^6 = a^3 * a^3
    }
}

ll binexp_iterative(ll a, ll b) {
    ll result = 1;
    ll temp = a;
    while (b) {
        if (b&1)
            result = result * temp;
        temp = temp*temp;
        std::cout << "Last bit of b: " << (b&1) << " result: " << result << endl;
        b = b >> 1;
    }

    return result;
}

int main() {

    ll a = 2;
    ll b = 13;
    ll re1 = binexp_iterative(a,b);
    ll re2 = binexp_recursive(a,b);
    std::cout << "Binary iterative: " << re1 << " recursive: " << re2 << endl;

    a = 3, b = 14;
    re1 = binexp_iterative(a,b);
    re2 = binexp_recursive(a,b);
    std::cout << "Binary iterative: " << re1 << " recursive: " << re2 << endl;

    a = 3, b = 1;
    re1 = binexp_iterative(a,b);
    re2 = binexp_recursive(a,b);
    std::cout << "Binary iterative: " << re1 << " recursive: " << re2 << endl;
}