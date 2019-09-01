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
    ll t = ((n - 1) * 2 - (k - 2) * 2) * (k - 1) * 2;
    ll h = n - (k - 1) * 2;
    if (k == i) {
        return t + j - k + 1;
    }
    t += h;
    if (k == n + 1 - j) {
        return t + i - k;
    }
    t += h;
    if (k == n + 1 - i) {
        return t + n - k - j;
    }
    t += h;
    return t + n - k - i - 1;
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

struct Point {
    int x, y;
    int tp;
    int ask_idx;
};

void solve() {
    int n, m, p;
    rd3(n, m, p);

    int i;

    static Point points[500000 + 7];
    int len = 0;

    asc(i, 1, m) {
        int x, y;
        rd2(x, y);
        points[++len] = Point{x, y, 0, 0};
    }

    static int ask[100000 + 3];
    asc(i, 1, p) {
        int lx, ly, ux, uy;
        rd4(lx, ly, ux, uy);

        ask[i] = 0;
        points[++len] = Point{lx - 1, ly - 1, 1, i};
        points[++len] = Point{ux, ly - 1, -1, i};
        points[++len] = Point{lx - 1, uy, -1, i};
        points[++len] = Point{ux, uy, 1, i};
    }

    sort(points + 1, points + len + 1, [](const Point &lhs, const Point &rhs) {
        if (lhs.y != rhs.y) {
            return lhs.y < rhs.y;
        }
        if (lhs.x != rhs.x) {
            return lhs.x < rhs.x;
        }
        return lhs.tp == 0;
    });

    static int bitree[1000000 + 7];
    std::memset(bitree, 0, sizeof(int) * (n + 3));

    asc(i, 1, len) {
        auto &pt = points[i];
        if (pt.tp == 0) {
            int now_bval = bval(n, pt.x, pt.y);
            bitree::add(bitree, pt.x, now_bval, n);
        } else {
            int res = bitree::query_prefix_sum(bitree, pt.x);
#ifdef DEBUG
            printf("s(%d, %d) = %d\n", pt.x, pt.y, res);
#endif
            ask[pt.ask_idx] += pt.tp * res;
        }
    }

    asc(i, 1, p) { pdln(ask[i]); }
}