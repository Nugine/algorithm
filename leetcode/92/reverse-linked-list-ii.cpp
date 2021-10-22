// https://leetcode-cn.com/problems/reverse-linked-list-ii/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        ListNode h{0, head};
        ListNode *t1, *t2, *iter, *next;
        t1 = &h;
        for (int i = 1; i < left; ++i) {
            t1 = t1->next;
        }
        iter = t1->next;
        t2 = iter;
        for (int i = left; i <= right; ++i) {
            next = iter->next;
            iter->next = t1->next;
            t1->next = iter;
            iter = next;
        }
        t2->next = iter;
        return h.next;
    }
};