#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

inline int base_from_char(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 10;
    }
    if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 10;
    }
    throw "unreachable";
}

inline char base_to_char(int t) {
    if (t >= 0 && t <= 9) {
        return t + '0';
    }
    return t + 'a';
}

int base_from_string(int base, const string &str) {
    int ans = 0;
    for (auto c : str) {
        ans = ans * base + base_from_char(c);
    }
    return ans;
}

string base_to_string(int base, int val) {
    string ans;
    if (val == 0) {
        ans += '0';
    } else {
        while (val) {
            int t = val % base;
            ans += base_to_char(t);
            val /= base;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    string s;
    int B1, B2;
    while (cin >> s >> B1 >> B2) {
        int val = base_from_string(B1, s);
        string ans = base_to_string(B2, val);
        cout << ans << endl;
    }
    return 0;
}
