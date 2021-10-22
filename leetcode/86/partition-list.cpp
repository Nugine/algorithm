// https://leetcode-cn.com/problems/partition-list/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *partition(ListNode *head, int x) {
        ListNode h1, *t1 = &h1;
        ListNode h2, *t2 = &h2;
        for (ListNode *p = head; p != nullptr; p = p->next) {
            ListNode *&t = (p->val < x) ? (t1) : (t2);
            t->next = p;
            t = p;
        }
        t1->next = h2.next;
        t2->next = nullptr;
        return h1.next;
    }
};