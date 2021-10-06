// https://leetcode-cn.com/problems/valid-parentheses/

#include <string>
using std::string;

class Solution {
    char map[256];

  public:
    Solution() {
        map['('] = ')';
        map['['] = ']';
        map['{'] = '}';
    }

    bool isValid(string s) {
        char *stk = new char[s.length()];
        int top = -1;

        for (auto c : s) {
            if (top >= 0 && stk[top] == c) {
                --top;
            } else {
                stk[++top] = map[c];
            }
        }

        return top == -1;
    }
};
