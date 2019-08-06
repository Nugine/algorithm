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

string solve();

int main() {
    int T;
    rd(T);
    int t;
    asc(t, 1, T) {
        string ans = solve();
        cout << "Case #" << t << ": " << ans << endl;
    }
}

string solve() {
    int i, j;
    char s[20];
    int a[10];
    rng(i, 0, 128 / 16) {
        scanf("%16s", s);
        int t = 0;
        rng(j, 0, 16) { t = (t << 1) | (s[j] - '0'); }
        a[i] = t;
    }

    string part[10];

    rng(i, 0, 8) {
        stringstream ss;
        ss << hex << a[i];
        ss >> part[i];
    }

    string ans;
    rng(i, 0, 8) {
        ans += part[i];
        if (i != 7) {
            ans += ':';
        }
    }

    rng(i, 0, 8) {
        if (a[i] == 0) {
            for (j = i + 1; j < 8 && a[j] == 0; ++j)
                ;

            if (j > i + 1) {
                // cout << i << " " << j << endl;

                string tmp;
                int k;
                rng(k, 0, i) {
                    if (k != 0) {
                        tmp += ':';
                    }
                    tmp += part[k];
                }
                tmp += "::";
                rng(k, j, 8) {
                    if (k != j) {
                        tmp += ':';
                    }
                    tmp += part[k];
                }

                // cout << tmp << endl;

                if (tmp.length() < ans.length()) {
                    ans = tmp;
                } else if (tmp.length() == ans.length()) {
                    if (tmp < ans) {
                        ans = tmp;
                    }
                }
            }
        }
    }

    return ans;
}