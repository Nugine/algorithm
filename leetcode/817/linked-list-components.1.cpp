// https://leetcode-cn.com/problems/linked-list-components/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
  public:
    int numComponents(ListNode *head, vector<int> &nums) {
        unordered_set<int> s;
        s.insert(nums.begin(), nums.end());

        int ans = 0;
        bool flag = false;
        for (ListNode *p = head; p != nullptr; p = p->next) {
            bool b = s.count(p->val);
            ans += (flag & !b);
            flag = b;
        }
        ans += flag;
        return ans;
    }
};