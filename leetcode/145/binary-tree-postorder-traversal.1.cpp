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

void post_dfs(TreeNode &root, vector<int> &out) {
    if (root.left != nullptr) {
        post_dfs(*root.left, out);
    }
    if (root.right != nullptr) {
        post_dfs(*root.right, out);
    }
    out.push_back(root.val);
}

class Solution {
  public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ans;
        if (root != nullptr) {
            post_dfs(*root, ans);
        }
        return ans;
    }
};