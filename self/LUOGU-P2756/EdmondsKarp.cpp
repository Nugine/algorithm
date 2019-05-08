// 网络流 - 最大流 - EdmondsKarp算法

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))

const int INF = 1 << 30;

int n, m, s, t;

struct Node {
    int pre;
    int e;
    int partner;
    vector<int> edges;
} nodes[100 + 100];

struct Edge {
    int u, v, w;
} edges[20000 + 100];
int edges_len = 0;

void addEdge(int u, int v, int w) {
    Edge &e = edges[edges_len++];
    e.u = u;
    e.v = v;
    e.w = w;
    nodes[u].edges.push_back(edges_len - 1);
}

bool bfs() {
    static bool inque[100 + 100];
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
            nodes[nodes[i].pre].partner = i;
            edges[nodes[i].e].w -= mi;
            edges[nodes[i].e ^ 1].w += mi;
        }

        ans += mi;
    }
    return ans;
}

int main() {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);

    int pm, pn;
    scanf("%d %d", &pm, &pn);
    n = pn + 2;
    s = n;
    t = n - 1;

    m = 0;
    int u, v;
    while (scanf("%d %d", &u, &v) > 0) {
        if (u == -1 && v == -1) {
            break;
        }
        ++m;
        addEdge(u, v, 1);
        addEdge(v, u, 0);
    }

    asc(v, 1, pm) {
        addEdge(s, v, 1);
        addEdge(v, s, 0);
    }
    asc(u, pm + 1, pn) {
        addEdge(u, t, 1);
        addEdge(t, u, 0);
    }

    printf("%d\n", max_flow());
    asc(u, 1, pm) {
        if (nodes[u].partner) {
            printf("%d %d\n", u, nodes[u].partner);
        }
    }
    return 0;
}
