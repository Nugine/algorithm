#include <algorithm>
#include <cstdio>
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

void init();
bool solve(int &X, int &Y);
int main() {
    int q;
    rd(q);
    int X, Y;
    while (q--) {
        init();
        if (solve(X, Y)) {
            printf("1 %d %d\n", X, Y);
        } else {
            printf("0\n");
        }
    }
    return 0;
}

int n;
struct Robot {
    int x, y;
    int f[4];
} a[100000 + 7];

void init() {
    rd(n);
    int i;
    asc(i, 1, n) {
        Robot &r = a[i];
        scanf("%d%d%d%d%d%d", &r.x, &r.y, &r.f[0], &r.f[1], &r.f[2], &r.f[3]);
    }
}

struct Point {
    int x, y;
};

const int E5 = 1e5;

inline bool inter(Point a[2], Point b[2], Point c[2]) {
    c[0].x = max(a[0].x, b[0].x);
    c[0].y = max(a[0].y, b[0].y);
    c[1].x = min(a[1].x, b[1].x);
    c[1].y = min(a[1].y, b[1].y);
    return c[0].x <= c[1].x && c[0].y <= c[1].y;
}

bool solve(int &X, int &Y) {
    Point prev_border[2] = {{-E5, -E5}, {+E5, +E5}};

    int i;
    asc(i, 1, n) {
        const Robot &r = a[i];
        const int x = r.x, y = r.y;

        Point border[2] = {{-E5, -E5}, {+E5, +E5}};

        if (!r.f[0]) {
            border[0].x = x;
        }
        if (!r.f[1]) {
            border[1].y = y;
        }
        if (!r.f[2]) {
            border[1].x = x;
        }
        if (!r.f[3]) {
            border[0].y = y;
        }

        // printf("[(%d, %d), (%d, %d)]\n", prev_border[0].x, prev_border[0].y,
            //    prev_border[1].x, prev_border[1].y);
        // printf("[(%d, %d), (%d, %d)]\n", border[0].x, border[0].y, border[1].x,
            //    border[1].y);

        Point temp_border[2];
        if (inter(prev_border, border, temp_border)) {
            prev_border[0] = temp_border[0];
            prev_border[1] = temp_border[1];
            // printf("[(%d, %d), (%d, %d)]\n", temp_border[0].x, temp_border[0].y,
                //    temp_border[1].x, temp_border[1].y);
        } else {
            return false;
        }
    }
    X = prev_border[0].x;
    Y = prev_border[0].y;
    return true;
}