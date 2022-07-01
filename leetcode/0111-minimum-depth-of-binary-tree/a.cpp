// 0111-minimum-depth-of-binary-tree
// https://leetcode.cn/problems/minimum-depth-of-binary-tree/
#ifdef LEETCODE_LOCAL
#include "leetcode.h"
#endif

class Solution {
  public:
    int minDepth(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int ans_left = minDepth(root->left);
        int ans_right = minDepth(root->right);
        if (ans_left == 0 || ans_right == 0) {
            return 1 + (ans_left | ans_right);
        }
        return 1 + min(ans_left, ans_right);
    }
};