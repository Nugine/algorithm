#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))
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

const int MAXN = 5e4 + 5;
const int MAXM = 5e4 + 5;

int n, m;
int c[MAXN];

struct Query {
    int l, r;
    int idx;
} q[MAXM];

int block;
ll ans = 0;
ll cnt[MAXN];

struct Res {
    ll a, b;
} res[MAXM];

bool comp(const Query &a, const Query &b) {
    int ta = a.l / block;
    int tb = b.l / block;
    return (ta != tb) ? (ta < tb) : (a.r < b.r);
}

inline void update(int p, int add) {
    ll t = cnt[c[p]];
    ans -= t * t;
    t += add;
    ans += t * t;
    cnt[c[p]] = t;
}

int main() {
    scanf("%d %d", &n, &m);
    int i;
    asc(i, 1, n) { scanf("%d", &c[i]); }
    block = sqrt(n);
    asc(i, 1, m) {
        scanf("%d %d", &q[i].l, &q[i].r);
        q[i].idx = i;
    }
    sort(q + 1, q + m + 1, comp);

    int L = 1, R = 0;
    asc(i, 1, m) {
        Query &qy = q[i];
        while (R < qy.r) {
            update(R + 1, 1);
            ++R;
        }
        while (R > qy.r) {
            update(R, -1);
            --R;
        }
        while (L < qy.l) {
            update(L, -1);
            ++L;
        }
        while (L > qy.l) {
            update(L - 1, 1);
            --L;
        }
        Res &re = res[qy.idx];
        if (qy.l == qy.r) {
            re.a = 0, re.b = 1;
        } else {
            ll len = qy.r - qy.l + 1;
            re.a = ans - len;
            re.b = len * (len - 1);
            ll d = gcd(re.a, re.b);
            re.a /= d, re.b /= d;
        }
    }

    asc(i, 1, m) { printf("%lld/%lld\n", res[i].a, res[i].b); }
}
