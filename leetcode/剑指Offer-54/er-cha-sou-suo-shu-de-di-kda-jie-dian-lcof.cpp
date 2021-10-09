// https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
    TreeNode *_rev_inorder(TreeNode *root, int k, int &count) {
        TreeNode *ans = nullptr;
        ans = root->right ? _rev_inorder(root->right, k, count) : nullptr;
        if (ans) {
            return ans;
        }
        count += 1;
        if (k == count) {
            return root;
        }
        ans = root->left ? _rev_inorder(root->left, k, count) : nullptr;
        return ans;
    }

    int kthLargest(TreeNode *root, int k) {
        int count = 0;
        TreeNode *ans = _rev_inorder(root, k, count);
        return ans->val;
    }
};