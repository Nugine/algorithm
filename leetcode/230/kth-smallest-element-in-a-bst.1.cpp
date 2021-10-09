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
    TreeNode *_kthSmallest(TreeNode *root, int k, int &rv_count) {
        if (root == nullptr) {
            return nullptr;
        }

        int left_count = 0, right_count = 0;
        TreeNode *ans = nullptr;
        ans = _kthSmallest(root->left, k, left_count);
        if (ans) {
            return ans;
        }
        k -= left_count;
        if (k == 1) {
            return root;
        }
        k -= 1;
        ans = _kthSmallest(root->right, k, right_count);
        if (ans) {
            return ans;
        }
        rv_count = left_count + 1 + right_count;
        return nullptr;
    }

    int kthSmallest(TreeNode *root, int k) {
        int count = 0;
        TreeNode *ans = _kthSmallest(root, k, count);
        return ans->val;
    }
};