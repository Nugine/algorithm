#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))
#define desc(i, s, e) for ((i) = (s); (i) >= (e); --(i))
#define clr(arr) (memset(arr, 0, sizeof(arr)))
inline int qread(int &x) { return scanf("%d", &x); }
inline int qread2(int &x, int &y) { return scanf("%d%d", &x, &y); }

const int MAXA = 1e6 + 7;
int cnt[MAXA];
int n, k;

int solve(int ma) {
    int ans;
    desc(ans, ma, 1) {
        int sum = 0;
        for (int t = ans; t <= ma; t += ans) {
            sum += cnt[t];
            if (sum >= k) {
                return ans;
            }
        }
    }
    return 1;
}

int main() {
    while (qread2(n, k) > 0) {
        clr(cnt);
        int i, t;
        int ma = -1;
        asc(i, 1, n) {
            qread(t);
            ++cnt[t];
            ma = max(ma, t);
        }
        printf("%d\n", solve(ma));
    }
    return 0;
}