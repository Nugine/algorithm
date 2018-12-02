// primes of [1,n]

#include <bitset>
#include <iostream>
using namespace std;

constexpr int MAXN = 1e7 + 1;
constexpr int MAXL = 1e7 + 1;

int prime[MAXN];
int prime_num = 0;
int _n = 2;
bitset<MAXL> _check;

void primes(int n) {
    if (n < _n)
        return;

    int i, j;
    for (i = _n; i <= n; ++i) {
        if (!_check[i])
            prime[prime_num++] = i;

        for (j = 0; j < prime_num; ++j) {
            if (i * prime[j] > MAXN)
                break;

            _check[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
    _n = n + 1;
}

int main() {
    int n;
    while (cin >> n) {
        primes(n);
        // for (int i = 0; i < prime_num; ++i) {
        //     cout << prime[i] << ",\n";
        // }
        // cout << endl;
        printf("done\n");
    }
    return 0;
}
