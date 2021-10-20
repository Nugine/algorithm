// https://leetcode-cn.com/problems/insertion-sort-list/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode h;
        ListNode *iter, *next;
        for (iter = head; iter != nullptr; iter = next) {
            next = iter->next;

            ListNode *pre = &h;
            for (; pre->next != nullptr; pre = pre->next) {
                if (iter->val <= pre->next->val) {
                    break;
                }
            }

            iter->next = pre->next;
            pre->next = iter;
        }
        return h.next;
    }
};

int main() {
    vector<ListNode> list = {4, 2, 1, 3};
    for (int i = 0; i + 1 < int(list.size()); ++i) {
        list[i].next = &list[i + 1];
    }
    auto sol = Solution();
    auto p = sol.insertionSortList(&list[0]);
    for (; p != nullptr; p = p->next) {
        cout << p->val << ", ";
    }
    cout << endl;
}