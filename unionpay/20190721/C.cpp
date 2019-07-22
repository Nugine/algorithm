#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))
#define desc(i, s, e) for ((i) = (s); (i) >= (e); --(i))
#define rng(i, s, e) for ((i) = (s); (i) < (e); ++(i))

const int M = 998244353;

ll qpow(ll b, ll p, ll m) {
    ll r = 1;
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
    int n;
    scanf("%d", &n);

    if (n == 2) {
        printf("2\n");
        return 0;
    }

    if (n == 3) {
        printf("6\n");
        return 0;
    }

    ll s = qpow(n - 1, n - 2, M);
    s = (s * n) % M;

    cout << s << endl;
    return 0;
}