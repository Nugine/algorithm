// https://leetcode-cn.com/problems/binary-tree-postorder-traversal/

#include <vector>
using std::vector;

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
    void _postorderTraversal(TreeNode &root, vector<int> &ans) {
        if (root.left) {
            _postorderTraversal(*root.left, ans);
        }
        if (root.right) {
            _postorderTraversal(*root.right, ans);
        }
        ans.push_back(root.val);
    }

    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ans;
        if (root) {
            _postorderTraversal(*root, ans);
        }
        return ans;
    }
};