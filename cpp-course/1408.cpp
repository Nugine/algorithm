#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll n, m;
    while (cin >> n >> m) {
        ll l = min(n, m);
        ll a = n * m * (l + 1) + l * (l + 1) * (2 * l + 1) / 6 -
               (n + m) * (l * (l + 1) / 2);
        ll b = (n * (n + 1) / 2) * (m * (m + 1) / 2) - a;
        cout << a << " " << b << endl;
    }
}