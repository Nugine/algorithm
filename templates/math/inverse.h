//! https://oi-wiki.org/math/inverse/

typedef long long ll;
extern void exgcd(const ll a, const ll b, ll &x, ll &y);
extern ll qpow(ll b, ll p, ll m);

/// `m` must be a prime
inline ll inverse_fermat(ll n, ll m) {
    ll ans = qpow(n, m - 2, m);
    return ans;
}

inline ll inverse_exgcd(ll n, ll m) {
    ll x, y;
    exgcd(n, m, x, y);
    return (x % m + m) % m;
}

inline void inverse_linear(ll n, ll m, ll inv[]) {
    inv[1] = 1;
    for (ll i = 2; i <= n; ++i) {
        inv[i] = (m - m / i) * inv[m % i] % m;
    }
}