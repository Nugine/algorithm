// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii/

#include <vector>
using namespace std;

class Solution {
  public:
    int removeDuplicates(vector<int> &nums) {
        int *const a = nums.data();
        const int n = nums.size();
        if (n <= 2) {
            return n;
        }
        int top = 2;
        for (int i = 2; i < n; ++i) {
            if (a[i] != a[top - 2]) {
                a[top++] = a[i];
            }
        }
        nums.resize(top);
        return top;
    }
};