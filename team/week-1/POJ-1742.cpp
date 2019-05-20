#include <cstdio>
#include <cstring>
using namespace std;
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))

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

int n, m;
int a[100 + 7];
int c[100 + 7];

int read(void) {
    qread(n);
    qread(m);
    if (n == 0 && m == 0) {
        return 0;
    }
    int i;
    asc(i, 1, n) { qread(a[i]); }
    asc(i, 1, n) { qread(c[i]); }
    return 1;
}
int solve(void);
int main() {
    while (read()) {
        printf("%d\n", solve());
    }
    return 0;
}

int solve(void) {
    static int dp[100000 + 7];
    static int sum[100000 + 7];

    memset(dp, 0, sizeof(dp));

    dp[0] = 1;
    int ans = 0;

    int i;
    asc(i, 1, n) {
        memset(sum, 0, sizeof(sum));

        int l;
        asc(l, a[i], m) {
            if (!dp[l] && dp[l - a[i]] && sum[l - a[i]] < c[i]) {
                dp[l] = 1;
                sum[l] = sum[l - a[i]] + 1;
                ++ans;
            }
        }
    }
    return ans;
}