#include <iostream>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    ll t = a % b;
    while (t) {
        a = b;
        b = t;
        t = a % b;
    }
    return b;
}

int main() {
    ll m, n, k;
    while (cin >> m >> n >> k) {
        ll ans = gcd(gcd(m, n), k);
        cout << ans << endl;
    }
}
