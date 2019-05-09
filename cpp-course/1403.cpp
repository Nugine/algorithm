#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))
#define rng(i, s, e) for ((i) = (s); (i) < (e); ++(i))

int main() {
    vector<ll> x;
    vector<ll> y;
    int n;

    while (cin >> n) {
        x.clear();
        y.clear();

        int i;
        int t;
        asc(i, 1, n) {
            cin >> t;
            x.push_back(t);
        }
        asc(i, 1, n) {
            cin >> t;
            y.push_back(t);
        }

        sort(x.begin(), x.end());
        sort(y.begin(), y.end(), [](ll a, ll b) { return a > b; });

        ll ans = 0;
        rng(i, 0, n) { ans += x[i] * y[i]; }
        cout << ans << endl;
    }
}
