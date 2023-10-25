// 1027 longest-arithmetic-subsequence
// https://leetcode.cn/problems/longest-arithmetic-subsequence
#ifdef LEETCODE_LOCAL
#include "leetcode.h"
#endif

#define rng(i, s, e) for ((i) = (s); (i) < (e); ++(i))
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))

/*
dp[i][d]: a[..=i] 中以 a[i] 为末尾、d 为公差的最长等差子序列的长度

dp[0][*] =  1
dp[i][d] =  dp[j][d] + 1   if 存在最大的 j 使 a[j]+d==a[i]
            1              else.

maxj[x]  = max(j for j in 0..i if a[j]==x)
*/
int solve(int *a, int n) {
    const int M = 512;
    static int dp[1024][1600];
    unordered_map<int, int> maxj;
    int i, j, d;

    int minx = 0x3f3f3f3f;
    int maxx = -0x3f3f3f3f;
    rng(i, 0, n) {
        minx = min(minx, a[i]);
        maxx = max(maxx, a[i]);
    }
    int m = maxx - minx;

    int ans = 0;

    rng(i, 0, n) {
        asc(d, -m, m) {
            if (maxj.count(a[i] - d)) {
                j = maxj[a[i] - d];
                dp[i][d + M] = dp[j][d + M] + 1;
            } else {
                dp[i][d + M] = 1;
            }
            ans = max(ans, dp[i][d + M]);
        }
        maxj[a[i]] = i;
    }

    return ans;
}

class Solution {
  public:
    int longestArithSeqLength(vector<int> &nums) {
        return solve(nums.data(), nums.size());
    }
};