#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <vector>
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

void solve();
int main() {
    int T;
    rd(T);
    int i;
    asc(i, 1, T) {
        printf("Case #%d: ", i);
        solve();
    }
}

void solve() {
    int n, m;
    rd2(n, m);
    static string a, b, s;
    cin >> a >> b >> s;
    int c1 = a[0] - 'A';
    int c2 = b[0] - 'A';

    int offset = c2 + 26 - c1;
    for (auto &c : s) {
        c = ((c - 'A') - offset + 52) % 26 + 'A';
    }
    cout << s << endl;
}