#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
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

const char *msgs[] = {
    "Harmful",
    "Recyclable",
    "Dry",
    "Wet",
};

int solve();
int main() {
    int T;
    rd(T);
    int t;
    asc(t, 1, T) {
        int ans = solve();
        const char *msg = msgs[ans - 1];
        printf("Case #%d: %s\n", t, msg);
    }
}

int solve() {
    static char s[2000 + 7];
    static char t[2000 + 7];
    scanf("%s", s);
    scanf("%s", t);

    int table[30];
    int i;
    rng(i, 0, 26) {
        if (t[i] == 'd') {
            table[i] = 1;
        } else if (t[i] == 'w') {
            table[i] = 2;
        } else {
            table[i] = 3;
        }
    }

    int sl = strlen(s);
    int cnt[5] = {0, 0, 0, 0, 0};
    rng(i, 0, sl) {
        ++cnt[table[int(s[i] - 'a')]];
        // printf("%d %d %d\n", cnt[1], cnt[2], cnt[3]);
    }

    int sum = cnt[1] + cnt[2] + cnt[3];
    // printf("%d %d %d\n", cnt[1], cnt[2], cnt[3]);
    if (cnt[3] * 4 >= sum) {
        return 1;
    } else if (cnt[3] * 10 <= sum) {
        return 2;
    } else if (cnt[2] * 2 <= cnt[1]) {
        return 3;
    } else {
        return 4;
    }
}