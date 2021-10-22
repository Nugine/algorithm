// https://leetcode-cn.com/problems/majority-element-ii/

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> majorityElement(vector<int> &nums) {
        const int n = nums.size();
        const int *a = nums.data();

        int x1, x2;
        int v1 = 0, v2 = 0;

        for (int i = 0; i < n; ++i) {
            const int x = a[i];
            if (v1 > 0 && x == x1) {
                v1 += 1;
            } else if (v2 > 0 && x == x2) {
                v2 += 1;
            } else if (v1 == 0) {
                v1 = 1;
                x1 = x;
            } else if (v2 == 0) {
                v2 = 1;
                x2 = x;
            } else {
                v1 -= 1;
                v2 -= 1;
            }
        }

        vector<int> ans;
        int c1 = 0, c2 = 0;
        for (int i = 0; i < n; ++i) {
            const int x = a[i];
            c1 += int(x1 == x);
            c2 += int(x2 == x);
        }
        if (v1 > 0 && c1 * 3 > n) {
            ans.push_back(x1);
        }
        if (v2 > 0 && c2 * 3 > n) {
            ans.push_back(x2);
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {2, 1, 1, 3, 1, 4, 5, 6};
    auto sol = Solution();
    auto ans = sol.majorityElement(nums);
    for (auto x : ans) {
        cout << x << ", ";
    }
    cout << endl;
}
