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

constexpr int f(int n) {
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

constexpr array<ull, MAXN> build_table() {
    array<ull, MAXN> table{};
    int n = 0;
    asc(n, 1, 10000) { table[n] = (ull(f(n)) << 32) + ull(n); }
    return table;
}

array<ull, MAXN> table = build_table();

int main() {
    int x, y, i;
    cin >> x >> y >> i;

    sort(table.begin() + x, table.begin() + (y + 1));
    int ans = table[x + i - 1] & ull(0xffffffff);

    cout << ans << endl;
}
