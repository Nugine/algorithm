// https://leetcode-cn.com/problems/add-two-numbers/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode h;
        ListNode *t = &h;
        int carry = 0;
        while (l1 && l2) {
            int x = l1->val + l2->val + carry;
            carry = x / 10;
            x %= 10;
            l1 = l1->next;
            l2 = l2->next;
            t->next = new ListNode(x);
            t = t->next;
        }
        ListNode *l = (l1) ? (l1) : (l2);
        while (l) {
            int x = l->val + carry;
            carry = x / 10;
            x %= 10;
            l = l->next;
            t->next = new ListNode(x);
            t = t->next;
        }
        if (carry) {
            t->next = new ListNode(carry);
            t = t->next;
        }
        return h.next;
    }
};