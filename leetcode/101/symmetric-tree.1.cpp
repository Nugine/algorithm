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

class Solution {
    bool _isSymmetric(TreeNode *lhs, TreeNode *rhs) {
        if (!lhs && !rhs) {
            return true;
        }
        if (!lhs || !rhs) {
            return false;
        }
        if (lhs->val != rhs->val) {
            return false;
        }
        return _isSymmetric(lhs->left, rhs->right) &&
               _isSymmetric(lhs->right, rhs->left);
    }

  public:
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }
        return _isSymmetric(root->left, root->right);
    }
};