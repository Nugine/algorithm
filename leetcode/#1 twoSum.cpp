#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> m;

        int len = nums.size();
        int i;

        for (i = 0; i < len; ++i) {
            m[target - nums[i]] = i;
        }

        vector<int> ans;
        for (i = 0; i < len; ++i) {
            if (m.count(nums[i]) && m[nums[i]] != i) {
                ans.push_back(i);
                ans.push_back(m[nums[i]]);
                break;
            }
        }
        return ans;
    }
};