// https://blog.csdn.net/zxm1306192988/article/details/80725404

#include <iostream>
#include <string>
using namespace std;

class Solution {
  public:
    string removeKdigits(string num, int k) {
        if (k <= 0) {
            return num;
        }
        if (k >= num.length()) {
            return "0";
        }

        int cnt = k;
        int len = num.length();
        string &stk = num;
        int top = -1;

        for (auto c : num) {
            while (top >= 0 && stk[top] > c && cnt > 0) {
                --cnt;
                --top;
            }
            stk[++top] = c;
        }

        string ans = num.substr(0, len - k);
        int i = 0;
        while (ans[i] == '0' && i < ans.length() - 1) {
            ++i;
        }
        return ans.substr(i);
    }
};