// https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    void flatten(TreeNode *root) {
        TreeNode *p, *left, *right;
        while (root) {
            left = root->left;
            right = root->right;
            if (left) {
                for (p = left; p->right; p = p->right) {
                }
                p->right = right;
                root->left = nullptr;
                root->right = left;
            }
            root = root->right;
        }
    }
};

int main() {
    vector<TreeNode> nodes = {1, 2, 5, 3, 4, 0, 6};
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
    s.flatten(&nodes[0]);
    for (auto &x : nodes) {
        cout << x.val << ", ";
    }
    cout << endl;
}