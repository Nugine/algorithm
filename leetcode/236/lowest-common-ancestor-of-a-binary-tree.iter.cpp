// https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

#include <vector>
using namespace std;

class Solution {
  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr) {
            return nullptr;
        }
        vector<TreeNode *> stk{root};
        TreeNode *popped = nullptr;

        vector<TreeNode *> p_path;

        while (!stk.empty()) {
            TreeNode *cur = stk.back();

            if (popped == nullptr) {
                goto state1;
            } else if (popped == cur->left) {
                goto state2;
            } else {
                goto state3;
            }
        state1:
            if (cur->left) {
                stk.push_back(cur->left);
                popped = nullptr;
                continue;
            }
        state2:
            if (cur->right) {
                stk.push_back(cur->right);
                popped = nullptr;
                continue;
            }
        state3:
            if (p_path.empty()) {
                if (cur == q) {
                    swap(p, q);
                }
                if (cur == p) {
                    p_path = stk;
                };
            } else {
                if (cur == q) {
                    int len = min(stk.size(), p_path.size());
                    for (int i = len - 1; i >= 0; --i) {
                        if (stk[i] == p_path[i]) {
                            return stk[i];
                        }
                    }
                }
            }

            stk.pop_back();
            popped = cur;
        }

        return nullptr;
    }
};