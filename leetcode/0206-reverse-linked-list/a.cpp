// 0206-reverse-linked-list
// https://leetcode.cn/problems/reverse-linked-list/
#ifdef LEETCODE_LOCAL
#include "leetcode.h"
#endif

class Solution {
  public:
    ListNode *reverseList(ListNode *l) {
        ListNode *head = nullptr;
        ListNode *it, *next;

        for (it = l; it; it = next) {
            next = it->next;
            it->next = head;
            head = it;
        }

        return head;
    }
};