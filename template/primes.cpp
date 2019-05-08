// 线性素数筛

#include <cstdio>
using namespace std;
#define rd(x) scanf("%d", &(x))
#define pdln(x) printf("%d\n", (x))
#define rng(i, s, e) for ((i) = (s); (i) < (e); ++(i))

void init_primes(int maxn, int &primes_len, int primes[], bool is_not_prime[]) {
    int i, j, t;

    for (i = 2; i <= maxn; ++i) {
        if (!is_not_prime[i]) {
            primes[primes_len++] = i;
        }

        for (j = 0; j < primes_len; ++j) {
            t = i * primes[j];
            if (t > maxn) {
                break;
            }
            is_not_prime[t] = 1;
            if (i % primes[j] == 0) {
                break;
            }
        }
    }
}

int main() {
    const int N = 1e6;
    static bool is_not_prime[N + 3];
    static int primes[N + 3], primes_len = 0;

    int n, i;
    while (rd(n) > 0) {
        init_primes(n, primes_len, primes, is_not_prime);
        rng(i, 0, primes_len) { pdln(primes[i]); }
    }
}