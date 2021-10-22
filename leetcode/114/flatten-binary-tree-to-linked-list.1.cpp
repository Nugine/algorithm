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
    void _flatten(TreeNode *root, TreeNode *&tail) {
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        tail->right = root;
        tail = root;
        root->left = root->right = nullptr;
        if (left) {
            _flatten(left, tail);
        }
        if (right) {
            _flatten(right, tail);
        }
    }

    void flatten(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        TreeNode h;
        TreeNode *t = &h;
        _flatten(root, t);
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
    cout << endl;
}