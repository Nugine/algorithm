// https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
#include <vector>
using namespace std;

TreeNode *_buildTree(int *preorder, int *inorder, int len) {
    if (len == 0) {
        return nullptr;
    }
    int x = preorder[0];
    int i = find(inorder, inorder + len, x) - inorder;
    TreeNode *ans = new TreeNode(x);
    ans->left = _buildTree(preorder + 1, inorder, i);
    ans->right = _buildTree(preorder + 1 + i, inorder + 1 + i, len - 1 - i);
    return ans;
}

class Solution {
  public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return _buildTree(preorder.data(), inorder.data(), preorder.size());
    }
};