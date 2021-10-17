// https://leetcode-cn.com/problems/merge-sorted-array/

#include <vector>
using namespace std;

class Solution {
  public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int *const a = nums1.data();
        int *const b = nums2.data();

        int i = m - 1, j = n - 1, k = m + n;
        while (i >= 0 && j >= 0) {
            if (a[i] > b[j]) {
                a[--k] = a[i--];
            } else {
                a[--k] = b[j--];
            }
        }
        while (j >= 0) {
            a[--k] = b[j--];
        }
    }
};