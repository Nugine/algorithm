// https://leetcode-cn.com/problems/merge-k-sorted-lists/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <queue>
#include <vector>
using namespace std;

class Solution {
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        using item = pair<int, ListNode *>;
        priority_queue<item, vector<item>, greater<item>> q;

        ListNode h, *t = &h;
        for (auto p : lists) {
            if (p) {
                q.emplace(p->val, p);
            }
        }

        while (!q.empty()) {
            ListNode *p = q.top().second;
            q.pop();
            t->next = p;
            t = p;
            if (p->next) {
                q.emplace(p->next->val, p->next);
            }
        }

        return h.next;
    }
};