#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define scand(x) scanf("%d", &x);
#define printd(x) printf("%d\n", x);
#define forin(i, s, e) for (i = s; i <= e; ++i)

const int MAXN = 10003;

int a[MAXN];
int b[MAXN];
int dp[MAXN][MAXN];

// dp[i][j] = dp[i - 1][j-1] + 1           | a[i] == b[j]
// dp[i][j] = max(dp[i - 1][j],dp[i][j-1]) | a[i] != b[j]
// dp[0][j] = 0
// dp[i][0] = 0

int lcs(int len) {
    register int i, j;
    // forin(i, 0, len) { dp[i][0] = 0; }
    // memset(dp[0], 0, sizeof(dp[0]));

    forin(i, 1, len) {
        forin(j, 1, len) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[len][len];
}

int main() {
    int len;
    register int i;
    scand(len);
    forin(i, 1, len) { scand(a[i]); }
    forin(i, 1, len) { scand(b[i]); }
    printd(lcs(len));
    return 0;
}