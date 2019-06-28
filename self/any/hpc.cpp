#include <cstring>
#include <iostream>
using namespace std;
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))
#define rng(i, s, e) for ((i) = (s); (i) < (e); ++(i))
#define desc(i, s, e) for ((i) = (s); (i) >= (e); --(i))

typedef unsigned char u8;

const int N = 400;

struct BInt {
    u8 inner[N];
};

inline void BInt_clear(BInt &self) {
    memset(self.inner, 0, sizeof(self.inner));
}

int BInt_len(const BInt &self) {
    int i = N - 1;
    while (i > 0 && self.inner[i] == 0) {
        --i;
    }
    return i + 1;
}

void BInt_from_string(BInt &self, const string &src) {
    int len = src.length();
    int i = 0;
    for (auto c : src) {
        self.inner[len - 1 - i] = c - '0';
        ++i;
    }
}

void BInt_show(const BInt &self, ostream &o) {
    static char cache[N];
    int len = BInt_len(self);
    int i;
    rng(i, 0, len) { cache[len - 1 - i] = self.inner[i] + '0'; }
    cache[len] = '\0';
    o << cache;
}

void BInt_add(BInt &dst, const BInt &lhs, const BInt &rhs) {
    int i;
    int carry = 0;
    rng(i, 0, N) {
        int t = carry + lhs.inner[i] + rhs.inner[i];
        carry = t / 10;
        dst.inner[i] = t % 10;
    }
}

// assert: self >= rhs
void BInt_minus(BInt &dst, const BInt &lhs, const BInt &rhs) {
    int i;
    int carry = 0;
    rng(i, 0, N) {
        int t = carry + lhs.inner[i] - rhs.inner[i];
        if (t < 0) {
            carry = -1;
            t += 10;
        } else {
            carry = 0;
        }
        dst.inner[i] = t % 10;
    }
}

void BInt_mul(BInt &dst, const BInt &lhs, const BInt &rhs) {
    BInt_clear(dst);
    int i, j;
    rng(i, 0, N) {
        int carry = 0;
        rng(j, 0, N - i) {
            int t = carry + rhs.inner[i] * lhs.inner[j] + dst.inner[j + i];
            carry = t / 10;
            dst.inner[j + i] = t % 10;
        }
    }
}

int BInt_cmp(const BInt &lhs, const BInt &rhs) {
    int i;
    desc(i, N - 1, 0) {
        u8 c1 = lhs.inner[i];
        u8 c2 = rhs.inner[i];
        if (c1 > c2) {
            return 1;
        }
        if (c1 < c2) {
            return -1;
        }
    }
    return 0;
}

int main() {
    BInt lhs, rhs, dst;
    char op;
    string s1, s2;
    while (cin >> s1 >> s2 >> op) {
        BInt_clear(lhs);
        BInt_clear(rhs);
        BInt_clear(dst);
        BInt_from_string(lhs, s1);
        BInt_from_string(rhs, s2);
        if (op == '+') {
            BInt_add(dst, lhs, rhs);
            BInt_show(dst, cout);
            cout << endl;
        } else if (op == 'c') {
            int ans = BInt_cmp(lhs, rhs);
            cout << ans << endl;
        } else if (op == 'l') {
            int l1 = BInt_len(lhs);
            int l2 = BInt_len(rhs);
            cout << l1 << ' ' << l2 << endl;
        } else if (op == '-') {
            BInt_minus(dst, lhs, rhs);
            BInt_show(dst, cout);
            cout << endl;
        } else if (op == '*') {
            BInt_mul(dst, lhs, rhs);
            BInt_show(dst, cout);
            cout << endl;
        } else {
            BInt_show(lhs, cout);
            cout << endl;
            BInt_show(rhs, cout);
            cout << endl;
        }
    }
}
