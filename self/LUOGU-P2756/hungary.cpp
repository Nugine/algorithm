// 二分图最大匹配 - 匈牙利算法

#include <cstdio>
#include <cstring>
using namespace std;
#define rd2(x, y) scanf("%d %d", &(x), &(y))
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))

const int MAXN = 1000;
int edge[MAXN][MAXN];
int used[MAXN];
int y[MAXN];
int nx, ny;

bool find(int x) {
    int j;
    for (j = 1; j <= ny; ++j) {
        if (!used[j] && edge[x][j]) {
            used[j] = 1;
            if (!y[j] || find(y[j])) {
                y[j] = x;
                return x;
            }
        }
    }
    return 0;
}

int max_match() {
    if (ny == 0 || nx == 0) {
        return 0;
    }

    int ans = 0;
    int i;
    for (i = 1; i <= nx; ++i) {
        memset(used, 0, sizeof(used));
        if (find(i)) {
            ++ans;
        }
    }
    return ans;
}

int main() {
    int m, n;
    rd2(m, n);

    nx = m;
    ny = n - m;

    int ne = 0;
    int u, v;
    while (rd2(u, v) > 0) {
        if (u == -1 && v == -1) {
            break;
        }
        ++ne;
        edge[u][v - m] = 1;
    }

    int ans = max_match();
    if (ans) {
        printf("%d\n", ans);

        int j;
        asc(j, 1, ny) {
            int u = y[j], v = j + m;
            if (u) {
                printf("%d %d\n", u, v);
            }
        }
    } else {
        printf("No Solution!\n");
    }
    return 0;
}
