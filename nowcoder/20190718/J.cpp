#include <algorithm>
#include <cstdio>
#include <iostream>
typedef unsigned long long u64;
typedef unsigned int u32;
using namespace std;

struct u128 {
    u32 a[4];

    u128(u64 x) {
        a[0] = u32(x);
        a[1] = (x >> 32);
        a[2] = a[3] = 0;
    }

    void mul(u32 rhs) {
        u64 carry = 0;
        for (auto &ai : a) {
            u64 t = carry + u64(ai) * rhs;
            ai = u32(t);
            carry = (t >> 32);
        }
    }

    int cmp(const u128 &rhs) {
        int i;
        for (i = 3; i >= 0; --i) {
            if (a[i] < rhs.a[i]) {
                return -1;
            } else if (a[i] > rhs.a[i]) {
                return 1;
            }
        }
        return 0;
    }
};

void solve(u64 x, u64 y, u64 a, u64 b) {
    u128 lhs(x), rhs(y);
    lhs.mul(b);
    rhs.mul(a);
    int ans = lhs.cmp(rhs);
    if (ans == 0) {
        printf("=\n");
    } else if (ans == -1) {
        printf("<\n");
    } else {
        printf(">\n");
    }
}

int main() {
    u64 x, y, a, b;
    while (cin >> x >> a >> y >> b) {
        solve(x, y, a, b);
    }

    return 0;
}