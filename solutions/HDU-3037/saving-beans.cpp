#include <cstdio>
using namespace std;
typedef long long ll;

const int MAXN = 100010;

ll fact[MAXN];

void init_fact(const int lim, const ll mod) {
    fact[0] = fact[1] = 1;
    register ll cache = 1;
    register int i;

    for (i = 2; i <= lim; ++i) {
        cache = fact[i] = cache * i % mod;
    }
}

ll qpow(ll b, ll p, const ll mod) {
    register ll r = 1;
    while (p) {
        if (p & 1) {
            r = r * b % mod;
        }
        b = b * b % mod;
        p >>= 1;
    }
    return r;
}

ll lucas(ll n, ll m, const ll p) {
    register ll t = 1, nmp, mmp;
    while (t) {
        if (n < m)
            return 0;
        if (n == m || m == 0)
            return t;
        nmp = n % p, mmp = m % p;
        if (nmp < mmp)
            return 0;
        if (nmp != mmp && mmp) {
            t = t * fact[nmp] % p;
            t = t * qpow(fact[mmp], p - 2, p) % p;
            t = t * qpow(fact[nmp - mmp], p - 2, p) % p;
        }
        n /= p, m /= p;
    }
}

int main() {
    int T, n, m, p;
    scanf("%d", &T);

    while (T--) {
        scanf("%d %d %d", &n, &m, &p);
        init_fact(p, p);
        printf("%d\n", lucas(n + m, m, p));
    }
    return 0;
}