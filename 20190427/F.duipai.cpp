#include <cmath>
#include <cstdio>
using namespace std;
typedef long long ll;
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))
#define rd(x) scanf("%d", &(x))
#define rd2(x, y) scanf("%d %d", &(x), &(y))
#define pdln(x) printf("%d\n", (x))

int n, m;
int a[5 * 100000 + 5];
int p[5 * 100000 + 5];

const int MOD = 1e9;

int main() {
    int T;
    rd(T);
    while (T--) {
        rd2(n, m);

        int i;
        asc(i, 1, n) { rd(a[i]); }
        asc(i, 1, m) { rd(p[i]); }

        int ans = 0;

        int j;
        asc(j, 1, m) {
            ll s = 0;
            asc(i, 1, n) {

                s += floor(a[i] / ceil(log(a[i]) / log(p[j])));
                s %= MOD;
            }
            ans = (ans + (s * j) % MOD) % MOD;
        }
        pdln(ans);
    }
}