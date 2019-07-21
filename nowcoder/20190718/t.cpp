#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))
const int M = 1e9 + 7;

int dp[1003][1003];
int n, m;

int main() {
    while (scanf("%d%d", &n, &m) > 0) {
        int i, j, k;
        memset(dp, 0, sizeof(int) * (n + m) * (n + m));
        asc(j, 0, m) { dp[0][j] = 1; }
        asc(i, 1, n) { dp[i][0] = 1; }
        asc(j, 1 + m, n + m) { dp[0][j] = 0; }
        asc(i, n + 1, n + m) { dp[i][0] = 0; }
        for (k = 1; k <= 2 * (n + m); ++k) {
            for (i = 1; i <= (min(n + m, k - 1)); ++i) {
                j = k - i;
                if (n + j >= i) {
                    dp[i][j] += dp[i - 1][j];
                    dp[i][j] %= M;
                }
                if (m + i >= j) {
                    dp[i][j] += dp[i][j - 1];
                    dp[i][j] %= M;
                }
            }
        }
        int ans = dp[n + m][n + m];
        printf("%d\n", ans);
    }
}