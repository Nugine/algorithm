#include <cstring>
#include <iostream>
using namespace std;
typedef unsigned long long ull;

const int BInt_N = 200;

struct BInt {
    char a[BInt_N];
};

inline void imul(BInt &lhs, const BInt &rhs) {
    char a[BInt_N] = {0};

    int i, j, k;
    char carry, t;
    for (i = 0; i < BInt_N; ++i) {
        carry = 0;
        for (j = 0; (k = i + j) < BInt_N; ++j) {
            t = rhs.a[i] * lhs.a[j] + carry + a[k];
            carry = t / 10;
            a[k] = t % 10;
        }
    }
    memcpy(lhs.a, a, sizeof(a));
}

inline void qpow(BInt &r, BInt &b, int p) {
    memset(r.a, 0, sizeof(r.a));
    r.a[0] = 1;
    while (p) {
        if (p & 1) {
            imul(r, b);
        }
        imul(b, b);
        p >>= 1;
    }
}

inline int rlocate(const char *a, int l, int r) {
    int i = r;
    while (a[i] == 0 && i >= l) {
        --i;
    }
    return i;
}

inline int llocate(const char *a, int l, int r) {
    int i = l;
    while (a[i] == 0 && i <= r) {
        ++i;
    }
    return i;
}

void solve(void) {
    string R;
    int n;
    cin >> R >> n;

    string Ra, Rb;
    int i = R.find('.');
    if (i >= 0) {
        Ra = R.substr(0, i);
        Rb = R.substr(i + 1);
    } else {
        Ra = R;
    }

    if (Ra == "") {
        Ra = "0";
    }
    if (Rb == "") {
        Rb = "0";
    }

    int la = Ra.length();
    int lb = Rb.length();

    BInt b;
    memset(b.a, 0, sizeof(b.a));
    for (i = 0; i < lb; ++i) {
        b.a[lb - 1 - i] = Rb[i] ^ '0';
    }
    for (i = 0; i < la; ++i) {
        b.a[la - 1 - i + lb] = Ra[i] ^ '0';
    }
    // cout << Ra << endl << Rb << endl;

    BInt r;
    qpow(r, b, n);
    int point = lb * n;
    int j;

    j = rlocate(r.a, point, BInt_N - 1);
    for (i = j; i >= point; --i) {
        putchar(r.a[i] ^ '0');
    }

    j = llocate(r.a, 0, point - 1);
    if (j < point) {
        putchar('.');
        for (i = point - 1; i >= j; --i) {
            putchar(r.a[i] ^ '0');
        }
    }
    putchar('\n');
}

int main() {
    int T;
    while (cin >> T) {
        while (T--) {
            solve();
        }
    }
}
