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
    int majorityElement(vector<int> &nums) {
        auto &a = nums;
        int n = nums.size();

        int x = a[0];
        int cnt = 1;
        for (int i = 1; i < n; ++i) {
            int t = a[i];
            if (t == x) {
                cnt += 1;
            } else {
                cnt -= 1;
            }
            if (cnt == 0) {
                x = t;
                cnt = 1;
            }
        }

        return x;
    }
};