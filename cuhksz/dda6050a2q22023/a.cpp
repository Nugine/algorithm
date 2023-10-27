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

const int INF = 0x3f3f3f3f;
const int N = 1e3 + 7;
const int M = 1e3 + 7;

int n, m;
int x[M];

int s[M];
int p[N][M];
int f[N][M];

int w(int l, int r) {
    int d = (l + r) / 2;
    return s[r] - s[d - 1] - s[d] + s[l - 1] + (2 * d - l - r) * x[d];
}

int solve() {
    int i, j, k;

    sort(x + 1, x + m + 1);
    asc(j, 1, m) { s[j] = s[j - 1] + x[j]; }

    asc(j, 1, m) { f[1][j] = w(1, j); }

    asc(j, 1, m) {
        desc(i, n, 2) {
            if (i == j) {
                f[i][j] = 0;
                p[i][j] = i - 1;
            } else {
                int lb = ordefault(p[i][j - 1], i - 1);
                int ub = ordefault(p[i + 1][j], j - 1);

                f[i][j] = INF;
                asc(k, lb, ub) {
                    int val = f[i - 1][k] + w(k + 1, j);
                    if (val < f[i][j]) {
                        f[i][j] = val;
                        p[i][j] = k;
                    }
                }
            }
        }
    }

    return f[n][m];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    m = 0;
    int t;
    while (cin >> t) {
        x[++m] = t;
    }
    m -= 1;
    n = x[m + 1];
    x[m + 1] = 0;

    eprintf("n = %d, m = %d\n", n, m);

    int ans = solve();
    cout << ans << endl;
}
