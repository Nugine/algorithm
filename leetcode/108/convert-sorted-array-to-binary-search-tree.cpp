// https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/

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
  public:
    TreeNode *build(int *a, int n) {
        if (n == 0) {
            return nullptr;
        }
        if (n == 1) {
            return new TreeNode(a[0]);
        }
        if (n == 2) {
            TreeNode *p1 = new TreeNode(a[0]);
            TreeNode *p2 = new TreeNode(a[1], p1, nullptr);
            return p2;
        }
        if (n == 3) {
            TreeNode *p1 = new TreeNode(a[0]);
            TreeNode *p2 = new TreeNode(a[2]);
            TreeNode *p3 = new TreeNode(a[1], p1, p2);
            return p3;
        }
        int mid = n / 2;
        TreeNode *p = new TreeNode(a[mid]);
        p->left = build(a, mid);
        p->right = build(a + mid + 1, n - mid - 1);
        return p;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return build(nums.data(), nums.size());
    }
};