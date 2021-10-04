struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode h;
        ListNode *t = &h;
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        while (p1 != nullptr && p2 != nullptr) {
            if (p1->val < p2->val) {
                t->next = p1;
                p1 = p1->next;
            } else {
                t->next = p2;
                p2 = p2->next;
            }
            t = t->next;
        }
        if (p1 != nullptr) {
            t->next = p1;
        }
        if (p2 != nullptr) {
            t->next = p2;
        }
        return h.next;
    }
};