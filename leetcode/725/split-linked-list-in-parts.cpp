// https://leetcode-cn.com/problems/split-linked-list-in-parts/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <algorithm>
#include <vector>
using namespace std;

// n = km + a
// n = a(m+1) + (k-a)m

class Solution {
  public:
    int get_length(ListNode *head) {
        int cnt = 0;
        for (; head; head = head->next) {
            cnt += 1;
        }
        return cnt;
    }
    vector<ListNode *> splitListToParts(ListNode *head, int k) {
        int n = get_length(head);
        int m = n / k;
        int a = n % k;

        vector<ListNode *> ans;
        for (int i = 0; i < k; ++i) {
            int cnt = (i < a) ? (m + 1) : (m);
            ListNode *p = head;
            for (int i = 1; i < cnt; ++i) {
                p = p->next;
            }
            ans.push_back(head);
            if (p) {
                head = p->next;
                p->next = nullptr;
            }
        }
        return ans;
    }
};