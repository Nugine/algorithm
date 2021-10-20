// https://leetcode-cn.com/problems/delete-node-in-a-linked-list/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
  public:
    void deleteNode(ListNode *node) {
        ListNode *next = node->next;
        *node = *next;
    }
};