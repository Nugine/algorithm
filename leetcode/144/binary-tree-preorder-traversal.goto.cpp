// https://leetcode-cn.com/problems/binary-tree-preorder-traversal/

#include <vector>
using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
  public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ans;
        if (root == nullptr) {
            return ans;
        }

        vector<TreeNode *> stk{root};
        TreeNode *popped = nullptr;

        while (!stk.empty()) {
            TreeNode *cur = stk.back();

            if (popped == nullptr) {
                goto state1;
            } else if (popped == cur->left) {
                goto state2;
            } else {
                goto state3;
            }

        state1:
            ans.push_back(cur->val);
            if (cur->left) {
                stk.push_back(cur->left);
                popped = nullptr;
                continue;
            }
        state2:
            if (cur->right) {
                stk.push_back(cur->right);
                popped = nullptr;
                continue;
            }
        state3:
            stk.pop_back();
            popped = cur;
        }

        return ans;
    }
};