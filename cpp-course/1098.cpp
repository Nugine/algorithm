#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rd(x) scanf("%d", &(x))
#define rd2(x, y) scanf("%d %d", &(x), &(y))
#define pd(x) printf("%d", (x))
#define sppd(x) printf(" %d", (x))
#define pdln(x) printf("%d\n", (x))
#define rng(i, s, e) for ((i) = (s); (i) < (e); ++(i))
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))
#define desc(i, s, e) for ((i) = (s); (i) >= (e); --(i))

const int N = 1e6;
bool is_not_prime[N + 3];
int primes[N + 3];
int primes_len = 0;

void init_primes(int maxn) {
    int i, j, t;
    asc(i, 2, maxn) {
        if (!is_not_prime[i]) {
            primes[primes_len++] = i;
        }

        rng(j, 0, primes_len) {
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
    init_primes(N);

    int n;
    vector<int> factors;
    while (rd(n) > 0) {
        factors.clear();

        int i = 0;
        int p;
        while (n != 1 && n != -1 && n != 0) {
            p = primes[i];
            while (n % p == 0) {
                factors.push_back(p);
                n /= p;
            }
            ++i;
        }
        pd(factors[0]);
        int len = factors.size();
        rng(i, 1, len) { sppd(factors[i]); }
        putchar('\n');
    }
    return 0;
}
