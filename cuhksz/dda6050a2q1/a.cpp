/*

The Longest Common Consecutive Subsequence of X and Y

dp[i][j]: 最长公共后缀 of X[..=i] and Y[..=j]

dp[i][j] = dp[i-1][j-1] + 1     if X[i]==Y[j]
dp[i][j] = 0                    if X[i]!=Y[j]

ans = max(dp)
O(nm)

 */

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
#define asc(i, s, e) for (i = (s); i <= (e); ++i)
#define rng(i, s, e) for (i = (s); i < (e); ++i)
// #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define eprintf(...)

const int MAXN = 1e4 + 63;
int X[MAXN], Y[MAXN];
int lx, ly;

int dp[2][MAXN];

int solve() {
    int *dp0 = &dp[0][0];
    int *dp1 = &dp[1][0];
    int i, j;
    int ans = 0;
    rng(i, 0, lx) {
        rng(j, 0, ly) {
            dp1[j] = (X[i] == Y[j]) ? (dp0[j - 1] + 1) : 0;
            ans = max(ans, dp1[j]);
            eprintf("dp[%d][%d] = %d\n", i, j, dp1[j]);
        }
        swap(dp0, dp1);
    }
    return ans;
}

int main() {
    lx = ly = 0;

    int i;
    while (scanf("%d", &i)) {
        X[lx++] = i;
        if (getchar() == '\n') {
            break;
        }
    }

    while (scanf("%d", &i)) {
        Y[ly++] = i;
        if (getchar() == '\n') {
            break;
        }
    }

    int ans = solve();
    printf("%d\n", ans);

    return 0;
}