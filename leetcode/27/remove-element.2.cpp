// https://leetcode-cn.com/problems/remove-element/

#include <vector>
using namespace std;

class Solution {
  public:
    int removeElement(vector<int> &nums, int val) {
        int *a = nums.data();
        int n = nums.size();
        for (int i = 0; i < n;) {
            if (a[i] == val) {
                a[i] = a[--n];
            } else {
                ++i;
            }
        }
        nums.resize(n);
        return n;
    }
};