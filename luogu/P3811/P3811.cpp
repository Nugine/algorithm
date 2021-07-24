//! https://www.luogu.com.cn/problem/P3811

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))
#define rng(i, s, e) for ((i) = (s); (i) < (e); ++(i))
#define desc(i, s, e) for ((i) = (s); (i) >= (e); --(i))
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
// #define eprintf(...)

inline void inverse_linear(ll n, ll m, ll inv[]) {
    inv[1] = 1;
    for (ll i = 2; i <= n; ++i) {
        inv[i] = (m - m / i) * inv[m % i] % m;
    }
}

struct Sol {
    ll inv[int(3e6 + 7)];

    void run() {
        int n, p;
        cin >> n >> p;

        inverse_linear(n, p, inv);

        int i;
        asc(i, 1, n) {
            ll ans = inv[i];
            cout << ans << '\n';
        }
    }
};

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    static Sol sol;
    sol.run();
    return 0;
}
