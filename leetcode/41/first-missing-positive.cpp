#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;
// #define vec_at(v, i) ((v).at((i)))
#define vec_at(v, i) ((v)[(i)])
// #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define eprintf(...)

class Solution {
  public:
    int firstMissingPositive(vector<int> &nums) {
        int *a = nums.data();
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            int x = a[i];
            for (;;) {
                if (x > 0 && x <= n) {
                    if (a[x - 1] != x) {
                        int t = a[x - 1];
                        a[x - 1] = x;
                        x = t;
                        continue;
                    }
                }
                break;
            }
        }

        int ans = 1;
        for (int i = 0; i < n; ++i) {
            int x = a[i];
            if (ans == x) {
                ++ans;
            } else {
                break;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> a{3, 4, -1, 1};
    auto sol = Solution();
    auto ans = sol.firstMissingPositive(a);
    printf("%d\n", ans);
}