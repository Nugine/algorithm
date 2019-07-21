#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))
typedef long long ll;

int n, k, m;
char s[1000];

ll solve() {
    int one = 0;
    int zero = 0;
    int i;
    int ma = 0;
    asc(i, 1, n) {
        if (s[i] == '1') {
            ++one;
        } else {
            if (k) {
                --k;
            } else {
                ++zero;
            }
        }
        ma = max(ma, one - zero);
    }
    if (one - zero <= 0) {
        return ma;
    } else {
        return ll(one - zero) * (m - 1) + ma;
    }
}

int main() {
    int T;
    scanf("%d", &T);

    int i;
    asc(i, 1, T) {
        scanf("%d %d %d", &n, &k, &m);
        scanf("%s", s + 1);
        ll ans = solve();
        cout << ans << endl;
    }
}