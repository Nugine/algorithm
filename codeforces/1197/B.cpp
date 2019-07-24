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

int n;
int a[200000 + 7];

int main() {
    rd(n);
    rd(a[1]);
    int max_i = 1;
    int i;
    asc(i, 2, n) {
        rd(a[i]);
        if (a[i] > a[max_i]) {
            max_i = i;
        }
    }

    auto solve = [max_i]() {
        int i = max_i;
        int l = max_i;
        int r = max_i;
        int sgn = -1;
        int cnt = 0;
        for (;;) {
            if (sgn == -1) {
                --l;
                if (l >= 1 && a[l] - a[i] == -1) {
                    a[i] = a[l];
                    cnt = 0;
                } else {
                    ++l;
                    sgn = 1;
                    ++cnt;
                }
            }
            if (sgn == 1) {
                ++r;
                if (r <= n && a[r] - a[i] == -1) {
                    a[i] = a[r];
                    cnt = 0;
                } else {
                    --r;
                    sgn = -1;
                    ++cnt;
                }
            }
            if (cnt >= 2) {
                break;
            }
        }
        return a[i] == 1;
    };
    bool ans = solve();
    if (ans) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}