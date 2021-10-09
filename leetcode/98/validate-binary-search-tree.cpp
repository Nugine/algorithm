// https://leetcode-cn.com/problems/validate-binary-search-tree/
// https://leetcode-cn.com/problems/legal-binary-search-tree-lcci/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

typedef long long ll;

class Solution {
  public:
    bool _inorderTraversal(TreeNode &root, ll &maxVal) {
        if (root.left && !_inorderTraversal(*root.left, maxVal)) {
            return false;
        }
        if (root.val <= maxVal) {
            return false;
        }
        maxVal = root.val;
        if (root.right && !_inorderTraversal(*root.right, maxVal)) {
            return false;
        }
        return true;
    }

    bool isValidBST(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }
        ll maxVal = -(1LL << 60);
        return _inorderTraversal(*root, maxVal);
    }
};