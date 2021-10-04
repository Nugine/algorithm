struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
  public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *p1 = head, *p2 = head;
        for (;;) {
            if (p2 == nullptr || p2->next == nullptr) {
                return nullptr;
            }
            p2 = p2->next->next;
            p1 = p1->next;
            if (p1 == p2) {
                break;
            }
        }
        p1 = head;
        while (p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};
