// https://leetcode-cn.com/problems/sort-an-array/

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

void heap_adjust(int *a, int n, int i) {
    int x = a[i];
    for (int j = i * 2 + 1; j < n; j = j * 2 + 1) {
        if (j + 1 < n && a[j] < a[j + 1]) {
            j += 1;
        }
        if (x >= a[j]) {
            break;
        }
        a[i] = a[j];
        i = j;
    }
    a[i] = x;
}

void heap_sort(int *a, int n) {
    if (n <= 1) {
        return;
    }
    for (int i = n / 2; i >= 0; --i) {
        heap_adjust(a, n, i);
    }
    for (int i = n - 1; i > 0; --i) {
        swap(a[0], a[i]);
        heap_adjust(a, i, 0);
    }
}

class Solution {
  public:
    vector<int> sortArray(vector<int> &nums) {
        vector<int> ans = nums;
        heap_sort(ans.data(), ans.size());
        return ans;
    }
};
