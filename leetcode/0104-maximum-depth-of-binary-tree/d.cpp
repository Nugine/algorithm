// 0104-maximum-depth-of-binary-tree
// https://leetcode.cn/problems/maximum-depth-of-binary-tree/
#ifdef LEETCODE_LOCAL
#include "leetcode.h"
#endif

class Solution {
  public:
    int maxDepth(TreeNode *root) {
        // 求解最深路径
        vector<TreeNode *> stk;
        TreeNode *popped = nullptr;
        vector<TreeNode *> path;

        if (root) {
            stk.push_back(root);
        }

        while (!stk.empty()) {
            if (stk.size() > path.size()) {
                path = stk;
            }

            TreeNode *cur = stk.back();
            int state =
                (popped == nullptr) ? (1) : (popped == cur->left ? 2 : 3);

            if (state <= 1 && cur->left) {
                stk.push_back(cur->left);
                popped = nullptr;
                continue;
            }
            if (state <= 2 && cur->right) {
                stk.push_back(cur->right);
                popped = nullptr;
                continue;
            }
            if (state <= 3) {
                stk.pop_back();
                popped = cur;
            }
        }

        return path.size();
    }
};
