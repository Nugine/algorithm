#include <cstdint>
#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))
#define rng(i, s, e) for ((i) = (s); (i) < (e); ++(i))
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

struct Sol {
    int n;
    int heights[1024];

    int stk[1024];
    int top = -1;

    int right[1024];
    int left[1024];

    void run() {
        cin.sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        cin >> n;
        int i;
        asc(i, 1, n) {
            cin >> heights[i];
            left[i] = -1;
            right[i] = n + 1;
        }

        asc(i, 1, n) {

            while (top >= 0 && heights[stk[top]] >= heights[i]) {
                right[stk[top]] = i;
                --top;
            }
            left[i] = (top >= 0) ? (stk[top]) : (0);
            stk[++top] = i;
        }

        int ans = 0;
        asc(i, 1, n) {
            int t = (right[i] - left[i] - 1) * heights[i];
            ans = max(ans, t);
        }

        cout << ans << '\n';
    }
};

int main() {
    static Sol sol;
    sol.run();
    return 0;
}