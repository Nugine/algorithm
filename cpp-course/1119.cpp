#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
#define rd(x) scanf("%d", &(x))
#define rd2(x, y) scanf("%d %d", &(x), &(y))
#define rd3(x, y, z) scanf("%d %d %d", &(x), &(y), &(z))
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))
#define pdln(x) printf("%d\n", (x))

int solve();
int main() {
    int T;
    rd(T);
    while (T--) {
        cout << solve() << endl;
    }
    return 0;
}

int conv(int n, int b) {
    int r = 0;
    int d = 0;
    while (n) {
        int t = n % 10;
        if (t >= b) {
            return -1;
        }
        r += pow(b, d) * t;
        n /= 10;
        ++d;
    }
    return r;
}

int solve() {
    int p, q, r;
    rd3(p, q, r);

    int b;
    int a1, a2, a3;

    asc(b, 2, 16) {
        a1 = conv(p, b);
        a2 = conv(q, b);
        a3 = conv(r, b);

        if (a1 == -1 || a2 == -1 || a3 == -1) {
            continue;
        }

        // cout << a1 << " " << a2 << " " << a3 << endl;
        if (a1 * a2 == a3) {
            return b;
        }
    }
    // cout << endl;
    return 0;
}
