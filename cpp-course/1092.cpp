#include <iostream>
using namespace std;
typedef long long ll;
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))

ll mat[10][100 + 3][100 + 3];

void solve(int n);

void print(int n, int s) {
    int i, j;
    asc(i, 1, n) {
        asc(j, 1, n - 1) { cout << (mat[s][i][j]) << ' '; }
        cout << (mat[s][i][n]) << endl;
    }
}

int main() {
    int n;
    while (cin >> n) {
        solve(n);
    }
    return 0;
}

void rotate(int n, int s, int d) {
    int i, j, ni, nj;

    asc(i, 1, n) {
        asc(j, 1, n) {
            ni = j;
            nj = n + 1 - i;
            mat[d][ni][nj] = mat[s][i][j];
        }
    }
}

void iadd(int n, int s, int d, ll mul) {
    int i, j;
    asc(i, 1, n) {
        asc(j, 1, n) { mat[d][i][j] += mat[s][i][j] * mul; }
    }
}

void solve(int n) {
    int i, j;
    asc(i, 1, n) {
        asc(j, 1, n) {
            cin >> (mat[0][i][j]);
            mat[5][i][j] = 0;
        }
    }

    int k;
    cin >> k;

    rotate(n, 0, 1);
    rotate(n, 1, 2);
    rotate(n, 2, 3);

    int a = k / 4;
    int b = k % 4;

    iadd(n, 0, 5, a + 1);
    iadd(n, 1, 5, a + ((b >= 1) ? 1 : 0));
    iadd(n, 2, 5, a + ((b >= 2) ? 1 : 0));
    iadd(n, 3, 5, a + ((b >= 3) ? 1 : 0));

    print(n, 5);
}
