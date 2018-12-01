#include <iostream>
using namespace std;
typedef unsigned long long num;

num qpow(num b, num p, num m) {
    num r = 1;
    b %= m;
    while (p) {
        if (p & 1) {
            r *= b;
            r %= m;
        }
        b *= b;
        b %= m;
        p >>= 1;
    }
    return r;
}

int main() {
    num b, p, m;
    while (cin >> b >> p >> m) {
        cout << qpow(b, p, m) << endl;
    }
    return 0;
}
