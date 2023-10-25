// 0215 kth-largest-element-in-an-array
// https://leetcode.cn/problems/kth-largest-element-in-an-array
#ifdef LEETCODE_LOCAL
#include "leetcode.h"
#endif

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

int partition(int *a, int n, int p) {
    int x = a[p];
    int l = -1, r = n;
    for (;;) {
        do {
            l++;
        } while (a[l] < x);
        do {
            r--;
        } while (a[r] > x);
        if (l < r) {
            swap(a[l], a[r]);
        } else {
            break;
        }
    }
    return l;
}

int quick_select(int *a, int n, int k) {
    if (n < 4) {
        sort(a, a + n);
        return a[n - k];
    }

    int p = rand() % n;
    int mid = partition(a, n, p);

    if (k > n - mid) {
        return quick_select(a, mid, k - (n - mid));
    } else {
        return quick_select(a + mid, n - mid, k);
    }
}

class Solution {
  public:
    int findKthLargest(vector<int> &nums, int k) {
        srand(time(0));
        return quick_select(nums.data(), nums.size(), k);
    }
};
