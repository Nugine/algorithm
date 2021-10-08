// https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

#include <algorithm>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int>> anss;
        if (!root) {
            return anss;
        }
        vector<int> ans;
        queue<tuple<TreeNode *, int>> q;

        q.push(make_tuple(root, 1));

        int max_level = 1;
        TreeNode *p;
        int level;
        while (!q.empty()) {
            tie(p, level) = q.front();
            q.pop();

            if (level > max_level) {
                anss.push_back(move(ans));
                ans = vector<int>();
                max_level = level;
            }
            ans.push_back(p->val);
            if (p->left) {
                q.push(make_tuple(p->left, level + 1));
            }
            if (p->right) {
                q.push(make_tuple(p->right, level + 1));
            }
        }

        if (!ans.empty()) {
            anss.push_back(move(ans));
        }

        reverse(anss.begin(), anss.end());
        return anss;
    }
};