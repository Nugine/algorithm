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

int n, m;
int mat[1010][1010];

int init() {
    scanf("%d%d", &n, &m);
    char ch[1010];
    int i, j;
    asc(i, 1, n) {

        asc(j, 1, m) {
            scanf("%s", ch);
            if (ch[0] == 'F') {
                mat[i][j] = 1;
            } else {
                mat[i][j] = 0;
            }
            // putchar('0' + mat[i][j]);
        }
        // putchar('\n');
    }
    return 0;
}

int uplen[1010][1010];

int solve() {
    int i, j;
    asc(i, 1, n) {
        asc(j, 1, m) {
            if (mat[i][j]) {
                uplen[i][j] = uplen[i - 1][j] + 1;
            } else {
                uplen[i][j] = 0;
            }
            // printf("%d ", uplen[i][j]);
        }
        // putchar('\n');
    }
    // return 0;

    struct Blk {
        int h, w;
    };

    stack<Blk> stk;
    int max_ans = 0;
    Blk tmp;
    asc(i, 1, n) {
        // printf("row: %d\n", i);
        int w;
        asc(j, 1, m) {
            // printf("col: %d\n", j);
            int h = uplen[i][j];

            if (!h) {
                w = 0;
                while (!stk.empty()) {
                    tmp = stk.top();
                    stk.pop();
                    w += tmp.w;
                    // if (tmp.h == w) {
                    max_ans = max(max_ans, tmp.h * w);
                    // }
                }

            } else {
                w = 0;
                while (!stk.empty() && stk.top().h >= h) {
                    Blk tmp = stk.top();
                    stk.pop();
                    // printf("tmp: {%d, %d}\n", tmp.h, tmp.w);
                    w += tmp.w;

                    // if (tmp.h == w) {
                    max_ans = max(max_ans, tmp.h * w);
                    // }
                }

                stk.push(Blk{h, w + 1});
            }
        }

        w = 0;
        while (!stk.empty()) {
            Blk tmp = stk.top();
            stk.pop();
            // printf("tmp: {%d, %d}\n", tmp.h, tmp.w);
            w += tmp.w;
            // if (tmp.h == w) {
            max_ans = max(max_ans, tmp.h * w);
            // }
        }
    }
    printf("%d\n", max_ans * 3);
    return 0;
}

int main() {
    // freopen("testdata (5).in", "r", stdin);

    // int T;
    // scanf("%d", &T);
    // while (T--) {
    init();
    solve();
    // }
    return 0;
}