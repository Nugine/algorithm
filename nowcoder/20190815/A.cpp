#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))
#define desc(i, s, e) for ((i) = (s); (i) >= (e); --(i))
#define rng(i, s, e) for ((i) = (s); (i) < (e); ++(i))

#define DEBUG

int n, m;
int mat[3003][3003];

void init() {
    scanf("%d%d", &n, &m);
    char buf[3003];
    cin.getline(buf, sizeof(buf));
    int i, j;
    asc(i, 1, n) {
        cin.getline(buf, sizeof(buf));
        asc(j, 1, m) { mat[i][j] = buf[j - 1] - '0'; }
    }
}

int uplen[3003][3003];

int solve() {
    int i, j;
    asc(i, 1, n) {
        asc(j, 1, m) {
            if (mat[i][j]) {
                uplen[i][j] = uplen[i - 1][j] + 1;
            } else {
                uplen[i][j] = 0;
            }
        }
    }

    struct Blk {
        int h, w;
    };

    stack<Blk> stk;
    int ans = 0;

    asc(i, 1, n) {
#ifdef DEBUG
        printf("row: %d\n", i);
#endif

        int th = 0;

        asc(j, 1, m) {
#ifdef DEBUG
            printf("    col: %d\n", j);
#endif

            int h = uplen[i][j];

            if (!h) {
                int w = 0;
                Blk tmp;
                while (!stk.empty()) {
                    tmp = stk.top();
                    stk.pop();
                    w += tmp.w;

#ifdef DEBUG
                    printf("a blk: {.h = %d, .w = %d}, th = %d\n", tmp.h, w,
                           th);
#endif
                    if (tmp.h != th) {
                        ++ans;
                    }
                    th = tmp.h;
                }

            } else {
                int w = 0;
                Blk tmp;
                while (!stk.empty() && stk.top().h >= h) {
                    tmp = stk.top();
                    stk.pop();
                    w += tmp.w;

#ifdef DEBUG
                    printf("b blk: {.h = %d, .w = %d}, th = %d\n", tmp.h, w,
                           th);
#endif
                    if (tmp.h != th) {

                        ++ans;
                    }
                    th = tmp.h;
                }

                stk.push(Blk{h, w + 1});
            }
        }

        int w = 0;
        Blk tmp;
        while (!stk.empty()) {
            tmp = stk.top();
            stk.pop();
            w += tmp.w;

#ifdef DEBUG
            printf("c blk: {.h = %d, .w = %d}, th = %d\n", tmp.h, w, th);
#endif

            if (tmp.h != th) {
                ++ans;
            }
            th = tmp.h;
        }
    }
    printf("%d\n", ans);
    return 0;
}

int main() {
    init();
    solve();
    return 0;
}