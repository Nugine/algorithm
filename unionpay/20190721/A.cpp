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
int mat[400][400];

int init() {
    scanf("%d%d", &n, &m);
    char buf[400];
    cin.getline(buf, 400);
    int i, j;
    asc(i, 1, n) {
        cin.getline(buf, 400);
        asc(j, 1, m) {
            if (buf[j - 1] == '*') {
                mat[i][j] = 0;
            } else {
                mat[i][j] = 1;
            }
        }
    }
    return 0;
}

int uplen[400][400];

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

                    max_ans = max(max_ans, min(tmp.h, w) * min(tmp.h, w));
                }

            } else {
                w = 0;
                while (!stk.empty() && stk.top().h >= h) {
                    Blk tmp = stk.top();
                    stk.pop();
                    // printf("tmp: {%d, %d}\n", tmp.h, tmp.w);
                    w += tmp.w;

                    max_ans = max(max_ans, min(tmp.h, w) * min(tmp.h, w));
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
            max_ans = max(max_ans, min(tmp.h, w) * min(tmp.h, w));
        }
    }
    printf("%d\n", max_ans);
    return 0;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        init();
        solve();
    }
    return 0;
}