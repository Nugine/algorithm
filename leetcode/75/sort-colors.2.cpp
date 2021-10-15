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

        constexpr int M = 4;
        int p[M] = {0, 0, 0, 0};
        int i = 0;
        while (i < n) {
            for (int m = 0; m < M; ++m) {
                if (m > 0 && p[m - 1] > p[m]) {
                    p[m] = p[m - 1];
                }
                if (a[i] == m) {
                    swap(a[i], a[p[m]]);
                    p[m] += 1;
                    if (p[m] > i) {
                        i = p[m];
                    }
                    break;
                }
            }
        }
    }
};

int main() {
    vector<int> nums = {3, 2, 1, 0};
    auto sol = Solution();
    sol.sortColors(nums);
    for (auto x : nums) {
        cout << x << ", ";
    }
    cout << endl;
}