#include <cstring>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))
#define rng(i, s, e) for ((i) = (s); (i) < (e); ++(i))

vector<pair<int, int>> edges[100000 + 7];
int n;

int from[100000 + 7];
int vis[100000 + 7];
int weight[100000 + 7];
int ans[100000 + 7];

int dfs(int u) {
    for (auto &p : edges[u]) {
        int v = p.first;
        int wt = p.second;
        if (v == from[u]) {
            continue;
        }
        from[v] = u;
        weight[v] = wt;
        if (!vis[v]) {
            vis[v] = 1;
            int ans = dfs(v);
            if (ans) {
                return ans;
            }
        } else {
            return u;
        }
    }
    return 0;
}

void dfs2(int u) {
    for (auto &p : edges[u]) {
        int v = p.first;
        int wt = p.second;
        if (ans[v] != 40000) {
            continue;
        } else {
            ans[v] = wt - ans[u];
            dfs2(v);
        }
    }
}

int main() {
    // freopen("../in", "r", stdin);

    scanf("%d", &n);
    int i;
    int x, y, z;

    asc(i, 1, n) {
        scanf("%d%d%d", &x, &y, &z);
        edges[x].push_back(make_pair(y, z));
        edges[y].push_back(make_pair(x, z));
        ans[i] = 40000;
    }

    from[1] = 0;
    vis[1] = 1;
    int s = dfs(1);
    // cout << s << endl;

    struct Edge {
        int u, v, wt;
    };

    vector<Edge> cyc;
    int t = s;
    while (from[t] != s) {
        cyc.push_back({t, from[t], weight[t]});
        t = from[t];
    }
    cyc.push_back({t, from[t], weight[t]});

    // for (auto &e : cyc) {
    //     cout << e.u << " " << e.v << " " << e.wt << endl;
    // }

    int sign = 1;
    int t1 = 0;
    rng(i, 0, cyc.size() - 1) {
        t1 += sign * cyc[i].wt;
        sign *= -1;
    }
    auto &e = cyc[cyc.size() - 1];
    int t2 = e.wt;
    // cout << t1 << " " << t2 << endl;
    // ans[e.v] = (t1 + t2) / 2;
    ans[e.u] = (t2 - t1) / 2;

    dfs2(e.u);

    asc(i, 1, n) { cout << ans[i] << endl; }
}