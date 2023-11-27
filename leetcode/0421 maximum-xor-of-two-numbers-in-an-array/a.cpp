// 0421 maximum-xor-of-two-numbers-in-an-array
// https://leetcode.cn/problems/maximum-xor-of-two-numbers-in-an-array
#ifdef LEETCODE_LOCAL
#include "leetcode.h"
#endif

#define desc(i, s, e) for ((i) = (s); (i) >= (e); --(i))
typedef unsigned int uint;

const int MAXN = 2e5 + 7;
const int BITS = 31;

struct Trie01 {
    int next[MAXN * BITS][2];
    int cnt;

    void init() {
        memset(next, 0, sizeof(next));
        cnt = 0;
    }

    void insert(uint x) {
        int p = 0;
        int i;
        desc(i, BITS - 1, 0) {
            int c = (x >> i) & 1;
            if (!next[p][c]) next[p][c] = ++cnt;
            p = next[p][c];
        }
    }

    uint max_xor(uint x) {
        uint ans = 0;
        int p = 0;
        int i;
        desc(i, BITS - 1, 0) {
            int c = (x >> i) & 1;
            if (next[p][c ^ 1]) {
                p = next[p][c ^ 1];
                ans |= (1 << i);
            } else {
                p = next[p][c];
            }
        }
        return ans;
    }
};

Trie01 trie;

class Solution {
  public:
    int findMaximumXOR(vector<int> &nums) {
        trie.init();
        for (uint x : nums) {
            trie.insert(x);
        }
        uint ans = 0;
        for (uint x : nums) {
            ans = max(ans, trie.max_xor(x));
        }
        return ans;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    vector<int> nums{14, 70, 53, 83, 49, 91, 36, 80, 92, 51, 66, 70};
    int ans = Solution().findMaximumXOR(nums);
    printf("ans = %d\n", ans);
}
#endif
