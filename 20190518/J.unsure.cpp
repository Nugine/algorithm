#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
char s[100000 + 7];
char t[100 + 7];
int sl, tl;

int table[100000 + 7][26];
int tmp[26];

int locate(int i) {
    int p, j;
    if (s[i] == t[0]) {
        j = 1;
    } else {
        j = 0;
    }
    p = i;
    while (j <= tl - 1 && table[p][t[j] - 'a'] >= 0) {
        p = table[p][t[j] - 'a'];
        ++j;
    }
    if (j > tl - 1) {
        return p;
    } else {
        return -1;
    }
}

int main() {
    // freopen("in", "r", stdin);
    scanf("%s %s", s, t);
    sl = strlen(s);
    tl = strlen(t);

    memset(tmp, -1, sizeof(tmp));
    int i;
    for (i = sl - 1; i >= 0; --i) {
        memcpy(table[i], tmp, sizeof(tmp));
        tmp[s[i] - 'a'] = i;
        // for (int j = 0; j < 26; ++j) {
        //     printf("%d ", tmp[j]);
        // }
        // putchar('\n');
    }
    ll ans = 0;
    for (i = 0; i < sl; ++i) {
        int p = locate(i);
        // printf("%d %d\n", i, p);
        if (p >= 0) {
            ans += sl - p;
        }
    }
    printf("%lld\n", ans);
    return 0;
}