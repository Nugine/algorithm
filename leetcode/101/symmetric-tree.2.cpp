// https://leetcode-cn.com/problems/symmetric-tree/

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
using namespace std;

class Solution {
  public:
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }
        queue<pair<TreeNode *, TreeNode *>> q;
        q.push(make_pair(root->left, root->right));

        while (!q.empty()) {
            auto [lhs, rhs] = q.front();
            q.pop();

            if (!lhs && !rhs) {
                continue;
            } else if (!lhs || !rhs) {
                return false;
            } else {
                if (lhs->val != rhs->val) {
                    return false;
                }
                q.push(make_pair(lhs->left, rhs->right));
                q.push(make_pair(lhs->right, rhs->left));
            }
        }

        return true;
    }
};