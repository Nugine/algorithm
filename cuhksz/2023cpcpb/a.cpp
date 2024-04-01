#include <cstdio>
#include <iostream>
using namespace std;
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))
#define rng(i, s, e) for ((i) = (s); (i) < (e); ++(i))
// #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define eprintf(...)

const int N = 1e4 + 7;

int n;
int b[N];
int a[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int i;
    rng(i, 0, n / 2) { cin >> b[i]; }

    int lb = 1;
    int ub = b[n / 2 - 1];
    rng(i, 0, n / 2) {
        int x = b[i];
        int found = 0;
        while (lb * lb <= x) {
            if (x % lb == 0 && x / lb <= ub) {
                eprintf("x = %d, lb = %d\n", x, lb);
                a[i] = lb;
                a[n - i - 1] = x / lb;
                ub = x / lb;
                found = 1;
                break;
            }
            ++lb;
        }
        if (!found) {
            printf("-1\n");
            return 0;
        }
    }

    rng(i, 0, n) {
        if (i != 0) {
            printf(" ");
        }
        printf("%d", a[i]);
    }
    printf("\n");
}
