// https://leetcode-cn.com/problems/binary-search/

#include <vector>
using namespace std;

class Solution {
  public:
    int search(vector<int> &nums, int target) {
        int *a = nums.data();
        int n = nums.size();

        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r) / 2;
            if (a[mid] < target) {
                l = mid + 1;
            } else if (a[mid] > target) {
                r = mid;
            } else {
                return mid;
            }
        }
        return -1;
    }
};