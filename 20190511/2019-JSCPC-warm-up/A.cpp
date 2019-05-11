#include <iostream>
using namespace std;

char mat[1007][1007];
const char *s = "helloworld";

int main() {
    int n, m;
    cin >> n >> m;

    int size = n * m;
    int cnt = 0;
    int i = 0, j = 1;
    while (cnt < size) {
        while (i < n && mat[i + 1][j] == 0) {
            mat[i + 1][j] = s[cnt % 10];
            ++i, ++cnt;
        }
        while (j < m && mat[i][j + 1] == 0) {
            mat[i][j + 1] = s[cnt % 10];
            ++j, ++cnt;
        }
        while (i > 1 && mat[i - 1][j] == 0) {
            mat[i - 1][j] = s[cnt % 10];
            --i, ++cnt;
        }
        while (j > 1 && mat[i][j - 1] == 0) {
            mat[i][j - 1] = s[cnt % 10];
            --j, ++cnt;
        }
    }
    for (i = 1; i <= n; ++i) {
        for (j = 1; j <= m; ++j) {
            putchar(mat[i][j]);
        }
        putchar('\n');
    }
    return 0;
}