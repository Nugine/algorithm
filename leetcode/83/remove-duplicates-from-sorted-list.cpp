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
        ListNode *t = head;
        for (ListNode *iter = head->next; iter != nullptr; iter = iter->next) {
            if (iter->val == t->val) {
                continue;
            }
            t->next = iter;
            t = iter;
        }
        t->next = nullptr;
        return head;
    }
};