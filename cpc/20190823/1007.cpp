#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long long u64;
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

char mat[1030][1030];

void solve(int k);
int main() {
    int T;
    rd(T);
    while (T--) {
        int k;
        rd(k);
        solve(k);
    }
}

void fill_mat(int sx, int sy, int k);
void print(int k);
void solve(int k) {
    // if (mat[k][1][1] != 'C') {
    fill_mat(1, 1, k);
    // }

    print(k);
}

void fill_mat_r(int sx, int sy, int k);
void fill_mat(int sx, int sy, int k) {
    // printf("fill %d %d %d\n", sx, sy, k);
    if (k == 1) {
        mat[sy][sx] = 'C';
        mat[sy][sx + 1] = 'C';
        mat[sy + 1][sx] = 'P';
        mat[sy + 1][sx + 1] = 'C';
    } else {
        int step = 1 << (k - 1);

        fill_mat(sx, sy, k - 1);
        fill_mat(sx + step, sy, k - 1);
        fill_mat(sx + step, sy + step, k - 1);
        fill_mat_r(sx, sy + step, k - 1);
    }
}

void fill_mat_r(int sx, int sy, int k) {
    // printf("fill_r %d %d %d\n", sx, sy, k);
    if (k == 1) {
        mat[sy][sx] = 'P';
        mat[sy][sx + 1] = 'P';
        mat[sy + 1][sx] = 'C';
        mat[sy + 1][sx + 1] = 'P';
    } else {
        int step = 1 << (k - 1);

        fill_mat_r(sx, sy, k - 1);
        fill_mat_r(sx + step, sy, k - 1);
        fill_mat_r(sx + step, sy + step, k - 1);
        fill_mat(sx, sy + step, k - 1);
    }
}

void print(int k) {
    int a = 1 << k;
    int i, j;
    asc(i, 1, a) {
        asc(j, 1, a) { putchar(mat[i][j]); }
        // asc(j, 1, a) { pdsp(int(mat[i][j])); }
        putchar('\n');
    }
}