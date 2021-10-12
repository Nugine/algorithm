// https://leetcode-cn.com/problems/course-schedule-ii/

#include <queue>
#include <vector>
using namespace std;

class Solution {
    struct Node {
        int in_degree;
        vector<int> out_edges;
        Node() : in_degree(0), out_edges() {}
    };

    vector<Node> nodes;

  public:
    vector<int> findOrder(int n, vector<vector<int>> &prerequisites) {
        nodes = vector<Node>(size_t(n));

        for (const auto &e : prerequisites) {
            int from = e[1], to = e[0];
            nodes[from].out_edges.push_back(to);
            nodes[to].in_degree += 1;
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (nodes[i].in_degree == 0) {
                q.push(i);
            }
        }

        vector<int> ans;
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            ans.push_back(u);

            for (auto v : nodes[u].out_edges) {
                if ((--nodes[v].in_degree) == 0) {
                    q.push(v);
                }
            }
        }

        if (ans.size() != n) {
            ans.clear();
        }
        return ans;
    }
};