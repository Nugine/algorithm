// 0104-maximum-depth-of-binary-tree
// https://leetcode.cn/problems/maximum-depth-of-binary-tree/
#ifdef LEETCODE_LOCAL
#include "leetcode.h"
#endif

class Solution {
  public:
    int maxDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        stack<TreeNode *> stk{{root}};
        TreeNode *popped = nullptr;
        int h = 0;

        while (!stk.empty()) {
            TreeNode *cur = stk.top();

            if (popped == nullptr) {
                goto call;
            }
            if (popped == cur->left) {
                goto ret_from_left;
            }
            if (popped == cur->right) {
                goto ret_from_right;
            }

        call:
            h = max(h, (int)stk.size());
            if (cur->left) {
                stk.push(cur->left);
                popped = nullptr;
                continue;
            }
        ret_from_left:
            if (cur->right) {
                stk.push(cur->right);
                popped = nullptr;
                continue;
            }
        ret_from_right:
            stk.pop();
            popped = cur;
        }

        return h;
    }
};
