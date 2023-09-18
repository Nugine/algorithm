/*

Number of Shortest Paths

无向图，无重边，无自环，非负权(?)

dijkstra 最短路，同时计数，O(mlogn)

答案可以被梯形图卡出指数级(?)

相似题目:
+ https://www.luogu.com.cn/problem/P1144

*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define asc(i, s, e) for (i = (s); i <= (e); ++i)
#define rng(i, s, e) for (i = (s); i < (e); ++i)
// #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define eprintf(...)
#define exassert(cond, msg)                                                    \
    if (!(cond))                                                               \
        throw msg;

const int MAXN = 256;

int n;
vector<pii> edges[MAXN];

void add_edge(int u, int v, int w) {
    exassert(w >= 0, "应为非负权图");
    edges[u].push_back({v, w});
    edges[v].push_back({u, w});
}

int dis[MAXN];
bool vis[MAXN];
ll cnt[MAXN];

void dijkstra() {
    priority_queue<pii, vector<pii>, greater<pii>> q;

    memset(dis, 0x3f, sizeof(dis));

    dis[0] = 0;
    q.push({0, 0});
    cnt[0] = 1;

    while (!q.empty()) {
        int u = q.top().second;
        q.pop();

        eprintf("dijkstra: %d\n", u);

        if (vis[u]) {
            continue;
        }
        vis[u] = true;

        for (auto [v, w] : edges[u]) {
            eprintf("dis[%d] vs dis[%d] + %d: %d vs %d\n", v, u, w, dis[v],
                    dis[u] + w);

            if (dis[v] == dis[u] + w) {
                cnt[v] += cnt[u];
                eprintf("cnt[%d] = %d\n", v, int(cnt[v]));
            } else if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                cnt[v] = cnt[u];
                q.push({dis[v], v});
                eprintf("cnt[%d] = %d\n", v, int(cnt[v]));
            }
        }
    }
    eprintf("dis[n-1] = %d\n", dis[n - 1]);
}

ll solve() {
    dijkstra();
    return cnt[n - 1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int u, v, w;
    while (cin >> u >> v >> w) {
        add_edge(u, v, w);
    }

    ll ans = solve();
    cout << ans << endl;
}