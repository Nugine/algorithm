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

ll exgcd(const ll a, const ll b, ll &x, ll &y) {
    ll c, d, q, t, x0, y0, x1, y1, temp;
    c = a, d = b, q = a / b, t = a % b, x0 = 1, y0 = 0, x1 = 0, y1 = 1;
    while (t) {
        temp = x0, x0 = x1, x1 = temp - q * x1;
        temp = y0, y0 = y1, y1 = temp - q * y1;
        c = d;
        d = t;
        q = c / d;
        t = c % d;
    }
    x = x1, y = y1;
    return d;
}

// #include <iostream>
// using namespace std;
// int main() {
//     ll a, b, x, y;
//     ll ans;
//     while (cin >> a >> b) {
//         ans = exgcd(a, b, x, y);
//         if (ans != (a * x + b * y) || ans != gcd(a, b)) {
//             cout << "WA" << endl;
//         }
//         cout << ans << " " << x << " " << y << endl;
//     }
// }