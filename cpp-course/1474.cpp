#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))

priority_queue<ll, vector<ll>, greater<ll>> q;

int main() {
    int n;
    int i;
    ll t;

    while (cin >> n) {
        asc(i, 1, n) {
            cin >> t;
            q.push(t);
        }
        while (q.size() > 1) {
            ll a = q.top();
            q.pop();
            ll b = q.top();
            q.pop();

            t = a * b + 1;
            q.push(t);
        }
        ll ans = q.top();
        q.pop();
        cout << ans << endl;
    }
}
