// https://leetcode-cn.com/problems/plus-one/

#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> plusOne(vector<int> &digits) {
        int *a = digits.data();
        int n = digits.size();

        int carry = 1;
        for (int i = n - 1; i >= 0; --i) {
            int x = a[i] + carry;
            carry = x / 10;
            a[i] = x % 10;
        }

        vector<int> ans;
        if (carry) {
            ans.push_back(carry);
        }
        ans.insert(ans.end(), digits.begin(), digits.end());
        return ans;
    }
};
