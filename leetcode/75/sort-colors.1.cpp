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

        int l = 0, r = n - 1;
        for (int i = 0; i <= r;) {
            if (a[i] == 0) {
                swap(a[i++], a[l++]);
            } else if (a[i] == 2) {
                swap(a[i], a[r--]);
            } else {
                i += 1;
            }
        }
    }
};