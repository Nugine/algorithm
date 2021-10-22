// https://leetcode-cn.com/problems/add-two-numbers-ii/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *reverse(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode h;
        ListNode *iter, *next;
        for (ListNode *iter = head; iter != nullptr; iter = next) {
            next = iter->next;
            iter->next = h.next;
            h.next = iter;
        }
        return h.next;
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode h, *t = &h;
        int carry = 0;
        for (; l1 && l2; l1 = l1->next, l2 = l2->next) {
            int x = l1->val + l2->val + carry;
            t->next = new ListNode(x % 10);
            t = t->next;
            carry = x / 10;
        }
        for (ListNode *l = (l1) ? (l1) : (l2); l; l = l->next) {
            int x = l->val + carry;
            t->next = new ListNode(x % 10);
            t = t->next;
            carry = x / 10;
        }
        if (carry) {
            t->next = new ListNode(1);
            t = t->next;
        }
        return reverse(h.next);
    }
};