#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
#define rd(x) scanf("%d", &(x))
#define rd2(x, y) scanf("%d %d", &(x), &(y))
#define rd3(x, y, z) scanf("%d %d %d", &(x), &(y), &(z))
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))
#define pdln(x) printf("%d\n", (x))

#define MLR                                                                    \
    int left = rt * 2;                                                         \
    int right = rt * 2 + 1;                                                    \
    int mid = (nd.s + nd.e) / 2;

#define ND Node &nd = tree[rt];
#define LRD                                                                    \
    Node &ld = tree[left];                                                     \
    Node &rd = tree[right];

struct Node {
    int s, e;
    int llen, rlen, tlen;
    int lazy_update;
    inline int len(void) { return e - s + 1; }
    inline void update(void) {
        tlen = rlen = llen = (lazy_update == 1 ? 0 : len());
    }

} tree[50000 * 4 + 7];
const int ROOT = 1;

void build(int rt, int s, int e) {
    ND;
    nd.s = s, nd.e = e;
    nd.lazy_update = 0;
    nd.update();

    if (s != e) {
        MLR;
        build(left, s, mid);
        build(right, mid + 1, e);
    }
}

void push_down(int rt) {
    ND;
    if (nd.lazy_update) {
        if (nd.s != nd.e) {
            MLR;
            LRD;

            ld.lazy_update = rd.lazy_update = nd.lazy_update;
            ld.update();
            rd.update();
        }
        nd.lazy_update = 0;
    }
}

int query(int rt, int w) {
    ND;

    if (nd.s == nd.e) {
        if (w == 1) {
            return nd.s;
        }
    }

    push_down(rt);
    MLR;
    LRD;
    int ans;
    if (ld.tlen >= w) {
        ans = query(left, w);
    } else if (ld.rlen + rd.llen >= w) {
        ans = ld.e - ld.rlen + 1;
    } else if (rd.tlen >= w) {
        ans = query(right, w);
    } else {
        ans = 0;
    }
    return ans;
}

void update(int rt, int s, int e, int kind) {
    ND;
    if (s <= nd.s && nd.e <= e) {
        nd.lazy_update = kind;
        nd.update();
        return;
    }

    push_down(rt);

    MLR;
    if (s <= mid) {
        update(left, s, e, kind);
    }
    if (e >= mid + 1) {
        update(right, s, e, kind);
    }
    LRD;

    nd.tlen = max(max(ld.tlen, rd.tlen), ld.rlen + rd.llen);

    if (ld.tlen == ld.len()) {
        nd.llen = ld.tlen + rd.llen;
    } else {
        nd.llen = ld.llen;
    }

    if (rd.tlen == rd.len()) {
        nd.rlen = rd.tlen + ld.rlen;
    } else {
        nd.rlen = rd.rlen;
    }
}

int main() {
    int n, m;
    rd2(n, m);
    build(ROOT, 1, n);
    while (m--) {
        int op;
        rd(op);
        if (op == 1) {
            int w;
            rd(w);
            int ans = query(ROOT, w);
            if (ans) {
                update(ROOT, ans, ans + w - 1, 1);
            }
            pdln(ans);
        } else {
            int x, w;
            rd2(x, w);
            update(ROOT, x, x + w - 1, 2);
        }
    }
    return 0;
}