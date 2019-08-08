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

struct slice {
    char *p;
    int len;
    int zero;
};

static slice ctx[200 + 7];
static int ctx_len = 0;

void parse_01(char *&st) {
    if (*st == '1') {
        char *p = st;
        while (*p == '1') {
            ++p;
        }
        ctx[ctx_len++] = slice{.p = st, .len = int(p - st), .zero = 0};
        st = p;
    } else {
        char *p = st;
        while (*p == '0') {
            ++p;
        }
        int zero = p - st;
        while (*p == '1') {
            ++p;
        }
        ctx[ctx_len++] = slice{.p = st, .len = int(p - st), .zero = zero};
        st = p;
    }
}

static char src[200 + 7];
static int src_len;

void solve();

int main() {
    int T;
    rd(T);
    while (T--) {
        scanf("%s", src);
        src_len = strlen(src);
        ctx_len = 0;
        solve();
    }
}

void solve() {
    char *p = src;
    while (*p != '\0') {
        parse_01(p);
    }

    // for (int i = 0; i < ctx_len; ++i) {
    //     printf("%d ", ctx[i].len);
    // }
    // putchar('\n');

    bool is_first = true;

    p = src;
    int i = 0;
    int j;
    while (i < ctx_len) {
        slice base = ctx[i];
        // printf("%d base len=%d\n", i, base.len);

        bool is_narrow = false;

        j = i + 1;
        while (j < ctx_len) {
            slice &rhs = ctx[j];

            if (rhs.zero == rhs.len) {
                break;
            }

            if (base.zero >= rhs.zero) {
                if (base.zero == rhs.zero) {
                    if (is_narrow) {
                        break;
                    } else {
                        base.len += rhs.len;
                        ++j;
                    }
                } else {
                    is_narrow = true;
                    base.len += rhs.len;
                    ++j;
                }
                // printf("comb %d len=%d\n", j - 1, rhs.len);
            } else {
                break;
            }
        }

        i = j;

        static char buf[200 + 7];
        memcpy(buf, base.p, base.len);
        buf[base.len] = '\0';

        if (is_first) {
            printf("%s", buf);
            is_first = false;
        } else {
            printf(" %s", buf);
        }
    }

    putchar('\n');
}