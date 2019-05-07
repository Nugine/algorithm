#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define rd(x) scanf("%d", &(x))
#define rd2(x, y) scanf("%d %d", &(x), &(y))
#define rd3(x, y, z) scanf("%d %d %d", &(x), &(y), &(z))
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))
#define rng(i, s, e) for ((i) = (s); (i) < (e); ++(i))
#define pdln(x) printf("%d\n", (x))

vector<int> v;
vector<int> ans;

int main() {
    int n, m;
    while (cin >> n >> m) {
        v.clear();
        ans.clear();

        int i;
        v.push_back(1);
        asc(i, 2, n) { v.push_back(i); }
        v.push_back(1);

        int p = 0, now = 0;
        while (v[now] != now) {

            asc(i, 1, m) {
                p = now;
                now = v[now];
            }
            v[p] = v[now];
            ans.push_back(now);
        }

        int len = ans.size();
        cout << ans[0];
        rng(i, 1, len) { cout << " " << ans[i]; }
        cout << endl;
    }
    return 0;
}