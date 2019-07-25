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

void init();
void solve();
int main() {
    int q;
    rd(q);
    while (q--) {
        init();
        solve();
    }
}

int n, k;
char s[200000 + 7];

void init() {
    rd2(n, k);
    scanf("%s", s);
}

int ask(int l) {
    int i;
    int cnt = 0;
    char pr = s[l];
    asc(i, l + 1, l + k - 1) {
        // printf("pr: %c\n", pr);
        if (pr == 'R') {
            if (s[i] != 'G') {
                ++cnt;
            }
            pr = 'G';
        } else if (pr == 'G') {
            if (s[i] != 'B') {
                ++cnt;
            }
            pr = 'B';
        } else if (pr == 'B') {
            if (s[i] != 'R') {
                ++cnt;
            }
            pr = 'R';
        }
    }
    return cnt;
}

void solve() {
    int ans = n;
    int l;
    asc(l, 0, n - k) { ans = min(ans, ask(l)); }
    printf("%d\n", ans);
}