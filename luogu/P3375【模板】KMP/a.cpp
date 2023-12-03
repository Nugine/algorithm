// #define LOCAL_DEBUG

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
#define asc(i, s, e) for (i = (s); i <= (e); ++i)
#define rng(i, s, e) for (i = (s); i < (e); ++i)
#define desc(i, s, e) for (i = (s); i >= (e); --i)
#define ordefault(a, b) (a) ? (a) : (b)
#ifdef LOCAL_DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...)
#endif

const int MAXN = 1e6 + 7;

char T[MAXN], P[MAXN];
int n, m;

int pi[MAXN];

void calc_pi(const char *s, int len) {
    int i, j;
    pi[0] = 0;
    rng(i, 1, len) {
        j = pi[i - 1];
        while (j > 0 && s[j] != s[i]) {
            j = pi[j - 1];
        }
        if (s[j] == s[i]) {
            j += 1;
        }
        pi[i] = j;
    }
}

void kmp() {
    int i, j;
    j = 0;
    rng(i, 0, n) {
        while (j > 0 && P[j] != T[i]) {
            j = pi[j - 1];
        }
        if (P[j] == T[i]) {
            j += 1;
        }
        if (j == m) {
            printf("%d\n", i - m + 1 + 1);
            j = pi[j - 1];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T >> P;

    n = strlen(T);
    m = strlen(P);

    eprintf("n = %d, m = %d\n", n, m);

    calc_pi(P, m);

    kmp();

    int i;
    rng(i, 0, m) { printf("%d ", pi[i]); }
    printf("\n");
}