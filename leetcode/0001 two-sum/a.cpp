// https://leetcode.cn/problems/two-sum/
#ifdef LEETCODE_LOCAL
#include "leetcode.h"
#endif

class Solution {
    unordered_map<int, int> m;

  public:
    vector<int> twoSum(vector<int> &nums, int target) {
        m.clear();
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            auto x = nums[i];
            m[x] = i;
        }
        for (int i = 0; i < len; ++i) {
            auto x = nums[i];
            auto y = target - x;
            if (m.count(y) && m[y] != i) {
                return {i, m[y]};
            }
        }
        throw "unreachable";
    }
};