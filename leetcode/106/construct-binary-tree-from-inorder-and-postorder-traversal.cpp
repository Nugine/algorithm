// https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

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

TreeNode *_buildTree(int *inorder, int *postorder, int len) {
    if (len == 0) {
        return nullptr;
    }
    int x = postorder[len - 1];
    int i = find(inorder, inorder + len, x) - inorder;
    TreeNode *ans = new TreeNode(x);
    ans->left = _buildTree(inorder, postorder, i);
    ans->right = _buildTree(inorder + 1 + i, postorder + i, len - 1 - i);
    return ans;
}

class Solution {
  public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return _buildTree(inorder.data(), postorder.data(), inorder.size());
    }
};