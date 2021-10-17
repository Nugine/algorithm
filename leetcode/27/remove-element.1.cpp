// https://leetcode-cn.com/problems/remove-element/

#include <vector>
using namespace std;

class Solution {
  public:
    int removeElement(vector<int> &nums, int val) {
        int top = 0;
        int *a = nums.data();
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int x = a[i];
            if (x != val) {
                a[top++] = x;
            }
        }
        nums.resize(top);
        return top;
    }
};