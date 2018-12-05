#include <iostream>
using namespace std;

typedef long long i64;

i64 gcd(i64 a, i64 b) {
    register i64 t = a % b;
    while (t) {
        a = b;
        b = t;
        t = a % b;
    }
    return b;
}

int main() {
    i64 a, b;
    while (cin >> a >> b) {
        cout << gcd(a, b) << endl;
    }
    return 0;
}