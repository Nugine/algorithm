// https://leetcode-cn.com/problems/binary-tree-preorder-traversal/

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
    void _preorderTraversal(TreeNode &root, vector<int> &out) {
        out.push_back(root.val);
        if (root.left) {
            _preorderTraversal(*root.left, out);
        }
        if (root.right) {
            _preorderTraversal(*root.right, out);
        }
    }

  public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ans;
        if (root) {
            _preorderTraversal(*root, ans);
        }
        return ans;
    }
};