// https://leetcode-cn.com/problems/two-sum/

#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> m;
        int n = nums.size();
        int *a = nums.data();
        for (int i = 0; i < n; ++i) {
            int x = a[i];
            int y = target - x;
            if (m.count(y)) {
                int j = m[y];
                return {j, i};
            } else {
                m[x] = i;
            }
        }
        return {};
    }
};