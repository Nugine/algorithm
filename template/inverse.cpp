typedef long long ll;
extern ll exgcd(ll a, ll b, ll &x, ll &y);

ll inverse(ll a, ll m) {
    ll x, y;
    return (exgcd(a, m, x, y) == 1) ? ((x % m + m) % m) : (-1);
}

const int N = 1e5 + 3;
const int M = 1e9 + 7;
static ll inv[N];

void inverse() {
    inv[1] = 1;
    for (int i = 2; i < N && i < M; i++) {
        inv[i] = (M - M / i) * inv[M % i] % M;
    }
}