// https://leetcode-cn.com/problems/sort-list/
// https://leetcode-cn.com/problems/7WHec2/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    int get_list_length(ListNode *head) {
        int len = 0;
        for (; head != nullptr; head = head->next) {
            len += 1;
        }
        return len;
    }

    ListNode *advance(ListNode *head, int count) {
        for (int i = 0; i < count; ++i) {
            head = head->next;
        }
        return head;
    }

    ListNode *sortList(ListNode *head) {
        int len = get_list_length(head);
        if (len < 2) {
            return head;
        }
        if (len == 2) {
            ListNode *p1 = head;
            ListNode *p2 = head->next;
            if (p1->val > p2->val) {
                p2->next = p1;
                p1->next = nullptr;
                return p2;
            } else {
                return p1;
            }
        }
        ListNode *l, *r, *t;

        t = advance(head, len / 2);
        l = head;
        r = t->next;
        t->next = nullptr;

        l = sortList(l);
        r = sortList(r);

        ListNode h;
        t = &h;

        while (l && r) {
            if (l->val < r->val) {
                t->next = l;
                t = l;
                l = l->next;
            } else {
                t->next = r;
                t = r;
                r = r->next;
            }
        }
        t->next = (l) ? (l) : (r);
        return h.next;
    }
};