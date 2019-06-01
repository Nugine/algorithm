#include <iostream>
using namespace std;

string s;
int k, n;

string solve(void);

int main() {
    while (cin >> s >> k) {
        n = s.length();
        cout << solve() << endl;
    }
}

string solve(void) {
    if (k <= 0) {
        return s;
    }
    if (k >= n) {
        return "0";
    }

    string &stk = s;
    int cnt = k;
    int top = -1;

    for (auto c : s) {
        while (top >= 0 && stk[top] < c && cnt > 0) {
            --cnt;
            --top;
        }
        stk[++top] = c;
    }

    string ans = s.substr(0, n - k);
    int i = 0;
    int len = ans.length();
    while (ans[i] == '0' && i < len - 1) {
        ++i;
    }
    return ans.substr(i);
}
