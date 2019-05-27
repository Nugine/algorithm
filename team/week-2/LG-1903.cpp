#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))

struct Query {
    int l, r, m;
    int idx;
};

struct Modify {
    int p, col;
    int pre;
};

int block;
bool comp(const Query &a, const Query &b) {
    if (a.l / block != b.l / block) {
        return a.l < b.l;
    }
    if (a.r / block != b.r / block) {
        return a.r < b.r;
    }
    return a.m < b.m;
}

const int MAXN = 5e4 + 5;

int n, m;
int a[MAXN];
Query query[MAXN];
Modify modify[MAXN];
int qlen = 0;
int mlen = 0;

int ans = 0;
int cnt[1000000 + 7];
int res[MAXN];

void init(void) {
    static int cache[MAXN];

    scanf("%d%d", &n, &m);

    int i, t;
    asc(i, 1, n) {
        scanf("%d", &t);
        a[i] = t;
        cache[i] = t;
    }
    getchar();

    char c;
    int t2;

    asc(i, 1, m) {
        c = getchar();
        scanf("%d%d", &t, &t2);
        getchar();

        if (c == 'Q') {
            Query &q = query[++qlen];
            q.idx = qlen;
            q.l = t;
            q.r = t2;
            q.m = mlen;
        } else if (c == 'R') {
            Modify &mod = modify[++mlen];
            mod.p = t;
            mod.col = t2;
            mod.pre = cache[t];
            cache[t] = t2;
        }
    }

    block = pow(n, double(2.0) / 3.0);
    sort(query + 1, query + qlen + 1, comp);
}

inline void add(int pos) {
    if (++cnt[a[pos]] == 1) {
        ++ans;
    }
}

inline void del(int pos) {
    if (--cnt[a[pos]] == 0) {
        --ans;
    }
}

inline void change(int L, int R, int mpos) {
    Modify &mod = modify[mpos];
    if (L <= mod.p && mod.p <= R) {
        del(mod.p);
        a[mod.p] = mod.col;
        add(mod.p);
    } else {
        a[mod.p] = mod.col;
    }
}

inline void revert(int L, int R, int mpos) {
    Modify &mod = modify[mpos];
    if (L <= mod.p && mod.p <= R) {
        del(mod.p);
        a[mod.p] = mod.pre;
        add(mod.p);
    } else {
        a[mod.p] = mod.pre;
    }
}

int main() {

    init();
    int i;

    int L = 1;
    int R = 0;
    int M = 0;

    ans = 0;

    asc(i, 1, qlen) {
        Query &q = query[i];
        while (L > q.l) {
            --L;
            add(L);
        }
        while (L < q.l) {
            del(L);
            ++L;
        }
        while (R > q.r) {
            del(R);
            --R;
        }
        while (R < q.r) {
            ++R;
            add(R);
        }
        while (M > q.m) {
            revert(L, R, M);
            --M;
        }
        while (M < q.m) {
            ++M;
            change(L, R, M);
        }
        res[q.idx] = ans;
    }
    asc(i, 1, qlen) { printf("%d\n", res[i]); }
}