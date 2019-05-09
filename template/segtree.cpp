// 线段树 - 区间查询，区间修改

typedef long long ll;

struct Node {
    int s, e;
    int left, right;
    ll sum;
    ll lazy_add;
} tree[100000 * 4 + 7];
const int ROOT = 1;

inline void push_up(int rt) {
    Node &nd = tree[rt];
    nd.sum = tree[nd.left].sum + tree[nd.right].sum;
}

inline void push_down(int rt) {
    Node &nd = tree[rt];
    if (nd.lazy_add) {
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
}

void build(int rt, int s, int e, int src[]) {
    Node &nd = tree[rt];
    nd.s = s, nd.e = e;
    nd.lazy_add = 0;
    if (s == e) {
        nd.left = nd.right = -1;
        nd.sum = src[s];
    } else {
        int mid = (nd.s + nd.e) / 2;
        nd.left = rt * 2;
        nd.right = rt * 2 + 1;
        build(nd.left, s, mid, src);
        build(nd.right, mid + 1, e, src);
        push_up(rt);
    }
}

void update(int rt, int us, int ue, int delta) {
    Node &nd = tree[rt];
    if (us <= nd.s && nd.e <= ue) {
        nd.sum += (nd.e - nd.s + 1) * delta;
        nd.lazy_add += delta;
        return;
    }

    push_down(rt);
    int mid = (nd.s + nd.e) / 2;
    if (us <= mid) {
        update(nd.left, us, ue, delta);
    }
    if (ue >= mid + 1) {
        update(nd.right, us, ue, delta);
    }
    push_up(rt);
}

ll query(int rt, int qs, int qe) {
    Node &nd = tree[rt];
    if (qs <= nd.s && nd.e <= qe) {
        return nd.sum;
    }
    push_down(rt);
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
