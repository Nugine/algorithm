// https://leetcode-cn.com/problems/sort-array-by-parity-ii/

#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void partition(int *a, int len) {
    if (len == 0) {
        return;
    }

    int top = 1;
    for (int i = 0; i < len;) {
        if (a[i] % 2 == 1) {
            swap(a[i], a[top]);
            top += 2;
        } else {
            i += 2;
        }
    }
}

class Solution {
  public:
    vector<int> sortArrayByParityII(vector<int> &nums) {
        vector<int> ans = nums;
        partition(ans.data(), ans.size());
        return ans;
    }
};

int main() {
    vector<int> nums = {4, 2, 5, 7};
    auto sol = Solution();
    auto ans = sol.sortArrayByParityII(nums);
    for (auto x : ans) {
        cout << x << ", ";
    }
    cout << endl;
    return 0;
}