typedef long long ll;

ll gcd(ll a, ll b) {
    ll t = a % b;
    while (t) {
        a = b;
        b = t;
        t = a % b;
    }
    return b;
}

ll exgcd(ll a, ll b, ll &x, ll &y) {
    ll q = a / b, t = a % b;
    ll x0 = 1, y0 = 0, x1 = 0, y1 = 1;
    while (t) {
        a = b;
        b = t;
        q = a / b;
        t = x0, x0 = x1, x1 = t - q * x1;
        t = y0, y0 = y1, y1 = t - q * y1;
        t = a % b;
    }
    x = x1, y = y1;
    return b;
}
