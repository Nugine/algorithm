#include <cstring>
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

num hp_qpow(num base, const char *power, num mod) {
    num r = 1;
    base %= mod;
    register int t, i = strlen(power) - 1;
    while (i >= 0) {
        t = power[i] - '0';
        if (t) {
            r *= qpow(base, t, mod);
            r %= mod;
        }
        base = qpow(base, 10, mod);
        --i;
    }
    return r;
}

int main() {
    string p;
    num b, m;
    while (cin >> b >> p >> m) {
        cout << hp_qpow(b, p.c_str(), m) << endl;
    }
    return 0;
}