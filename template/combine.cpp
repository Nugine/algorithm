typedef long long ll;

const int N = 1e5 + 3;
const int M = 1e9 + 7;

ll fac[N] = {1, 1};
ll inv[N] = {1, 1};
ll f[N] = {1, 1};

ll C(ll a, ll b) {
    if (b > a)
        return 0;
    return fac[a] * inv[b] % M * inv[a - b] % M;
}

void init() {
    for (int i = 2; i < N; i++) {
        fac[i] = fac[i - 1] * i % M;
        f[i] = (M - M / i) * f[M % i] % M;
        inv[i] = inv[i - 1] * f[i] % M;
    }
}

// --------------
extern ll qpow(ll b, ll p, ll m);

// assert: M is prime
// time: O(m)
ll C(ll n, ll m) {
    if (m > n)
        return 0;
    ll ans = 1;
    for (int i = 1; i <= m; i++)
        ans = ans * (n - i + 1) % M * qpow(i, M - 2, M) % M;
    return ans;
}
