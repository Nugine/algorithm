#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long long u64;
#define rd(x) scanf("%d", &(x))
#define rd2(x, y) scanf("%d %d", &(x), &(y))
#define rd3(x, y, z) scanf("%d %d %d", &(x), &(y), &(z))
#define rd4(w, x, y, z) scanf("%d %d %d %d", &(w), &(x), &(y), &(z))
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))
#define rng(i, s, e) for ((i) = (s); (i) < (e); ++(i))
#define desc(i, s, e) for ((i) = (s); (i) >= (e); --(i))
#define pd(x) printf("%d", (x))
#define pdsp(x) printf("%d ", (x))
#define sppd(x) printf(" %d", (x))
#define pdln(x) printf("%d\n", (x))

// #define DEBUG

void solve();
int main() {
#ifdef DEBUG
    freopen("in", "r", stdin);
#endif
    int T;
    rd(T);
    while (T--) {
        solve();
    }
}

inline ll min4(ll a, ll b, ll c, ll d) {
    ll m = a;
    if (b < m)
        m = b;
    if (c < m)
        m = c;
    if (d < m)
        m = d;
    return m;
}

ll f(ll n, ll x, ll y) {
    ll i = n - x + 1, j = n - y + 1;
    ll k = min4(i, j, n + 1 - i, n + 1 - j);
    ll ans = ((n - 1) * 2 - (k - 2) * 2) * (k - 1) * 2;
    if (k == i) {
        ans = ans + j - k + 1;
    } else {
        ans = ans + n - (k - 1) * 2;
        if (k == n + 1 - j) {
            ans = ans + i - k;
        } else {
            ans = ans + n - (k - 1) * 2;
            if (k == n + 1 - i) {
                ans = ans + n - k - j;
            } else {
                ans = ans + n - (k - 1) * 2;
                ans = ans + n - k - i - 1;
            }
        }
    }
    return ans;
}

int bval(ll n, ll x, ll y) {
    int ans = 0;
    ll val = f(n, x, y);
    while (val) {
        ans += val % 10;
        val /= 10;
    }
    return ans;
}

namespace bitree {
inline int lowbit(const int x) { return x & (-x); }
void add(int a[], int x, int d, int n) {
    for (int i = x; i <= n; i += lowbit(i)) {
        a[i] += d;
    }
}
int query_prefix_sum(int a[], int x) {
    int ans = 0;
    for (int i = x; i != 0; i -= lowbit(i)) {
        ans += a[i];
    }
    return ans;
}
} // namespace bitree

void solve() {
    int n, m, p;
    rd3(n, m, p);

    int i;

    map<int, vector<int>> palaces;
    asc(i, 1, m) {
        int x, y;
        rd2(x, y);
        palaces[y].push_back(x);
    }

    map<int, map<int, int>> queries;
    static int ask[100000 + 3][4];
    asc(i, 1, p) {
        int lx, ly, ux, uy;
        rd4(lx, ly, ux, uy);
        int *a = ask[i];
        a[0] = lx, a[1] = ly, a[2] = ux, a[3] = uy;
        queries[ly - 1][lx - 1] = 0;
        queries[ly - 1][ux] = 0;
        queries[uy][lx - 1] = 0;
        queries[uy][ux] = 0;
    }

    static int bitree[1000000 + 7];
    memset(bitree, 0, sizeof(int) * (n + 3));

    for (auto &row_pr : palaces) {
        auto &row = row_pr.second;
        int y = row_pr.first;

        for (int x : row) {
            int now_bval = bval(n, x, y);
            bitree::add(bitree, x, now_bval, n);
        }

        if (queries.count(y)) {
            for (auto &pr : queries[y]) {
                int x = pr.first;
                pr.second = bitree::query_prefix_sum(bitree, x);
            }
        }
    }

    asc(i, 1, p) {
        int *a = ask[i];
        int lx, ly, ux, uy;
        lx = a[0], ly = a[1], ux = a[2], uy = a[3];

        int ans = queries[uy][ux];
        ans -= queries[uy][lx - 1];
        ans -= queries[ly - 1][ux];
        ans += queries[ly - 1][lx - 1];

        cout << ans << endl;
    }
}