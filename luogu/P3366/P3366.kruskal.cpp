// https://www.luogu.com.cn/problem/P3366

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
// #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define eprintf(...)

const int MAXN = 5000;
const int MAXM = 2e5;

struct Solution {
    struct Edge {
        int from;
        int to;
        int weight;
    };

    Edge edges[MAXM * 2 + 7];
    int n, m;

    void run() {
        cin >> n >> m;
        int i;
        asc(i, 1, m) {
            auto &e = edges[i];
            cin >> e.from >> e.to >> e.weight;
        }
        int ans = solve();
        if (ans) {
            cout << ans << '\n';
        } else {
            cout << "orz\n";
        }
    }

    int fa[MAXN + 7];

    int _find(int x) {
        if (fa[x] != x) {
            fa[x] = _find(fa[x]);
        }
        return fa[x];
    }

    int solve() {
        int i;
        asc(i, 1, n) { fa[i] = i; }

        sort(edges + 1, edges + m + 1, [](const Edge &lhs, const Edge &rhs) {
            return lhs.weight < rhs.weight;
        });

        int ans = 0;
        int cnt = 0;
        asc(i, 1, m) {
            const auto &e = edges[i];

            eprintf("%d -> %d, weight = %d\n", e.from, e.to, e.weight);

            int p1 = _find(e.from);
            int p2 = _find(e.to);

            eprintf("p1 = %d, p2 = %d\n", p1, p2);

            if (p1 == p2) {
                continue;
            } else {
                fa[p2] = p1;
                cnt += 1;
                ans += e.weight;
                eprintf("ans += %d\n", e.weight);
            }
        }

        if (cnt != n - 1) {
            return 0;
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
