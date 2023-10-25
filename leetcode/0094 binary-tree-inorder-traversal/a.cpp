// 0094-binary-tree-inorder-traversal
// https://leetcode.cn/problems/binary-tree-inorder-traversal/
#ifdef LEETCODE_LOCAL
#include "leetcode.h"
#endif

class Solution {
  public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ans;

        stack<TreeNode *> stk;
        TreeNode *popped = nullptr;

        if (root) {
            stk.push(root);
        }

        while (!stk.empty()) {
            TreeNode *cur = stk.top();

            if (popped == nullptr) {
                goto state1;
            } else if (popped == cur->left) {
                goto state2;
            } else {
                goto state3;
            }

        state1:
            if (cur->left) {
                stk.push(cur->left);
                popped = nullptr;
                continue;
            }
        state2:
            ans.push_back(cur->val);
            if (cur->right) {
                stk.push(cur->right);
                popped = nullptr;
                continue;
            }
        state3:
            stk.pop();
            popped = cur;
        }

        return ans;
    }
};