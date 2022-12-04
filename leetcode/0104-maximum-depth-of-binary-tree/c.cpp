// 0104-maximum-depth-of-binary-tree
// https://leetcode.cn/problems/maximum-depth-of-binary-tree/
#ifdef LEETCODE_LOCAL
#include "leetcode.h"
#endif

class Solution {
  public:
    int maxDepth(TreeNode *root) {
        queue<TreeNode *> q;
        int h = 0;

        if (root) {
            q.push(root);
        }

        while (!q.empty()) {
            int cnt = q.size();
            while (cnt--) {
                TreeNode *p = q.front();
                q.pop();
                if (p->left) {
                    q.push(p->left);
                }
                if (p->right) {
                    q.push(p->right);
                }
            }
            h += 1;
        }
        return h;
    }
};
