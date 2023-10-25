// https://leetcode.cn/problems/merge-two-sorted-lists/
#ifdef LEETCODE_LOCAL
#include "leetcode.h"
#endif

class Solution {
  public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode h;
        ListNode *tail = &h;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                tail = tail->next;
                l1 = l1->next;
            } else {
                tail->next = l2;
                tail = tail->next;
                l2 = l2->next;
            }
        }
        tail->next = (l1) ? (l1) : (l2);
        return h.next;
    }
};