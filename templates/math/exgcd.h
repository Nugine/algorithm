//! https://oi-wiki.org/math/gcd/

typedef long long ll;

inline ll gcd(ll a, ll b) {
    while (b) {
        ll c = a % b;
        a = b;
        b = c;
    }
    return a;
}

inline ll exgcd_recursive(ll a, ll b, ll &x, ll &y) {
    if (b) {
        ll g = exgcd_recursive(b, a % b, x, y);
        ll t = x;
        x = y;
        y = t - (a / b) * y;
        return g;
    } else {
        x = 1, y = 0;
        return a;
    }
}

inline ll exgcd_iterative(const ll a, const ll b, ll &x, ll &y) {
    ll c, d, q, t, x0, y0, x1, y1, v;
    c = a, d = b, q = a / b, t = a % b, x0 = 1, y0 = 0, x1 = 0, y1 = 1;
    while (t) {
        v = x0, x0 = x1, x1 = v - q * x1;
        v = y0, y0 = y1, y1 = v - q * y1;
        c = d;
        d = t;
        q = c / d;
        t = c % d;
    }
    x = x1, y = y1;
    return d;
}
