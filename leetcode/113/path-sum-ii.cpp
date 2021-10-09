// https://leetcode-cn.com/problems/path-sum-ii/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

#include <vector>
using namespace std;

class Solution {
    int target_sum;
    int sum;
    vector<int> stk;
    vector<vector<int>> anss;

  public:
    void _preorder(TreeNode *root) {
        sum += root->val;
        stk.push_back(root->val);

        bool is_leaf = root->left == nullptr && root->right == nullptr;
        if (is_leaf && target_sum == sum) {
            anss.push_back(stk);
        }
        if (root->left) {
            _preorder(root->left);
        }
        if (root->right) {
            _preorder(root->right);
        }
        sum -= root->val;
        stk.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        this->target_sum = targetSum;
        this->sum = 0;
        this->stk = vector<int>();
        this->anss = vector<vector<int>>();
        if (root != nullptr) {
            _preorder(root);
        }
        return move(anss);
    }
};