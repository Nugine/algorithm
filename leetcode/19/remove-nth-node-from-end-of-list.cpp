// https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode h(0, head);
        ListNode *p1 = &h;
        ListNode *p2 = &h;
        for (int i = 0; i < n; ++i) {
            p2 = p2->next;
        }
        while (p2->next) {
            p1 = p1->next;
            p2 = p2->next;
        }
        p1->next = p1->next->next;
        return h.next;
    }
};