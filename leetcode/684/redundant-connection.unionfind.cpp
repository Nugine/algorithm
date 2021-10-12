// https://leetcode-cn.com/problems/redundant-connection/

#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> fa;

    int _find(int x) {
        if (fa[x] != x) {
            fa[x] = _find(fa[x]);
        }
        return fa[x];
    }

    void _union(int x1, int x2) {
        int p1 = _find(x1);
        int p2 = _find(x2);
        fa[p2] = p1;
    }

    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        int n = edges.size();
        this->fa = vector<int>(size_t(n + 1));
        for (int i = 1; i <= n; ++i) {
            fa[i] = i;
        }
        for (const auto &e : edges) {
            int a = e[0], b = e[1];
            int pa = _find(a), pb = _find(b);
            if (pa == pb) {
                return e;
            } else {
                _union(pa, pb);
            }
        }
        throw "unreachable";
    }
};