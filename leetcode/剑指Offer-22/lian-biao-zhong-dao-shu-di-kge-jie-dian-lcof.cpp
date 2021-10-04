struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
  public:
    ListNode *getKthFromEnd(ListNode *head, int k) {
        int cnt = 0;
        ListNode *iter;
        for (iter = head; iter != nullptr; iter = iter->next) {
            cnt += 1;
            if (cnt == k) {
                break;
            }
        }
        if (iter == nullptr) {
            return nullptr;
        }
        ListNode *p = head;
        while (iter->next != nullptr) {
            iter = iter->next;
            p = p->next;
        }
        return p;
    }
};