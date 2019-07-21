#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 7;
const int mod = 1e9 + 7;
int dp[N][N];
int main(void) {
    int n, m;
    while (~scanf("%d %d", &n, &m)) {
        memset(dp, 0, sizeof(int) * (n + m) * (n + m));
        for (int j = 0; j <= m; j++) {
            dp[0][j] = 1;
        }
        for (int i = 1; i <= n; i++) {
            dp[i][0] = 1;
        }
        for (int j = m + 1; j <= n + m; j++) {
            dp[0][j] = 0;
        }
        for (int i = n + 1; i <= n + m; i++) {
            dp[i][0] = 0;
        }
        dp[0][0] = 1;
        for (int k = 1; k <= 2 * n + 2 * m; k++) {
            for (int i = 1; i <= min(n + m, k - 1); i++) {
                int j = k - i;
                if (n + j >= i) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
                } else
                    dp[i][j] = 0;
                if (m + i >= j) {
                    dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
                }
            }
        }
        printf("%d\n", dp[n + m][n + m]);
    }
    return 0;
}