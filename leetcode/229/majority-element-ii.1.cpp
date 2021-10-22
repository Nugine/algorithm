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

        constexpr int M = 3 - 1;
        int xs[M];
        int cnt[M] = {0, 0};
        int len = 0;

        for (int i = 0; i < n; ++i) {
            const int x = a[i];
            int j = find(xs, xs + len, x) - xs;
            if (j < len) {
                cnt[j] += 1;
            } else if (len < M) {
                cnt[len] = 1;
                xs[len] = x;
                len += 1;
            } else {
                int top = 0;
                for (int j = 0; j < len; ++j) {
                    if (cnt[j] > 1) {
                        cnt[top] = cnt[j] - 1;
                        xs[top] = xs[j];
                        top += 1;
                    }
                }
                len = top;
            }
        }

        vector<int> ans;
        for (int j = 0; j < len; ++j) {
            const int x = xs[j];
            const int c = count(a, a + n, x);
            if (c * 3 > n) {
                ans.push_back(x);
            }
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
