// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
  public:
    int removeDuplicates(vector<int> &nums) {
        auto iter = unique(nums.begin(), nums.end());
        return iter - nums.begin();
    }
};