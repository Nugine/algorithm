#include <algorithm>
#include <cstdio>
#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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

char a[100000 + 7];
int s[100000 + 7];

int b[3][100000 + 7];

int n;

int count0() {
    int ans = 0;
    int i;
    asc(i, 1, n) {
        if (a[i] == 0) {
            ++ans;
        }
    }
    return ans;
}

int count00() {
    int ans = 0;
    int i;
    asc(i, 2, n) {
        if (a[i - 1] == 0 && a[i] == 0) {
            ++ans;
        }
    }
    return ans;
}

int main() {
    scanf("%s", a + 1);
    int i = 1;
    b[0][0] = 1;
    while (a[i] != '\0') {
        a[i] -= '0';
        s[i] = s[i - 1] + a[i];
        int j;
        asc(j, 0, 2) { b[j][i] = b[j][i - 1] + (s[i] % 3 == j); }
        ++i;
    }
    n = i - 1;

    ll ans = 0;
    asc(i, 3, n) {
        int r = i - 2;
        if (s[r] == s[i]) {
            int delta = b[s[r] % 3][r] - 1;
            // cout << i << " " << delta << endl;
            ans += delta;
        }
    }
    ans += count0();
    ans += count00();

    cout << ans << endl;
}
