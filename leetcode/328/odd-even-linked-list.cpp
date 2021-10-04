
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *oddEvenList(ListNode *head) {
        ListNode h[2];
        ListNode *tails[2] = {&h[0], &h[1]};
        int which = 1;
        for (ListNode *iter = head; iter != nullptr; iter = iter->next) {
            ListNode *&t = tails[which];
            t->next = iter;
            t = iter;
            which ^= 1;
        }
        tails[0]->next = nullptr;
        tails[1]->next = h[0].next;
        return h[1].next;
    }
};