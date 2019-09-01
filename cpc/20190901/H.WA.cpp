#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
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

void solve();
int main() {
    int T;
    rd(T);
    while (T--) {
        solve();
    }
}

ll weight[300 + 3][300 + 3];

void solve() {
    int n, m;
    rd2(n, m);
    int i, j, k;
    rng(i, 0, n) {
        rng(j, 0, n) { weight[i][j] = (1LL << 60); }
    }

    asc(i, 1, m) {
        int x, y, w;
        rd3(x, y, w);
        weight[x][y] = w;
    }

    rng(k, 0, n) {
        rng(i, 0, n) {
            rng(j, 0, n) {
                ll nw = weight[i][k] + weight[k][j];
                ll w = weight[i][j];
                if (nw < w) {
                    weight[i][j] = nw;
                    // cout << "update " << i << ' ' << j << ' ' << nw << endl;
                }
            }
        }
    }

    int e;
    asc(e, 1, 6) {
        int s, t;
        rd2(s, t);

        ll w = weight[t][s];
        ll ans = -w;
        cout << ans << endl;

        weight[s][t] = min(weight[s][t], ans);

        rng(i, 0, n) {
            rng(j, 0, n) {
                ll nw = weight[i][s] + weight[s][t] + weight[t][j];
                ll w = weight[i][j];
                if (nw < w) {
                    weight[i][j] = nw;
                }
            }
        }
    }
}
