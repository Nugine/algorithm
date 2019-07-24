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
int a[300000 + 7];

int b[300000 + 7];

int main() {
    rd2(n, k);
    int i;
    asc(i, 1, n) { rd(a[i]); }

    auto solve = []() {
        if (n == k) {
            return ll(0);
        }
        if (k == 1) {
            return ll(a[n] - a[1]);
        }

        int i;
        asc(i, 1, n - 1) { b[i] = a[i + 1] - a[i]; }
        sort(b + 1, b + n - 1 + 1, greater<int>());
        // asc(i, 1, n - 1) { pdln(b[i]); }
        ll s = 0;
        asc(i, 1, k - 1) { s += b[i]; }
        ll ans = ll(a[n] - a[1]) - s;
        return ans;
    };

    ll ans = solve();
    cout << ans << endl;
    return 0;
}