// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode h, *t = &h;
        for (ListNode *p = head; p != nullptr; p = p->next) {
            if (p->next == nullptr) {
                t->next = p, t = p;
                break;
            }
            if (p->next->val != p->val) {
                t->next = p, t = p;
                continue;
            }
            while (p->next && p->next->val == p->val) {
                p = p->next;
            }
        }
        t->next = nullptr;
        return h.next;
    }
};