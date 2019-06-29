#include <algorithm>
#include <bitset>
#include <cstring>
#include <iostream>
using namespace std;
#define rng(i, s, e) for ((i) = (s); (i) < (e); ++(i))

typedef char i8;
typedef unsigned int u32;

int div2(string &src) {
    int d = 0, m = 0;
    for (auto &c : src) {
        int t = m * 10 + c;
        d = t / 2;
        m = t % 2;
        c = d;
    }

    int i = 0;
    while (src[i] == 0 && i < int(src.length())) {
        ++i;
    }
    src.erase(0, i);
    return m;
}

int div10(string &src) {
    int d = 0, m = 0;
    for (auto &c : src) {
        int t = m * 2 + c;
        d = t / 10;
        m = t % 10;
        c = d;
    }
    int i = 0;
    while (src[i] == 0 && i < int(src.length())) {
        ++i;
    }
    src.erase(0, i);
    return m;
}

void to_raw(string &s) {
    for (auto &c : s) {
        c -= '0';
    }
}

const int N = 1000;
class Bint {
  public:
    i8 a[N];
    int len;
    bool pos;
    int carry;

    void from_string_pos(string &src) {
        len = 0;
        while (!src.empty()) {
            a[len++] = div2(src);
        }
        if (a[len - 1] == 1) {
            a[len++] = 0;
        }
        pos = true;
        carry = 0;
    }

    void from_string_neg(string &src) {
        from_string_pos(src);
        tcr();
        pos = false;
    }

    void add(int n) {
        carry = n;
        int i;
        rng(i, 0, len) {
            int t = carry + a[i];
            carry = t / 2;
            a[i] = (t + 2) % 2;
        }
    }

    void tcr() {
        int i;
        rng(i, 0, len) { a[i] = 1 - a[i]; }
        add(1);
    }

    void extend(int new_len) {
        if (len >= new_len) {
            return;
        }
        if (pos) {
            return;
        }

        int i;
        rng(i, len, new_len) {
            int t = carry + 1;
            carry = t / 2;
            a[i] = (t + 2) % 2;
        }
        len = new_len;
    }

    void clear() { memset(a, 0, sizeof(a)); }

    void bint_and(Bint &rhs, Bint &dst) {
        int max_len = max(len, rhs.len);
        extend(max_len);
        rhs.extend(max_len);
        dst.clear();
        int i;
        rng(i, 0, max_len) { dst.a[i] = a[i] & rhs.a[i]; }
        dst.len = max_len;
        dst.pos = dst.a[max_len - 1] == 0;
        dst.carry = 0;
    }

    void show() {
        if (len == 1) {
            cout << char(a[0] + '0');
            return;
        }

        if (!pos) {
            tcr();
        }
        string src;
        int i;
        rng(i, 0, len) {
            string t;
            t += char(a[i]);
            src.insert(0, t);
        }

        string ans;
        while (!src.empty()) {
            ans += div10(src) + '0';
        }
        if (!pos) {
            ans += '-';
        }
        reverse(ans.begin(), ans.end());
        cout << ans;
    }

    Bint() { clear(); }

    void from_string(string &src) {
        if (src[0] == '-') {
            src.erase(0, 1);
            to_raw(src);
            from_string_neg(src);
        } else {
            to_raw(src);
            from_string_pos(src);
        }
    }
};

void solve() {
    string s1;
    string s2;
    Bint lhs, rhs, dst;

    cin >> s1 >> s2;

    lhs.from_string(s1);
    rhs.from_string(s2);
    lhs.bint_and(rhs, dst);
    dst.show();
    cout << endl;
}

int main() {
    int T;
    while (cin >> T) {
        while (T--) {
            solve();
        }
    }
}