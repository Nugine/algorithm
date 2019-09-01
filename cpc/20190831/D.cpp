#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long long u64;
#define rd(x) scanf("%d", &(x))
#define rd2(x, y) scanf("%d %d", &(x), &(y))
#define rd3(x, y, z) scanf("%d %d %d", &(x), &(y), &(z))
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))
#define rng(i, s, e) for ((i) = (s); (i) < (e); ++(i))
#define desc(i, s, e) for ((i) = (s); (i) >= (e); --(i))
#define pd(x) printf("%d", (x))
#define pdsp(x) printf("%d ", (x))
#define sppd(x) printf(" %d", (x))
#define pdln(x) printf("%d\n", (x))

void solve(double &y, double &z);
int main() {
    int T;
    rd(T);
    int i;
    asc(i, 1, T) {
        double y, z;
        solve(y, z);
        printf("Case #%d: %.6lf %.6lf\n", i, y, z);
    }
}

void solve(double &y, double &z) {
    int n, m;
    scanf("%d %d", &n, &m);
    y = (n != 1) ? (0.5) : (1.0);
    z = (m + 1.0) / (m * 2.0);
}