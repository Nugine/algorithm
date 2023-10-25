// 1955 count-number-of-special-subsequences
// https://leetcode.cn/problems/count-number-of-special-subsequences
#ifdef LEETCODE_LOCAL
#include "leetcode.h"
#endif

/*

子序列类型 0: regex(0+)
子序列类型 1: regex(0+1+)
子序列类型 2: regex(0+1+2+)

f(i, c): 以 x[i] 结尾，类型为 c 的子序列数量
g(i, c) = sum{ f(j, c) | 1<=j<=i }
ans = g(n-1, 2)

f(0, c) = 1,    if x[0]==0 and c==0
        = 0     else.

f(i, 0) = 1 + g(i-1, 0),            if x[i]==0
        = 0                         else.

f(i, 1) = g(i-1, 0) + g(i-1, 1),    if x[i]==1
        = 0                         else.

f(i, 2) = g(i-1, 1) + g(i-1, 2),    if x[i]==2
        = 0                         else.

g(i, c) = g(i-1, c) + f(i, c)

维度压缩: 去掉第一维

*/

#define rng(i, s, e) for ((i) = (s); (i) < (e); ++(i))
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))

const int MOD = 1e9 + 7;
const int N = 1e5 + 7;

int f[3];
int g[3];

int solve(int *x, int n) {
    int i, c;

    f[0] = int(x[0] == 0);
    f[1] = 0;
    f[2] = 0;
    asc(c, 0, 2) { g[c] = f[c]; }

    rng(i, 1, n) {
        f[0] = (x[i] == 0) ? (1 + g[0]) % MOD : (0);
        f[1] = (x[i] == 1) ? (g[0] + g[1]) % MOD : (0);
        f[2] = (x[i] == 2) ? (g[1] + g[2]) % MOD : (0);
        asc(c, 0, 2) { g[c] = (g[c] + f[c]) % MOD; }
    }

    return g[2];
}

class Solution {
  public:
    int countSpecialSubsequences(vector<int> &nums) { return solve(nums.data(), nums.size()); }
};
