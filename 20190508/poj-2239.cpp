// http://www.pianshen.com/article/7725212002/#_36

#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))

const int N = 1000;
int m[N][N];
int used[N];
int y[N];
int nx, ny;

bool find(int x) {
    for (int i = 1; i <= ny; i++)
        if (!used[i] && m[x][i]) {
            used[i] = 1;
            if (!y[i] || find(y[i]))
                return (y[i] = x);
        }
    return 0;
}
void solve() {
    nx = 200;
    memset(m, 0, sizeof(m));
    memset(y, 0, sizeof(y));

    int i;
    asc(i, 1, ny) {
        int t;
        cin >> t;

        int j;
        asc(j, 1, t) {
            int p, q;
            cin >> p >> q;

            int x;
            x = (p - 1) * 12 + q;
            m[x][i] = 1;
        }
    }
    int ans = 0;
    asc(i, 1, nx) {
        memset(used, 0, sizeof(used));
        if (find(i))
            ans++;
    }
    cout << ans << endl;
}
int main() {
    while (cin >> ny) {
        solve();
    }

    return 0;
}