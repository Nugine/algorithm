#include <algorithm>
#include <array>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define asc(i, s, e) for (i = (s); i <= (e); ++i)
#define rng(i, s, e) for (i = (s); i < (e); ++i)
// #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define eprintf(...)

const int MAXN = 1e4 + 7;

int f(int n) {
    int ans = 0;
    while (n != 1) {
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }
        ans += 1;
    }
    return ans;
}

pair<int, int> score[MAXN];

int main() {
    int x, y, i;
    cin >> x >> y >> i;

    int n;
    asc(n, x, y) { score[n] = {f(n), n}; }
    sort(score + x, score + (y + 1));
    int ans = score[x + i - 1].second;

    cout << ans << endl;
}
