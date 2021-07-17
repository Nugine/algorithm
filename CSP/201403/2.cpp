#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))
#define rng(i, s, e) for ((i) = (s); (i) < (e); ++(i))
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

struct Window {
    int x1, y1, x2, y2;
};

int main() {
    static uint8_t table[2600][1500] = {0};
    Window windows[16];

    int n, m;
    cin >> n >> m;

    int i;
    asc(i, 1, n) {
        Window &w = windows[i];
        cin >> w.x1 >> w.y1 >> w.x2 >> w.y2;

        int x, y;
        asc(x, w.x1, w.x2) {
            asc(y, w.y1, w.y2) { table[x][y] = i; }
        }
    }

    asc(i, 1, m) {
        int x, y;
        cin >> x >> y;
        int idx = table[x][y];
        if (idx == 0) {
            cout << "IGNORED\n";
        } else {
            Window &w = windows[idx];
            asc(x, w.x1, w.x2) {
                asc(y, w.y1, w.y2) { table[x][y] = idx; }
            }
            cout << idx << '\n';
        }
    }

    return 0;
}