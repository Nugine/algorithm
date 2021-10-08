// https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/

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
#include <queue>
using namespace std;

class Solution {
  public:
    int maxDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        queue<TreeNode *> q;
        q.push(root);

        int ans = 0;
        while (!q.empty()) {
            int cnt = q.size();
            while (cnt--) {
                auto p = q.front();
                q.pop();
                if (p->left) {
                    q.push(p->left);
                }
                if (p->right) {
                    q.push(p->right);
                }
            }
            ans += 1;
        }
        return ans;
    }
};