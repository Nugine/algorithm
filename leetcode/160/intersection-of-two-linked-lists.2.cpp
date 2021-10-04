#include <algorithm>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
  public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *iterA = headA;
        ListNode *iterB = headB;
        for (;;) {
            if (iterA == iterB) {
                return iterA;
            }
            iterA = (iterA) ? (iterA->next) : (headB);
            iterB = (iterB) ? (iterB->next) : (headA);
        }
        throw "unreachable";
    }
};