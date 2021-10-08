// https://leetcode-cn.com/problems/binary-tree-postorder-traversal/

#include <iostream>
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
  public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ans;

        if (root == nullptr) {
            return ans;
        }

        vector<TreeNode *> stk;
        stk.push_back(root);

        TreeNode *popped = nullptr;

        while (!stk.empty()) {
            TreeNode *cur = stk.back();
            if (popped == nullptr && cur->left) {
                stk.push_back(cur->left);
                continue;
            }
            if (popped == cur->left && cur->right) {
                stk.push_back(cur->right);
                popped = nullptr;
                continue;
            }
            ans.push_back(cur->val);
            stk.pop_back();
            popped = cur;
        }

        return ans;
    }
};

int main() {
    TreeNode nodes[3];
    nodes[0] = TreeNode(1, nullptr, &nodes[1]);
    nodes[1] = TreeNode(2, &nodes[2], nullptr);
    nodes[2] = TreeNode(3, nullptr, nullptr);
    auto sol = Solution();
    auto ans = sol.postorderTraversal(&nodes[0]);
    for (auto x : ans) {
        std::cout << x << ",";
    }
    std::cout << std::endl;
}