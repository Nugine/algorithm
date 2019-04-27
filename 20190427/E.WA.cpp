#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
#define rd(x) scanf("%d", &(x))
#define rd2(x, y) scanf("%d %d", &(x), &(y))
#define rd3(x, y, z) scanf("%d %d %d", &(x), &(y), &(z))
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))
#define pdln(x) printf("%d\n", (x))

void solve();
int main() {
    int T;
    rd(T);
    while (T--) {
        solve();
    }
    return 0;
}

int n;
int f[100000 + 5];
int l[100000 + 5];
int r[100000 + 5];

int last[100000 + 5];
int ans[100000 + 5];

void solve() {
    rd(n);

    int i;
    asc(i, 1, n) { rd(f[i]); }
    asc(i, 1, n) { rd2(l[i], r[i]); }

    memset(last, 0, sizeof(last));
    last[1] = 1;

    asc(i, 2, n) {
        int j;
        if (f[i] - 1 > 0 && last[f[i] - 1]) {
            j = last[f[i] - 1];
            // ai > aj
            // aj_max = min(aj_max, ai_max-1)
            // ai_min = max(ai_min, aj_min+1)
            r[j] = min(r[j], r[i] - 1);
            l[i] = max(l[i], l[j] + 1);
        }
        if (last[f[i]]) {
            j = last[f[i]];
            // ai <= aj
            // ai_max = min(ai_max,aj_max)
            // aj_min = max(ai_min,aj_min)
            r[i] = min(r[i], r[j]);
            l[j] = max(l[i], l[j]);
        }
        last[f[i]] = i;
    }

    memset(last, 0, sizeof(last));
    last[1] = 1;
    ans[1] = l[1];

    asc(i, 2, n) {
        int j;
        if (f[i] - 1 > 0 && last[f[i] - 1]) {
            j = last[f[i] - 1];
            // ai > aj
            ans[i] = max(ans[j] + 1, l[i]);
        } else if (last[f[i]]) {
            j = last[f[i]];
            // ai <= aj
            ans[i] = min(min(ans[j], r[i]), l[i]);
        } else {
            ans[i] = l[i];
        }
        last[f[i]] = i;
    }

    asc(i, 1, n - 1) { printf("%d ", ans[i]); }
    printf("%d\n", ans[n]);
}
