// https://leetcode-cn.com/problems/rotate-list/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode *tail;
        int n = 1;
        for (tail = head; tail->next; tail = tail->next) {
            n += 1;
        }
        tail->next = head;
        k %= n;
        for (int i = 0; i < n - k; ++i) {
            tail = tail->next;
        }
        head = tail->next;
        tail->next = nullptr;
        return head;
    }
};