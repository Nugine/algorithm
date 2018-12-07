#include <algorithm>
#include <cstdio>
using namespace std;
#define asc_cl(i, s, e) for (i = s; i <= e; ++i)
#define desc_cl(i, s, e) for (i = s; i >= e; --i)
#define scand(x) scanf("%d", &x);
#define printd(x) printf("%d\n", x);

const int MAXN = 1000 + 2;
int dp[MAXN][MAXN];
int R;

// dp[i][j]: max sum from arr[i][j] to bottom
// dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + arr[i][j]

int solve() {
    register int i, j;
    desc_cl(i, R - 1, 1) {
        asc_cl(j, 1, i) { dp[i][j] += max(dp[i + 1][j], dp[i + 1][j + 1]); }
    }
    return dp[1][1];
}

void init() {
    register int i, j;
    scand(R);
    asc_cl(i, 1, R) {
        asc_cl(j, 1, i) { scand(dp[i][j]); }
    }
}

int main() {
    init();
    printd(solve());
    return 0;
}