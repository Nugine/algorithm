// 2589 minimum-time-to-complete-all-tasks
// https://leetcode.cn/problems/minimum-time-to-complete-all-tasks
#ifdef LEETCODE_LOCAL
#include "leetcode.h"
#endif

#define rng(i, s, e) for ((i) = (s); (i) < (e); ++(i))
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))

const int N = 2000 + 7;

struct Task {
    int l, r, d;
};

Task tasks[N];
int len;

struct Period {
    int l, r;
};

Period stk[N];
int top;
int sum[N];

void stk_init() {
    stk[0] = {0, 0};
    top = 0;
    sum[0] = 0;
}

void stk_push(Period p) {
    int d = p.r - p.l + 1;
    stk[++top] = p;
    sum[top] = sum[top - 1] + d;
}

void stk_pop() { --top; }

int stk_sum(int l, int r) { return sum[r] - sum[l - 1]; }

int solve() {
    sort(tasks, tasks + len, [](const auto &lhs, const auto &rhs) {
        if (lhs.r != rhs.r) {
            return lhs.r < rhs.r;
        }
        return lhs.l < rhs.l;
    });

    stk_init();

    int i;
    rng(i, 0, len) {
        const auto [tl, tr, td] = tasks[i];

        if (stk[top].r < tl) {
            stk_push({tr - td + 1, tr});
        } else {
            const auto iter = lower_bound(
                stk, stk + top + 1, tl, [](const auto &ele, const int val) { return ele.r < val; });

            int low = iter - stk;

            int d;
            if (tl <= stk[low].l) {
                d = td - stk_sum(low, top);
            } else {
                d = td - stk_sum(low + 1, top) - (stk[low].r - tl + 1);
            }

            if (d > 0) {
                while (top > 0 && stk[top].r >= tr - d + 1) {
                    d += (stk[top].r - stk[top].l + 1);
                    stk_pop();
                }

                stk_push({tr - d + 1, tr});
            }
        }
    }

    return sum[top];
}

class Solution {
  public:
    int findMinimumTime(vector<vector<int>> &input) {
        len = 0;
        for (const auto &t : input) {
            tasks[len++] = {t[0], t[1], t[2]};
        }
        return solve();
    }
};