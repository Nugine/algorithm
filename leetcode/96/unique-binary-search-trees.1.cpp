// https://leetcode-cn.com/problems/unique-binary-search-trees/

// f(0) = 1
// f(1) = 1
// f(2) = (f(0) * f(1)) + (f(1) * f(0))
//      = 2
// f(3) = (f(0) * f(2)) + (f(1) * f(1)) + (f(2) * f(0))
//      = 2 + 1 + 2
//      = 5
// f(4) = (f(0) * f(3)) + (f(1) * f(2)) + (f(2) * f(1)) + (f(3) * f(0))
//      = 5 + 2 + 2 + 5
//      = 14
// f(n) = \sum_{i=0}^{n-1}{f(i)*f(n-1-i)}

#include <array>
using namespace std;

constexpr array<int, 32> get_table() {
    auto a = array<int, 32>();
    a[0] = a[1] = 1;
    for (int n = 2; n <= 19; ++n) {
        int ans = 0;
        for (int i = 0; i <= n - 1; ++i) {
            ans += a[i] * a[n - 1 - i];
        }
        a[n] = ans;
    }
    return a;
}

class Solution {
  public:
    int numTrees(int n) {
        static array<int, 32> table = get_table();
        return table[n];
    }
};