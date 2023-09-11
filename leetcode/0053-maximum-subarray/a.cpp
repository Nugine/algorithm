// 0053-maximum-subarray
// https://leetcode.cn/problems/maximum-subarray/
#ifdef LEETCODE_LOCAL
#include "leetcode.h"
#endif

int solve_cross(int *a, int l, int r) {
    int mid = (l + r) / 2;

    int left_sum = -2e9;
    int right_sum = -2e9;

    int sum = 0;
    for (int i = mid - 1; i >= l; --i) {
        sum += a[i];
        left_sum = max(left_sum, sum);
    }

    sum = 0;
    for (int i = mid; i < r; ++i) {
        sum += a[i];
        right_sum = max(right_sum, sum);
    }

    return left_sum + right_sum;
}

int solve(int *a, int l, int r) {
    if (l == r) {
        return 0;
    }
    if (l + 1 == r) {
        return a[l];
    }
    if (l + 2 == r) {
        return max(max(a[l], a[r - 1]), a[l] + a[r - 1]);
    }

    int mid = (l + r) / 2;
    int left_ans = solve(a, l, mid);
    int right_ans = solve(a, mid, r);
    int cross_ans = solve_cross(a, l, r);

    return max(max(left_ans, right_ans), cross_ans);
}

class Solution {
  public:
    int maxSubArray(vector<int> &nums) {
        return solve(nums.data(), 0, nums.size());
    }
};