#include <cstring>
#include <vector>
using namespace std;

int dfs(vector<vector<int>> &graph, int color[], int u, int c) {
    color[u] = c;
    for (auto v : graph[u]) {
        if (color[v] == c) {
            goto nope;
        }
        if (color[v] == 0) {
            if (dfs(graph, color, v, -c) == false) {
                goto nope;
            }
        }
    }
    return true;
nope:
    color[u] = 0;
    return false;
}

class Solution {
  public:
    bool isBipartite(vector<vector<int>> &graph) {
        int color[1000];
        memset(color, 0, sizeof(color));

        int len = graph.size();
        for (int u = 0; u < len; ++u) {
            if (color[u] == 0) {
                if (dfs(graph, color, u, 1) == false) {
                    if (dfs(graph, color, u, -1) == false) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
