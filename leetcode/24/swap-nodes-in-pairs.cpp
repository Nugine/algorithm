// https://leetcode-cn.com/problems/swap-nodes-in-pairs/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *swapPairs(ListNode *head) {
        ListNode h{0, head};
        ListNode *t = &h;
        ListNode *iter = head, *p1, *p2;

        while (iter != nullptr && iter->next != nullptr) {
            p1 = iter;
            p2 = p1->next;
            iter = p2->next;
            t->next = p2;
            p2->next = p1;
            t = p1;
        }
        if (iter) {
            t->next = iter;
            t = iter;
        }
        t->next = nullptr;
        return h.next;
    }
};