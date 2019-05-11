#include <algorithm>
#include <cstdio>
using namespace std;
#define rd(x) scanf("%d", &(x))
#define rd2(x, y) scanf("%d %d", &(x), &(y))

struct Node {
    int s, e;
    int left, right;
    int max;
    int min;
} tree[100000 * 4 + 7];
const int ROOT = 1;

inline void push_up(Node &nd) {
    Node &left = tree[nd.left];
    Node &right = tree[nd.right];
    nd.min = min(left.min, right.min);
    nd.max = max(left.max, right.max);
}

void build(int rt, int s, int e, int src[]) {
    Node &nd = tree[rt];
    nd.s = s, nd.e = e;

    if (s == e) {
        nd.left = nd.right = -1;
        nd.max = src[s];
        nd.min = src[s];
    } else {
        int mid = (s + e) / 2;
        nd.left = rt * 2;
        nd.right = rt * 2 + 1;
        build(nd.left, s, mid, src);
        build(nd.right, mid + 1, e, src);
        push_up(nd);
    }
}

int query(int rt, int qs, int qe, int x) {
    Node &nd = tree[rt];
    if (nd.s == nd.e) {
        if (nd.min >= x) {
            return 1;
        } else {
            return 0;
        }
    }

    if (qs <= nd.s && nd.e <= qe) {
        if (x > nd.max) {
            return 0;
        }
        if (x <= nd.min) {
            return nd.e - nd.s + 1;
        }
    }
    int mid = (nd.s + nd.e) / 2;
    int ans = 0;
    if (qs <= mid) {
        ans += query(nd.left, qs, qe, x);
    }
    if (qe >= mid + 1) {
        ans += query(nd.right, qs, qe, x);
    }
    return ans;
}

int a[100000 + 7];

int solve(int qs, int qe) {
    int l, r, mid, t;
    l = 1, r = qe - qs + 1;
    while (r - l > 1) {
        mid = (l + r) / 2;
        t = query(ROOT, qs, qe, mid);
        if (t >= mid) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}

int main() {
    // freopen("in", "r", stdin);
    int n, q;
    int i;
    int qs, qe;

    while (rd2(n, q) > 0) {
        for (i = 1; i <= n; ++i) {
            rd(a[i]);
        }
        build(ROOT, 1, n, a);

        for (i = 1; i <= q; ++i) {
            rd2(qs, qe);
            int ans = solve(qs, qe);
            printf("%d\n", ans);
        }
    }

    return 0;
}