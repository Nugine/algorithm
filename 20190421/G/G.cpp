#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
#define rd(x) scanf("%d", &(x))
#define rd2(x, y) scanf("%d %d", &(x), &(y))
#define rd3(x, y, z) scanf("%d %d %d", &(x), &(y), &(z))
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))
#define desc(i, s, e) for ((i) = (s); (i) >= (e); --(i))
#define rng(i, s, e) for ((i) = (s); (i) < (e); ++(i))
#define pdln(x) printf("%d\n", (x))

int point[40000 + 4];

struct Post {
    int l, r;
} posts[10000 + 4];

int id[10000000 + 7];

struct Node {
    int s, e;
    bool covered;
    bool lazy_cover;
} tree[40000 * 4 + 7];
const int ROOT = 1;

void build(int rt, int s, int e) {
    Node &nd = tree[rt];
    nd.s = s, nd.e = e;
    nd.covered = false;
    nd.lazy_cover = false;

    if (nd.s != nd.e) {

        int left = rt * 2;
        int right = rt * 2 + 1;
        int mid = (s + e) / 2;

        build(left, s, mid);
        build(right, mid + 1, e);
    }
}

void push_down(int rt) {
    Node &nd = tree[rt];
    if (nd.lazy_cover) {
        if (nd.s != nd.e) {
            Node &left = tree[rt * 2];
            Node &right = tree[rt * 2 + 1];
            left.covered = true;
            right.covered = true;
            left.lazy_cover = true;
            right.lazy_cover = true;
        }
        nd.lazy_cover = false;
    }
}

void cover(int rt, int cs, int ce) {
    Node &nd = tree[rt];

    // printf("[%d,%d] cover [%d,%d]\n", point[cs - 1], point[ce - 1],
    //        point[nd.s - 1], point[nd.e - 1]);

    if (cs <= nd.s && nd.e <= ce) {
        nd.covered = true;
        // printf("[%d,%d] covered\n", point[nd.s - 1], point[nd.e - 1]);

        nd.lazy_cover = true;
        return;
    }

    push_down(rt);

    int mid = (nd.s + nd.e) / 2;
    int left = rt * 2;
    int right = rt * 2 + 1;

    if (cs <= mid) {
        cover(left, cs, ce);
    }
    if (ce >= mid + 1) {
        cover(right, cs, ce);
    }
    nd.covered = (tree[left].covered && tree[right].covered);
    // printf("[%d,%d] %s\n", point[nd.s - 1], point[nd.e - 1],
    //        nd.covered ? "covered" : "uncovered");
}

bool query(int rt, int qs, int qe) {
    Node &nd = tree[rt];

    // printf("[%d,%d] query [%d,%d]\n", point[qs - 1], point[qe - 1],
    //        point[nd.s - 1], point[nd.e - 1]);

    if (qs <= nd.s && nd.e <= qe) {
        return nd.covered;
    }
    push_down(rt);

    int mid = (nd.s + nd.e) / 2;
    int left = rt * 2;
    int right = rt * 2 + 1;

    bool ans = true;
    if (qs <= mid) {
        ans = (ans && query(left, qs, qe));
    }
    if (qe >= mid + 1) {
        ans = (ans && query(right, qs, qe));
    }
    return ans;
}

int main() {
    int T;
    rd(T);
    while (T--) {
        int n;
        rd(n);

        int len = 0;
        int i;
        asc(i, 1, n) {
            Post &p = posts[i];
            rd2(p.l, p.r);
            point[len++] = p.l;
            point[len++] = p.l + 1;
            point[len++] = p.r;
            point[len++] = p.r + 1;
        }

        sort(point, point + len);
        len = unique(point, point + len) - point;

        rng(i, 0, len) { id[point[i]] = i + 1; }

        build(ROOT, 1, len);

        int ans = 0;
        desc(i, n, 1) {
            Post &p = posts[i];

            bool isCovered = query(ROOT, id[p.l], id[p.r]);
            // printf("main [%d,%d] %s\n", p.l, p.r,
            //        isCovered ? "covered" : "uncovered");
            if (!isCovered) {
                ++ans;
                cover(ROOT, id[p.l], id[p.r]);
            }
            isCovered = query(ROOT, id[p.l], id[p.r]);
            // printf("main [%d,%d] %s\n", p.l, p.r,
            //        isCovered ? "covered" : "uncovered");
        }
        pdln(ans);
    }
    return 0;
}