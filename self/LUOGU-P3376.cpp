// 网络流 - 最大流 - EdmondsKarp算法
// <https://www.luogu.org/blog/ONE-PIECE/wang-lao-liu-di-zong-jie>
// [洛谷 P3376](https://www.luogu.org/problemnew/show/P3376)

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 1 << 30;

int n, m, s, t;

struct Node {
    int pre;
    int e;
    vector<int> edges;
} nodes[10000 + 100];

struct Edge {
    int u, v, w;
} edges[200000 + 100];
int edges_len = 0;

void addEdge(int u, int v, int w) {
    Edge &e = edges[edges_len++];
    e.u = u;
    e.v = v;
    e.w = w;
    nodes[u].edges.push_back(edges_len - 1);
}

bool bfs() {
    static bool inque[100000 + 100];
    memset(inque, 0, sizeof(inque));

    queue<int> q;
    inque[s] = 1;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto i : nodes[u].edges) {
            Edge &e = edges[i];
            int v = e.v;

            if (!inque[v] && e.w > 0) {
                nodes[v].pre = u;
                nodes[v].e = i;
                if (v == t) {
                    return true;
                }
                inque[v] = true;
                q.push(v);
            }
        }
    }
    return false;
}

int max_flow() {
    int ans = 0;
    while (bfs()) {
        int mi = INF;
        for (int i = t; i != s; i = nodes[i].pre) {
            Edge &e = edges[nodes[i].e];
            mi = min(mi, e.w);
        }

        for (int i = t; i != s; i = nodes[i].pre) {
            edges[nodes[i].e].w -= mi;
            edges[nodes[i].e ^ 1].w += mi;
        }
        ans += mi;
    }
    return ans;
}

int main() {
    scanf("%d %d %d %d", &n, &m, &s, &t);

    int u, v, w;
    for (int i = 1; i <= m; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
        addEdge(v, u, 0);
    }
    printf("%d\n", max_flow());
    return 0;
}
