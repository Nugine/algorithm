#include <algorithm>
#include <cstdio>
#include <cstring>
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

// #define DEBUG ;

inline int lowbit(int x) { return x & -x; }

int n;
int a[100000 + 7];

ll tree1[100000 + 7];
ll tree2[100000 + 7];

void update(int x, ll w) {
    for (int i = x; i <= n; i += lowbit(i)) {
        tree1[i] += w;
        tree2[i] += w * (x - 1);
    }
}

void range_update(int l, int r, ll val) {
    update(l, val);
    update(r + 1, -val);
}

ll sum(int x) {
    ll ans = 0;
    for (int i = x; i > 0; i -= lowbit(i)) {
        ans += x * tree1[i] - tree2[i];
    }
    return ans;
}

ll range_sum(int l, int r) { return sum(r) - sum(l - 1); }

int main() {
    rd(n);

    int i;
    asc(i, 1, n) { rd(a[i]); }

    static int last_idx[100000 + 7];
    memset(last_idx, -1, sizeof(last_idx));

    ll ans = 0;
    asc(i, 1, n) {
        int idx = last_idx[a[i]];
#ifdef DEBUG
        printf("i: %d, last idx: %d\n", i, idx);
#endif

        if (idx == -1) {
            range_update(1, i, 1);
        } else {
            range_update(idx + 1, i, 1);
        }

#ifdef DEBUG
        printf("updated\n");
#endif

        ans += range_sum(1, i);
        last_idx[a[i]] = i;
    }

    cout << ans << endl;
}