// https://www.luogu.com.cn/problem/P1359

#include <algorithm>
#include <cassert>
#include <climits>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))
#define rng(i, s, e) for ((i) = (s); (i) < (e); ++(i))
#define desc(i, s, e) for ((i) = (s); (i) >= (e); --(i))
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
// #define eprintf(...)

const int MAXN = 200;

int &min_assign(int &a, int b) { return (b < a) ? (a = b) : (a); }

struct Solution {
    int n;
    int dis[MAXN + 7][MAXN + 7];

    void run() {
        cin >> n;
        int i, j, k, d;
        asc(i, 1, n - 1) {
            dis[i][i] = 0;
            asc(j, i + 1, n) {
                cin >> d;
                dis[i][j] = d;
                dis[j][i] = INT_MAX / 2;
            }
        }

        asc(k, 1, n) {
            asc(i, 1, n) {
                asc(j, 1, n) { min_assign(dis[i][j], dis[i][k] + dis[k][j]); }
            }
        }

        int ans = dis[1][n];
        cout << ans << '\n';
    }
};

int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    static Solution s;
    s.run();
    return 0;
}
