// https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst/

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
    TreeNode *_inorder(TreeNode *root, int k, int &count) {
        if (root == nullptr) {
            return nullptr;
        }
        TreeNode *ans = nullptr;
        ans = _inorder(root->left, k, count);
        if (ans) {
            return ans;
        }
        count += 1;
        if (k == count) {
            return root;
        }
        return _inorder(root->right, k, count);
    }

    int kthSmallest(TreeNode *root, int k) {
        int count = 0;
        TreeNode *ans = _inorder(root, k, count);
        return ans->val;
    }
};