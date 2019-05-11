#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
typedef unsigned long long ull;
const int MAXN = 1e3 + 7;
const int M = 1e6;

inline void fun(ull d, ull e, ull &a, ull &b, ull &c) {
    ull d11 = d / M, d12 = d % M;
    ull e11 = e / M, e12 = e % M;
    c = d12 * e12;
    b = c / M, c = c % M;
    b += d11 * e12 + e11 * d12;
    a = b / M, b = b % M;
    a += d11 * e11;
}

struct Node {
    int idx;
    ull d, e;
    bool operator<(const Node &rhs) {
        ull a1, b1, c1;
        ull a2, b2, c2;
        fun(d, rhs.e, a1, b1, c1);
        fun(e, rhs.d, a2, b2, c2);
        if (a1 == a2 && b1 == b2 && c1 == c2) {
            return idx < rhs.idx;
        }
        if (a1 != a2) {
            return a1 < a2;
        }
        if (b1 != b2) {
            return b1 < b2;
        }
        return c1 < c2;
    }
};

Node nodes[MAXN];

int main() {
    // freopen("in", "r", stdin);
    int a, b, c;
    int n;
    while (scanf("%d", &n) > 0) {
        int i;
        for (i = 1; i <= n; ++i) {
            scanf("%d %d %d", &a, &b, &c);
            Node &nd = nodes[i];
            nd.idx = i;
            nd.d = ull(a) + b;
            nd.e = nd.d + c;
        }
        sort(nodes + 1, nodes + n + 1);
        printf("%d", nodes[1].idx);
        for (i = 2; i <= n; ++i) {
            printf(" %d", nodes[i].idx);
        }
        putchar('\n');
    }
    return 0;
}