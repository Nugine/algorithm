// #define LOCAL_DEBUG

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
#define asc(i, s, e) for (i = (s); i <= (e); ++i)
#define rng(i, s, e) for (i = (s); i < (e); ++i)
#define desc(i, s, e) for (i = (s); i >= (e); --i)
#define ordefault(a, b) (a) ? (a) : (b)
#ifdef LOCAL_DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...)
#endif

const int L = 1e4 + 7;

struct Plan {
    int x, y, n;
};

Plan plans[L];
int len;

struct Period {
    int l, r;
};

Period stk[L];
int top;
int sum[L];

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

void stk_display() {
    eprintf("stk = [");
    int i;
    asc(i, 0, top) { eprintf("(%d, %d, %d), ", stk[i].l, stk[i].r, sum[i]); }
    eprintf("]\n");
}

int solve() {
    sort(plans, plans + len, [](const auto &lhs, const auto &rhs) {
        if (lhs.y != rhs.y) {
            return lhs.y < rhs.y;
        }
        return lhs.x < rhs.x;
    });

    stk_init();

    int i;
    rng(i, 0, len) {
        const auto [x, y, n] = plans[i];

        if (stk[top].r < x) {
            stk_push({y - n + 1, y});
        } else {
            const auto iter = lower_bound(
                stk, stk + top + 1, x, [](const auto &ele, const int val) { return ele.r < val; });

            int low = iter - stk;

            int d;
            if (x <= stk[low].l) {
                d = n - stk_sum(low, top);
            } else {
                d = n - stk_sum(low + 1, top) - (stk[low].r - x + 1);
            }

            if (d > 0) {
                while (top > 0 && stk[top].r >= y - d + 1) {
                    d += (stk[top].r - stk[top].l + 1);
                    stk_pop();
                }

                stk_push({y - d + 1, y});
            }
        }
#ifdef LOCAL_DEBUG
        eprintf("i = %d\n", i);
        stk_display();
#endif
    }

    return sum[top];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> len;
    int i;
    int x, y, n;
    rng(i, 0, len) {
        cin >> x >> y >> n;
        plans[i] = {x, y, n};
    }

    int ans = solve();
    cout << ans << endl;
}
