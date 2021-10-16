// https://leetcode-cn.com/problems/sort-list/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

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

    ListNode *merge(ListNode *t, ListNode *l, ListNode *r) {
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
        while (t->next) {
            t = t->next;
        }
        return t;
    }

    ListNode *sortList(ListNode *head) {
        int len = get_list_length(head);
        if (len < 2) {
            return head;
        }

        ListNode d{0, head};

        for (int delta = 1; delta < len; delta *= 2) {
            ListNode *t = &d;

            for (int cnt = len; cnt > delta; cnt -= delta * 2) {
                ListNode *lt = advance(head, delta - 1);
                ListNode *l = head;
                ListNode *r = lt->next;
                if (cnt > delta * 2) {
                    ListNode *rt = advance(lt, delta);
                    head = rt->next;
                    rt->next = nullptr;
                } else {
                    head = nullptr;
                }
                lt->next = nullptr;
                t = merge(t, l, r);
                t->next = head;
            }
            head = d.next;
        }

        return head;
    }
};

int main() {
    vector<ListNode> list = {-1, 5, 3, 4, 0};
    for (int i = 1; i < int(list.size()); ++i) {
        list[i - 1].next = &list[i];
    }
    auto sol = Solution();
    ListNode *p = sol.sortList(&list[0]);
    while (p) {
        cout << p->val << ", ";
        p = p->next;
    }
    cout << endl;
    return 0;
}