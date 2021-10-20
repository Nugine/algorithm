// https://leetcode-cn.com/problems/linked-list-cycle/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
  public:
    bool hasCycle(ListNode *head) {
        ListNode *p1 = head;
        ListNode *p2 = head;

        while (p2 && p2->next) {
            p2 = p2->next->next;
            p1 = p1->next;

            if (p1 == p2) {
                return true;
            }
        }
        return false;
    }
};