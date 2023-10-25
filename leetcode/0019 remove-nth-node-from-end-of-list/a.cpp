// https://leetcode.cn/problems/remove-nth-node-from-end-of-list/
#ifdef LEETCODE_LOCAL
#include "leetcode.h"
#endif

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
            p2 = p2->next;
            p1 = p1->next;
        }
        p1->next = p1->next->next;
        return h.next;
    }
};
