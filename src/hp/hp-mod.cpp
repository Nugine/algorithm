#include <cstring>
#include <iostream>
using namespace std;
typedef unsigned long long num;

num hp_mod(const char *a, num mod) {
    register int i, l = strlen(a);
    num r = 0;
    for (i = 0; i < l; ++i) {
        r = (r * 10 + (a[i] - '0')) % mod;
    }
    return r;
}

int main() {
    string a;
    num m;
    while (cin >> a >> m) {
        cout << hp_mod(a.c_str(), m) << endl;
    }
    return 0;
}
