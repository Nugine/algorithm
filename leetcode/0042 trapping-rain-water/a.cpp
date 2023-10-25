// 0042 trapping-rain-water
// https://leetcode.cn/problems/trapping-rain-water
#ifdef LEETCODE_LOCAL
#include "leetcode.h"
#endif

// #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define eprintf(...)

const int MAXN = 2e4 + 7;
int leftmax[MAXN];
int rightmax[MAXN];

int solve(int *a, int n) {
    int ma, pos;

    ma = 0, pos = -1;
    for (int i = 0; i < n; ++i) {
        if (ma <= a[i]) {
            ma = a[i];
            pos = i;
        }
        leftmax[i] = pos;
        eprintf("leftmax[%d]=%d\n", i, pos);
    }

    ma = 0, pos = n;
    for (int i = n - 1; i >= 0; --i) {
        if (ma <= a[i]) {
            ma = a[i];
            pos = i;
        }
        rightmax[i] = pos;
        eprintf("rightmax[%d]=%d\n", i, pos);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int lp = leftmax[i];
        int rp = rightmax[i];
        int lm = lp >= 0 ? a[lp] : 0;
        int rm = rp < n ? a[rp] : 0;
        int h = min(lm, rm);
        ans += h - a[i];
        eprintf("i = %d, h = %d\n", i, h);
    }

    return ans;
}

class Solution {
  public:
    int trap(vector<int> &height) {
        return solve(height.data(), height.size());
    }
};

// int main() {
//     int a[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
//     int ans = solve(a, sizeof(a) / sizeof(int));
//     printf("%d\n", ans);
// }
