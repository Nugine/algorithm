// https://www.luogu.com.cn/problem/P3371
// https://www.luogu.com.cn/problem/P4779

#include <algorithm>
#include <cassert>
#include <climits>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))
#define rng(i, s, e) for ((i) = (s); (i) < (e); ++(i))
#define desc(i, s, e) for ((i) = (s); (i) >= (e); --(i))
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
// #define eprintf(...)

const int MAXN = 1e4;
const int MAXM = 5e5;

struct Solution {
    struct Edge {
        int to;
        int weight;
        Edge *next;
    };
    struct Node {
        Edge *edges;
    };

    Node graph[MAXN + 7];

    void add_edge(int u, int v, int w) {
        static Edge edges[MAXM + 7];
        static int cnt = 0;
        auto &e = edges[cnt++];
        e = Edge{v, w, graph[u].edges};
        graph[u].edges = &e;
    }

    int n, m, s;
    int dis[MAXN + 7];
    bool vis[MAXN + 7];
    void run() {
        cin >> n >> m >> s;
        int i;
        asc(i, 1, m) {
            int u, v, w;
            cin >> u >> v >> w;
            add_edge(u, v, w);
        }
        solve();
        asc(i, 1, n) {
            if (dis[i] == INT_MAX / 2) {
                cout << ((1LL << 31) - 1) << ' ';
            } else {
                cout << dis[i] << ' ';
            }
        }
        cout << '\n';
    }

    void solve() {
        fill(dis + 1, dis + n + 1, INT_MAX / 2);
        dis[s] = 0;

        typedef pair<int, int> pii;
        priority_queue<pii, vector<pii>, greater<pii>> q;
        q.push({0, s});

        while (!q.empty()) {
            int d = q.top().first;
            int u = q.top().second;
            q.pop();

            if (vis[u]) {
                continue;
            }
            vis[u] = true;

            for (Edge *e = graph[u].edges; e != nullptr; e = e->next) {
                if (vis[e->to]) {
                    continue;
                }
                int new_dis = e->weight + d;
                if (new_dis < dis[e->to]) {
                    dis[e->to] = new_dis;
                    q.push({new_dis, e->to});
                }
            }
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
