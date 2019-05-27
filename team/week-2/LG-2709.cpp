#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))
typedef long long ll;

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

const int MAX = 5e4 + 5;
int n, m, k;
int a[MAX];
int cnt[MAX];
Query q[MAX];

ll ans;
ll res[MAX];

void init() {
    scanf("%d%d%d", &n, &m, &k);
    int i;
    asc(i, 1, n) { scanf("%d", &a[i]); }
    asc(i, 1, m) {
        scanf("%d%d", &q[i].l, &q[i].r);
        q[i].idx = i;
    }
    block = sqrt(n);
    sort(q + 1, q + m + 1, comp);
}

inline void add(int pos) {
    int x = cnt[a[pos]]++;
    ans += x * 2 + 1;
}

inline void remove(int pos) {
    int x = cnt[a[pos]]--;
    ans -= x * 2 - 1;
}

int main() {
    init();

    int L = 1;
    int R = 0;
    ans = 0;

    int i;
    asc(i, 1, m) {
        const Query &qe = q[i];
        while (L > qe.l) {
            --L;
            add(L);
        }
        while (L < qe.l) {
            remove(L);
            ++L;
        }
        while (R > qe.r) {
            remove(R);
            --R;
        }
        while (R < qe.r) {
            ++R;
            add(R);
        }
        res[qe.idx] = ans;
    }
    asc(i, 1, m) { printf("%lld\n", res[i]); }
}
