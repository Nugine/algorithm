// https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/
// https://leetcode-cn.com/problems/er-cha-shu-de-shen-du-lcof/

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
using namespace std;

class Solution {
  public:
    int maxDepth(TreeNode *root) {
        if (root) {
            int l = maxDepth(root->left);
            int r = maxDepth(root->right);
            return max(l, r) + 1;
        } else {
            return 0;
        }
    }
};