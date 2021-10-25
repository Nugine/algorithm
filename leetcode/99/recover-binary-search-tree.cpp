// https://leetcode-cn.com/problems/recover-binary-search-tree/

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
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
  public:
    void recoverTree(TreeNode *root) {
        TreeNode *cur, *next, *prev, *lhs, *rhs;
        prev = lhs = rhs = nullptr;
        for (cur = root; cur; cur = next) {
            if (cur->left) {
                TreeNode *last = cur->left;
                while (last->right != nullptr && last->right != cur) {
                    last = last->right;
                }
                if (last->right == nullptr) {
                    last->right = cur;
                    next = cur->left;
                    continue;
                } else {
                    last->right = nullptr;
                    next = cur->right;
                }
            } else {
                next = cur->right;
            }
        visit:
            if (prev != nullptr && cur->val < prev->val) {
                if (lhs == nullptr) {
                    lhs = prev;
                }
                rhs = cur;
            }
            prev = cur;
        }
        swap(lhs->val, rhs->val);
    }
};

int main() {
    vector<TreeNode> nodes = {3, 1, 4, 0, 0, 2};
    const int n = nodes.size();
    for (int i = 0; i < n; ++i) {
        int left = i * 2 + 1;
        int right = i * 2 + 2;
        if (left < n && nodes[left].val != 0) {
            nodes[i].left = &nodes[left];
        }
        if (right < n && nodes[right].val != 0) {
            nodes[i].right = &nodes[right];
        }
    }
    auto s = Solution();
    s.recoverTree(&nodes[0]);
    printf("\n");
}