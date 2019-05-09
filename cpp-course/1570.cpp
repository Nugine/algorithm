#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;

const int N = 200;
struct BInt {
    char inner[N];

    inline void clear() { memset(inner, 0, sizeof(inner)); }
    inline int len() const {
        int i = N - 1;
        while (i > 0 && inner[i] == 0) {
            --i;
        }
        return i + 1;
    }

    void read() {
        clear();
        char c = getchar();
        while (c < '0' || c > '9') {
            c = getchar();
        }
        int i = 0;
        while (c >= '0' && c <= '9') {
            inner[i++] = c ^ '0';
            c = getchar();
        }
        reverse(inner, inner + i);
    }

    void println() const {
        int i;

        for (i = len() - 1; i >= 0; --i) {
            putchar(inner[i] ^ '0');
        }
        putchar('\n');
    }

    void minus(const BInt &rhs, BInt &ret) const {
        if (&ret != this) {
            ret.clear();
        }
        const BInt lhs = *this;
        int i, t;
        int carry = 0;
        for (i = 0; i < N; ++i) {
            t = lhs.inner[i] + carry - rhs.inner[i];
            if (t < 0) {
                t += 10;
                carry = -1;
            } else {
                carry = 0;
            }
            ret.inner[i] = t;
        }
    }

    int compare(const BInt &rhs) const {
        const BInt &lhs = *this;
        int i = N - 1;
        while (lhs.inner[i] == 0 && rhs.inner[i] == 0) {
            --i;
        }
        if (lhs.inner[i] == 0) {
            return -1;
        }
        if (rhs.inner[i] == 0) {
            return 1;
        }
        for (; i >= 0; --i) {
            if (lhs.inner[i] > rhs.inner[i]) {
                return 1;
            } else if (lhs.inner[i] < rhs.inner[i]) {
                return -1;
            }
        }
        return 0;
    }

    void div(const BInt &rhs, BInt &ret) const {
        const BInt &lhs = *this;
        ret.clear();

        int t;
        t = lhs.compare(rhs);
        if (t == -1) {
            return;
        }
        if (t == 0) {
            ret.inner[0] = 1;
            return;
        }

        static BInt cache1;
        static BInt cache2;
        memcpy(cache1.inner, lhs.inner, N);

        int ld;
        for (ld = lhs.len() - rhs.len(); ld >= 0; --ld) {
            cache2.clear();
            memcpy(cache2.inner + ld, rhs.inner, N - ld);
            while (cache1.compare(cache2) >= 0) {
                cache1.minus(cache2, cache1);
                ++ret.inner[ld];
            }
        }
    }
};

void solve();
int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}

void solve() {
    static BInt a, b, c;
    a.read();
    b.read();

    a.div(b, c);
    c.println();
}