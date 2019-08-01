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

ll M;

int mat_size = 4 * sizeof(int);

void mat_imul(int lhs[2][2], int rhs[2][2], int r[2][2]) {
    r[0][0] =
        ((ll(lhs[0][0]) * rhs[0][0]) % M + (ll(lhs[0][1]) * rhs[1][0]) % M) % M;
    r[0][1] =
        ((ll(lhs[0][0]) * rhs[0][1]) % M + (ll(lhs[0][1]) * rhs[1][1]) % M) % M;
    r[1][0] =
        ((ll(lhs[1][0]) * rhs[0][0]) % M + (ll(lhs[1][1]) * rhs[1][0]) % M) % M;
    r[1][1] =
        ((ll(lhs[1][0]) * rhs[0][1]) % M + (ll(lhs[1][1]) * rhs[1][1]) % M) % M;
}

void mat_ipow(int base[2][2], char n_str[], int n_len, int r[2][2]) {
    static int tmp[2][2], tmp1[2][2], tmp2[2][2], tmp4[2][2], tmp8[2][2];

    memset(r, 0, mat_size);
    r[0][0] = r[1][1] = 1;

    int i, j, p;
    desc(i, n_len - 1, 0) {
        p = n_str[i] - '0';
        asc(j, 1, p) {
            // r = base * r
            mat_imul(base, r, tmp);
            memcpy(r, tmp, mat_size);
        }
        memcpy(tmp, base, mat_size);

        memcpy(tmp1, tmp, mat_size); // base^1
        mat_imul(tmp, tmp1, tmp2);   // base^2

        memcpy(tmp, tmp2, mat_size);
        mat_imul(tmp, tmp2, tmp4); // base^4

        memcpy(tmp, tmp4, mat_size);
        mat_imul(tmp, tmp4, tmp8); // base^8

        mat_imul(tmp2, tmp8, base); // base = base^10
    }
}

int main() {

    int x0, x1, a, b;
    scanf("%d%d%d%d", &x0, &x1, &a, &b);
    getchar();

    static char n_str[1000000 + 7];

    int n_len = 0;
    char ch;
    while ((ch = getchar()) != ' ') {
        n_str[n_len++] = ch;
    }

    int m;
    scanf("%d", &m);
    M = m;

    int base[2][2] = {{a, b}, {1, 0}};
    int r[2][2];

    mat_ipow(base, n_str, n_len, r);

    int ans = ((ll(r[1][0]) * x1) % M + (ll(r[1][1]) * x0) % M) % M;

    printf("%d\n", ans);
    return 0;
}