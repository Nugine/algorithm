#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
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

// #define DEBUG

int solve();
int main() {
    int T;
    rd(T);
    int t;
    asc(t, 1, T) {
        int ans = solve();
        printf("Case #%d: %d\n", t, ans);
    }
}

int n, k;
int v[1000 + 7];
vector<int> vset;

bool is_valid(int vol);

int solve() {
    rd2(n, k);
    int i;
    vset.clear();
    asc(i, 1, n) {
        rd(v[i]);
        vset.push_back(v[i]);
    }
    sort(vset.begin(), vset.end());

    int max_vol = 1000 * 1000;
    int min_vol = 0;

    int l = min_vol;
    int r = max_vol;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (!is_valid(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    return r;
}

bool is_valid(int vol) {
    vector<int> vs(vset);
#ifdef DEBUG
    cout << "vol: " << vol << endl;
#endif

    int used_box = 0;
    int free = vol;

    while (!vs.empty()) {
        auto iter = upper_bound(vs.begin(), vs.end(), free);
        int i = (iter - vs.begin()) - 1;

#ifdef DEBUG
        cout << i << endl;
        for (auto x : vs) {
            cout << x << " ";
        }
        cout << endl;
#endif

        if (i < 0 || vs[i] > free) {
            free = vol;
            ++used_box;
        } else {
            free -= vs[i];
            vs.erase(vs.begin() + i);
        }

        if (used_box > k) {
#ifdef DEBUG
            cout << "false" << endl;
#endif

            return false;
        }
    }

    if (free < vol) {
        ++used_box;
    }

#ifdef DEBUG
    cout << (used_box <= k ? "true" : "false") << endl;
#endif

    return used_box <= k;
}