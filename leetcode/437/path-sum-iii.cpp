// https://leetcode-cn.com/problems/path-sum-iii/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

#include <unordered_map>
using namespace std;

typedef long long ll;

class Solution {
  public:
    unordered_map<ll, int> prefix_sum;
    ll sum;
    int target_sum;

    int _preorder(TreeNode *root) {
        sum += root->val;
        int ans = prefix_sum[sum - target_sum];
        prefix_sum[sum] += 1;
        if (root->left) {
            ans += _preorder(root->left);
        }
        if (root->right) {
            ans += _preorder(root->right);
        }
        prefix_sum[sum] -= 1;
        sum -= root->val;
        return ans;
    }

    int pathSum(TreeNode *root, int targetSum) {
        if (root == nullptr) {
            return 0;
        }
        this->prefix_sum = unordered_map<ll, int>();
        this->sum = 0;
        this->target_sum = targetSum;
        prefix_sum[0] = 1;
        return _preorder(root);
    }
};