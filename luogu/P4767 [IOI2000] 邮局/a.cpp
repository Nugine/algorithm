/*
[IOI2000] 邮局

f(i, j): i 个邮局放在前 j 个村庄的最优总距离,       where 1<=i<=P, 1<=j<=V, i<=j
w(l, r): 1 个邮局放在区间 [l,r] 的村庄的最优总距离  where 1<=l<=r<=V
ans = f(P, V)

s(j): x 前缀和

w(l, r) = sum{ abs(x[j]-x[d]) for j in [l,r] },             where d=(l+r)//2
        = s(r) - s(d-1) - s(d) + s(l-1) + (2d-l-r)*x[d]

f(1, j) = w(1, j)
f(i, j) = 0,    where i==j
f(i, j) = min{ f(i-1, k) + w(k+1, j) for k in [i-1, j-1] }

四边形不等式优化

p(i, j): f(i, j) 的决策函数

p(i, j) = i-1,    where i==j
p(i, j-1) <= p(i, j) <= p(i+1, j),      where 1<=i<P, 2<=j<=V, i<=j

*/

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
const int MAXV = 3000 + 7;
const int MAXP = 300 + 7;

int V, P;
int x[MAXV];

int s[MAXV];
int p[MAXP][MAXV];
int f[MAXP][MAXV];

int w(int l, int r) {
    int d = (l + r) / 2;
    return s[r] - s[d - 1] - s[d] + s[l - 1] + (2 * d - l - r) * x[d];
}

int solve() {
    int i, j, k;

    sort(x + 1, x + V + 1);
    asc(j, 1, V) { s[j] = s[j - 1] + x[j]; }

    asc(j, 1, V) { f[1][j] = w(1, j); }

    asc(j, 1, V) {
        desc(i, P, 2) {
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

    return f[P][V];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> V >> P;
    int i;
    asc(i, 1, V) { cin >> x[i]; }

    int ans = solve();
    cout << ans << endl;
}
