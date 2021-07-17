#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))
#define rng(i, s, e) for ((i) = (s); (i) < (e); ++(i))
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

int main() {
    int n;
    int x1, y1, x2, y2;
    static bool table[128][128] = {0};

    cin >> n;

    int i;
    int x, y;
    asc(i, 1, n) {
        cin >> x1 >> y1 >> x2 >> y2;
        rng(x, x1, x2) {
            rng(y, y1, y2) { table[x][y] = true; }
        }
    }

    int cnt = 0;
    asc(x, 0, 100) {
        asc(y, 0, 100) { cnt += table[x][y]; }
    }

    cout << cnt << '\n';

    return 0;
}
