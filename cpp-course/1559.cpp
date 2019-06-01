#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const int M = 10000;

ll qpow2(ll p) {
    ll b = 2, r = 1;
    while (p) {
        if (p & 1) {
            r *= b;
            r %= M;
        }
        b *= b;
        b %= M;
        p >>= 1;
    }
    return r;
}

ll solve(vector<ll> &v, int n) {
    for (int i = v.size() - 1; i < n; ++i) {
        ll t = v[i] + qpow2(ll((sqrt(8 * i + 1) - 1) / 2));
        v.push_back(t % M);
    }
    return v[n];
}

int main() {
    vector<ll> v = {0, 1};
    int n;
    while (cin >> n) {
        cout << solve(v, n) << endl;
    }
}
