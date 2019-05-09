// 线段树 - 单点修改，区间查询
// 快读
// 爆int

#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
#define rd(x) scanf("%d", &(x))
#define rd2(x, y) scanf("%d %d", &(x), &(y))
#define rd3(x, y, z) scanf("%d %d %d", &(x), &(y), &(z))
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))
#define rng(i, s, e) for ((i) = (s); (i) < (e); ++(i))
#define desc(i, s, e) for ((i) = (s); (i) >= (e); --(i))
#define pdln(x) printf("%d\n", (x))

int read() {
    char c = getchar();
    int ans = 0;
    int sign = 1;
    while (c < '0' || c > '9') {
        if (c == '-') {
            sign = -1;
        }
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        ans = 10 * ans + c - '0';
        c = getchar();
    }
    return sign * ans;
}

struct Node {
    int s, e;
    int left, right;
    ll val;
} tree[100000 * 4 + 7];
const int ROOT = 1;

int Q, M;

void build(int rt, int s, int e) {
    Node &nd = tree[rt];
    nd.s = s, nd.e = e;

    if (s == e) {
        nd.left = -1;
        nd.right = -1;
        nd.val = 1;
    } else {
        nd.left = rt * 2;
        nd.right = rt * 2 + 1;
        int mid = (s + e) / 2;
        build(nd.left, s, mid);
        build(nd.right, mid + 1, e);
        nd.val = 1;
    }
}

ll query(int rt, int qs, int qe) {
    Node &nd = tree[rt];
    if (qs <= nd.s && nd.e <= qe) {
        return nd.val;
    }
    int mid = (nd.s + nd.e) / 2;
    int ans = 1;
    if (qs <= mid) {
        ans *= query(nd.left, qs, qe);
    }
    if (qe >= mid + 1) {
        ans *= query(nd.right, qs, qe);
    }
    ans %= M;
    return ans;
}

void update(int rt, int idx, ll val) {
    Node &nd = tree[rt];

    if (nd.s == nd.e && nd.s == idx) {
        nd.val = val;
        return;
    }

    int mid = (nd.s + nd.e) / 2;
    if (idx <= mid) {
        update(nd.left, idx, val);
    } else if (idx >= mid + 1) {
        update(nd.right, idx, val);
    }
    nd.val = tree[nd.left].val * tree[nd.right].val % M;
}

int main() {
    // freopen("in", "r", stdin);

    int T;
    // rd(T);
    // cin >> T;
    T = read();
    while (T--) {
        // rd2(Q, M);
        // getchar();
        // cin >> Q >> M;
        Q = read();
        M = read();

        build(ROOT, 1, Q);

        int i;
        char c;
        int t;
        asc(i, 1, Q) {
            // cin >> c >> t;
            c = getchar();
            t = read();

            if (c == 'M') {
                update(ROOT, i, t);
                int ans = query(ROOT, 1, Q);
                pdln(ans);
            } else if (c == 'D') {
                update(ROOT, t, 1);
                int ans = query(ROOT, 1, Q);
                pdln(ans);
            }
        }
    }
    return 0;
}
