// https://leetcode-cn.com/problems/contains-duplicate/
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
  public:
    bool containsDuplicate(vector<int> &nums) {
        unordered_set<int> s;
        for (auto x : nums) {
            if (s.count(x)) {
                return true;
            }
            s.insert(x);
        }
        return false;
    }
};