#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        if (s == "") {
            return 0;
        }
        int m[300];
        fill(m, m + 300, -1);

        int l = 0, r = 0;
        m[s[0]] = 0;
        int ans = 1;

        int i, j, t;
        int len = s.length();
        for (i = 1; i < len; ++i) {
            t = m[s[i]];
            if (t >= 0 && t >= l) {
                l = t + 1;
            }
            ++r;
            m[s[i]] = i;
            ans = max(r - l + 1, ans);
        }
        return ans;
    }
};
