// #define LOCAL_DEBUG

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
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

const int INF = 0x3f3f3f3f;
const int MAXV = 200 * 2 + 7;
const int MAXE = 200 * 200 + 7;

struct Edge {
    int v;
    int cap, flow;
    Edge *next, *rev;
};

struct Node {
    Edge *edges;
};

Node g[MAXV];
int V, S, T;

Edge pool[MAXE * 2];
int cnt = 0;

int dep[MAXV];
Node gf[MAXV];

void add_edge(int u, int v, int cap) {
    Edge *e1 = &pool[cnt++];
    Edge *e2 = &pool[cnt++];
    *e1 = {v, cap, 0, g[u].edges, e2};
    *e2 = {u, 0, 0, g[v].edges, e1};
    g[u].edges = e1;
    g[v].edges = e2;
}

bool bfs() {
    queue<int> q;
    memset(dep, 0, sizeof(int) * V);

    q.push(S);
    dep[S] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (Edge *e = g[u].edges; e != nullptr; e = e->next) {
            int v = e->v;
            if (dep[v] == 0 && e->cap > e->flow) {
                dep[v] = dep[u] + 1;
                q.push(v);
            }
        }
    }

    return dep[T] != 0;
}

int dfs(int u, int flow) {
    if (u == T || flow == 0) {
        return flow;
    }

    int ans = 0;
    for (Edge *&e = gf[u].edges; e != nullptr; e = e->next) {
        int v = e->v;
        if (dep[v] != dep[u] + 1) {
            continue;
        }
        int d = dfs(v, min(flow - ans, e->cap - e->flow));
        if (d == 0) {
            continue;
        }
        ans += d;
        e->flow += d;
        e->rev->flow -= d;
        if (ans == flow) {
            return ans;
        }
    }
    return ans;
}

int dinic() {
    int maxflow = 0;
    while (bfs()) {
        memcpy(gf, g, sizeof(Node) * V);
        maxflow += dfs(S, INF);
    }
    return maxflow;
}

const int N = 200 + 7;
int mat[N][N];
int n;

bool solve() {
    int i, j;
    asc(i, 1, n) {
        asc(j, 1, n) {
            if (mat[i][j]) break;
        }
        if (j > n) {
            return false;
        }
    }
    asc(j, 1, n) {
        asc(i, 1, n) {
            if (mat[i][j]) break;
        }
        if (i > n) {
            return false;
        }
    }

    V = n * 2 + 2;
    S = 0;
    T = n * 2 + 1;

    memset(g, 0, sizeof(Node) * V);
    cnt = 0;

    asc(i, 1, n) {
        asc(j, 1, n) {
            if (mat[i][j]) {
                add_edge(i, n + j, 1);
            }
        }
    }
    asc(i, 1, n) { add_edge(S, i, 1); }
    asc(j, 1, n) { add_edge(n + j, T, 1); }

    int maxflow = dinic();
    return maxflow == n;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cases;
    cin >> cases;
    while (cases--) {
        int i, j;

        cin >> n;
        asc(i, 1, n) {
            asc(j, 1, n) { cin >> mat[i][j]; }
        }

        if (solve()) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
}
