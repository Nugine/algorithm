// 0092-reverse-linked-list-ii
// https://leetcode.cn/problems/reverse-linked-list-ii/
#ifdef LEETCODE_LOCAL
#include "leetcode.h"
#endif

class Solution {
  public:
    ListNode *reverseBetween(ListNode *l, int left, int right) {
        ListNode *it, *next;
        ListNode d1{}, *t1 = &d1;
        ListNode *t2 = nullptr, *h2 = nullptr;

        int i = 0;
        for (it = l; it; it = next) {
            next = it->next;
            ++i;

            if (i < left) {
                t1->next = it;
                t1 = it;
            } else if (i <= right) {
                it->next = h2;
                h2 = it;
                if (!t2) {
                    t2 = it;
                }
            } else {
                break;
            }
        }

        t1->next = h2;
        t2->next = it;
        return d1.next;
    }
};
