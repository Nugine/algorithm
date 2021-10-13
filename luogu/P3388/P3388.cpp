// https://www.luogu.com.cn/problem/P3388

#include <algorithm>
#include <cassert>
#include <climits>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))
#define rng(i, s, e) for ((i) = (s); (i) < (e); ++(i))
#define desc(i, s, e) for ((i) = (s); (i) >= (e); --(i))
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
// #define eprintf(...)

const int MAXN = 2e4;
const int MAXM = 1e5;

struct Solution {
    struct Edge {
        int to;
        Edge *next;
    };

    struct Node {
        Edge *edges;
    };

    Node graph[MAXN + 7];

    void add_edge(int from, int to) {
        static int cnt = 0;
        static Edge edges[MAXM * 2 + 7];
        auto &e = edges[cnt++];
        e = Edge{to, graph[from].edges};
        graph[from].edges = &e;
    }

    bool is_cut[MAXN + 7];

    int n, m;
    void run() {
        cin >> n >> m;
        int i;
        asc(i, 1, m) {
            int x, y;
            cin >> x >> y;
            add_edge(x, y);
            add_edge(y, x);
        }

        int u;
        asc(u, 1, n) {
            if (dfn[u] == 0) {
                tarjan(u, u);
            }
        }

        int ans = 0;
        asc(i, 1, n) { ans += is_cut[i]; }
        cout << ans << '\n';

        asc(u, 1, n) {
            if (is_cut[u]) {
                cout << u << ' ';
            }
        }
        cout << '\n';
    }

    int no = 0;
    int dfn[MAXN + 7];
    int low[MAXN + 7];

    void tarjan(int u, int fa) {
        dfn[u] = low[u] = ++no;

        int child = 0;
        for (Edge *e = graph[u].edges; e != nullptr; e = e->next) {
            int v = e->to;
            if (dfn[v] == 0) {
                tarjan(v, fa);
                low[u] = min(low[u], low[v]);
                child += 1;
                if (low[v] >= dfn[u] && u != fa) {
                    is_cut[u] = true;
                }
            }
            low[u] = min(low[u], dfn[v]);
        }
        if (u == fa && child >= 2) {
            is_cut[u] = true;
        }
    }
};

int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    static Solution s;
    s.run();
    return 0;
}
