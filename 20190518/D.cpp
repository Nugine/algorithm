#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll get(ll a, ll b, ll c, ll n) {
    ll s = 0;

    for (;;) {
        if (n <= 0) {
            break;
        }
        if (n == 1) {
            s += b / c;
            break;
        }
        ll tmp = 0;
        tmp += a / c * (n - 1) * n / 2 + b / c * n;
        a = a % c;
        b = b % c;
        if (a == 0) {
            s += tmp;
            break;
        }
        s += tmp;

        ll ta = c, tb = (a * n + b) % c, tc = a, tn = (a * n + b) / c;
        a = ta, b = tb, c = tc, n = tn;
    }
    return s;
}

int main() {

    int T;
    ll p, q, n;
    scanf("%d", &T);

    while (T--) {
        scanf("%lld %lld %lld", &p, &q, &n);
        cout << (p * n * (n + 1) / 2 - q * get(p, p, q, n)) << endl;
    }
}