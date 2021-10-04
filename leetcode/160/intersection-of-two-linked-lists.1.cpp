#include <algorithm>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
  public:
    int getLength(ListNode *head) {
        int ans = 0;
        for (ListNode *iter = head; iter != nullptr; iter = iter->next) {
            ans += 1;
        }
        return ans;
    }

    ListNode *advance(ListNode *head, int step) {
        int cnt = 0;
        for (ListNode *iter = head; iter != nullptr; iter = iter->next) {
            if (cnt == step) {
                return iter;
            }
            cnt += 1;
        }
        return nullptr;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getLength(headA);
        int lenB = getLength(headB);
        if (lenA > lenB) {
            std::swap(lenA, lenB);
            std::swap(headA, headB);
        }
        headB = advance(headB, lenB - lenA);
        ListNode *iterA = headA;
        ListNode *iterB = headB;
        while (iterA != nullptr) {
            if (iterA == iterB) {
                return iterA;
            }
            iterA = iterA->next;
            iterB = iterB->next;
        }
        return nullptr;
    }
};