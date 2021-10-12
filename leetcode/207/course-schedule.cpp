// https://leetcode-cn.com/problems/course-schedule/

#include <queue>
#include <vector>
using namespace std;

class Solution {
  public:
    struct Node {
        int in_degree;
        vector<int> out_edges;
        Node() : in_degree(0), out_edges() {}
    };

    vector<Node> nodes;

    bool canFinish(int n, vector<vector<int>> &prerequisites) {
        nodes = vector<Node>(size_t(n));
        for (const auto &e : prerequisites) {
            int from = e[1], to = e[0];
            nodes[to].in_degree += 1;
            nodes[from].out_edges.push_back(to);
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (nodes[i].in_degree == 0) {
                q.push(i);
            }
        }

        int cnt = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            cnt += 1;

            for (auto v : nodes[u].out_edges) {
                if ((--nodes[v].in_degree) == 0) {
                    q.push(v);
                }
            }
        }

        return cnt == n;
    }
};