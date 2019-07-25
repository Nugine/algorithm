#include <bits/stdc++.h>
#define N 500000 + 7
#define clear(a) memset(a, 0, sizeof(a))

using namespace std;
inline int read() {
    int ans = 0;
    char ch = getchar();
    while (!isdigit(ch))
        ch = getchar();
    while (isdigit(ch))
        ans = (ans << 3) + (ans << 1) + (ch ^ 48), ch = getchar();
    return ans;
}
int n, m, in[N], pred[N], last[N], cnt[N], len, st[N][21], L[N], R[N];
vector<int> del;
inline int min(int a, int b) { return a < b ? a : b; }
inline int find(int *fa, int x) {
    return x == fa[x] ? x : fa[x] = find(fa, fa[x]);
}
inline bool solve(int l, int r) {
    vector<int> pos;
    int Ri = -1;
    for (int i = find(R, l); i <= r; i = find(R, i + 1)) {
        pos.push_back(i), ++Ri;
        while (pos.size() >= 3) {
            if (((!in[pos[Ri - 2]] && in[i]) || (in[pos[Ri - 2]] && !in[i]) ||
                 (in[pos[Ri - 2]] && (in[pos[Ri - 2]] == in[i]))) &&
                in[pos[Ri - 1]]) {
                if (in[pos[Ri - 2]] != in[pos[Ri]])
                    in[pos[Ri - 2]] = in[i] = in[pos[Ri - 2]] + in[i];
                pos.pop_back(), pos.pop_back(), Ri -= 2;
            } else
                break;
        }
    }
    for (int i = 1; i < pos.size(); ++i)
        if (in[pos[i]] && in[pos[i - 1]]) {
            puts("no");
            return 0;
        }
    deque<int> q;
    int Le = pos[0];
    for (int i = 1; i < pos.size() - 1; ++i)
        q.push_back(pos[i]);
    while (!q.empty()) {
        int x = q.front(), y = q.back();
        if (q.size() == 1) {
            if (!in[x]) {
                if (del.empty()) {
                    puts("no");
                    return 0;
                }
                in[x] = del.back(), del.pop_back();
            }
            break;
        } else {
            if (!in[x] && !in[y]) {
                if (del.empty()) {
                    puts("no");
                    return 0;
                }
                in[x] = in[y] = del.back(), del.pop_back(), Le = in[x],
                q.pop_front(), q.pop_back();
            } else if (in[x])
                in[q[1]] = Le, q.pop_front(), q.pop_front();
            else
                in[q[q.size() - 2]] = Le, q.pop_back(), q.pop_back();
        }
    }
    for (int i = find(R, l); i <= r; i = find(R, i + 1))
        if (i != l)
            R[i] = r + 1;
    L[r] = l;
    return 1;
}
int _main() {
    n = read();
    for (int i = 1; i < n * 2; ++i)
        in[i] = read(), ++cnt[in[i]];
    for (int i = 1; i <= n; ++i)
        if (!cnt[i])
            del.push_back(i);
    if (in[1] && in[n * 2 - 1] && in[1] != in[n * 2 - 1]) {
        puts("no");
        return 0;
    } else if (!in[1] && !in[n * 2 - 1]) {
        if (del.empty()) {
            puts("no");
            return 0;
        }
        in[1] = in[n * 2 - 1] = del.back(), del.pop_back();
    } else if (in[1] != in[n * 2 - 1])
        in[1] = in[n * 2 - 1] = in[1] + in[n * 2 - 1];
    for (int i = 1; i < n * 2; ++i) {
        if (!in[i])
            continue;
        pred[i] = last[in[i]] ? last[in[i]] : i, last[in[i]] = i;
    }
    for (int i = 1; i < n * 2; ++i) {
        st[i][0] = pred[i] ? pred[i] : i;
        if (in[i] && ((pred[i] & 1) != (i & 1))) {
            puts("no");
            return 0;
        }
        for (int j = 1; j <= 20 && (1 << j) <= i; ++j)
            st[i][j] = min(st[i][j - 1], st[i - (1 << (j - 1))][j - 1]);
        if (in[i] && pred[i] < i) {
            int mn = i, pre = i - 1;
            for (int j = 20; ~j; --j)
                if (pre - (1 << j) + 1 > pred[i])
                    mn = min(mn, st[pre][j]), pre -= (1 << j);
            if (mn <= pred[i]) {
                puts("no");
                return 0;
            }
        }
    }
    for (int i = 1; i <= n * 2; ++i)
        L[i] = R[i] = i;
    for (int i = 2; i < n * 2; ++i) {
        if (!in[i] || find(L, pred[i]) >= i)
            continue;
        if (!solve(find(L, pred[i]), i))
            return 0;
    }
    // puts("yes");
    for (int i = 1; i < n * 2 - 1; ++i)
        printf("%d ", in[i]);
    printf("%d\n", in[n * 2 - 1]);
    return 0;
}

int main() {
    int T = read();
    while (T--) {
        _main();
        clear(in);
        clear(pred);
        clear(last);
        clear(cnt);
        clear(st);
        clear(L);
        clear(R);
    }
}