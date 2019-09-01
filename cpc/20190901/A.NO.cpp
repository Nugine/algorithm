#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long long u64;
#define rd(x) scanf("%d", &(x))
#define rd2(x, y) scanf("%d %d", &(x), &(y))
#define rd3(x, y, z) scanf("%d %d %d", &(x), &(y), &(z))
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))
#define rng(i, s, e) for ((i) = (s); (i) < (e); ++(i))
#define desc(i, s, e) for ((i) = (s); (i) >= (e); --(i))
#define pd(x) printf("%d", (x))
#define pdsp(x) printf("%d ", (x))
#define sppd(x) printf(" %d", (x))
#define pdln(x) printf("%d\n", (x))

#define DEBUG

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

int bval(ll val) {
    int ans = 0;
    while (val) {
        ans += val % 10;
        val /= 10;
    }
    return ans;
}

struct Point {
    int x, y;
    bool operator<(const Point rhs) {
        const Point lhs = *this;
        if (lhs.x != rhs.x) {
            return lhs.x < rhs.x;
        } else {
            return lhs.y < rhs.y;
        }
    }
};

int find_y(const map<int, int> &last, int y) {
    auto it = last.lower_bound(y);
    if (it == last.end()) {
        return last.rbegin()->first;
    } else if (it->first == y) {
        return y;
    } else {
        --it;
        return it->first;
    }
}

int fd_x(const map<int, int> &max_y, int x) {
    auto it = max_y.lower_bound(x);
    if (it == max_y.end()) {
        return max_y.rbegin()->first;
    } else if (it->first == x) {
        return x;
    } else {
        --it;
        return it->first;
    }
}

int fd_y(const map<int, int> &max_x, int y) {
    auto it = max_x.lower_bound(y);
    if (it == max_x.end()) {
        return max_x.rbegin()->first;
    } else if (it->first == y) {
        return y;
    } else {
        --it;
        return it->first;
    }
}

void solve() {

    int n, m, p;
    rd3(n, m, p);

    static Point palaces[100000 + 3];
    int i;
    asc(i, 1, m) {
        Point &p = palaces[i];
        rd2(p.x, p.y);
    }
    sort(palaces + 1, palaces + m + 1);

    map<int, int> last; // y -> last_bval
    last[0] = 0;
    int last_x = 0;

    map<int, int> max_x; // y -> maxx
    map<int, int> max_y; // x -> maxy
    max_x[0] = 0;
    max_y[0] = 0;

    map<int, map<int, int>> mat;
    mat[0][0] = 0;

    asc(i, 1, m) {
        const Point &p = palaces[i];
        int now_bval = bval(f(n, p.x, p.y));
        int store = now_bval;
        if (p.x != last_x) {
            int y = find_y(last, p.y);
            store += last[y];
        } else {
            auto it = last.rbegin();
            store += it->second;
        }
        last[p.y] = store;
        mat[p.x][p.y] = store;
        max_x[p.y] = max(max_x[p.y], p.x);
        max_y[p.x] = max(max_y[p.x], p.y);
    }

#ifdef DEBUG
    for (auto &pr : mat) {
        for (auto p : pr.second) {
            printf("(%d,%d) = %d\n", pr.first, p.first, p.second);
        }
    }
#endif

    auto fn_s = [mat, max_x, max_y](int x, int y) {
#ifdef DEBUG
        printf("enter s: (%d,%d)\n", x, y);

#endif

        if (x == 0 || y == 0) {
            return 0;
        }

        for (;;) {
            // x = fd_x(max_y, x);

            y = fd_y(max_x, y);

            if (mat.count(x)) {
                auto &col = mat.at(x);
                if (col.count(y)) {
                    return col.at(y);
                }
            }
#ifdef DEBUG
            printf("%d %d\n", x, y);
            break;
#endif
        }

        throw "unreachable";
    };

    asc(i, 1, p) {
        int lx, ly, ux, uy;
        rd2(lx, ly);
        rd2(ux, uy);

        int ans = fn_s(ux, uy);
#ifdef DEBUG
        cout << ans << endl;

#endif
        ans -= fn_s(ux, ly - 1);
#ifdef DEBUG
        printf("s(%d,%d) %d\n", ux, ly - 1, ans);

#endif
        ans -= fn_s(lx - 1, uy);
#ifdef DEBUG
        printf("s(%d,%d) %d\n", lx - 1, uy, ans);

#endif
        ans += fn_s(lx - 1, ly - 1);
        cout << ans << endl;
#ifdef DEBUG
        cout << endl;

#endif
    }
}