#include <cstdio>
#include <cstring>
using namespace std;

inline int qread(int &x) { return scanf("%d", &x); }
inline int qread2(int &x, int &y) { return scanf("%d%d", &x, &y); }
inline int qread3(int &x, int &y, int &z) {
    return scanf("%d%d%d", &x, &y, &z);
}
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))

struct Node {
    int root;
    int rank;
};

const int MAXN = 50000 + 3;
Node nodes[MAXN];
int n, k;

inline int find(int x) {
    int rt = nodes[x].root;
    if (rt == 0) {
        return x;
    }
    if (nodes[rt].root == 0) {
        return rt;
    }
    int nrt = find(rt);
    nodes[x].rank = (nodes[rt].rank + nodes[x].rank) % 3;
    return nodes[x].root = nrt;
}

inline int judge(int d, int x, int y) {
    if (x > n || y > n) {
        return 1;
    }

    if (d == 2 && x == y) {
        return 1;
    }

    int rx = find(x);
    int ry = find(y);

    Node &nx = nodes[x];
    Node &ny = nodes[y];

    if (rx == ry) {
        if (d == 1) {
            return nx.rank != ny.rank;
        } else {
            return (nx.rank + 1) % 3 != ny.rank;
        }
    } else {
        nodes[ry].root = rx;
        nodes[ry].rank = (nx.rank + (d - 1) - ny.rank + 3) % 3;
        return 0;
    }
}

int main() {
    qread2(n, k);

    int i;
    int d, x, y;

    int ans = 0;
    asc(i, 1, k) {
        qread3(d, x, y);
        ans += judge(d, x, y);
    }
    printf("%d\n", ans);
}