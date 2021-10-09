// https://leetcode-cn.com/problems/find-bottom-left-tree-value/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

#include <tuple>
using namespace std;

class Solution {
  public:
    tuple<int, int> _findBottomLeftValue(TreeNode &root, int depth) {
        int ld = 0, rd = 0;
        int lv, rv;
        if (root.left) {
            tie(lv, ld) = _findBottomLeftValue(*root.left, depth + 1);
        }
        if (root.right) {
            tie(rv, rd) = _findBottomLeftValue(*root.right, depth + 1);
        }
        if (root.left == nullptr && root.right == nullptr) {
            return make_tuple(root.val, depth);
        }
        return make_tuple((ld >= rd) ? (lv) : (rv), max(ld, rd));
    }

    int findBottomLeftValue(TreeNode *root) {
        int val, depth;
        tie(val, depth) = _findBottomLeftValue(*root, 1);
        return val;
    }
};