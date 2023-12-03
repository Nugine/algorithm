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

char S[MAXN];
int n;

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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> S;
    n = strlen(S);

    calc_pi(S, n);

    int i;
    int max_pi = 0;
    rng(i, 1, n - 1) { max_pi = max(max_pi, pi[i]); }

    int k;
    for (k = pi[n - 1]; k > 0; k = pi[k - 1]) {
        if (max_pi >= k) {
            break;
        }
    }

    if (k) {
        rng(i, 0, k) { putchar(S[i]); }
        putchar('\n');
    } else {
        printf("Just a legend\n");
    }
}