//! https://www.luogu.com.cn/problem/P5431

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

inline ll qread(void) {
    ll x = 0, flag = 1;
    char c;
    for (;;) {
        c = getchar_unlocked();
        if (c == '-') {
            flag = -1;
            break;
        }
        if (c >= '0' && c <= '9') {
            break;
        }
    }
    for (;;) {
        x = x * 10 + (c ^ '0');
        c = getchar_unlocked();
        if (c >= '0' && c <= '9') {
            continue;
        }
        return x * flag;
    }
}

inline ll qpow(ll b, ll p, ll m) {
    ll r = 1;
    while (p) {
        if (p & 1) {
            r = r * b % m;
        }
        b = b * b % m;
        p >>= 1;
    }
    return r;
}

/// `m` must be a prime
inline ll inverse_fermat(ll n, ll m) {
    ll ans = qpow(n, m - 2, m);
    return ans;
}

struct Sol {
    ll a[int(5e6 + 7)];
    ll prefix_product[int(5e6 + 7)];
    ll suffix_product[int(5e6 + 7)];

    void run() {
        ll n, p, k;
        n = qread();
        p = qread();
        k = qread();

        int i;
        asc(i, 1, n) { a[i] = qread(); }

        prefix_product[0] = 1;
        asc(i, 1, n) { prefix_product[i] = prefix_product[i - 1] * a[i] % p; }

        suffix_product[n + 1] = 1;
        desc(i, n, 1) { suffix_product[i] = suffix_product[i + 1] * a[i] % p; }

        ll ki = k;
        ll num = 0;
        asc(i, 1, n) {
            ll t = prefix_product[i - 1] * suffix_product[i + 1] % p;
            num = (num + ki * t % p) % p;
            ki = ki * k % p;
        }
        ll ans = num * inverse_fermat(prefix_product[n], p) % p;
        cout << ans << '\n';
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
