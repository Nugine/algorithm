#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
#define asc(i, s, e) for (i = (s); i <= (e); ++i)
#define rng(i, s, e) for (i = (s); i < (e); ++i)
#define desc(i, s, e) for (i = (s); i >= (e); --i)
#define ordefault(a, b) (a) ? (a) : (b)
// #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define eprintf(...)

const int MOD = 1e8 + 7;
const int N = 1e5 + 7;

int x[N];
int n;

int f[3];
int g[3];

int solve() {
    int i, c;

    f[2] = int(x[1] == 2);
    f[1] = 0;
    f[0] = 0;
    asc(c, 0, 2) { g[c] = f[c]; }

    asc(i, 2, n) {
        f[2] = (x[i] == 2) ? (1 + g[2]) % MOD : (0);
        f[1] = (x[i] == 1) ? (g[2] + g[1]) % MOD : (0);
        f[0] = (x[i] == 0) ? (g[1] + g[0]) % MOD : (0);
        asc(c, 0, 2) { g[c] = (g[c] + f[c]) % MOD; }
    }

    return g[0];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    n = 0;
    int t;
    while (cin >> t) {
        x[++n] = t;
    }

    eprintf("n = %d\n", n);

    int ans = solve();
    cout << ans << endl;
}
