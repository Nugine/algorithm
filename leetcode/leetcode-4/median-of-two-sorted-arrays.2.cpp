#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;
#define vec_at(v, i) ((v).at((i)))
#define vec_at(v, i) ((v)[(i)])
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define eprintf(...)

class Solution {
  public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if ((m + n) % 2 == 0) {
            int median1 = getKth(nums1, nums2, (m + n) / 2);
            int median2 = getKth(nums1, nums2, (m + n) / 2 + 1);
            return (double(median1) + median2) / 2;
        } else {
            return getKth(nums1, nums2, (m + n) / 2 + 1);
        }
    }

    int getKth(vector<int> &a1, vector<int> &a2, int k) {
        int len1 = a1.size();
        int len2 = a2.size();
        int base1 = 0;
        int base2 = 0;
        for (;;) {
            if (base1 == len1) {
                return vec_at(a2, base2 + k - 1);
            }
            if (base2 == len2) {
                return vec_at(a1, base1 + k - 1);
            }
            if (k == 1) {
                return min(vec_at(a1, base1), vec_at(a2, base2));
            }
            int idx1 = min(base1 + k / 2 - 1, len1 - 1);
            int idx2 = min(base2 + k / 2 - 1, len2 - 1);
            eprintf("base1 = %d, base2 = %d, idx1 = %d, idx2 = %d, k = %d\n",
                    base1, base2, idx1, idx2, k);
            if (vec_at(a1, idx1) < vec_at(a2, idx2)) {
                k -= idx1 - base1 + 1;
                base1 = idx1 + 1;
            } else {
                k -= idx2 - base2 + 1;
                base2 = idx2 + 1;
            }
        }
    }
};

int main() {
    vector<int> a1{1, 2};
    vector<int> a2{3, 4};

    auto sol = Solution();
    auto ans = sol.findMedianSortedArrays(a1, a2);
    eprintf("%lf\n", ans);
}