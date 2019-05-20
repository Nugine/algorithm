#include <cstdio>
#include <deque>
using namespace std;
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))
#define desc(i, s, e) for ((i) = (s); (i) >= (e); --(i))

template <typename T> void qread(T &a) {
    char c = getchar();
    int s = 1;
    while (c < '0' || c > '9') {
        if (c == '-') {
            s = -1;
        }
        c = getchar();
    }
    T x = 0;
    while (c >= '0' && c <= '9') {
        x = 10 * x + c - '0';
        c = getchar();
    }
    a = s * x;
}

// for i from n to 0
// dp[i] = a[i] + max( dp[k] for k in [i+l, i+r] ), i+l <= n
// dp[i] = a[i] + 0,                                i+l >  n

// optimization:
// max( dp[k] for k in [i+l, i+r] )
// O(1)

int n, l, r;
int a[200000 + 7];

int dp[200000 + 7];

int main() {
    qread(n);
    qread(l);
    qread(r);

    int i;
    asc(i, 0, n) { qread(a[i]); }

    deque<int> q;
    q.push_back(n + 1);

    desc(i, n, 0) {
        if (i + l <= n) {
            while (q.size() && dp[q.front()] <= dp[i + l]) {
                q.pop_front();
            }
            q.push_front(i + l);
            while (q.size() && q.back() > i + r) {
                q.pop_back();
            }
        }
        if (i + l <= n) {
            dp[i] = a[i] + dp[q.back()];
        } else {
            dp[i] = a[i];
        }
        // printf("%d: [%d, %d] max = %d, [%d]\n", i, i + l, i + r,
        // dp[q.back()],
        //        q.back());
        // for (int j = 0; j <= n; ++j) {
        //     printf("%d ", dp[j]);
        // }
        // putchar('\n');
        // for (auto j : q) {
        //     printf("%d ", dp[j]);
        // }
        // putchar('\n');
    }
    printf("%d\n", dp[0]);
    return 0;
}
