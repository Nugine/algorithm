// https://leetcode-cn.com/problems/unique-binary-search-trees/

#include <array>
using namespace std;

constexpr array<int, 32> get_table() {
    auto a = array<int, 32>();
    a[0] = a[1] = 1;
    for (int n = 2; n <= 19; ++n) {
        a[n] = (long long)(a[n - 1]) * 2 * (2 * n - 1) / (n + 1);
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