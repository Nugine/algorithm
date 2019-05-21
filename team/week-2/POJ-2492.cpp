#include <cstdio>
#include <cstring>
using namespace std;

inline void qread(int &x) { scanf("%d", &x); }
inline void qread2(int &x, int &y) { scanf("%d%d", &x, &y); }

struct Node {
    int root;
    int diff;
};

const int MAXN = 2000 + 3;
Node nodes[MAXN];

int find(int x) {
    int rt = nodes[x].root;
    if (rt == 0) {
        return x;
    }
    int nrt = find(rt);
    nodes[x].diff ^= nodes[rt].diff;
    nodes[x].root = nrt;
    return nrt;
}

int main() {
    int T;
    qread(T);

    int t;
    for (t = 1; t <= T; ++t) {
        memset(nodes, 0, sizeof(nodes));
        int n, m;
        qread2(n, m);

        int flag = 1;
        while (m--) {
            int x1, x2;
            qread2(x1, x2);

            if (flag) {
                int r1 = find(x1);
                int r2 = find(x2);

                // printf("%d %d\n", x1, x2);
                // printf("%d %d\n", r1, r2);
                // printf("%d %d\n\n", nodes[x1].diff,
                //        nodes[x2].diff);

                if (r1 == r2) {
                    int diff = nodes[x1].diff ^ nodes[x2].diff;
                    if (!diff) {
                        flag = 0;
                        // printf("%d %d invalid\n", x1, x2);
                    }
                    // else {
                    //     printf("%d %d valid\n", x1, x2);
                    // }
                } else {
                    nodes[r2].root = r1;
                    nodes[r2].diff = nodes[x1].diff ^ nodes[x2].diff ^ 1;
                }
            }
        }
        printf("Scenario #%d:\n", t);
        if (flag) {
            printf("No suspicious bugs found!\n");
        } else {
            printf("Suspicious bugs found!\n");
        }
        putchar('\n');
    }
}
