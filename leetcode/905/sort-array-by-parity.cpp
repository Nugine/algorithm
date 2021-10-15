// https://leetcode-cn.com/problems/sort-array-by-parity/

#include <vector>
using namespace std;

int partition(int *a, int len) {
    if (len == 0) {
        return 0;
    }
    int top = 0;
    for (int i = 0; i < len; ++i) {
        if (a[i] % 2 == 0) {
            swap(a[i], a[top++]);
        }
    }
    return top;
}

class Solution {
  public:
    vector<int> sortArrayByParity(vector<int> &nums) {
        vector<int> ans = nums;
        partition(ans.data(), ans.size());
        return ans;
    }
};