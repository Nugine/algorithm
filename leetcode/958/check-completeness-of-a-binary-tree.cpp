// https://leetcode-cn.com/problems/check-completeness-of-a-binary-tree/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

#include <queue>
#include <tuple>
using namespace std;

class Solution {
  public:
    bool isCompleteTree(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }
        queue<tuple<TreeNode *, int>> q;
        q.push(make_tuple(root, 1));

        int cnt = 0;
        while (!q.empty()) {
            auto p = get<0>(q.front());
            auto i = get<1>(q.front());
            q.pop();

            cnt += 1;
            if (cnt != i) {
                return false;
            }

            if (p->left) {
                q.push(make_tuple(p->left, i * 2));
            }
            if (p->right) {
                q.push(make_tuple(p->right, i * 2 + 1));
            }
        }

        return true;
    }
};