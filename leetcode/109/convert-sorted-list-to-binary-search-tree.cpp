// https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
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
    int get_length(ListNode *head) {
        int cnt = 0;
        for (; head; head = head->next) {
            cnt += 1;
        }
        return cnt;
    }
    TreeNode *_sortedListToBST(ListNode *&head, int count) {
        if (count == 0) {
            return nullptr;
        }
        int mid = (count - 1) / 2;
        TreeNode *root = new TreeNode();
        root->left = _sortedListToBST(head, mid);
        root->val = head->val;
        head = head->next;
        root->right = _sortedListToBST(head, count - 1 - mid);
        return root;
    }

    TreeNode *sortedListToBST(ListNode *head) {
        int len = get_length(head);
        return _sortedListToBST(head, len);
    }
};