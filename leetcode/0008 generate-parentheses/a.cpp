// 0008 generate-parentheses
// https://leetcode.cn/problems/generate-parentheses
#ifdef LEETCODE_LOCAL
#include "leetcode.h"
#endif

// https://leetcode.cn/problems/generate-parentheses/solutions/192912/gua-hao-sheng-cheng-by-leetcode-solution/

unordered_map<int, vector<string>> memo;

vector<string> &solve(int n) {
    if (memo.count(n)) {
        return memo[n];
    }
    vector<string> &list = memo[n];
    int i;
    for (int i = 0; i <= n - 1; ++i) {
        for (auto &sa : solve(i)) {
            for (auto &sb : solve(n - 1 - i)) {
                string s = "(" + sa + ")" + sb;
                list.push_back(std::move(s));
            }
        }
    }
    return list;
}

class Solution {
  public:
    vector<string> generateParenthesis(int n) {
        memo.emplace(0, vector{string{}});
        memo.emplace(1, vector{string{"()"}});

        return solve(n);
    }
};