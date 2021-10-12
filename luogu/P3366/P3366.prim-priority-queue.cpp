// https://www.luogu.com.cn/problem/P3366

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

const int MAXN = 5000;
const int MAXM = 2e5;

struct Solution {
    struct Edge {
        int to;
        int weight;
        Edge *next;
    };

    Edge edges[MAXM * 2 + 7];
    int edges_count = 0;

    struct Node {
        Edge *edges;
    };

    Node graph[MAXN + 7];
    int n, m;

    void run() {
        cin >> n >> m;
        int i;
        asc(i, 1, m) {
            int x, y, z;
            cin >> x >> y >> z;
            add_edge(x, y, z);
            add_edge(y, x, z);
        }
        int ans = solve();
        if (ans) {
            cout << ans << '\n';
        } else {
            cout << "orz\n";
        }
    }

    void add_edge(int from, int to, int weight) {
        auto &e = edges[edges_count++];
        e = Edge{to, weight, graph[from].edges};
        graph[from].edges = &e;
    }

    bool vis[MAXN + 7];
    int solve() {
        fill(vis + 1, vis + n + 1, false);

        using pii = pair<int, int>;

        priority_queue<pii, vector<pii>, greater<pii>> q;

        int u = 1;
        vis[u] = true;
        for (Edge *e = graph[u].edges; e != nullptr; e = e->next) {
            if (!vis[e->to]) {
                q.push({e->weight, e->to});
            }
        }

        int ans = 0;
        for (int cnt = 1; cnt < n; ++cnt) {
            int min_dis = INT_MAX;
            u = 0;
            while (!q.empty()) {
                int d = q.top().first;
                int v = q.top().second;
                q.pop();
                if (!vis[v]) {
                    min_dis = d;
                    u = v;
                    break;
                }
            }
            if (u == 0) {
                return 0;
            }
            vis[u] = true;
            ans += min_dis;
            for (Edge *e = graph[u].edges; e != nullptr; e = e->next) {
                if (!vis[e->to]) {
                    q.push({e->weight, e->to});
                }
            }
        }

        return ans;
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
