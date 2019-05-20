#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))
typedef long long ll;

template <typename T> void qread(T &a) {
    char c = getchar();
    int s = 1;
    while (c < '0' || c > '9') {
        if (c == '-') {
            s = -1;
        }
        c = getchar();
    }
    T x = 0;
    while (c >= '0' && c <= '9') {
        x = 10 * x + c - '0';
        c = getchar();
    }
    a = s * x;
}

struct Query {
    int l, r;
    int idx;
};

int block;
bool comp(const Query &a, const Query &b) {
    int ta = a.l / block;
    int tb = b.l / block;
    return (ta != tb) ? (ta < tb) : (a.r < b.r);
}

const int MAXN = 2e5 + 7;
const int MAXT = 2e5 + 7;
int n;
int t;
int a[MAXN];
Query q[MAXT];

ll power = 0;
int k[1000000 + 7];
inline void md_add(int pos) {
    ll s = a[pos];
    ll ks = k[s];
    ++k[s];
    power += s * (2 * ks + 1);
}

inline void md_remove(int pos) {
    ll s = a[pos];
    ll ks = k[s];
    --k[s];
    power -= s * (2 * ks - 1);
}

int main() {
    qread(n);
    qread(t);
    int i;
    asc(i, 1, n) { qread(a[i]); }
    block = sqrt(n);
    asc(i, 1, t) {
        qread(q[i].l);
        qread(q[i].r);
        q[i].idx = i;
    }
    sort(q + 1, q + t + 1, comp);

    static ll res[MAXT];
    int L = 1, R = 0;
    asc(i, 1, t) {
        const Query qe = q[i];
        while (L < qe.l) {
            md_remove(L);
            ++L;
        }
        while (L > qe.l) {
            --L;
            md_add(L);
        }
        while (R < qe.r) {
            ++R;
            md_add(R);
        }
        while (R > qe.r) {
            md_remove(R);
            --R;
        }
        res[qe.idx] = power;
    }
    asc(i, 1, t) {
        // printf("%I64d\n", res[i]);
        cout << res[i] << '\n';
    }
}
