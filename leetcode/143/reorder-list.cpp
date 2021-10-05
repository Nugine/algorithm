// https://leetcode-cn.com/problems/reorder-list/
// https://leetcode-cn.com/problems/LGjMqU/

#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *middleNode(ListNode *head) {
        ListNode *p1 = head, *p2 = head;
        while (p2 != nullptr && p2->next != nullptr &&
               p2->next->next != nullptr) {
            p2 = p2->next->next;
            p1 = p1->next;
        }
        return p1;
    }

    ListNode *reverseList(ListNode *head) {
        ListNode *p = nullptr;
        ListNode *iter = head;
        while (iter != nullptr) {
            ListNode *next = iter->next;
            iter->next = p;
            p = iter;
            iter = next;
        }
        return p;
    }

    void reorderList(ListNode *head) {
        ListNode *mid = middleNode(head);
        ListNode *l2 = reverseList(mid->next);
        ListNode *l1 = head;
        ListNode *n1, *n2;
        while (l2 != nullptr) {
            n1 = l1->next;
            n2 = l2->next;
            l1->next = l2;
            l2->next = n1;
            l1 = n1;
            l2 = n2;
        }
        l1->next = nullptr;
    }
};

int main() {
    std::vector<int> vals = {1, 2, 3, 4};
    std::vector<ListNode> v(vals.size());

    for (int i = 0; i < vals.size(); ++i) {
        ListNode *next = ((i + 1) == vals.size()) ? nullptr : (&v[i + 1]);
        v[i] = ListNode(vals[i], next);
    }
    auto sol = Solution();
    sol.reorderList(&v[0]);
}