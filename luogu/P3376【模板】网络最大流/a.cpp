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

const ll INF = 0x3f3f3f3f3f3f3f3f;
const int N = 200 + 7;
const int M = 5000 + 7;

struct Edge {
    int v;
    ll cap, flow;
    Edge *next;
    Edge *rev;
};

struct Node {
    Edge *edges;
};

Node graph[N];
int n, m, s, t;

int dep[N];
Node gf[N];

void add_edge(int u, int v, ll cap) {
    static Edge pool[M * 2];
    static int cnt = 0;
    Edge *e1 = &pool[cnt++];
    Edge *e2 = &pool[cnt++];
    *e1 = {v, cap, 0, graph[u].edges, e2};
    graph[u].edges = e1;
    *e2 = {u, 0, 0, graph[v].edges, e1};
    graph[v].edges = e2;
}

// 求层次图
bool bfs() {
    queue<int> q;
    memset(dep, 0, sizeof(int) * (n + 1));

    q.push(s);
    dep[s] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (Edge *e = graph[u].edges; e != nullptr; e = e->next) {
            int v = e->v;
            if (dep[v] == 0 && e->cap > e->flow) {
                dep[v] = dep[u] + 1;
                q.push(v);
            }
        }
    }

    return dep[t] != 0;
}

// 求阻塞流
ll dfs(int u, ll flow) {
    if (u == t || flow == 0) {
        return flow;
    }

    ll ans = 0;
    // Edge *&e: 当前弧优化
    for (Edge *&e = gf[u].edges; e != nullptr; e = e->next) {
        int v = e->v;
        if (dep[v] != dep[u] + 1) {
            continue;
        }
        ll d = dfs(v, min(flow - ans, e->cap - e->flow));
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

ll solve() {
    ll maxflow = 0;
    while (bfs()) {
        memcpy(gf, graph, sizeof(Node) * (n + 1));
        maxflow += dfs(s, INF);
    }
    return maxflow;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> s >> t;

    int i;
    asc(i, 1, n) { graph[i].edges = nullptr; }

    int u, v, w;
    asc(i, 1, m) {
        cin >> u >> v >> w;
        add_edge(u, v, w);
    }

    cout << solve() << endl;
}