// https://leetcode-cn.com/problems/balanced-binary-tree/
// https://leetcode-cn.com/problems/ping-heng-er-cha-shu-lcof/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

#include <tuple>
using namespace std;

class Solution {
  public:
    tuple<int, bool> _isBalanced(TreeNode &root) {
        int left_depth = 0, right_depth = 0;
        bool a1 = true, a2 = true;
        if (root.left) {
            tie(left_depth, a1) = _isBalanced(*root.left);
        }
        if (root.right) {
            tie(right_depth, a2) = _isBalanced(*root.right);
        }
        int depth = max(left_depth, right_depth) + 1;
        bool ans = a1 && a2 && abs(left_depth - right_depth) <= 1;
        return make_tuple(depth, ans);
    }

    bool isBalanced(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }
        return get<1>(_isBalanced(*root));
    }
};