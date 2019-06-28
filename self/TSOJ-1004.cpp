#include <cstring>
#include <iostream>
using namespace std;
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))
#define rng(i, s, e) for ((i) = (s); (i) < (e); ++(i))
#define desc(i, s, e) for ((i) = (s); (i) >= (e); --(i))

typedef unsigned char u8;

const int N = 100;

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

int main() {
    string s1, s2;
    BInt lhs, rhs, dst;
    while (cin >> s1 >> s2) {
        BInt_clear(lhs);
        BInt_clear(rhs);
        BInt_clear(dst);
        BInt_from_string(lhs, s1);
        BInt_from_string(rhs, s2);
        BInt_add(dst, lhs, rhs);
        BInt_show(dst, cout);
        cout << endl;
    }
}