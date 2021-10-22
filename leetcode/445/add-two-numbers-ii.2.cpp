// https://leetcode-cn.com/problems/add-two-numbers-ii/

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
    int get_length(ListNode *head) {
        int cnt = 0;
        for (ListNode *iter = head; iter != nullptr; iter = iter->next) {
            cnt += 1;
        }
        return cnt;
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int n1 = get_length(l1);
        int n2 = get_length(l2);
        if (n1 < n2) {
            swap(l1, l2);
            swap(n1, n2);
        }
        ListNode h, *p, *next;
        for (int i = 0; i < n1 - n2; ++i, l1 = l1->next) {
            p = new ListNode(l1->val, h.next);
            h.next = p;
        }
        for (; l1; l1 = l1->next, l2 = l2->next) {
            p = new ListNode(l1->val + l2->val, h.next);
            h.next = p;
        }
        int carry = 0;
        p = h.next;
        h.next = nullptr;
        for (; p != nullptr; p = next) {
            next = p->next;
            int x = p->val + carry;
            p->val = x % 10;
            carry = x / 10;
            p->next = h.next;
            h.next = p;
        }
        if (carry) {
            p = new ListNode(1, h.next);
            h.next = p;
        }
        return h.next;
    }
};

void make_list(vector<ListNode> &l) {
    int n = l.size();
    for (int i = 0; i + 1 < n; ++i) {
        l[i].next = &l[i + 1];
    }
}

int main() {
    vector<ListNode> l1 = {7, 2, 4, 3};
    vector<ListNode> l2 = {5, 6, 4};
    make_list(l1);
    make_list(l2);
    auto s = Solution();
    auto p = s.addTwoNumbers(&l1[0], &l2[0]);
    ListNode *next;
    for (; p; p = next) {
        next = p->next;
        cout << p->val << ", ";
        delete p;
    }
    cout << endl;
}