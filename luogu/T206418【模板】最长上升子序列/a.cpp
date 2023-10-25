/*

T206418 【模板】最长上升子序列

*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
#define asc(i, s, e) for (i = (s); i <= (e); ++i)
#define rng(i, s, e) for (i = (s); i < (e); ++i)
// #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define eprintf(...)

const int MAXN = 5e6;
int a[MAXN];
int n;

int solve();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int i;
    rng(i, 0, n) { cin >> a[i]; }

    cout << solve() << endl;
}

int tail[MAXN];
int len = 0;

int solve() {
    int i;
    rng(i, 0, n) {
        if (a[i] > tail[len]) {
            tail[++len] = a[i];
        } else {
            int pos = lower_bound(tail + 1, tail + len + 1, a[i]) - tail;
            tail[pos] = a[i];
        }
    }
    return len;
}
