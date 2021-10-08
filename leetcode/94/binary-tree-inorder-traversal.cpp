// https://leetcode-cn.com/problems/binary-tree-inorder-traversal/

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
    void _inorderTraversal(TreeNode &root, vector<int> &out) {
        if (root.left) {
            _inorderTraversal(*root.left, out);
        }
        out.push_back(root.val);
        if (root.right) {
            _inorderTraversal(*root.right, out);
        }
    }

  public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ans;
        if (root) {
            _inorderTraversal(*root, ans);
        }
        return ans;
    }
};