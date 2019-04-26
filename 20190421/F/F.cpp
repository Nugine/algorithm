#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
#define rd(x) scanf("%d", &(x))
#define rd2(x, y) scanf("%d %d", &(x), &(y))
#define rd3(x, y, z) scanf("%d %d %d", &(x), &(y), &(z))
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))

int n, q;
ll a[100000 + 7];

struct Node {
    int s, e;
    int left, right;
    ll sum;
    ll lazy_add;
} tree[4 * 100000 + 7];

void build(int rt, int s, int e) {
    Node &nd = tree[rt];
    nd.s = s, nd.e = e;
    nd.lazy_add = 0;

    if (s == e) {
        nd.left = -1, nd.right = -1;
        nd.sum = a[s];

    } else {
        int mid = (s + e) / 2;
        nd.left = rt * 2;
        nd.right = rt * 2 + 1;

        build(nd.left, s, mid);
        build(nd.right, mid + 1, e);

        nd.sum = (tree[nd.left].sum + tree[nd.right].sum);
    }
}

void propagate(Node &nd) {
    if (nd.s != nd.e) {
        Node &left = tree[nd.left];
        Node &right = tree[nd.right];
        left.lazy_add += nd.lazy_add;
        right.lazy_add += nd.lazy_add;
        left.sum += (left.e - left.s + 1) * nd.lazy_add;
        right.sum += (right.e - right.s + 1) * nd.lazy_add;
    }

    nd.lazy_add = 0;
}

void add(int rt, int us, int ue, int delta) {
    Node &nd = tree[rt];

    if (us <= nd.s && nd.e <= ue) {
        nd.sum += (nd.e - nd.s + 1) * delta;
        nd.lazy_add += delta;
        return;
    }

    if (nd.lazy_add) {
        propagate(nd);
    }

    int mid = (nd.s + nd.e) / 2;

    if (us <= mid) {
        add(nd.left, us, ue, delta);
    }

    if (ue >= mid + 1) {
        add(nd.right, us, ue, delta);
    }

    nd.sum = (tree[nd.left].sum + tree[nd.right].sum);
}

ll query(int rt, int qs, int qe) {
    Node &nd = tree[rt];

    if (qs <= nd.s && nd.e <= qe) {
        return nd.sum;
    }

    if (nd.lazy_add) {
        propagate(nd);
    }

    int mid = (nd.s + nd.e) / 2;
    ll ans = 0;
    if (qs <= mid) {
        ans += query(nd.left, qs, qe);
    }
    if (qe >= mid + 1) {
        ans += query(nd.right, qs, qe);
    }

    return ans;
}

void build(int s, int e) { build(1, s, e); }
void add(int us, int ue, int delta) { add(1, us, ue, delta); }
ll query(int qs, int qe) { return query(1, qs, qe); }

int main() {
    rd2(n, q);

    int i;
    int t;
    asc(i, 1, n) {
        rd(t);
        a[i] = t;
    }
    getchar();
    build(1, n);

    char op;
    asc(i, 1, q) {
        op = getchar();
        if (op == 'Q') {
            int qa, qb;
            rd2(qa, qb);
            ll ans = query(qa, qb);
            printf("%lld\n", ans);
        }

        else if (op == 'C') {
            int ua, ub, c;
            rd3(ua, ub, c);
            add(ua, ub, c);
        }
        getchar();
    }

    return 0;
}
