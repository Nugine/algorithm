#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define MAX 1000100
inline int read() {
    int x = 0;
    bool t = false;
    char ch = getchar();
    while ((ch < '0' || ch > '9') && ch != '-')
        ch = getchar();
    if (ch == '-')
        t = true, ch = getchar();
    while (ch <= '9' && ch >= '0')
        x = x * 10 + ch - 48, ch = getchar();
    return t ? -x : x;
}
void Fail() {
    puts("no");
    exit(0);
}
int n, m, a[MAX], pre[MAX], suf[MAX], vis[MAX], nxt[MAX];
void Del(int l, int r) {
    suf[pre[l]] = suf[r];
    pre[suf[r]] = pre[l];
}
int nw = 1;
int get() {
    while (vis[nw])
        ++nw;
    if (nw > n)
        Fail();
    vis[nw] = -1;
    return nw;
}
void Solve(int l, int r) {
    if ((r - l) & 1)
        Fail();
    for (int i = l; i <= r; i = suf[i])
        while (nxt[i]) {
            if (nxt[i] > r)
                Fail();
            Solve(suf[i], pre[nxt[i]]);
            Del(suf[i], nxt[i]);
            nxt[i] = nxt[nxt[i]];
        }
    int sum = 0, cnt = 0, rt = a[pre[l]];
    for (int i = l; i <= r; i = suf[i])
        ++sum, cnt += a[i] > 0;
    sum = (sum + 1) / 2;
    if (cnt > sum)
        Fail();
    for (int i = suf[l]; i <= r; i = suf[i])
        if (!a[i] && cnt < sum)
            a[i] = get(), ++cnt;
    if (sum == 1 && cnt == 0)
        a[l] = get();
    for (int i = l; suf[i] <= r; i = suf[i]) {
        while (i > l && suf[i] <= r && !a[pre[i]] && a[i] && a[suf[i]])
            a[pre[i]] = a[suf[i]], Del(i, suf[i]), i = pre[pre[i]];
        while (i >= l && suf[suf[i]] <= r && a[i] && a[suf[i]] &&
               !a[suf[suf[i]]])
            a[suf[suf[i]]] = a[i], Del(suf[i], suf[suf[i]]), i = pre[i];
    }
    for (int i = l; i <= r; i = suf[i])
        if (!a[i])
            a[i] = rt;
}
int main() {
    n = read();
    m = n + n - 1;
    for (int i = 1; i <= m; ++i)
        a[i] = read();
    if (a[1] && a[m] && a[1] != a[m])
        Fail();
    a[1] = a[m] = a[1] | a[m];
    for (int i = 0; i <= m; ++i)
        pre[i] = i - 1, suf[i] = i + 1;
    for (int i = m; i; --i)
        if (a[i])
            nxt[i] = vis[a[i]], vis[a[i]] = i;
    Solve(1, m);
    puts("yes");
    for (int i = 1; i <= m; ++i)
        printf("%d ", a[i]);
    puts("");
    return 0;
}