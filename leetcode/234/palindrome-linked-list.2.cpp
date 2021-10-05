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
        int *stk = new int[cnt];
        int top = 0;

        ListNode *iter = head;
        for (int i = 0; i < cnt; ++i) {
            stk[top++] = iter->val;
            iter = iter->next;
        }
        if (len & 1) {
            iter = iter->next;
        }
        for (; iter != nullptr; iter = iter->next) {
            if (iter->val != stk[--top]) {
                return false;
            }
        }
        return true;
    }
};
