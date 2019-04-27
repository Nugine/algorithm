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

struct Node {
    int s, e;
    int left, right;
    int sum;
    int lazy_change;
} tree[100000 * 4 + 7];

const int ROOT = 1;

void build(int rt, int s, int e) {
    Node &nd = tree[rt];
    nd.s = s, nd.e = e;
    nd.lazy_change = 0;

    if (s == e) {
        nd.left = -1;
        nd.right = -1;
        nd.sum = 1;
    } else {
        nd.left = rt * 2;
        nd.right = rt * 2 + 1;

        int mid = (s + e) / 2;
        build(nd.left, s, mid);
        build(nd.right, mid + 1, e);
        nd.sum = tree[nd.left].sum + tree[nd.right].sum;
    }
}

inline void propagate(Node &nd) {
    if (nd.lazy_change) {
        if (nd.s != nd.e) {
            Node &left = tree[nd.left];
            Node &right = tree[nd.right];
            left.lazy_change = nd.lazy_change;
            right.lazy_change = nd.lazy_change;
            left.sum = (left.e - left.s + 1) * left.lazy_change;
            right.sum = (right.e - right.s + 1) * right.lazy_change;
        }
        nd.lazy_change = 0;
    }
}

void change(int rt, int cs, int ce, int val) {
    Node &nd = tree[rt];
    // printf("[%d,%d] change %d\n", nd.s, nd.e, val);
    if (cs <= nd.s && nd.e <= ce) {
        nd.sum = (nd.e - nd.s + 1) * val;
        nd.lazy_change = val;
        return;
    }

    propagate(nd);

    int mid = (nd.s + nd.e) / 2;

    if (cs <= mid) {
        change(nd.left, cs, ce, val);
    }
    if (ce >= mid + 1) {
        change(nd.right, cs, ce, val);
    }

    nd.sum = tree[nd.left].sum + tree[nd.right].sum;
}

inline int query() { return tree[ROOT].sum; }

int main() {
    int T;
    rd(T);
    int t;

    asc(t, 1, T) {
        int N, Q;
        rd2(N, Q);

        build(ROOT, 1, N);

        int i;
        int X, Y, Z;
        asc(i, 1, Q) {
            rd3(X, Y, Z);
            change(ROOT, X, Y, Z);
        }
        int ans = query();
        printf("Case %d: The total value of the hook is %d.\n", t, ans);
    }
    return 0;
}