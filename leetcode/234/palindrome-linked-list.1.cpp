struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    int getLength(ListNode *head) {
        int ans = 0;
        for (ListNode *iter = head; iter != nullptr; iter = iter->next) {
            ans += 1;
        }
        return ans;
    }

    bool isPalindrome(ListNode *head) {
        int len = getLength(head);
        int cnt = len / 2;
        ListNode *l = nullptr;
        ListNode *iter = head, *next;
        for (int i = 0; i < cnt; ++i) {
            next = iter->next;
            iter->next = l;
            l = iter;
            iter = next;
        }
        if (len & 1) {
            iter = iter->next;
        }
        for (; iter != nullptr; iter = iter->next) {
            if (iter->val != l->val) {
                return false;
            }
            l = l->next;
        }
        return true;
    }
};
