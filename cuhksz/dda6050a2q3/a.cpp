/*

The Longest Subsequence with Equal Step

dp[i]: X[..=i] 中以 X[i] 为末尾的最长等差子序列的长度

dp[0] = 1
dp[i] = dp[j] + 1       if 存在最大的 j 使 X[j]+step==X[i]
dp[i] = 1               else.

maxj[x]: max(j for j in 0..i if a[j]==x)

ans=max(dp)

*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long ll;
#define asc(i, s, e) for (i = (s); i <= (e); ++i)
#define rng(i, s, e) for (i = (s); i < (e); ++i)
// #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define eprintf(...)

const int MAXN = 1e5 + 63;
int X[MAXN];
int n;
int step;

int dp[MAXN];

int solve() {
    unordered_map<int, int> maxj;
    int i, j;
    int ans = 0;

    rng(i, 0, n) {
        if (maxj.count(X[i] - step)) {
            j = maxj[X[i] - step];
            dp[i] = dp[j] + 1;
        } else {
            dp[i] = 1;
        }
        maxj[X[i]] = i;
        ans = max(ans, dp[i]);
        eprintf("dp[%d] = %d\n", i, dp[i]);
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    n = 0;
    int x;
    while (cin >> x) {
        X[n++] = x;
    }
    n -= 1;
    step = X[n];
    X[n] = 0;
    eprintf("n = %d, step = %d\n", n, step);

    cout << solve() << endl;
}
