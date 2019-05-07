#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
#define rd(x) scanf("%d", &(x))
#define rd2(x, y) scanf("%d %d", &(x), &(y))
#define rd3(x, y, z) scanf("%d %d %d", &(x), &(y), &(z))
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))
#define pdln(x) printf("%d\n", (x))

int mat[20][20];
int n;

int a[20];
int b[20];
int c[20];
int d[20];

inline void set(int i, int j, int t) {
    if (t) {
        ++n;
        a[i] = 1;
        b[j] = 1;
        c[i + j] = 1;
        d[i - j + 8] = 1;
    }

    mat[i][j] = t;
}

void dfs(int row, int &ans) {
    if (row > 8) {
        ++ans;
        return;
    }

    if (a[row]) {
        dfs(row + 1, ans);
    } else {
        int col;
        asc(col, 1, 8) {
            if (b[col] == 0 && c[row + col] == 0 && d[row - col + 8] == 0) {
                b[col] = 1;
                c[row + col] = 1;
                d[row - col + 8] = 1;
                dfs(row + 1, ans);
                b[col] = c[row + col] = d[row - col + 8] = 0;
            }
        }
    }
}

int main() {
    int t, i, j;

    while (cin >> t) {
        n = 0;
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));
        memset(d, 0, sizeof(d));

        set(1, 1, t);
        asc(j, 2, 8) {
            cin >> t;
            set(1, j, t);
        }
        asc(i, 2, 8) {
            asc(j, 1, 8) {
                cin >> t;
                set(i, j, t);
            }
        }

        int ans = 0;
        dfs(1, ans);
        cout << ans << endl;
    }
}
