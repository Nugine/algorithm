#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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

void init();
void solve();
int main() {
    int T;
    rd(T);
    while (T--) {
        init();
        solve();
    }
}

const int M = 998244353;

int n, m;
char s[3000 + 7];
char t[3000 + 7];

void init() {
    rd2(n, m);
    scanf("%s", s);
    scanf("%s", t);
}

int dp[3000 + 7][3000 + 7];

int C(int len, int k);

void solve() {
    int i, j;
    asc(j, 1, m) {
        dp[n - j + 1][j] = 0;
        desc(i, n - j, 0) {
            int tmp;
            if (s[i] > t[m - j]) {
                tmp = C(n - i - 1, j - 1);
                // printf("[%d,%d] tmp: %d (C)\n", i, j, tmp);
            } else if (s[i] == t[m - j]) {
                tmp = dp[i + 1][j - 1];
                // printf("[%d,%d] tmp: %d (dp)\n", i, j, tmp);
            } else {
                tmp = 0;
            }

            dp[i][j] = (dp[i + 1][j] + tmp) % M;
        }
    }

    int ans1 = dp[0][m];
    // printf("ans1: %d\n", ans1);

    int ans2 = 0;
    asc(i, 0, n - m - 1) {
        if (s[i] != '0') {
            int len = n - i - 1;
            int k;
            asc(k, m, len) {
                ans2 = (ans2 + C(len, k)) % M;
                // printf("ans2[%d] = %d (+C(%d, %d))\n", i, ans2, len, k - 1);
            }
        }
    }

    int ans = (ans1 + ans2) % M;
    pdln(ans);
}

int C(int len, int k) {
    static int cache[3000 + 7][3000 + 7];
    int tmp;
    if (cache[len][k]) {
        tmp = cache[len][k];
    } else if (len < k) {
        tmp = 0;
    } else if (k == 0 || len == k) {
        tmp = cache[len][k] = 1;
    } else {
        tmp = cache[len][k] = (C(len - 1, k - 1) + C(len - 1, k)) % M;
    }
    // printf("C(%d, %d) = %d\n", len, k, tmp);
    return tmp;
}