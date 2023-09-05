#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
#define asc(i, s, e) for (i = (s); i <= (e); ++i)

const ll M = 998244353;
ll fib[1007];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    fib[0] = fib[1] = 1;
    int i;
    asc(i, 2, n) { fib[i] = (fib[i - 1] + fib[i - 2]) % M; }

    cout << (fib[n]) << endl;

    return 0;
}