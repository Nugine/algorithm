// https://leetcode-cn.com/problems/sort-an-array/

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

int partition(int *a, const int l, const int r) {
    int p = rand() % (r - l + 1) + l;
    swap(a[r], a[p]);
    int j = l;
    for (int i = l; i < r; ++i) {
        if (a[i] <= a[r]) {
            swap(a[i], a[j++]);
        }
    }
    swap(a[j], a[r]);
    return j;
}

// 0 <= l <= r < len
void quick_sort(int *a, int l, int r) {
    if (l + 1 > r) {
        return;
    }
    int mid = partition(a, l, r);
    if (mid != l) {
        quick_sort(a, l, mid - 1);
    }
    if (mid != r) {
        quick_sort(a, mid + 1, r);
    }
}

class Solution {
  public:
    vector<int> sortArray(vector<int> &nums) {
        vector<int> ans = nums;
        if (!ans.empty()) {
            srand(time(nullptr));
            quick_sort(ans.data(), 0, ans.size() - 1);
        }
        return ans;
    }
};
