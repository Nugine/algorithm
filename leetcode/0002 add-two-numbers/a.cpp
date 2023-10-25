// https://leetcode.cn/problems/add-two-numbers/
#ifdef LEETCODE_LOCAL
#include "leetcode.h"
#endif

class Solution {
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode h;
        ListNode *tail = &h;
        int c = 0;
        for (; l1 && l2; l1 = l1->next, l2 = l2->next) {
            c += l1->val + l2->val;
            tail->next = new ListNode(c % 10);
            tail = tail->next;
            c /= 10;
        }
        for (ListNode *it = l1 ? (l1) : (l2); it; it = it->next) {
            c += it->val;
            tail->next = new ListNode(c % 10);
            tail = tail->next;
            c /= 10;
        }
        if (c > 0) {
            tail->next = new ListNode(c);
        }
        return h.next;
    }
};