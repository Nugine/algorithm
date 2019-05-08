// 二分图最大匹配 - 匈牙利算法

#include <cstring>
#include <iostream>
using namespace std;

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
    int ne;
    cin >> nx >> ny >> ne;

    while (ne--) {
        int x, y;
        cin >> x >> y;
        if (y > ny || x > nx) {
            continue;
        }
        edge[x][y] = 1;
    }
    int ans = max_match();
    cout << ans << endl;
}
