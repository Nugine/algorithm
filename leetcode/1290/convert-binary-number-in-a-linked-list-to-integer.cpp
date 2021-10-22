// https://leetcode-cn.com/problems/convert-binary-number-in-a-linked-list-to-integer/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <cstdint>

class Solution {
  public:
    int getDecimalValue(ListNode *head) {
        uint32_t ans = 0;
        for (ListNode *p = head; p != nullptr; p = p->next) {
            uint32_t x = (p->val) & 1;
            ans = (ans << 1) | x;
        }
        return ans;
    }
};