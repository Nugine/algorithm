// https://leetcode-cn.com/problems/maximum-gap/

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

using u32 = uint32_t;

class Solution {
  public:
    int maximumGap(vector<int> &nums) {
        if (nums.size() < 2) {
            return 0;
        }
        vector<u32> qs[256];

        for (u32 i = 0; i < 32; i += 8) {
            for (u32 x : nums) {
                u32 k = (x >> i) & 0xff;
                auto &q = qs[k];
                q.push_back(x);
            }
            nums.clear();
            for (auto &q : qs) {
                if (!q.empty()) {
                    nums.insert(nums.end(), q.begin(), q.end());
                    q.clear();
                }
            }
        }

        u32 ans = 0;
        u32 n = nums.size();
        for (u32 i = 1; i < n; ++i) {
            ans = max(ans, u32(nums[i] - nums[i - 1]));
        }
        return ans;
    }
};
