// 0104-maximum-depth-of-binary-tree
// https://leetcode.cn/problems/maximum-depth-of-binary-tree/
#ifdef LEETCODE_LOCAL
#include "leetcode.h"
#endif

class Solution {
  public:
    int maxDepth(TreeNode *root) {
        stack<pair<TreeNode *, int>> stk;
        int ans = 0;

        if (root) {
            stk.push({root, 1});
        }

        while (!stk.empty()) {
            TreeNode *cur = stk.top().first;
            int h = stk.top().second;
            stk.pop();

            // vis(cur); // 先序遍历
            ans = max(ans, h);

            if (cur->right) {
                stk.push({cur->right, h + 1});
            }
            if (cur->left) {
                stk.push({cur->left, h + 1});
            }
        }

        return ans;
    }
};
