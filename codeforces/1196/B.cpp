#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rd(x) scanf("%d", &(x))
#define rd2(x, y) scanf("%d %d", &(x), &(y))
#define rd3(x, y, z) scanf("%d %d %d", &(x), &(y), &(z))
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))
#define rng(i, s, e) for ((i) = (s); (i) < (e); ++(i))
#define desc(i, s, e) for ((i) = (s); (i) >= (e); --(i))
#define pd(x) printf("%d", (x))
#define pdsp(x) printf("%d ", (x))
#define sppd(x) printf(" %d", (x))
#define pdln(x) printf("%d\n", (x))

int n, k;
int a[200000 + 7];
ull s[200000 + 7];
int f[200000 + 7];

bool solve() {
    rd2(n, k);
    int i;
    asc(i, 1, n) {
        rd(a[i]);
        s[i] = s[i - 1] + a[i];
    }

    if (k == 1) {
        return s[n] & 1;
    }

    if (k & 1) {
        if ((s[n] & 1) == 0) {
            return false;
        }
    } else {
        if ((s[n] & 1) == 1) {
            return false;
        }
    }

    int flip = 0;
    asc(i, 1, n - 1) {
        if ((flip & 1) == 0) {
            if ((s[i] & 1) == 1) {
                ++flip;
                f[flip] = i;
            }
        } else {
            if ((s[i] & 1) == 0) {
                ++flip;
                f[flip] = i;
            }
        }
        if (flip == k - 1) {
            return true;
        }
    }
    return false;
}

int main() {
    int q;
    rd(q);
    while (q--) {
        bool ans = solve();
        if (ans) {
            printf("YES\n");

            int i;
            asc(i, 1, k - 1) { printf("%d ", f[i]); }
            printf("%d\n", n);
        } else {
            printf("NO\n");
        }
    }
    return 0;
}