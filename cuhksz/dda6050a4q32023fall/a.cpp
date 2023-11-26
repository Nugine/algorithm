// #define LOCAL_DEBUG

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
#define asc(i, s, e) for (i = (s); i <= (e); ++i)
#define rng(i, s, e) for (i = (s); i < (e); ++i)
#define desc(i, s, e) for (i = (s); i >= (e); --i)
#define ordefault(a, b) (a) ? (a) : (b)
#ifdef LOCAL_DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...)
#endif

const int MAXT = 5e5 + 7;
const int MAXC = 3e4 + 7;

int fa[MAXC];
int sz[MAXC];
int delta[MAXC];

void init() {
    int i;
    asc(i, 1, 30000) {
        fa[i] = i;
        sz[i] = 1;
        delta[i] = 0;
    }
}

int root(int x) {
    if (fa[x] == x) {
        return x;
    }

    int rt = root(fa[x]);
    delta[x] += delta[fa[x]];
    fa[x] = rt;

    return rt;
}

void merge(int x, int y) {
    x = root(x);
    y = root(y);
    eprintf("merge: root: x = %d, y=%d\n", x, y);
    if (x == y) {
        return;
    }
    fa[x] = y;
    delta[x] = sz[y];
    sz[y] += sz[x];
}

int position(int x) {
    int p = 0;
    for (int i = x; fa[i] != i; i = fa[i]) {
        p += delta[i];
    }
    return p;
}

int query(int x, int y) {
    if (root(x) != root(y)) {
        return -1;
    }
    int px = position(x);
    int py = position(y);
    eprintf("px = %d, py = %d\n", px, py);
    return abs(px - py) - 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    init();

    char cmd;
    int i, j;

    int T;
    cin >> T;
    while (T--) {
        cin >> cmd >> i >> j;
        eprintf("%c: %d, %d\n", cmd, i, j);
        if (cmd == 'M') {
            merge(i, j);
        } else if (cmd == 'C') {
            int ans = query(i, j);
            printf("%d\n", ans);
        }
    }
}
