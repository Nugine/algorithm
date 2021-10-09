// https://leetcode-cn.com/problems/path-sum/

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
    bool is_leaf(TreeNode &root) {
        return root.left == nullptr && root.right == nullptr;
    }

    bool _preorder(TreeNode *root, int target_sum, int &sum) {
        sum += root->val;
        if (is_leaf(*root) && target_sum == sum) {
            return true;
        }
        if (root->left && _preorder(root->left, target_sum, sum)) {
            return true;
        }
        if (root->right && _preorder(root->right, target_sum, sum)) {
            return true;
        }
        sum -= root->val;
        return false;
    }

    bool hasPathSum(TreeNode *root, int targetSum) {
        int sum = 0;
        return root != nullptr && _preorder(root, targetSum, sum);
    }
};