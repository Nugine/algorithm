#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
#define rd(x) scanf("%d", &(x))
#define rd2(x, y) scanf("%d %d", &(x), &(y))
#define rd3(x, y, z) scanf("%d %d %d", &(x), &(y), &(z))
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))
#define rng(i, s, e) for ((i) = (s); (i) < (e); ++(i))
#define desc(i, s, e) for ((i) = (s); (i) >= (e); --(i))
#define pdln(x) printf("%d\n", (x))

int table[][4] = {
    {4, 5, 9, 10}, {8, 9, 4, 5}, {2, 3, 8, 9}, {7, 8, 2, 3}, {1, 2, 7, 8}};

void solve(int n) {
    if (n == 4) {
        int i;
        for (auto a : table) {
            printf("%d,%d-->%d,%d\n", a[0], a[1], a[2], a[3]);
        }
    } else {
        printf("%d,%d-->%d,%d\n", n, n + 1, n * 2 + 1, n * 2 + 2);
        printf("%d,%d-->%d,%d\n", 2 * n - 1, 2 * n, n, n + 1);
        solve(n - 1);
    }
}

int main() {
    int n;
    while (cin >> n) {
        solve(n);
    }
}