#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
  public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int len1, len2;
        int l = 0;
        int r = m + 1;
        while (l < r) {
            len1 = l + (r - l) / 2;
            len2 = (m + n) / 2 - len1;
            bool cond = len1 == 0 || nums1[len1 - 1] <= nums2[len2];
            if (cond) {
                l = len1 + 1;
            } else {
                r = len1;
            }
        }

        len1 = max(l - 1, 0);
        len2 = (m + n) / 2 - len1;
        int median1, median2;
        if (len1 > 0) {
            median1 = nums1[len1 - 1];
            if (len2 > 0) {
                median1 = max(median1, nums2[len2 - 1]);
            }
        } else {
            if (len2 > 0) {
                median1 = nums2[len2 - 1];
            }
        }
        if (len1 < m) {
            median2 = nums1[len1];
            if (len2 < n) {
                median2 = min(median2, nums2[len2]);
            }
        } else {
            median2 = nums2[len2];
        }

        if ((m + n) % 2 == 0) {
            return ((double)median1 + median2) / 2;
        } else {
            return median2;
        }
    }
};
