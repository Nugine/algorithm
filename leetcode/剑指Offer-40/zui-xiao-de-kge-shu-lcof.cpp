// https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

int partition(int *a, int len) {
    int p = rand() % len;
    int r = len - 1;
    swap(a[r], a[p]);
    int top = 0;
    for (int i = 0; i < r; ++i) {
        if (a[i] <= a[r]) {
            swap(a[i], a[top++]);
        }
    }
    swap(a[top], a[r]);
    return top;
}

// 0 <= k < len
int quick_select(int *a, int len, int k) {
    if (len == 1) {
        return a[0];
    }
    int mid = partition(a, len);
    if (mid > k) {
        return quick_select(a, mid, k);
    }
    if (mid < k) {
        return quick_select(a + mid + 1, len - mid - 1, k - mid - 1);
    }
    return a[mid];
}

class Solution {
  public:
    vector<int> getLeastNumbers(vector<int> &arr, int k) {
        vector<int> ans = arr;
        if (arr.empty()) {
            return ans;
        }
        srand(time(nullptr));
        quick_select(ans.data(), ans.size(), k - 1);
        ans.resize(k);
        return ans;
    }
};

int main() {
    vector<int> arr = {3, 2, 1};
    auto sol = Solution();
    auto ans = sol.getLeastNumbers(arr, 2);
    for (auto x : ans) {
        cout << x << ", ";
    }
    cout << endl;
}