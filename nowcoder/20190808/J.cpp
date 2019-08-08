#include <algorithm>
#include <cstdio>
#include <iostream>
#include <sstream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rd(x) scanf("%d", &(x))
#define rd2(x, y) scanf("%d %d", &(x), &(y))
#define rd3(x, y, z) scanf("%d %d %d", &(x), &(y), &(z))
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))
#define rng(i, s, e) for ((i) = (s); (i) < (e); ++(i))
#define desc(i, s, e) for ((i) = (s); (i) >= (e); --(i))
#define pd(x) printf("%d", (x))
#define pdsp(x) printf("%d ", (x))
#define sppd(x) printf(" %d", (x))
#define pdln(x) printf("%d\n", (x))

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        string a, b;
        cin >> a >> b;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        // cout << a << endl << b << endl;

        ll an = 0, bn = 0;
        {
            stringstream ss;
            ss << a;
            ss >> an;
        }

        {
            stringstream ss;
            ss << b;
            ss >> bn;
        }

        // cout << an << endl << bn << endl;

        ll cn = an + bn;

        string c = to_string(cn);
        reverse(c.begin(), c.end());

        {
            stringstream ss;
            ss << c;
            ss >> cn;
        }

        cout << cn << endl;
    }
}