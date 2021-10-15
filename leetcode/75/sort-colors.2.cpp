// https://leetcode-cn.com/problems/sort-colors/

#include <algorithm>
#include <iostream>
#include <vector>
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
using namespace std;

class Solution {
  public:
    void sortColors(vector<int> &nums) {
        int *a = nums.data();
        int n = nums.size();

        if (n <= 1) {
            return;
        }

        int bucket[3] = {0, 0, 0};
        for (int i = 0; i < n; ++i) {
            bucket[a[i]] += 1;
        }
        int top = 0;
        for (int i = 0; i < 3; ++i) {
            int cnt = bucket[i];
            fill(a + top, a + top + cnt, i);
            top += cnt;
        }
    }
};

int main() {
    vector<int> nums = {2, 1, 0};
    auto sol = Solution();
    sol.sortColors(nums);
    for (auto x : nums) {
        cout << x << ", ";
    }
    cout << endl;
}